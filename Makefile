
LINK_TARGET = main

PACK_DEST = LemoineVergnolleHeavyMetal.zip

OBJS = \
	main.o \
	soundCode.o \
	soundDecode.o \
	utils.o


REBUILDABLES = $(OBJS) $(LINK_TARGET) $(PACK_DEST)


all : $(LINK_TARGET)


clean:
	rm -f $(REBUILDABLES) *.gch


$(LINK_TARGET) : $(OBJS)
	gcc -g -o $@ $^


%.o : %.c
	gcc -g  -Wall -o $@ -c $<

%.c : %.h

pack: #prepare the zip file to be uploaded on Moodle
	zip $(PACK_DEST) *.md *.c *.h Makefile
