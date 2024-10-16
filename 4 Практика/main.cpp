#include <iostream>
#include <cmath> 
using namespace std;

// Задание 1
class Point {
private:
    float x, y; // координаты точки

public:
    // Конструктор для инициализации координат
    Point(float xCoord, float yCoord) : x(xCoord), y(yCoord) {}

    // Метод для получения координаты X
    float getX() { return x; }

    // Метод для получения координаты Y
    float getY() { return y; }

    // Деструктор, который сообщает о разрушении объекта
    ~Point() {
        cout << "Object at (" << x << ", " << y << ") is destroyed." << endl;
    }

    // Статический метод для вычисления расстояния между двумя точками
    static float distance(Point p1, Point p2) {
        return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    }
};

// Задание 2
class LocalNetwork {
private:
    int numberOfDevices; // количество устройств в сети
    float installationCostPerDevice; // стоимость установки на одно устройство

public:
    // Конструктор для инициализации количества устройств и стоимости установки
    LocalNetwork(int devices, float cost) : numberOfDevices(devices), installationCostPerDevice(cost) {}

    // Метод для расчета минимальной стоимости установки
    float calculateMinimumInstallationCost() {
        return numberOfDevices * installationCostPerDevice;
    }

    // Деструктор, который сообщает о разрушении объекта
    ~LocalNetwork() {
        cout << "LocalNetwork object destroyed." << endl;
    }
};

int main() {
    // Создание двух точек с заданными координатами
    Point point1(1.0, 2.0); 
    Point point2(4.0, 6.0); 

    // Вычисление расстояния между двумя точками
    float distanceBetweenPoints = Point::distance(point1, point2);
    cout << "Distance between points: " << distanceBetweenPoints << endl;

    // Создание локальной сети с 10 устройствами и стоимостью установки 150.0
    LocalNetwork network(10, 150.0); 
    // Расчет минимальной стоимости установки
    float installationCost = network.calculateMinimumInstallationCost();
    cout << "Minimum installation cost: " << installationCost << endl;

    return 0; // Завершение программы
}
