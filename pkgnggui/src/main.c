#include <gtk/gtk.h>
#include <unistd.h>

// When exit, quit
void on_window_destroy (AtkObject *object, gpointer user_data){
        gtk_main_quit();
}

// MAIN
int main (int argc, char *argv[]){
        GtkBuilder *builder;
        GtkWidget  *window;

        gtk_init(&argc, &argv);

        // Use pkgnggui.glade for UI creation        
        builder = gtk_builder_new();
        gtk_builder_add_from_file(builder, "pkgnggui.glade", NULL);

        window = GTK_WIDGET(gtk_builder_get_object (builder, "mainWindow"));
        gtk_builder_connect_signals(builder, NULL);
        g_object_unref(G_OBJECT (builder));

	// Run pkg info (works!)
	// TODO: Format output of 'pkg info' so that each newline
	// designates a new entry in the packageList treeview.
	g_spawn_command_line_async("pkg info", NULL);

        gtk_widget_show(window);      
        gtk_main();
        
        return 0;
}

