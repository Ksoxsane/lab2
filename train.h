#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class TRAIN {
private:
    string destination;
    int trainNumber;
    string departureTime; // формат HH:MM

public:
    TRAIN();
    TRAIN(string destination, int trainNumber, string departureTime);

    // Методы доступа
    string getDestination() const;
    int getTrainNumber() const;
    string getDepartureTime() const;

    // Дружественные функции для ввода и вывода
    friend ostream& operator<<(ostream& os, const TRAIN& train);
    friend istream& operator>>(istream& is, TRAIN& train);
};

#endif