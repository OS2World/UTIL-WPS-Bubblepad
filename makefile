# Makefile for BubblePd.dll

CC           = icc
CFLAGS       =  -Ge- /Gm+ -G4 /ss -Gl /O+ -Oc+ -Ol- /Q+ /W3 /C
LDFLAGS =	-Ge- /Gm+ -G4 /ss -Gl /O+ -Oc+ -Ol-  /Q+
#CFLAGS       =  -Ge- /Gm+ /ss  -Ol- /Q+  /C
#LDFLAGS =	-Ge- /Gm+ /ss  -Ol-  /Q+

LIBS		=	somtk.lib
DEFS         = 
IDLDIR		=	./idl
IHDIR		=	./obj
OBJDIR		=	./obj
CDIR		=	./c
HELPDIR		=	./hlp
COMPINC		=	$(IHDIR) -I./include
INC		=	./include
PROGS        = bubblepd.dll
 
OBJECTS		= 	$(OBJDIR)/bubblepd.obj $(OBJDIR)/misc_funcs.obj

all: 	../Deutsch/bubblepd.dll \
	../English/bubblepd.dll \
	../Nederlands/bubblepd.dll \
	../Svenska/bubblepd.dll \
	../Francais/bubblepd.dll \
	../Deutsch/bubblepd.hlp \
	../English/bubblepd.hlp \
	../Nederlands/bubblepd.hlp \
	../Svenska/bubblepd.hlp \
	../Francais/bubblepd.hlp \
	../bin/lpreplace.exe

#######################################
#
# Define *.ih files.
#
#######################################
IHFILES	=	$(OBJDIR)/bubblepd.ih

#######################################
#
# Define SOM compile command
#
#######################################

SCCOMPILEC	=	sc -I $(IDLDIR) -I ../include -p -r -sc -d../c -maddstar -mnoint -S128000 -C128000 
SCCOMPILEIH	=	sc -I $(IDLDIR) -I ../include -p -r -sih";"h -d../obj -maddstar -mnoint -S128000 -C128000 

###################################
#
#  Create all the *.ih files from the IDL files
#
###################################
$(IHDIR)/%.ih:	 $(IDLDIR)/%.idl
	cd $(IDLDIR) && $(SCCOMPILEC) $(notdir $<)
	cd $(IDLDIR) && $(SCCOMPILEIH) $(notdir $<)


###################################
#
#    Rules for compiling
#
###################################
$(OBJDIR)/%.obj:	$(CDIR)/%.c $(IHDIR)/%.ih $(INC)/defines.h
	$(CC) -I $(COMPINC)  $(CFLAGS)  /Fo$@ $<

## Files with additional functions
$(OBJDIR)/%.obj:	$(CDIR)/%.c $(INC)/defines.h
	$(CC) -I $(COMPINC) $(CFLAGS)  /Fo$@ $<


../Deutsch/bubblepd.dll:	 $(OBJDIR)/bubblepd.dll deutsch.rc
	-rm ../Deutsch/bubblepd.dll
	 rc -i .\include deutsch.rc $(OBJDIR)/bubblepd.dll
	-cp $(OBJDIR)/bubblepd.dll ../Deutsch

../English/bubblepd.dll:	 $(OBJDIR)/bubblepd.dll english.rc
	-rm ../English/bubblepd.dll
	 rc -i ./include english.rc $(OBJDIR)/bubblepd.dll
	-cp $(OBJDIR)/bubblepd.dll ../English

../Nederlands/bubblepd.dll:	 $(OBJDIR)/bubblepd.dll nederlands.rc
	-rm ../Nederlands/bubblepd.dll
	 rc -i ./include nederlands.rc $(OBJDIR)/bubblepd.dll
	-cp $(OBJDIR)/bubblepd.dll ../Nederlands

../Svenska/bubblepd.dll:	 $(OBJDIR)/bubblepd.dll SWEDISH.RC
	-rm ../Svenska/bubblepd.dll
	 rc -i ./include SWEDISH.RC $(OBJDIR)/bubblepd.dll
	-cp $(OBJDIR)/bubblepd.dll ../Svenska

../Francais/bubblepd.dll:	 $(OBJDIR)/bubblepd.dll FRENCH.RC
	-rm ../Francais/bubblepd.dll
	 rc -i ./include FRENCH.RC $(OBJDIR)/bubblepd.dll
	-cp $(OBJDIR)/bubblepd.dll ../Francais

$(OBJDIR)/bubblepd.dll: $(IHFILES) $(OBJECTS) $(CDIR)/bubblepd.def $(INC)/bubblepadres.h
	$(CC) $(LDFLAGS) /L /Fm$(basename $@)  /Fe$@ $(OBJECTS) $(LIBS) $(CDIR)/bubblepd.def


###################################
#
#  Help files
#
###################################
../English/bubblepd.hlp:	 $(HELPDIR)/bubblepdenglish.ipf
	ipfc $< ../english/bubblepd.hlp

../Deutsch/bubblepd.hlp:	 $(HELPDIR)/bubblepddeutsch.ipf
	ipfc $< ../deutsch/bubblepd.hlp

../Nederlands/bubblepd.hlp:	 $(HELPDIR)/bubblepdnederlands.ipf
	ipfc $< ../Nederlands/bubblepd.hlp

../Svenska/bubblepd.hlp:	 $(HELPDIR)/bubblepdswedish.ipf
	ipfc $< ../Svenska/bubblepd.hlp

../Francais/bubblepd.hlp:	 $(HELPDIR)/bubblepdfrench.ipf
	ipfc $< ../Francais/bubblepd.hlp

###################################
#
#  lpreplace.exe
#
###################################
../bin/lpreplace.exe: $(CDIR)/lpreplace.cpp
	icc /Fe../bin/lpreplace.exe /Fo$(OBJDIR)/lpreplace $<

clean:
	-rm $(OBJDIR)/*
	-rm $(CDIR)/*.*~
	-rm $(HELPDIR)/*.*~
	-rm $(IDLDIR)/*.*~
	-rm $(INC)/*.*~
	-rm *.res

cleaner:
	-rm ../Deutsch/bubblepd.dll
	-rm ../English/bubblepd.dll
	-rm ../Nederlands/bubblepd.dll
	-rm ../Svenska/bubblepd.dll
	-rm ../Francais/bubblepd.dll
	-rm ../Deutsch/bubblepd.hlp
	-rm ../English/bubblepd.hlp
	-rm ../Nederlands/bubblepd.hlp
	-rm ../Svenska/bubblepd.hlp
	-rm ../Francais/bubblepd.hlp
	-rm ../bin/lpreplace.exe

#Note that this will automatically discard the subversion hidden dirs
distribution:
	cd .. && zip -r bubblepad_v108.zip *


install:
	cd ..
	install.cmd
