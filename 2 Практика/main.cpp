#include <iostream>
#include <limits> 

using namespace std;

void task1() {
    unsigned char a;  
    float b;         

    // запрашиваем у пользователя значение для типа unsigned char
    cout << "Введите значение для unsigned char (0-255): ";
    cin >> a;  
    // проверяем, если ввод некорректен или значение вне диапазона
    if (cin.fail() || a < 0 || a > 255) {
        cout << "Ошибка: введите значение в диапазоне от 0 до 255." << endl;
        return; 
    }
    // запрашиваем значение для переменной типа float
    cout << "Введите значение для float: ";
    cin >> b;       

    // вычисляем сумму a и b
    float sum = a + b;     
    int sumInt = static_cast<int>(sum); // приводим сумму к типу int
    cout << "Сумма (int): " << sumInt << endl;

    // выводим размер переменной sum в байтах
    cout << "Размер суммы (в байтах): " << sizeof(sum) << endl;
}


void task2() {
    const int MAX_SIZE = 100;  
    double arr[MAX_SIZE]; // массив для хранения элементов
    int count = 0;          
    double value;               
    double positiveSum = 0; // переменная для суммы положительных чисел

    // запрашиваем ввод элементов массива
    cout << "Введите элементы массива типа double (введите нечисловое значение для завершения ввода):" << endl;
    while (count < MAX_SIZE && cin >> value) {  
        arr[count++] = value;  
        // если число положительное, добавляем его к сумме
        if (value > 0) {
            positiveSum += value; 
        }
    }

    // очищаем поток ввода
    cin.clear();  
    // игнорируем остаток строки после завершения ввода
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // выводим сумму положительных элементов
    cout << "Сумма положительных элементов массива: " << positiveSum << endl;
}

int main() {
    task1(); 
    task2(); 

    return 0;
}
