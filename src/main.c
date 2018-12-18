#include <gtk/gtk.h>
#include <main_window.h>

int main(int argc, char *argv[])
{
	GtkWidget		*window;

	gtk_init(&argc, &argv);
	window = create_main_window();
	g_signal_connect(G_OBJECT(window), "destroy",
		G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all(window);
	gtk_main();
}
