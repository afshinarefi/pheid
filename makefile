PROJECT_NAME=pheid
CC=g++
SRCEXT=.cpp
HDREXT=.hpp
OBJEXT=.obj
BINEXT=
FLAGS=-Wall -g -std=c++11
DEPS=$(OBJDIR)$(PROJECT_NAME)$(OBJEXT) $(HDRDIR)types$(HDREXT)
DEPS+= $(OBJDIR)random_generator$(OBJEXT)
DEPS+= $(OBJDIR)data$(OBJEXT)
DEPS+= $(OBJDIR)chromosome$(OBJEXT)
BINDIR=bin/
SRCDIR=src/
OBJDIR=obj/
HDRDIR=hdr/

$(BINDIR)$(PROJECT_NAME)$(BINEXT): $(DEPS)
	mkdir -p $(BINDIR)
	$(CC) $(FLAGS) $^ -o $@

$(OBJDIR)%$(OBJEXT): $(SRCDIR)%$(SRCEXT) $(HDRDIR)%$(HDREXT) \
                     $(HDRDIR)types$(HDREXT)
	mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) -I$(HDRDIR) -c $< -o $@

run:
	$(BINDIR)$(PROJECT_NAME)$(BINEXT)

clean:
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)
