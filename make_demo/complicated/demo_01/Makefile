.PHONY : all clean

MKDIR = mkdir
RM = rm
RMFLAGS = -rf

CC = gcc

DIR_OBJS = objs
DIR_EXES = exes
DIR_DEPS = deps
DIRS = $(DIR_OBJS) $(DIR_EXES) $(DIR_DEPS)
EXE = complicated
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix $(DIR_OBJS)/, $(OBJS))
DEPS = $(SRCS:.c=.dep)
DEPS := $(addprefix $(DIR_DEPS)/, $(DEPS))

ifeq ("$(wildcard $(DIR_OBJS))", "")
DEP_DIR_OBJS := $(DIR_OBJS)
endif
ifeq ("$(wildcard $(DIR_EXES))", "")
DEP_DIR_EXES := $(DIR_EXES)
endif
ifeq ("$(wildcard $(DIR_DEPS))", "")
DEP_DIR_DEPS := $(DIR_DEPS)
endif

all: $(EXE)

include $(DEPS)
$(DIRS):
	$(MKDIR) $@
$(EXE): $(DEP_DIR_EXES) $(OBJS)
	$(CC) -o $@ $(filter %.o, $^)
$(DIR_OBJS)/%.o: $(DEP_DIR_OBJS) %.c
	$(CC) -o $@ -c $ $(filter %.c, $^)
$(DIR_DEPS)/%.dep: $(DEP_DIR_DEPS) %.c
	@echo "Creating $@ ..."
	@set -e; \
	$(RM) $(RMFLAGS) $@.tmp; \
	$(CC) -E -MM $(filter %.c, $^) > $@.tmp; \
	sed 's,\(.*\)\.o[ :]*, objs/\1.o: ,g' < $@.tmp > $@ ;\
	$(RM) $(RMFLAGS) $@.tmp

clean:
	$(RM) $(RMFLAGS) $(DIRS) $(EXE)
