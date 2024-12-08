#include "second.h"
#include "iostream"
int main() {
    try {
        int wordCount;
        cout << "Enter amount of words in sentence: ";
        if (!(cin >> wordCount)) {
            throw invalid_argument("Error: некорректный ввод количества слов.");
        }
        int choice;
        cout << "Enter choice (1 - stroka, 2 - file): ";
        if (!(cin >> choice)) {
            throw invalid_argument("Error: некорректный ввод выбора источника.");
        }
        if (choice == 1) {
            cin.ignore();
            char text[8192];
            cout << "Enter text: ";
            cin.getline(text, sizeof(text));
            if (cin.fail()) {
                throw overflow_error("Error: превышена максимальная длина текста.");
            }
            SentenceFilter filter(text, wordCount, true);
            filter.result();
        } else if (choice == 2) {
            char filename[256];
            cout << "Enter file's name: ";
            cin >> filename;
            ifstream file(filename);
            if (!file) {
                throw runtime_error("Error: файл не найден или не может быть открыт.");
            }
            file.close();
            SentenceFilter filter(filename, wordCount);
            filter.result();
        } else {
            throw out_of_range("Error: выбран несуществующий источник.");
        }
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return 1;
    }
    catch (const overflow_error& e) {
        cerr << e.what() << endl;
        return 2;
    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return 3;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
        return 4;
    }
    catch (...) {
        cerr << " Error." << endl;
        return -1;
    }
    return 0;
}

