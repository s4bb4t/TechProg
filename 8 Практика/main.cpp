#include <iostream>
#include <vector>
#include "LocalNetwork.h"

using namespace std;

int main() {
    // Вектор указателей на объекты локальных сетей
    vector<LocalNetwork*> networks;

    // Добавляем одноранговые и клиент-серверные сети в вектор
    networks.push_back(new PeerToPeerNetwork("Сеть A", 10000, 10));
    networks.push_back(new ClientServerNetwork("Сеть B", 15000, 5));
    networks.push_back(new PeerToPeerNetwork("Сеть C", 8000, 8));
    networks.push_back(new ClientServerNetwork("Сеть D", 20000, 15));
    networks.push_back(new PeerToPeerNetwork("Сеть E", 12000, 12));

    // Перебираем все сети и выводим их детали и стоимость установки
    for (const auto& network : networks) {
        network->showDetails(); // Показываем детали сети
        cout << "Общая стоимость установки: " << network->calculateInstallationCost() << " рублей" << endl << endl; // Выводим стоимость установки
    }

    // Освобождаем память, выделенную для объектов сетей
    for (auto& network : networks) {
        delete network; 
    }
    networks.clear(); // Очищаем вектор

    return 0; // Завершение программы
}
