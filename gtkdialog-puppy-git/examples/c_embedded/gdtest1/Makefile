TARGET = GTK-dialog1
CC = gcc
LDLIBS=`pkg-config --libs gtk+-2.0 gmodule-2.0`
CFLAGS=-Wall -g `pkg-config --cflags gtk+-2.0 gmodule-2.0`

all:
	$(CC) -o $(TARGET) gtkdialog1.c $(LDLIBS) $(CFLAGS)

clean:
	rm $(TARGET)
