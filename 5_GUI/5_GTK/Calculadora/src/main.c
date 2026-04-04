#include <gtk-4.0/gtk/gtk.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    GtkLabel *display;
    char display_text[256];
    double result;
    double operand;
    char operator;
    gboolean new_number;
} CalculatorData;

static void on_number_clicked(GtkButton *button, gpointer user_data)
{
    CalculatorData *calc = (CalculatorData *)user_data;
    const char *label = gtk_button_get_label(button);

    if (calc->new_number)
    {
        strcpy(calc->display_text, label);
        calc->new_number = FALSE;
    }
    else
    {
        strcat(calc->display_text, label);
    }

    gtk_label_set_text(calc->display, calc->display_text);
}

static void on_operator_clicked(GtkButton *button, gpointer user_data)
{
    CalculatorData *calc = (CalculatorData *)user_data;
    const char *label = gtk_button_get_label(button);

    calc->operand = g_ascii_strtod(calc->display_text, NULL);
    calc->operator = label[0];
    calc->new_number = TRUE;
}

static void on_equals_clicked(GtkButton *button, gpointer user_data)
{
    CalculatorData *calc = (CalculatorData *)user_data;
    double current = g_ascii_strtod(calc->display_text, NULL);
    double result = 0;

    switch (calc->operator)
    {
    case '+':
        result = calc->operand + current;
        break;
    case '-':
        result = calc->operand - current;
        break;
    case '*':
        result = calc->operand * current;
        break;
    case '/':
        result = (current != 0) ? calc->operand / current : 0;
        break;
    default:
        result = current;
    }

    g_snprintf(calc->display_text, sizeof(calc->display_text), "%.6g", result);
    gtk_label_set_text(calc->display, calc->display_text);
    calc->new_number = TRUE;
}

static void on_clear_clicked(GtkButton *button, gpointer user_data)
{
    CalculatorData *calc = (CalculatorData *)user_data;
    strcpy(calc->display_text, "0");
    gtk_label_set_text(calc->display, calc->display_text);
    calc->result = 0;
    calc->operand = 0;
    calc->operator = '\0';
    calc->new_number = TRUE;
}

static void on_activate(GtkApplication *app, gpointer user_data)
{
    CalculatorData *calc = g_new0(CalculatorData, 1);
    strcpy(calc->display_text, "0");
    calc->new_number = TRUE;

    // Create main window
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Calculadora GTK4");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 400);

    // Main container
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_margin_top(box, 10);
    gtk_widget_set_margin_bottom(box, 10);
    gtk_widget_set_margin_start(box, 10);
    gtk_widget_set_margin_end(box, 10);
    gtk_window_set_child(GTK_WINDOW(window), box);

    // Display
    calc->display = GTK_LABEL(gtk_label_new("0"));
    gtk_widget_set_halign(GTK_WIDGET(calc->display), GTK_ALIGN_END);
    gtk_label_set_xalign(calc->display, 1.0);
    gtk_box_append(GTK_BOX(box), GTK_WIDGET(calc->display));

    // Button grid
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_box_append(GTK_BOX(box), grid);

    // Clear button
    GtkWidget *btn_clear = gtk_button_new_with_label("C");
    g_signal_connect(btn_clear, "clicked", G_CALLBACK(on_clear_clicked), calc);
    gtk_grid_attach(GTK_GRID(grid), btn_clear, 0, 0, 4, 1);

    // Number buttons
    const char *numbers[10] = {"7", "8", "9", "4", "5", "6", "1", "2", "3"};
    int pos = 0;
    for (int row = 1; row < 4; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            GtkWidget *btn = gtk_button_new_with_label(numbers[pos]);
            g_signal_connect(btn, "clicked", G_CALLBACK(on_number_clicked), calc);
            gtk_grid_attach(GTK_GRID(grid), btn, col, row, 1, 1);
            pos++;
        }
    }

    // Zero button (spans 2 columns)
    GtkWidget *btn_zero = gtk_button_new_with_label("0");
    g_signal_connect(btn_zero, "clicked", G_CALLBACK(on_number_clicked), calc);
    gtk_grid_attach(GTK_GRID(grid), btn_zero, 0, 4, 2, 1);

    // Decimal button
    GtkWidget *btn_decimal = gtk_button_new_with_label(".");
    g_signal_connect(btn_decimal, "clicked", G_CALLBACK(on_number_clicked), calc);
    gtk_grid_attach(GTK_GRID(grid), btn_decimal, 2, 4, 1, 1);

    // Operator buttons
    const char *operators[4] = {"+", "-", "*", "/"};
    for (int i = 0; i < 4; i++)
    {
        GtkWidget *btn = gtk_button_new_with_label(operators[i]);
        g_signal_connect(btn, "clicked", G_CALLBACK(on_operator_clicked), calc);
        gtk_grid_attach(GTK_GRID(grid), btn, 3, i + 1, 1, 1);
    }

    // Equals button
    GtkWidget *btn_equals = gtk_button_new_with_label("=");
    g_signal_connect(btn_equals, "clicked", G_CALLBACK(on_equals_clicked), calc);
    gtk_grid_attach(GTK_GRID(grid), btn_equals, 3, 4, 1, 1);

    gtk_widget_set_visible(window, TRUE);
}

int main(int argc, char *argv[])
{
    GtkApplication *app = gtk_application_new("com.example.calculator",
                                              G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
