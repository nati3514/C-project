#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure to store passenger information
struct Passenger {
    string name;
    int age;
    string destination;
};

// Function to register a new passenger
void registerPassenger(vector<Passenger>& passengers) {
    Passenger passenger;
    
    cout << "Enter passenger name: ";
    getline(cin >> ws, passenger.name);
    
    cout << "Enter passenger age: ";
    cin >> passenger.age;
    
    cout << "Enter destination: ";
    getline(cin >> ws, passenger.destination);
    
    passengers.push_back(passenger);
    
    cout << "Passenger registered successfully!" << endl;
}

// Function to display all registered passengers
void displayPassengers(const vector<Passenger>& passengers) {
    cout << "Registered Passengers:" << endl;
    
    for (const auto& passenger : passengers) {
        cout << "Name: " << passenger.name << endl;
        cout << "Age: " << passenger.age << endl;
        cout << "Destination: " << passenger.destination << endl;
        cout << "------------------------" << endl;
    }
}

// Function to buy a ticket
void buyTicket(const vector<Passenger>& passengers) {
    string name;
    
    cout << "Enter passenger name: ";
    getline(cin >> ws, name);
    
    bool found = false;
    
    for (const auto& passenger : passengers) {
        if (passenger.name == name) {
            found = true;
            cout << "Ticket purchased for passenger: " << passenger.name << endl;
            break;
        }
    }
    
    if (!found) {
        cout << "Passenger not found!" << endl;
    }
}

int main() {
    vector<Passenger> passengers;
    int choice;
    
    do {
        cout << "===== Bus System =====" << endl;
        cout << "1. Register Passenger" << endl;
        cout << "2. Display Passengers" << endl;
        cout << "3. Buy Ticket" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                registerPassenger(passengers);
                break;
            case 2:
                displayPassengers(passengers);
                break;
            case 3:
                buyTicket(passengers);
                break;
            case 4:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
        
        cout << endl;
    } while (choice != 4);
    
    return 0;
}