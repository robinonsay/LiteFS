CC := gcc
OUT := $(abspath ../)/out/apps
TARGET := example.so
CFLAGS := --debug -std=c99 -Wall
# CFLAGS := --debug -std=c99 -Werror -Wall
LINK_FLAGS :=
LINK_DIRS := -L../out/lib
LINK_LIBS := -lLiteFS
INCLUDE_DIR := -I../src

all: $(TARGET)

$(TARGET): $(OUT)
	$(CC) -shared $(CFLAGS) $(INCLUDE_DIR) -fPIC -o $(OUT)/$@ example.c $(LINK_FLAGS) $(LINK_DIRS) $(LINK_LIBS)

$(OUT):
	if ! [ -d $(OUT) ]; then \
		mkdir $(OUT); \
	fi
