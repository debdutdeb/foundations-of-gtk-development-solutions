#include <gtk/gtk.h>
#include <string.h>
#include <malloc.h>

static void destroy(GtkWidget*, gpointer);
static gboolean key_pressed (GtkWidget*, GdkEvent*, gpointer);

int main (int argc, char *argv[])
{
	gtk_init(&argc, &argv);

	GtkWidget *window, *label;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL); // GtkWindowType

	GtkWindow *_window = GTK_WINDOW(window);

	gtk_window_set_title (_window, "Debdut");
	gtk_window_set_resizable (_window, FALSE);
	gtk_window_set_default_size(_window, 300, 100);

	gtk_widget_set_events(window, GDK_KEY_PRESS_MASK);

	label = gtk_label_new ("Chakraborty");
	gtk_label_set_selectable(GTK_LABEL(label), TRUE);

	gtk_container_add(GTK_CONTAINER(window), label);


	g_signal_connect (
			G_OBJECT(window), "destroy",
			G_CALLBACK(destroy), NULL);

	g_signal_connect (
			G_OBJECT(window), "key-press-event",
			G_CALLBACK(key_pressed), (gpointer)label);

	gtk_widget_show_all(window);


	gtk_main();
	return 0;
}


static void destroy

(GtkWidget *widget, gpointer x)
{
	gtk_main_quit();
}

static gboolean key_pressed
(GtkWidget *widget, GdkEvent *event, gpointer x)
{



	const gchar* str0 = gtk_window_get_title (
			GTK_WINDOW(widget));
	const gchar* str1 = gtk_label_get_text(
			GTK_LABEL(x));

	char* save = malloc(sizeof (gchar) * strlen((char*)str0));
	strcpy(save, str0);
	
	if (g_ascii_strcasecmp(str0, str1) > 0)
	{
		gtk_window_set_title(GTK_WINDOW(widget), str1);
		gtk_label_set_label(GTK_LABEL(x), save);
	}

	free(save);

	return TRUE;
}
