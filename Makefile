TARGET   = emerg_reboot
CC       = gcc
CFLAGS   = -std=c99 -Wall -I.
LINKER   = gcc
LFLAGS   = -Wall -I. -lm

SRCDIR   = src
OBJDIR   = build
BINDIR   = bin

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

EMERG_REBOOT_OBJECTS	:= $(OBJDIR)/emerg_reboot.o $(OBJDIR)/sysrq.o $(OBJDIR)/textfile.o
GETSYSRQ_OBJECTS	:= $(OBJDIR)/getsysrq.o $(OBJDIR)/sysrq.o $(OBJDIR)/textfile.o

linuxtools: emerg_reboot sysrq

emerg_reboot: $(BINDIR)/emerg_reboot
sysrq: $(BINDIR)/getsysrq

$(BINDIR)/emerg_reboot: $(EMERG_REBOOT_OBJECTS)
	@mkdir -p $(@D)
	$(LINKER) $(EMERG_REBOOT_OBJECTS) $(LFLAGS) -o $@

$(BINDIR)/getsysrq: $(GETSYSRQ_OBJECTS)
	@mkdir -p $(@D)
	$(LINKER) $(GETSYSRQ_OBJECTS) $(LFLAGS) -o $@

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJECTS)

.PHONY: remove
remove: clean
	rm -f $(BINDIR)/*
