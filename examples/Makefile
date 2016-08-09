# Sources are located relative to Makefile
MAKEFILE_DIR := $(shell readlink -f $(dir $(word $(words $(MAKEFILE_LIST)), $(MAKEFILE_LIST))))
LIB_DIR := $(MAKEFILE_DIR)/../lib

# The path of the invoking module
vpath %.cpp $(MAKEFILE_DIR)

default: examples

include $(MAKEFILE_DIR)/../make.inc

CXXFLAGS += -pthread
INCLUDE += -iquote$(LIB_DIR)
LDFLAGS += -pthread

LIBNAME = cppbackport
EXAMPLES = gibberish lshere multithreading now singlell

.PHONY: default lib examples

lib:
	$(MAKE) -f $(LIB_DIR)/Makefile

$(EXAMPLES): lib

examples: $(EXAMPLES)

gibberish: gibberish.o
lshere: lshere.o
multithreading: multithreading.o
now: now.o
singlell: singlell.o

$(EXAMPLES):
	$(LD) $(LDFLAGS) $(@).o -L. -l$(LIBNAME) -o $@

clean:
	$(MAKE) -f $(LIB_DIR)/Makefile clean
	@$(RM) $(EXAMPLES) $(EXAMPLES:%=%.o)
