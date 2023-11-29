#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

GtkWidget *entry1;
GtkWidget *entry2;
GtkWidget *resultEntry;
GtkWidget *operationComboBox;

// Функция для преобразования шестнадцатеричной строки в десятичное число
long long hexToDecimal(const char *hex) {
    long long result = 0;
    int i = 0;
    while (hex[i] != '\0') {
        result = result * 16;
        if (hex[i] >= '0' && hex[i] <= '9') {
            result += hex[i] - '0';
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            result += hex[i] - 'a' + 10;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            result += hex[i] - 'A' + 10;
        }
        i++;
    }
    return result;
}

// Функция для преобразования восьмеричной строки в десятичное число
long long octToDecimal(const char *oct) {
    long long result = 0;
    int i = 0;
    while (oct[i] != '\0') {
        result = result * 8 + (oct[i] - '0');
        i++;
    }
    return result;
}

// Функция для преобразования десятичного числа в шестнадцатеричную строку
void decimalToHex(long long decimal, char *resultHex) {
    int i = 0;
    do {
        int digit = decimal % 16;
        resultHex[i++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'A');
        decimal /= 16;
    } while (decimal > 0);

    resultHex[i] = '\0';

    // Обратный порядок символов - переворачиваем строку
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = resultHex[start];
        resultHex[start] = resultHex[end];
        resultHex[end] = temp;
        start++;
        end--;
    }
}

void convertAndCalculate() {
    const gchar *text1 = gtk_entry_get_text(GTK_ENTRY(entry1));
    const gchar *text2 = gtk_entry_get_text(GTK_ENTRY(entry2));
    const gchar *operation = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(operationComboBox));

    if (text1 && text2 && operation) {
        // Конвертация строк в числа в соответствующих системах счисления
        long long num1 = hexToDecimal(text1);
        long long num2 = octToDecimal(text2);

        long long result = 0;
        if (g_strcmp0(operation, "Сложение") == 0) {
            result = num1 + num2;
        } else if (g_strcmp0(operation, "Вычитание") == 0) {
            result = num1 - num2;
        } else if (g_strcmp0(operation, "Умножение") == 0) {
            result = num1 * num2;
        } else if (g_strcmp0(operation, "Деление") == 0 && num2 != 0) {
            result = num1 / num2;
        }

        // Конвертация результата обратно в шестнадцатеричную систему счисления
        gchar resultHex[50];
        decimalToHex(result, resultHex);

        // Установка результата в соответствующее поле
        gtk_entry_set_text(GTK_ENTRY(resultEntry), resultHex);
    }
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calc");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    entry1 = gtk_entry_new();
    entry2 = gtk_entry_new();
    resultEntry = gtk_entry_new();
    gtk_editable_set_editable(GTK_EDITABLE(resultEntry), FALSE);

    operationComboBox = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(operationComboBox), "Сложение");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(operationComboBox), "Вычитание");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(operationComboBox), "Умножение");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(operationComboBox), "Деление");

    GtkWidget *calculateButton = gtk_button_new_with_label("Вычислить");
    g_signal_connect(calculateButton, "clicked", G_CALLBACK(convertAndCalculate), NULL);

    gtk_grid_attach(GTK_GRID(grid), entry1, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), operationComboBox, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry2, 2, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), calculateButton, 0, 1, 3, 1);
    gtk_grid_attach(GTK_GRID(grid), resultEntry, 0, 2, 3, 1);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
