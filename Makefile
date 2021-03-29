
LINK_TARGETS = mainSender mainReceiver

PACK_DEST = LemoineVergnolleHeavyMetal.zip

OBJS = \
	mainReceiver.o \
	mainSender.o \
	soundCode.o \
	soundDecode.o \
	utils.o \
	tun.o \
	sniffer.o \
	feeder.o \
	parse.o


REBUILDABLES = $(OBJS) $(LINK_TARGET) $(PACK_DEST)


all : mainSender mainReceiver


clean:
	rm -f $(REBUILDABLES) $(LINK_TARGETS) *.gch


mainSender : mainSender.o soundCode.o utils.o sniffer.o parse.o tun.o
	gcc -g -o $@ $^ -lm #lm allows to compile with the math library

mainReceiver : mainReceiver.o soundDecode.o utils.o parse.o tun.o feeder.o
	gcc -g -o $@ $^

%.o : %.c
	gcc -g  -Wall -o $@ -c $<

%.c : %.h

%.o : %.h

pack: #prepare the zip file to be uploaded on Moodle
	zip $(PACK_DEST) *.md *.c *.h *.sh Makefile growl.wav
