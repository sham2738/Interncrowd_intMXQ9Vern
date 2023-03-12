#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Birthday {
    string name;
    int day;
    int month;
    int year;
};

void addBirthday(vector<Birthday>& list) {
    Birthday bday;
    cout << "Enter name: ";
    cin >> bday.name;
    cout << "Enter day (1-31): ";
    cin >> bday.day;
    cout << "Enter month (1-12): ";
    cin >> bday.month;
    cout << "Enter year: ";
    cin >> bday.year;
    list.push_back(bday);
    cout << "Birthday added successfully!" << endl;
}

void editBirthday(vector<Birthday>& list) {
    cout << "Enter the name of the birthday to edit: ";
    string name;
    cin >> name;
    bool found = false;
    for (auto& bday : list) {
        if (bday.name == name) {
            cout << "Enter new day (1-31): ";
            cin >> bday.day;
            cout << "Enter new month (1-12): ";
            cin >> bday.month;
            cout << "Enter new year: ";
            cin >> bday.year;
            found = true;
            cout << "Birthday updated successfully!" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Birthday not found!" << endl;
    }
}

void displayBirthdays(const vector<Birthday>& list) {
    if (list.empty()) {
        cout << "No birthdays found!" << endl;
        return;
    }
    cout << "Birthday List:" << endl;
    for (const auto& bday : list) {
        cout << bday.name << " - " << bday.day << "/" << bday.month << "/" << bday.year << endl;
    }
}

int main() {
    vector<Birthday> birthdayList;
    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Add Birthday" << endl;
        cout << "2. Edit Birthday" << endl;
        cout << "3. Display Birthdays" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        switch (choice) {
            case 1:
                addBirthday(birthdayList);
                break;
            case 2:
                editBirthday(birthdayList);
                break;
            case 3:
                displayBirthdays(birthdayList);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != 4);
    return 0;
}
