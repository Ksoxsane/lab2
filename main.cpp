#include "list.h"
#include <iostream>

using namespace std;

int main() {
    TrainList trainList;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Train\n";
        cout << "2. Print All Trains\n";
        cout << "3. Search Trains by number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                TRAIN train;
                cin >> train;
                trainList.addTrain(train);
                break;
            }
            case 2:
                trainList.printAll();
                break;
            case 3: {
                int number;
                cout << "Enter number: ";
                cin >> number;
                trainList.printTrainsToNumber(number);
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}