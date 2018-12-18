#include <gtk/gtk.h>
#include <main_window.h>

GtkWidget *create_main_window(void)
{
	GtkWidget		*window;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Игральные кубики");
	return window;
}
