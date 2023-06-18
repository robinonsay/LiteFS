#!/usr/bin/python3
import json
from pathlib import Path
import struct
import argparse

config_path = Path(__file__).parent.parent / 'config.json'
secret_path = Path(__file__).parent.parent / 'secret.key'

MAX_MISSION_NAME = 256
MAX_PATH_LEN = 256
SECRET_LENGTH = 32


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('out_path', nargs=1, type=str, default=str(config_path.parent))
    args = parser.parse_args()
    out_path = Path(args.out_path[0])
    with open(config_path, 'r') as f:
        config = json.load(f)

    if secret_path.exists():
        with open(secret_path, 'rb') as f:
            secret = f.read()
    else:
        secret = b'\0' * 32

    config_packed = struct.pack(f"{MAX_MISSION_NAME}s{MAX_PATH_LEN}s{SECRET_LENGTH}s",
                                config['mission'].encode('ASCII'),
                                config['app_prefix'].encode('ASCII'),
                                secret)

    with open(out_path / 'config.o', 'wb') as f:
        f.write(config_packed)
