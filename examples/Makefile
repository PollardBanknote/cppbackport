# Sources are located relative to Makefile
MAKEFILE_DIR := $(shell readlink -f $(dir $(word $(words $(MAKEFILE_LIST)), $(MAKEFILE_LIST))))

# The path of the invoking module
vpath %.cpp $(MAKEFILE_DIR)

CXX = g++
LD = g++

STANDARD = -ansi -pedantic
DEBUGGING = -g
OPTIMIZATION = -O2
WARNINGS = -Wall -Wsign-compare -Wconversion -Wpointer-arith -Winit-self -Wcast-qual -Wredundant-decls -Wcast-align -Wwrite-strings -Wno-long-long -Woverloaded-virtual -Wformat -Wno-unknown-pragmas -Wnon-virtual-dtor -Wno-c++0x-compat 
OPTIONS = -fuse-cxa-atexit -ffor-scope -fdiagnostics-color
TARGET_ARCH =
CXXFLAGS = $(STANDARD) $(DEBUGGING) $(OPTIMIZATION) $(WARNINGS) $(OPTIONS) $(TARGET_ARCH) -pthread
INCLUDE = -iquote$(MAKEFILE_DIR)/../lib
DEFINES = -D_FORTIFY_SOURCE=1
CPPFLAGS = $(INCLUDE) $(DEFINES)
LDFLAGS = -pthread

LIBNAME = cppbackport
EXAMPLES = gibberish lshere

.PHONY: default lib examples

default: examples

lib:
	$(MAKE) -f $(MAKEFILE_DIR)/../lib/Makefile

$(EXAMPLES): lib

examples: $(EXAMPLES)

gibberish: gibberish.o
lshere: lshere.o

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

$(EXAMPLES):
	$(LD) $(LDFLAGS) $(@).o -L. -l$(LIBNAME) -o $@

clean:
	$(MAKE) -f $(MAKEFILE_DIR)/../lib/Makefile clean
	@$(RM) $(EXAMPLES) $(EXAMPLES:%=%.o)
