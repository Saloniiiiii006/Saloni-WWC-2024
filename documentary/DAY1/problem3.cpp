#include <iostream>
#include <string>
using namespace std;

int main() {
    // Declare variables to store bio data
    string name, section, area_of_interest, dob, hometown;
    int uid, age;
    float cgpa_last_year;

    // Input the details
    cout << "Enter your Name: ";
    getline(cin, name);

    cout << "Enter your UID: ";
    cin >> uid;
    cin.ignore();  // To consume the newline character left by cin

    cout << "Enter your Section: ";
    getline(cin, section);

    cout << "Enter your Area of Interest: ";
    getline(cin, area_of_interest);

    cout << "Enter your Age: ";
    cin >> age;

    cout << "Enter your CGPA for last year: ";
    cin >> cgpa_last_year;

    cin.ignore();  // To consume the newline character left by cin

    cout << "Enter your Date of Birth (DD/MM/YYYY): ";
    getline(cin, dob);

    cout << "Enter your Hometown: ";
    getline(cin, hometown);

    // Print the academic bio data
    cout << "\n--- Academic Bio Data ---" << endl;
    cout << "Name: " << name << endl;
    cout << "UID: " << uid << endl;
    cout << "Section: " << section << endl;
    cout << "Area of Interest: " << area_of_interest << endl;
    cout << "Age: " << age << endl;
    cout << "Last Year CGPA: " << cgpa_last_year << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Hometown: " << hometown << endl;

    return 0;
}
