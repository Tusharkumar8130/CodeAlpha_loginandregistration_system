#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, string> loadUsers() {
    unordered_map<string, string> users;
    ifstream file("users.txt");
    string username, password;
    while (file >> username >> password) {
        users[username] = password;
    }
    file.close();
    return users;
}

void saveUser(const string &username, const string &password) {
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();
}

bool registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    auto users = loadUsers();
    if (users.find(username) != users.end()) {
        cout << "❌ Username already exists! Try a different one.\n";
        return false;
    }

    saveUser(username, password);
    cout << "✅ Registration successful!\n";
    return true;
}

bool loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    auto users = loadUsers();
    if (users.find(username) != users.end() && users[username] == password) {
        cout << "✅ Login successful! Welcome, " << username << "!\n";
        return true;
    }
    cout << "❌ Invalid username or password!\n";
    return false;
}

int main() {
    int choice;
    do {
        cout << "\n--- Login & Registration System ---\n";
        cout << "1. Register\n2. Login\n3. Exit\nChoose: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
