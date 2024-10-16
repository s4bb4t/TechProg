#ifndef LOCALNETWORK_H
#define LOCALNETWORK_H

#include <iostream>
#include <string>

using namespace std;

// Базовый класс для локальных сетей
class LocalNetwork {
protected:
    string networkName; // Имя сети
    double installationCost; // Стоимость установки

public:
    LocalNetwork(string name, double cost); // Конструктор
    virtual void showDetails(); // Виртуальный метод для показа деталей
    virtual double calculateInstallationCost() = 0; // Чисто виртуальный метод для расчета стоимости
};

// Класс для одноранговой сети
class PeerToPeerNetwork : public LocalNetwork {
private:
    int numberOfNodes; // Количество узлов
    string description; // Описание сети

public:
    PeerToPeerNetwork(string name, double cost, int nodes); // Конструктор
    void showDetails() override; // Переопределяем метод показа деталей
    double calculateInstallationCost() override; // Переопределяем метод расчета стоимости
};

// Класс для клиент-серверной сети
class ClientServerNetwork : public LocalNetwork {
private:
    int numberOfClients; // Количество клиентов
    string description; // Описание сети

public:
    ClientServerNetwork(string name, double cost, int clients); // Конструктор
    void showDetails() override; // Переопределяем метод показа деталей
    double calculateInstallationCost() override; // Переопределяем метод расчета стоимости
};

#endif
