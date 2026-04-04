#ifndef INPUT_BUTTONS_H
#define INPUT_BUTTONS_H

#include <gtk-4.0/gtk/gtk.h>

typedef struct input_buttons
{
    GtkButton **buttons;
    int button_count;
} BUTTONS;

#endif // INPUT_BUTTONS_H
