#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name, email, password;
    int age;
    long long mobile;
    float fee;
    int marks[5];
    int total;
    float avg;

public:
    void StudentDetail() {
        cout << "Enter Student Name: ";
        cin >> name;

        if (name.length() < 5 || name.length() > 50) {
            cout << "Invalid Name Length\n";
            return;
        }

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Mobile Number: ";
        cin >> mobile;

        cout << "Enter Email: ";
        cin >> email;

        if (email.find('@') == string::npos) {
            cout << "Invalid Email\n";
            return;
        }

        cout << "Enter Password (min 8 chars): ";
        cin >> password;

        if (password.length() < 8) {
            cout << "Weak Password\n";
            return;
        }

        cout << "Enter College Fee: ";
        cin >> fee;
    }

    void getMarks() {
        total = 0;
        cout << "Enter 5 Marks:\n";
        for (int i = 0; i < 5; i++) {
            cin >> marks[i];
            total += marks[i];
        }
        avg = total / 5.0;
    }

    void display() {
        cout << "\n--- Student Survey Report ---\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Mobile: " << mobile << endl;
        cout << "Email: " << email << endl;
        cout << "Fee: " << fee << endl;
        cout << "Total Marks: " << total << endl;
        cout << "Average: " << avg << endl;

        if (avg >= 80)
            cout << "Grade: A | Scholarship Eligible\n";
        else
            cout << "Grade: B | Scholarship Not Eligible\n";
    }
};

int main() {
    Student s;
    s.StudentDetail();
    s.getMarks();
    s.display();
    return 0;
}
