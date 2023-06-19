# GCC support can be specified at major, minor, or micro version
# (e.g. 8, 8.2 or 8.2.0).
# See https://hub.docker.com/r/library/gcc/ for all supported GCC
# tags from Docker Hub.
# See https://docs.docker.com/samples/library/gcc/ for more on how to use this image
FROM gcc:latest

# These commands copy your files into the specified directory in the image
# and set that as the working location

# This command compiles your app using GCC, adjust for your source code
RUN apt-get -y update
RUN apt-get -y install gdb gdbserver
COPY . /usr/src/litefs
WORKDIR /usr/src/litefs
RUN make
RUN ldconfig /usr/src/litefs/out/lib
RUN cd example_app && make

# This command runs your application, comment out this line to compile only
WORKDIR /usr/src/litefs/out
CMD ["./litefs"]

LABEL Name=litefs Version=0.0.1
