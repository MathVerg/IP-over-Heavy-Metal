
LINK_TARGETS = mainSender mainReceiver main

PACK_DEST = LemoineVergnolleHeavyMetal.zip

OBJS = \
	mainReceiver.o \
	mainSender.o \
	main.o \
	soundCode.o \
	soundDecode.o \
	utils.o \
	tun.o \
	sniffer.o


REBUILDABLES = $(OBJS) $(LINK_TARGET) $(PACK_DEST)


all : mainSender mainReceiver main


clean:
	rm -f $(REBUILDABLES) *.gch


mainSender : mainSender.o soundCode.o
	gcc -g -o $@ $^

mainReceiver : mainReceiver.o soundDecode.o utils.o
	gcc -g -o $@ $^

main: main.o tun.o sniffer.o utils.o
	gcc -g -o $@ $^

%.o : %.c
	gcc -g  -Wall -o $@ -c $<

%.c : %.h

%.o : %.h

pack: #prepare the zip file to be uploaded on Moodle
	zip $(PACK_DEST) *.md *.c *.h Makefile
