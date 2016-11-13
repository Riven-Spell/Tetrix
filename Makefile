# build environment
CC=g++

# directories where source and header files are found for Tetrix and NotSudo
DIRS_TETRIX = src/tetrix $(filter %/,$(wildcard src/tetrix/*/))
DIRS_NOTSUDO = src/notsudo $(filter %/,$(wildcard src/notsudo/*/))

# source files for Tetrix and NotSudo
SRC_TETRIX = $(foreach dir,$(DIRS_TETRIX),$(wildcard $(dir)/*.cpp))
SRC_NOTSUDO = $(foreach dir,$(DIRS_NOTSUDO),$(wildcard $(dir)/*.cpp))

# include directories for Tetrix and NotSudo
INCL_TETRIX := $(foreach dir,$(wildcard $(DIRS_TETRIX)),-I$(dir))
INCL_NOTSUDO := $(foreach dir,$(wildcard $(DIRS_NOTSUDO)),-I$(dir))

all: tetrix notsudo

tetrix:
	-mkdir -p builds
	$(CC) $(SRC_TETRIX) -o builds/Tetrix $(INCL_TETRIX) -Wall -std=c++11
	
notsudo:
	-mkdir -p builds/resources
	$(CC) $(SRC_NOTSUDO) -o builds/resources/NotSudo $(INCL_NOTSUDO) -Wall -std=c++11

clean:
	-rm -rf builds
