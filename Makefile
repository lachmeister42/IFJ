PROGS=ifj2018
CC=@gcc
CFLAGS=-Wall -std=c99 -pedantic -lm

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

$(BINDIR)/$(PROGS): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c dirs
	$(CC) $(CFLAGS) -c $< -o $@
dirs:
	@mkdir -p $(SRCDIR)
	@mkdir -p $(OBJDIR)
	@mkdir -p $(BINDIR)
clean:
	rm -f -r $(OBJDIR)
	rm -f -r $(BINDIR)


