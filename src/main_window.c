#include <limits.h>
#include <gtk/gtk.h>
#include <main_window.h>

#define				WINDOW_TITLE	"Игральные кубики"
#define				BUTTON_LABEL	"Бросить кубики"
#define				SPACING			10

static void on_button_go_clicked(GtkWidget *button, gpointer data);
static void	show_on_entry_dice(int a, int b);
static void	show_on_label_sum(int a, int b);
static void	show_on_images(int a, int b);
static const char *image_path(int a);

static GtkWidget		*entry_dice;
static GtkWidget		*label_sum;
static GtkWidget		*image_left;
static GtkWidget		*image_right;

GtkWidget		*create_main_window(void)
{
	GtkWidget		*window;
	GtkWidget		*vbox;
	GtkWidget		*hbox;
	GtkWidget		*frame_label;
	GtkWidget		*button_go;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), WINDOW_TITLE);
	entry_dice = gtk_entry_new();
	frame_label = gtk_frame_new(NULL);
	label_sum = gtk_label_new(NULL);
	image_left = gtk_image_new();
	image_right = gtk_image_new();
	button_go = gtk_button_new_with_label(BUTTON_LABEL);

	gtk_widget_set_sensitive(entry_dice, FALSE);
	gtk_entry_set_alignment(GTK_ENTRY(entry_dice), 0.5);
	gtk_container_set_border_width(GTK_CONTAINER(window), SPACING);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, SPACING);
	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, SPACING);
	gtk_container_add(GTK_CONTAINER(frame_label), label_sum);
	gtk_box_pack_start(GTK_BOX(hbox), image_left, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox), image_right, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), entry_dice, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), frame_label, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), button_go, FALSE, FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);
	
	g_signal_connect(G_OBJECT(button_go), "clicked",
		G_CALLBACK(on_button_go_clicked), NULL);

	return window;
}

static void		on_button_go_clicked(GtkWidget *button, gpointer data)
{
}

static void		show_on_entry_dice(int a, int b)
{
	enum {int_bit_count = sizeof(int) * CHAR_BIT};
	char	buffer[2 * int_bit_count + 4];

	g_snprintf(buffer, sizeof buffer, "%d : %d", a, b);
	gtk_entry_set_text(GTK_ENTRY(entry_dice), buffer);
}

static void		show_on_label_sum(int a, int b)
{
	enum {int_bit_count = sizeof(int) * CHAR_BIT};
	char	buffer[int_bit_count + 1];

	g_snprintf(buffer, sizeof buffer, "%d", a + b);
	gtk_label_set_text(GTK_LABEL(label_sum), buffer);
}

static void		show_on_images(int a, int b)
{
	gtk_image_set_from_resource(GTK_IMAGE(image_left), image_path(a));
	gtk_image_set_from_resource(GTK_IMAGE(image_right), image_path(b));
}

static const char *image_path(int a)
{
	switch (a)
	{
		case 1:	return "/images/1.png";
		case 2:	return "/images/2.png";
		case 3:	return "/images/3.png";
		case 4:	return "/images/4.png";
		case 5:	return "/images/5.png";
		case 6:	return "/images/6.png";
	}
	return NULL;
}
