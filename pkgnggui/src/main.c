#include <unistd.h>
#include <gtk/gtk.h>

void on_window_destroy (AtkObject *object, gpointer user_data){
        gtk_main_quit();
}

int main (int argc, char *argv[]){
        GtkBuilder 	*builder;
        GtkWidget 	*window;
        
        gtk_init (&argc, &argv);

	execl("/usr/local/bin/pkg info -ag", "pkg", 0);

	// Use pkgnggui.glade for UI creation        
        builder = gtk_builder_new ();
        gtk_builder_add_from_file (builder, "pkgnggui.glade", NULL);

        window = GTK_WIDGET (gtk_builder_get_object (builder, "mainWindow"));
        gtk_builder_connect_signals (builder, NULL);
        g_object_unref (G_OBJECT (builder));
        
        gtk_widget_show (window);      
        gtk_main ();
        
        return 0;
}

