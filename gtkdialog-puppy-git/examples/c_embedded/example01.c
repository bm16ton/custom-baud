#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
//#include <asm/termios.h>
#include <unistd.h> // for close
#include <sys/ioctl.h>
#include "termios.h"
#include <sys/types.h>
//#include <stropts.h>
//#include <sys/stream.h>
#include <getopt.h>
#include <stdarg.h>
#include <assert.h>
/*
Set gtkdialog-window over 'vbox' and 'hbox':
OK-button 			Cancel-button
Help-button 		Label-MyLabel
Entry-single-string
Edit-multiline-edit-box
Static-text(label) 	Refresh-button
File-chooser-dialog

Contributed by sklimkin:
	http://www.murga-linux.com/puppy/viewtopic.php?p=639831#639831
*/
void test2(int argc, char* argv[]);
	char line[10];
char TTY[12];
const char *TEST;
char BAUD[10];

int main(int argc, char* argv[]) {
	FILE *stream;
    FILE *fptr;
    int num;
    argv[1] = "/dev/ttyUSB0 ";
    printf("argc %d\n", argc);
	/* Create window MAIN_DIALOG */
	putenv(
	"MAIN_DIALOG=<vbox>"
	/*  static text (label) as window-header */
	"<text><label>UART tty set and test</label></text>"
	/* frame 1 - default buttons & static text (label) */
	"<hbox>"
				"<text>"
				"<label>Select tty:</label>"
			"</text>"
			"<tree>"
			    "<label>tty's available</label>"
			    "<height>150</height>"
			    "<width>300</width>"
				"<variable>TTY</variable>"
				"<input>bash -c 'ls /dev/tty*'</input>"
			"</tree>"
	"</hbox>"
	"<tree file-monitor=\"true\" visible=\"false\">"
	"<<input file>test4.txt</input>"
	"<action signal=\"file-changed\">exit:'MAIN_DIALOG'</action>"
	"<action signal=\"file-changed\">close:'MAIN_DIALOG'</action>"
	"<action signal=\"changed\">close:'MAIN_DIALOG'</action>"
	"<action function=\"exit\">CLOSE</action>"
	"<action function=\"exit\">OK</action>"
	"</tree>"
	"<hbox>"
			"<text xalign=\"0\" space-expand=\"true\" space-fill=\"true\">"
				"<label>Enter custom baud</label>"
			"</text>"
	"</hbox>"
	"<hbox>"
			"<entry>"
			"<input>echo \"new baud\"</input>"
			"<variable>BAUD</variable>"
			"</entry>"
	"</hbox>"
			"<hbox>"
					"<button>"
				"<label>show_vars</label>"
				"<action>whoami</action>"
				"<action>echo $TTY</action>"
				"<action>echo $TTY</action>"
			"</button>"
			"</hbox>"
		"<frame>"
		"<hbox>"
			"<button ok>"
				"<action>echo $BAUD</action>"
				"<action>echo $TTY</action>"
				"<action>echo $BAUD</action>"
			"</button>"
			"<button cancel></button>"
		"</hbox>"
	"</frame>"
	"</vbox>");
	/* end of put environment - MAIN_DIALOG */
char * endptr;
	/* open gtkdialog as stream */
	stream = popen("gtkdialog --program=MAIN_DIALOG", "r");
	fgets(line, 255, stream);
	fgets(TTY, 13, stream);
	fgets(BAUD, 10, stream);
	printf("Line is: %s\n", line);
	printf("1st tty is: %s\n", TTY);
	printf("1st baud is is: %s\n", BAUD);
	test2(3, (char **)TTY);
//    pclose(stream);
    fptr = fopen("test4.txt","a");
    num = 16;
    fprintf(fptr,"%d",num);
    fclose(fptr);
	return 0;
}

void test2(int argc, char* argv[]) {
 unsigned long speed =  atoi (line);
 	printf("2nd tty is: %s\n", TTY);
	printf("speed is: %ld\n", speed);
	printf("line is: %s\n", line);
	 int fd = open(TTY, O_RDONLY);
    struct termios2 tio;
    ioctl(fd, TCGETS2, &tio);
    tio.c_cflag &= ~CBAUD;
    tio.c_cflag |= BOTHER;
    tio.c_ispeed = speed;
    tio.c_ospeed = speed;
    int r = ioctl(fd, TCSETS2, &tio);
    close(fd);

    if (r == 0) {
        printf("Changed successfully.\n");
    } else {
        perror("ioctl");
    }
    return;
}
/* end of main, end of program */
