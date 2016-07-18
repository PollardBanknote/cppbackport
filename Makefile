# Sources are located relative to Makefile
MAKEFILE_DIR := $(dir $(word $(words $(MAKEFILE_LIST)), $(MAKEFILE_LIST)))

# The path of the invoking module
MODULE_PATH := $(shell readlink -f $(MAKEFILE_DIR))

vpath %.cpp $(MODULE_PATH)

default: lib

include $(MAKEFILE_DIR)/make.inc

LIBNAME = cppbackport
LIBFILE = lib$(LIBNAME).a
LIBOBJS += $(patsubst %.cpp,%.o,$(notdir $(wildcard $(MODULE_PATH)/*.cpp)))

.PHONY: lib clean

$(LIBFILE): $(LIBOBJS)

# Lib --------------------------------------------------------------------------
lib: $(LIBFILE)

# Clean ------------------------------------------------------------------------
clean: clean_objects
	@$(RM) $(LIBFILE)

# ------------------------------------------------------------------------------
INCLUDE += -iquote$(MAKEFILE_DIR)/..
CXXFLAGS += -pthread
LDFLAGS += -pthread
