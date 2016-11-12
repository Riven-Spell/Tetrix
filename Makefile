# build environment
CC=g++

# directories where source and header files are found
DIRS = src $(filter %/,$(wildcard src/*/))

# source files
SOURCES = $(foreach dir,$(DIRS),$(wildcard $(dir)/*.cpp))

# include directories
INCLUDES := $(foreach dir,$(wildcard $(DIRS)),-I$(dir))

all:
	-mkdir builds
	$(CC) $(SOURCES) -o builds/Tetrix $(INCLUDES) -Wall

cleanup:
	-rm -rf builds
