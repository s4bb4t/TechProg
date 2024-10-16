#include <iostream>
using namespace std;

int main() {
    float num1, num2; 
    char operation;   

    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;
    cout << "Введите знак операции (+, -, *, /): ";
    cin >> operation;

    switch (operation) {
        case '+':
            cout << "Результат: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Результат: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Результат: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << "Результат: " << num1 / num2 << endl;
            else
                cout << "Ошибка: деление на ноль!" << endl;
            break;
        default:
            cout << "Ошибка: неверный знак операции!" << endl;
    }

    return 0;
}
