#include "Train.h"

TRAIN::TRAIN() : destination(""), trainNumber(0), departureTime("00:00") {}

TRAIN::TRAIN(string destination, int trainNumber, string departureTime)
    : destination(destination), trainNumber(trainNumber), departureTime(departureTime) {}

string TRAIN::getDestination() const { return destination; }
int TRAIN::getTrainNumber() const { return trainNumber; }

ostream& operator<<(ostream& os, const TRAIN& train) {
    os << "Destination: " << train.destination
       << ", Train Number: " << train.trainNumber
       << ", Departure Time: " << train.departureTime;
    return os;
}

istream& operator>>(istream& is, TRAIN& train) {
    cout << "Enter destination: ";
    is >> train.destination;
    cout << "Enter train number: ";
    is >> train.trainNumber;
    cout << "Enter departure time (HH:MM): ";
    is >> train.departureTime;
    return is;
}