import tkinter as tk
from tkinter import messagebox

# Функция для преобразования шестнадцатеричного числа в десятичное
def hex_to_dec(hex_operand):
    hex_nums = "0123456789ABCDEF"
    hex_operand = hex_operand.upper()
    decimal_value = 0

    # Проходим по каждой цифре в шестнадцатеричном числе
    for number in hex_operand:
        # Умножаем текущее значение на 16 и добавляем значение текущей цифры
        decimal_value = decimal_value * 16 + hex_nums.index(number)

    return decimal_value

# Функция для преобразования восьмеричного числа в десятичное
def oct_to_dec(oct_operand):
    oct_nums = "01234567"
    decimal_value = 0

    # Проходим по каждой цифре в восьмеричном числе
    for number in oct_operand:
        # Умножаем текущее значение на 8 и добавляем значение текущей цифры
        decimal_value = decimal_value * 8 + oct_nums.index(number)

    return decimal_value

# Функция для выполнения вычислений
def calculate():
    try:
        hex_operand = entry_hex.get()
        oct_operand = entry_oct.get()

        # Проверка наличия обоих операндов
        if not hex_operand or not oct_operand:
            messagebox.showerror("Ошибка", "Введите оба операнда")
            return

        # Преобразование операндов в десятичные числа
        dec_operand1 = hex_to_dec(hex_operand)
        dec_operand2 = oct_to_dec(oct_operand)

        operation = operation_var.get()

        # Выполнение операции в зависимости от выбора пользователя
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
            
      # Ручной перевод десятичного результата в шестнадцатеричное число
        hex_chars = "0123456789ABCDEF"
        hex_result = ""
        result_copy = abs(result)

        while result_copy > 0:
            remainder = result_copy % 16
            hex_result = hex_chars[remainder] + hex_result
            result_copy //= 16

        # Добавляем знак минуса, если результат отрицателен
        if result < 0:
            hex_result = "-" + hex_result

        # Выводим результат
        label_result.config(text=f"Результат: {hex_result}")

    except ValueError:
        messagebox.showerror("Ошибка", "Неверный формат чисел")

# Создаем главное окно
root = tk.Tk()
root.title("Calculator")

# Создаем элементы управления
label_hex = tk.Label(root, text="Первый операнд (16):")
label_hex.grid(row=0, column=0, padx=10, pady=10)

entry_hex = tk.Entry(root)
entry_hex.grid(row=0, column=1, padx=10, pady=10)

label_oct = tk.Label(root, text="Второй операнд (8):")
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
