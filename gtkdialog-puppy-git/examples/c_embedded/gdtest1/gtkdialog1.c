#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Set gtkdialog-window over 'vbox' and 'hbox':
OK-button 			Cancel-button
Help-button 		Label-MyLabel
Entry-single-string
Edit-multyline-edit-box
Static-text(label) 	Refresh-button
File-chooser-dialog
*/
/*
int commandexec (char exec) {
char *cmd = "echo";
        char buf[BUFSIZ];
        FILE *ptr;

        if ((ptr = popen(cmd, "r")) != NULL)
                while (fgets(buf, BUFSIZ, ptr) != NULL)
                        (void) printf("%s", buf);
                (void) pclose(ptr);
        return 0;
}
*/
void main(){
	FILE *stream;
	char line[256];

	/* Create window MAIN_DIALOG */
	putenv(
"MAIN_DIALOG=<vbox>"
	/*  static text (label) as window-header */
	"<text><label>G T K D I A L O G    C - L A N G   E X A M P L E</label></text>"
	/* frame 1 - default buttons & static text (label) */
	"<frame Command buttons (defaults)>"
		"<hbox>"
			"<button ok></button>"
			"<button cancel></button>"
		"</hbox>"
		"<hbox>"
			"<text><label>this is a Label - static text in one string (nothing more)</label></text>"
			"<button help></button>"
		"</hbox>"
	"</frame>"
	/* frame 2 */
	/* set 'entry' - single-line text, set 'edit' - multy-line text */
	"<frame Single-line & Multy-line string boxes>"
		"<entry>"
			"<default>Entry for single string input</default>"
			"<input>date</input>"
			"<variable>ENTRY</variable>"
		"</entry>"
		"<edit>"
			"<input file>tmp.txt</input>"
			"<variable>EDITOR</variable>"
		"</edit>"
	"</frame>"
	/* frame 3 */
	"<frame Label from command & system commands>"
		"<hbox>"
			"<text>"
				"<label>Static text (label) for Date</label>"
				"<input>date</input>"
				"<variable>DATE</variable>"
			"</text>"
			/* This button refresh current date-time in Entry edit-box */
			"<button>"
				"<label>Refresh Date-Time in Entry</label>"
				"<action>refresh:ENTRY</action>"
				"<label>date</label>"
			"</button>"
		"</hbox>"

		"<hbox>"
			/* add window (system call) View kernel messages */
			"<button>"
				"<label>View kernel</label>"
				"<action>dmesg | zenity --text-info  --width=600 --height=500 --title View_kernel_messages</action>"
			"</button>"
			/* add window (system call) Ethernet */
			"<button>"
				"<label>Ethernet</label>"
				"<action>ifconfig | zenity --text-info  --width=480 --height=400 --title Ethernet</action>"
			"</button>"
			/* add window (system call) PCI devices */
			"<button>"
				"<label>PCI devices</label>"
				"<action>lspci | zenity --text-info  --width=720 --height=400 --title PCI_devices</action>"
			"</button>"
			/* add window (system call) Loaded modules */
			"<button>"
				"<label>Loaded modules</label>"
				"<action>lsmod | zenity --text-info  --width=600 --height=400 --title Loaded_modules</action>"
			"</button>"
			/* add window (system call) $PATH */
			"<button>"
				"<label>$PATH</label>"
				"<action>echo $PATH | zenity --text-info  --width=600 --height=25 --title user_PATH</action>"
			"</button>"
		"</hbox>"
	"</frame>"
	/* now without frame - add file-dialog at bottom window */
	"<chooser>"
		"<height>250</height><width>450</width>"
		"<variable>FILE</variable>"
		"<default>/home/</default>"
		"<action>cat [ echo $FILE ] | zenity --text-info  --width=720 --height=400 --title $FILE</action>"
	"</chooser>"

	"</vbox>");
	/* end of put environment - MAIN_DIALOG */

	/* open gtkdialog as stream */
	stream = popen("gtkdialog --program=MAIN_DIALOG", "r");
	fgets(line, 255, stream);
printf("Last window-widget is: %s\n", line);
}
/* end of main, end of program */

/*
//"<title> Example_GTKdialog</title>"

//ENTRY=gtk_entry_get_text(entry);
//const gchar* gtk_entry_get_text(GtkEntry *entry);
//void gtk_entry_set_text(GtkEntry *entry, const gchar *text);
//MAIN_DIALOG.EDITOR=gtk_text_view_get_buffer(entry);
//GtkTextBuffer * gtk_text_view_get_buffer(GtkTextView *text_view);
//void gtk_text_view_set_buffer(GtkTextView *text_view, GtkTextBuffer *buffer);
//(zenity:5046): Gtk-CRITICAL **: gtk_text_buffer_emit_insert: assertion `g_utf8_validate (text, len, NULL)' failed
*/

/*
	if (strstr(line, ENTRY))
		printf("You entered: %s\n", ENTRY);

	if (strstr(line, "Help"))
		printf("You pressed the Help button named %s\n", line);

	if (strstr(line, "OK"))
		printf("You pressed the OK button named %s\n", line);
	else {
		printf("This is not the OK button, button label is %s\n", line);
	pclose(stream);
	}
*/

