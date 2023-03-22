#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a new user
void registerUser(string username, string password) {
    ofstream file;
    file.open(username + ".txt");
    file << password;
    file.close();
    cout << "User " << username << " registered successfully!\n";
}

// Function to check if a user exists
bool userExists(string username) {
    ifstream file;
    file.open(username + ".txt");
    if (file) {
        file.close();
        return true;
    } else {
        file.close();
        return false;
    }
}

// Function to validate a user's password
bool validatePassword(string username, string password) {
    ifstream file;
    file.open(username + ".txt");
    string storedPassword;
    getline(file, storedPassword);
    file.close();
    if (password == storedPassword) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string username, password;
    int choice;
    bool loggedIn = false;

    while (!loggedIn) {
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                if (userExists(username)) {
                    cout << "User already exists!\n";
                } else {
                    registerUser(username, password);
                }
                break;
            case 2:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                if (userExists(username) && validatePassword(username, password)) {
                    cout << "Login successful!\n";
                    loggedIn = true;
                } else {
                    cout << "Invalid username or password!\n";
                }
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }

    // Rest of the program logic goes here

    return 0;
}
