#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a contact
struct Contact {
    string name;
    string phoneNumber;
}; // <-- Added semicolon here

// PhoneBook class to manage contacts
class PhoneBook {
private:
    vector<Contact> contacts;
    string filename;

public:
    // Constructor to initialize filename
    PhoneBook(const string& filename) : filename(filename) {}

    // Function to load contacts from file
    void loadContactsFromFile() {
        ifstream file(filename);
        if (file.is_open()) {
            Contact contact;
            while (file >> contact.name >> contact.phoneNumber) {
                contacts.push_back(contact);
            }
            file.close();
        }
    }

    // Function to save contacts to file
    void saveContactsToFile() {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& contact : contacts) {
                file << contact.name << " " << contact.phoneNumber << endl;
            }
            file.close();
        }
    }

    // Function to add a contact
    void addContact(const string& name, const string& phoneNumber) {
        contacts.push_back({ name, phoneNumber });
        cout << "Contact added successfully!" << endl;
    }

    // Function to delete a contact by name or number
    void deleteContact(const string& keyword) {
        auto it = find_if(contacts.begin(), contacts.end(), [&](const Contact& c) {
            return c.name == keyword || c.phoneNumber == keyword;
            });
        if (it != contacts.end()) {
            contacts.erase(it);
            cout << "Contact deleted successfully!" << endl;
        }
        else {
            cout << "Contact not found!" << endl;
        }
    }

    // Function to retrieve a contact by name or number
    void retrieveContact(const string& keyword) {
        bool found = false;
        for (const auto& contact : contacts) {
            if (contact.name == keyword || contact.phoneNumber == keyword) {
                cout << "Name: " << contact.name << ", Phone Number: " << contact.phoneNumber << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Contact not found!" << endl;
        }
    }

    // Function to edit a contact by name or number
    void editContact(const string& keyword, const string& newName, const string& newPhoneNumber) {
        auto it = find_if(contacts.begin(), contacts.end(), [&](const Contact& c) {
            return c.name == keyword || c.phoneNumber == keyword;
            });
        if (it != contacts.end()) {
            it->name = newName;
            it->phoneNumber = newPhoneNumber;
            cout << "Contact edited successfully!" << endl;
        }
        else {
            cout << "Contact not found!" << endl;
        }
    }

    // Function to display all contacts
    void displayAllContacts() {
        if (contacts.empty()) {
            cout << "Phone book is empty!" << endl;
        }
        else {
            cout << "All Contacts:" << endl;
            for (const auto& contact : contacts) {
                cout << "Name: " << contact.name << ", Phone Number: " << contact.phoneNumber << endl;
            }
        }
    }
};

int main() {
    PhoneBook phoneBook("contacts.txt");
    phoneBook.loadContactsFromFile();

    int choice;
    string name, phoneNumber, keyword, newName, newPhoneNumber;

    do {
        cout << "\nPhone Book Menu:" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Delete Contact" << endl;
        cout << "3. Retrieve Contact" << endl;
        cout << "4. Edit Contact" << endl;
        cout << "5. Display All Contacts" << endl;
        cout << "6. Save Contacts to File" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone number: ";
            cin >> phoneNumber;
            phoneBook.addContact(name, phoneNumber);
            break;
        case 2:
            cout << "Enter name or number to delete: ";
            cin >> keyword;
            phoneBook.deleteContact(keyword);
            break;
        case 3:
            cout << "Enter name or number to retrieve: ";
            cin >> keyword;
            phoneBook.retrieveContact(keyword);
            break;
        case 4:
            cout << "Enter name or number to edit: ";
            cin >> keyword;
            cout << "Enter new name: ";
            cin >> newName;
            cout << "Enter new phone number: ";
            cin >> newPhoneNumber;
            phoneBook.editContact(keyword, newName, newPhoneNumber);
            break;
        case 5:
            phoneBook.displayAllContacts();
            break;
        case 6:
            phoneBook.saveContactsToFile();
            cout << "Contacts saved to file." << endl;
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}



