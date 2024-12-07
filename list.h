#ifndef TRAINLIST_H
#define TRAINLIST_H

#include "train.h"

class TrainList {
private:
    vector<TRAIN> trains;

    void sortByNumber();

public:
    void addTrain(const TRAIN& train);
    void printAll() const;
    void printTrainsToNumber(const int& number) const;
};

#endif