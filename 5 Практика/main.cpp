#include <iostream>
#include "LocalNetwork.h" // Подключаем заголовочный файл с определением классов

using namespace std;

int main() {
    // Создание одноранговой сети с заданными параметрами
    PeerToPeerNetwork p2p("Сеть 1", 2000, 10);
    // Создание сети типа клиент-сервер с заданными параметрами
    ClientServerNetwork c2s("Сеть 2", 3000, 5);

    // Вывод деталей одноранговой сети
    cout << "Детали одноранговой сети:" << endl;
    p2p.showDetails();
    cout << "Итоговая стоимость монтажа: " << p2p.calculateInstallationCost() << " рублей" << endl;

    cout << endl;

    // Вывод деталей сети типа клиент-сервер
    cout << "Детали сети типа клиент-сервер:" << endl;
    c2s.showDetails();
    cout << "Итоговая стоимость монтажа: " << c2s.calculateInstallationCost() << " рублей" << endl;

    return 0; // Завершение программы
}
