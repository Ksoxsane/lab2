#include "list.h"
#include <algorithm>

void TrainList::sortByNumber() {
    sort(trains.begin(), trains.end(), [](const TRAIN& a, const TRAIN& b) {
        return a.getTrainNumber() < b.getTrainNumber();
    });
}

void TrainList::addTrain(const TRAIN& train) {
    trains.push_back(train);
    sortByNumber();
}

void TrainList::printAll() const {
    if (trains.empty()) {
        cout << "No trains available.\n";
        return;
    }

    for (const auto& train : trains) {
        cout << train << endl;
    }
}

void TrainList::printTrainsToNumber(const int& number) const {
    bool found = false;
    for (const auto& train : trains) {
        if (train.getTrainNumber() == number) {
            cout << train << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No trains found heading to " << number << ".\n";
    }
}