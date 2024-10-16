#include <iostream>
using namespace std;

// Шаблонная функция для нахождения минимальной стоимости
template <typename T>
T calculateMinCost(T costs[], int size) {
    T minCost = costs[0]; // Инициализируем минимальную стоимость первым элементом массива
    for (int i = 1; i < size; i++) { // Перебираем все элементы массива
        if (costs[i] < minCost) { // Если текущий элемент меньше минимальной стоимости
            minCost = costs[i]; // Обновляем минимальную стоимость
        }
    }
    return minCost; // Возвращаем найденную минимальную стоимость
}

// Шаблонная функция для подсчета количества компьютеров
template <typename T>
int countComputers(T computers[], int size) {
    return size; // Возвращаем размер массива, который равен количеству компьютеров
}

int main() {
    // Массив с затратами на установку
    double installationCosts[] = {150.5, 200.75, 100.0, 250.25, 120.0};
    int sizeCosts = sizeof(installationCosts) / sizeof(installationCosts[0]); // Вычисляем количество затрат

    // Массив с количеством компьютеров в сети
    int computersInNetwork[] = {1, 2, 3, 4, 5};
    int sizeComputers = sizeof(computersInNetwork) / sizeof(computersInNetwork[0]); // Вычисляем количество компьютеров

    // Вычисляем минимальную стоимость установки
    double minCost = calculateMinCost(installationCosts, sizeCosts);
    cout << "Минимальная стоимость монтажа: " << minCost << " рублей" << endl; // Выводим минимальную стоимость

    // Подсчитываем количество компьютеров в сети
    int computerCount = countComputers(computersInNetwork, sizeComputers);
    cout << "Количество компьютеров в сети: " << computerCount << endl; // Выводим количество компьютеров

    return 0; // Завершение программы
}
