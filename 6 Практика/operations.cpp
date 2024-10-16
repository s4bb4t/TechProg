#include "operations.h" // Подключаем заголовочный файл с определением операций

// Функция для сложения двух чисел
double add(double a, double b) {
    return a + b; // Возвращаем сумму
}

// Функция для вычитания двух чисел
double subtract(double a, double b) {
    return a - b; // Возвращаем разность
}

// Функция для умножения двух чисел
double multiply(double a, double b) {
    return a * b; // Возвращаем произведение
}

// Функция для деления двух чисел
double divide(double a, double b) {
    if (b != 0) {
        return a / b; // Возвращаем частное, если делитель не равен нулю
    } else {
        throw std::invalid_argument("Деление на ноль!"); // Генерируем исключение для деления на ноль
    }
}
