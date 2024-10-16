#include <iostream>
#include "operations.h" // Подключаем заголовочный файл с определением операций

int main() {
    double num1, num2; // Переменные для хранения вводимых чисел

    // Запрашиваем первое число у пользователя
    std::cout << "Введите первое число: ";
    std::cin >> num1;
    
    // Запрашиваем второе число у пользователя
    std::cout << "Введите второе число: ";
    std::cin >> num2;

    // Выполняем арифметические операции и выводим результаты
    std::cout << "Сложение: " << add(num1, num2) << std::endl;
    std::cout << "Вычитание: " << subtract(num1, num2) << std::endl;
    std::cout << "Умножение: " << multiply(num1, num2) << std::endl;

    // Обрабатываем исключение для деления на ноль
    try {
        std::cout << "Деление: " << divide(num1, num2) << std::endl;
    } catch (const std::invalid_argument& e) {
        // Выводим сообщение об ошибке, если произошло исключение
        std::cerr << e.what() << std::endl;
    }

    return 0; // Завершение программы
}
