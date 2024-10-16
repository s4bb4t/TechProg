#ifndef LOCALNETWORK_H // Защита от повторного включения
#define LOCALNETWORK_H

#include <iostream>
#include <string>

using namespace std;

// Базовый класс для локальных сетей
class LocalNetwork {
protected:
    string networkName; // Название сети
    double installationCost; // Стоимость установки

public:
    LocalNetwork(string name, double cost); // Конструктор
    virtual void showDetails(); // Метод для отображения деталей сети
    virtual double calculateInstallationCost() = 0; // Чисто виртуальный метод для расчета стоимости установки
};

// Класс для одноранговых сетей
class PeerToPeerNetwork : publ
