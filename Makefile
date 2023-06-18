CC := gcc
OUT ?= $(abspath ./)/out
TARGET := litefs
LIB_NAME := LiteFS
LIB_TARGET := lib$(LIB_NAME).so
CFLAGS := --debug -std=c99 -pedantic -Wall
# CFLAGS := --debug -std=c99 -Werror -Wall
LINK_FLAGS :=
LIB_OUT := $(OUT)/lib
LINK_DIRS := -L$(LIB_OUT)
LINK_LIBS := -lLiteFS
INCLUDE_DIR := -I./osw -I./src
SRC:= ./src/litefs.c
LIB_SRCS := $(filter-out $(SRC), $(wildcard ./src/*.c))
POSIX_SRCS := $(wildcard ./osw/posix/*.c)
PLATFORM ?= POSIX

export CC OUT

.PHONY: clean lib config

all: $(TARGET) lib config

$(TARGET): $(LIB_OUT)/$(LIB_TARGET)
	$(CC) $(CFLAGS) $(INCLUDE_DIR) -fPIC -o $(OUT)/$@ $(SRC) $(LINK_FLAGS) $(LINK_DIRS) $(LINK_LIBS)

lib: $(LIB_OUT)/$(LIB_TARGET)

$(LIB_OUT)/$(LIB_TARGET): $(LIB_OUT)
	if [ "$(PLATFORM)" = "POSIX" ]; then \
	$(CC) -shared $(CFLAGS) $(INCLUDE_DIR) -fPIC -o $@ $(LIB_SRCS) $(POSIX_SRCS); \
	fi

$(LIB_OUT): $(OUT)
	if ! [ -d $(LIB_OUT) ]; then \
		mkdir $(LIB_OUT); \
	fi

config: $(OUT)/config.o

$(OUT)/config.o: $(OUT)
	./scripts/gen_config.py $(OUT)

$(OUT):
	if ! [ -d $(OUT) ]; then \
		mkdir $(OUT); \
	fi
	

clean:
	if [ -d $(OUT) ]; then \
		rm -rf $(OUT); \
	fi


