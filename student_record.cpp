/*#include <iostream>
#include<string>
#include <cctype>
using namespace std;

class student {
string name ;
string email;
string Paasword;
float fee;
long long int mobile_number[10];
float marks;

void StudentDetail ()
{
    cout << "Enter the student Name : "<<endl;
    cin >> name;
    if (name. length <5 || name. length >50)
    {
        cout << "Name Registered Successfully "<<endl;
    }
    else
    {
        return 0;
    }
    cout << "Eneter the Student Age : "<<endl;
    cin >> age;
    cout << "Mobile number :"<<endl;
    cin >> mobile_number;
    if (mobile.length == 10)
    {
        cout << "Mobile number registered successfully !"<<endl;
    }
    else 
    {
        return 0;
    }
    cout << "Email Id"<<endl;
    cin >> email;
    if (email.find('@gamil.com'))
    {
        cout << "Email has been registered"<<endl;
    }
    else 
    {
        return 0;
    }
    cout <<"Enter the Password :"<<endl;
    cin >> Password;
    if (Password.find(isupper))
    cout << "enter the college fee :"<<endl;
    cin >> fee;
}
  

}
*/

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
