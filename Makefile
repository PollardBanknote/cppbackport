# Sources are located relative to Makefile
MAKEFILE_DIR := $(shell readlink -f $(dir $(word $(words $(MAKEFILE_LIST)), $(MAKEFILE_LIST))))

# The path of the invoking module
vpath %.cpp $(MAKEFILE_DIR)

default: examples

include $(MAKEFILE_DIR)/make.inc

CXXFLAGS += -pthread
LDFLAGS += -pthread
INCLUDE += -iquote$(MAKEFILE_DIR)/lib

LIBNAME = cppbackport
LIBFILE = lib$(LIBNAME).a
SRCDIRS = lib lib/fs
LIBSRC = $(wildcard $(SRCDIRS:%=$(MAKEFILE_DIR)/%/*.cpp))
LIBOBJS = $(LIBSRC:$(MAKEFILE_DIR)/%.cpp=%.o)
EXAMPLES = gibberish lshere

.PHONY: lib clean

$(LIBFILE): $(LIBOBJS)

lib: $(LIBFILE)

gibberish: examples/gibberish.o $(LIBFILE)
lshere: examples/lshere.o $(LIBFILE)

$(EXAMPLES):
	$(LD) $(LDFLAGS) $^ -o $@

examples: lib $(EXAMPLES)

clean: clean_objects
	@$(RM) $(LIBFILE)
