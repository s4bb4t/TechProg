#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// функция для вывода матрицы
void printMatrix(int n) {
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= n; j++) {
            // выводим звёздочки и пробелы в зависимости от индексов
            if (j <= n - i + 1) {
                cout << "* ";
            } else {
                cout << "  "; 
            }
        }
        cout << endl; // переход на новую строку
    }
}

// функция для обмена слов "Zero" и "Null"
char* swapWords(const char* input) {
    size_t length = strlen(input); // определяем длину строки
    char* output = new char[length + 1]; // создаём новый массив
    strcpy(output, input); // копируем исходную строку

    // находим позиции слов "Zero" и "Null"
    char* zeroPos = strstr(output, "Zero");
    char* nullPos = strstr(output, "Null");

    // если оба слова найдены, меняем их местами
    if (zeroPos && nullPos) {
        char temp[5]; // временный массив для хранения слова
        strncpy(temp, zeroPos, 4); // копируем "Zero" во временный массив
        temp[4] = '\0'; // добавляем нулевой символ в конец

        strncpy(zeroPos, nullPos, 4); // заменяем "Zero" на "Null"
        strncpy(nullPos, temp, 4); // заменяем "Null" на "Zero"
    }

    return output; // возвращаем преобразованную строку
}

// Задание 3: Структура для локальной сети
struct LocalNetwork {
    string name; // имя сети
    int cost; // стоимость сети
};

int main() {
    // Задание 1
    int size = 8; 
    printMatrix(size); // выводим матрицу размером size

    // Задание 2
    const char* original = "Zero Two Null"; // исходная строка
    char* transformed = swapWords(original); // вызываем функцию для преобразования
    cout << "Исходная строка: " << original << endl; // выводим исходную строку
    cout << "Преобразованная строка: " << transformed << endl; // выводим преобразованную строку
    delete[] transformed; // освобождаем память

    // Задание 3
    LocalNetwork networks[3] = { // создаём массив локальных сетей
        {"Сеть A", 1000}, // первая сеть
        {"Сеть B", 1500}, // вторая сеть
        {"Сеть C", 1200}  // третья сеть
    };

    // Запись в файл
    ofstream outFile("networks.txt"); // открываем файл для записи
    if (outFile.is_open()) { // проверяем, открылся ли файл
        // записываем данные о сетях в файл
        for (const auto& network : networks) {
            outFile << "Имя: " << network.name << ", Стоимость: " << network.cost << endl;
        }
        outFile.close(); // закрываем файл
        cout << "Данные о локальных сетях записаны в файл networks.txt." << endl;
    }

    // находим минимальную стоимость
    int minCost = networks[0].cost; // устанавливаем минимальную стоимость равной первой сети
    for (const auto& network : networks) {
        if (network.cost < minCost) { // если стоимость сети меньше минимальной
            minCost = network.cost; // обновляем минимальную стоимость
        }
    }
    cout << "Минимальная стоимость монтажа: " << minCost << endl; // выводим минимальную стоимость

    return 0; // завершение программы
}
