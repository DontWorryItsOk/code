import tkinter as tk
from tkinter import messagebox

def calculate():
    try:
        hex_operand = entry_hex.get()
        oct_operand = entry_oct.get()

        if not hex_operand or not oct_operand:
            messagebox.showerror("Ошибка", "Введите оба операнда")
            return

        dec_operand1 = int(hex_operand, 16)
        dec_operand2 = int(oct_operand, 8)

        operation = operation_var.get()

        if operation == "+":
            result = dec_operand1 + dec_operand2
        elif operation == "-":
            result = dec_operand1 - dec_operand2
        elif operation == "*":
            result = dec_operand1 * dec_operand2
        elif operation == "/":
            result = dec_operand1 / dec_operand2
        else:
            messagebox.showerror("Ошибка", "Недопустимая операция")
            return

        hex_result = hex(result).upper()[2:]
        label_result.config(text=f"Результат: {hex_result}")

    except ValueError:
        messagebox.showerror("Ошибка", "Неверный формат чисел")

# Создаем главное окно
root = tk.Tk()
root.title("Hex-Oct Calculator")

# Создаем элементы управления
label_hex = tk.Label(root, text="Первый операнд (hex):")
label_hex.grid(row=0, column=0, padx=10, pady=10)

entry_hex = tk.Entry(root)
entry_hex.grid(row=0, column=1, padx=10, pady=10)

label_oct = tk.Label(root, text="Второй операнд (oct):")
label_oct.grid(row=1, column=0, padx=10, pady=10)

entry_oct = tk.Entry(root)
entry_oct.grid(row=1, column=1, padx=10, pady=10)

operation_var = tk.StringVar()
operation_var.set("+")

label_operation = tk.Label(root, text="Операция:")
label_operation.grid(row=2, column=0, padx=10, pady=10)

operation_menu = tk.OptionMenu(root, operation_var, "+", "-", "*", "/")
operation_menu.grid(row=2, column=1, padx=10, pady=10)

button_calculate = tk.Button(root, text="Вычислить", command=calculate)
button_calculate.grid(row=3, column=0, columnspan=2, pady=10)

label_result = tk.Label(root, text="Результат:")
label_result.grid(row=4, column=0, columnspan=2, pady=10)

# Запускаем главный цикл
root.mainloop()
