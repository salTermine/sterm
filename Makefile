CC := gcc
SRCD := src
BLDD := build
BIND := bin
INCD := include

_SRCF := $(shell find $(SRCD) -type f -name *.c)
_OBJF := $(patsubst $(SRCD)/%,$(BLDD)/%,$(_SRCF:.c=.o))
INC := -I $(INCD)

EXEC := sterm

CFLAGS := -Wall
DFLAGS := -g -DDEBUG
LIBS := readline

.PHONY: clean all

debug: CFLAGS += -g -DDEBUG
debug: all

all: $(EXEC)

$(EXEC): $(_OBJF)
	$(CC) $^ -o $(BIND)/$@ -l $(LIBS)

$(BLDD)/%.o: $(SRCD)/%.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	$(RM) -rf $(BLDD) $(BIND)