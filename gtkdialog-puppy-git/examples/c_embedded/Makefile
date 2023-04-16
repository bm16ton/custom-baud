TARGET = example01
CC = gcc
LDLIBS=`pkg-config --libs gtk+-2.0 gmodule-2.0`
CFLAGS=-Wall -g `pkg-config --cflags gtk+-2.0 gmodule-2.0`

all:
	$(CC) -o $(TARGET) $(TARGET).c $(LDLIBS) $(CFLAGS)

clean:
	rm $(TARGET)
	rm inputfile
