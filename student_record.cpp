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
    bool validemail=false;
    bool Upper =false;
    bool Lower = false;
    bool number =false;
    bool specialchar= false;
    

public:
    void StudentDetail() {
        cout << "Enter Student Name (length should max 5 and min 20): ";
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

       for(int i=0;i<email.length();i++)
       {
        if(email[i]=='@')
        {
            validemail=true;
            break;
        }
        else{
           validemail=false;
        }
       }

        cout << "Enter Password (min 8 chars) only allowed char @ $# ^: ";
        cin >> password;

        if (password.length() <= 8 ) {

            for (int i = 0; i< password.length();i++)
            {
                if (password[i]>=97 && password[i]<=122)
                {
                    //cout << "LOwer "<<endl;
                    Lower = true;
                }
                else if (password[i]>= 65 && password[i] <= 90 )
                {
                   // cout << "Upper"<<endl;
                    Upper = true;
                }
                else if (password[i]>=48 &&password[i]<=57)
                {
                   // cout << "number "<<endl;
                    number = true;
                }
                else if (password[i] == '@' || password[i] == '$' ||password[i] == '^' || password[i] == '#')
                {
                   // cout << "specialchar "<<endl;
                    specialchar = true;
                }

               
            }
           if (!Upper || !Lower || !specialchar || !number)
           {
                    cout << "Password must be contain special char ,Uppercase ,Lowercase, special char !"<< endl;
                    return;
           }
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
        if(validemail){
           cout << "Email: " << email << endl;
        }
       
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
