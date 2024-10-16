#include <iostream>
#include <cmath>
using namespace std;

// Задание 1: Класс для представления точки на плоскости
class Point {
private:
    float x, y; // Закрытые переменные для координат

public:
    // Конструктор с параметрами для инициализации координат
    Point(float xCoord, float yCoord) : x(xCoord), y(yCoord) {}

    // Функции доступа к закрытым переменным
    float getX() const { return x; }
    float getY() const { return y; }

    // Деструктор, сообщающий о разрушении объекта
    ~Point() {
        cout << "Object at (" << x << ", " << y << ") is destroyed." << endl;
    }

    // Статический метод для вычисления расстояния между двумя точками
    static float distance(const Point &p1, const Point &p2) {
        return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    }
};

// Дружественная функция для вычисления площади прямоугольника
float calculateRectangleArea(Point* points) {
    float length = Point::distance(points[0], points[1]);
    float width = Point::distance(points[1], points[2]);
    return length * width; // Площадь = длина * ширина
}

// Задание 2: Класс для представления локальной сети
class LocalNetwork {
private:
    int numberOfDevices; // Количество устройств в сети
    float installationCostPerDevice; // Стоимость установки на одно устройство

public:
    // Конструктор для инициализации количества устройств и стоимости установки
    LocalNetwork(int devices, float cost) : numberOfDevices(devices), installationCostPerDevice(cost) {}

    // Метод для расчета минимальной стоимости установки
    float calculateMinimumInstallationCost() const {
        return numberOfDevices * installationCostPerDevice;
    }

    // Деструктор, сообщающий о разрушении объекта
    ~LocalNetwork() {
        cout << "LocalNetwork object destroyed." << endl;
    }
};

int main() {
    // Задание 1: Создание массива из 4 объектов класса Point
    Point* rectangleVertices = new Point[4]{
        Point(0.0, 0.0), // Нижний левый угол
        Point(0.0, 4.0), // Верхний левый угол
        Point(3.0, 4.0), // Верхний правый угол
        Point(3.0, 0.0)  // Нижний правый угол
    };

    // Вычисление площади прямоугольника
    float area = calculateRectangleArea(rectangleVertices);
    cout << "Area of the rectangle: " << area << endl;

    // Освобождение памяти
    delete[] rectangleVertices;

    // Задание 2: Создание локальной сети
    LocalNetwork network(10, 150.0); 
    // Расчет минимальной стоимости установки
    float installationCost = network.calculateMinimumInstallationCost();
    cout << "Minimum installation cost: " << installationCost << endl;

    return 0; // Завершение программы
}
