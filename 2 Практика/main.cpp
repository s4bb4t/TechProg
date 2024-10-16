#include <iostream>
#include <limits>

using namespace std;

// Глобальные переменные для второй версии
unsigned char globalA;
int globalState;
float globalB;
double globalArray[5]; // Глобальный массив для хранения элементов
double globalPositiveSum = 0; // Глобальная переменная для суммы положительных элементов
int globalCount = 0; // Счетчик для глобального массива

// Функция 1: Вычисление суммы и размер памяти
void task1(bool useGlobal) {
    if (useGlobal) {
        // Используем глобальные переменные
        cout << "Введите значение для unsigned char (0-255): ";
        cin >> globalState;

        if (cin.fail() || globalState < 0 || globalState > 255) {
            cout << "Ошибка: введите значение в диапазоне от 0 до 255." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        globalA = static_cast<unsigned char>(globalState);

        cout << "Введите значение для float: ";
        cin >> globalB;


        // Вычисляем сумму
        float sum = globalA + globalB;
        int sumInt = static_cast<int>(sum);
        cout << "Сумма (int): " << sumInt << endl;
        cout << "Размер суммы (в байтах): " << sizeof(sum) << endl;
    } else {
        // Используем локальные переменные
        int input;
        unsigned char a;
        float b;

        cout << "Введите значение для unsigned char (0-255): ";
        cin >> input;

        if (cin.fail() || input < 0 || input > 255) {
            cout << "Ошибка: введите значение в диапазоне от 0 до 255." << endl;
            return;
        }

        a = static_cast<unsigned char>(input);

        cout << "Введите значение для float: ";
        cin >> b;

        // Вычисляем сумму
        float sum = a + b;
        int sumInt = static_cast<int>(sum);
        cout << "Сумма (int): " << sumInt << endl;
        cout << "Размер суммы (в байтах): " << sizeof(sum) << endl;
    }
}

// Функция 2: Заполнение массива и вычисление суммы положительных элементов
void task2(bool useGlobal) {
    if (useGlobal) {
        cout << "Введите 5 элементов массива типа double:" << endl;
        globalPositiveSum = 0; // Обнуляем сумму перед вводом

        for (globalCount = 0; globalCount < 5; globalCount++) {
            cin >> globalArray[globalCount];

            // Если число положительное, добавляем его к сумме
            if (globalArray[globalCount] > 0) {
                globalPositiveSum += globalArray[globalCount];
            }
        }

        // Выводим сумму положительных элементов
        cout << "Сумма положительных элементов массива: " << globalPositiveSum << endl;
    } else {
        // Локальные переменные
        double localArray[5];
        double positiveSum = 0; // Сумма положительных чисел

        cout << "Введите 5 элементов массива типа double:" << endl;
        for (int i = 0; i < 5; i++) {
            cin >> localArray[i];

            // Если число положительное, добавляем его к сумме
            if (localArray[i] > 0) {
                positiveSum += localArray[i];
            }
        }

        // Выводим сумму положительных элементов
        cout << "Сумма положительных элементов массива: " << positiveSum << endl;
    }
}

// Основная функция
int main() {
    char choice;
    int task, version;

    do {
        // Меню для выбора задания и версии
        cout << "Выберите задание:\n1 - Задание 1\n2 - Задание 2\n0 - Выход\n";
        cin >> task;

        if (task == 0) break; // Выход из программы

        cout << "Выберите версию:\n1 - Локальные переменные\n2 - Глобальные переменные\n";
        cin >> version;

        switch (task) {
            case 1:
                task1(version == 2);
                break;
            case 2:
                task2(version == 2);
                break;
            default:
                cout << "Ошибка: неверный выбор задания!" << endl;
                break;
        }
    } while (true);

    return 0;
}
