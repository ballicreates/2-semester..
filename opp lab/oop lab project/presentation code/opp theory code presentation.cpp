  #include <iostream>
#include <string>
#include <limits>

using namespace std;

// Base Class
class Person
{
protected:
    string name;
    int age;

public:
    virtual void display()
    {
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
    }

    virtual ~Person() {}
};

// Student Class
class Student : public Person
{
private:
    int studentID;
    string fatherName;
    string cnic;
    string contactNo;
    int roomNo;
    float fee;

public:
    Student()
    {
        studentID = 0;
        fatherName = "";
        cnic = "";
        contactNo = "";
        roomNo = 0;
        fee = 0;
    }

    void input()
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Father Name: ";
        getline(cin, fatherName);

        cout << "Enter CNIC: ";
        getline(cin, cnic);

        cout << "Enter Contact Number: ";
        getline(cin, contactNo);

        cout << "Enter Student ID: ";
        while (!(cin >> studentID))
        {
            cout << "Enter Valid Student ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter Age: ";
        while (!(cin >> age))
        {
            cout << "Enter Valid Age: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter Room Number: ";
        while (!(cin >> roomNo))
        {
            cout << "Enter Valid Room Number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter Hostel Fee: ";
        while (!(cin >> fee))
        {
            cout << "Enter Valid Fee: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    int getID()
    {
        return studentID;
    }

    void updateFee(float amount)
    {
        fee += amount;
    }

    void updateRoom(int room)
    {
        roomNo = room;
    }

    void display()
    {
        cout << "\n================================";
        cout << "\nStudent ID   : " << studentID;
        cout << "\nName         : " << name;
        cout << "\nFather Name  : " << fatherName;
        cout << "\nCNIC         : " << cnic;
        cout << "\nContact No   : " << contactNo;
        cout << "\nAge          : " << age;
        cout << "\nRoom No      : " << roomNo;
        cout << "\nFee Paid     : " << fee;
        cout << "\n================================\n";
    }
};

// Login Class
class Login
{
private:
    string username;
    string password;

public:
    Login()
    {
        username = "zodiacop";
        password = "zodiac";
    }

    bool login()
    {
        string user, pass;

        cout << "\n========== LOGIN ==========\n";

        cout << "Username: ";
        cin >> user;

        cout << "Password: ";
        cin >> pass;

        if (user == username && pass == password)
        {
            cout << "\nLogin Successful!\n";
            return true;
        }

        cout << "\nInvalid Username or Password!\n";
        return false;
    }
};

// Hostel Class
class Hostel
{
private:
    Student students[100];
    int count;

public:
    Hostel()
    {
        count = 0;
    }

    void addStudent()
    {
        if (count >= 100)
        {
            cout << "\nHostel Record Full!\n";
            return;
        }

        students[count].input();
        count++;

        cout << "\nStudent Added Successfully!\n";
    }

    void showStudents()
    {
        if (count == 0)
        {
            cout << "\nNo Students Found!\n";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            students[i].display();
        }
    }

    void searchStudent()
    {
        int id;
        cout << "\nEnter Student ID: ";
        cin >> id;

        bool found = false;

        for (int i = 0; i < count; i++)
        {
            if (students[i].getID() == id)
            {
                students[i].display();
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "\nStudent Not Found!\n";
        }
    }

    void updateFee()
    {
        int id;
        float amount;

        cout << "\nEnter Student ID: ";
        cin >> id;

        for (int i = 0; i < count; i++)
        {
            if (students[i].getID() == id)
            {
                cout << "Enter Additional Fee: ";
                cin >> amount;

                students[i].updateFee(amount);

                cout << "\nFee Updated Successfully!\n";
                return;
            }
        }

        cout << "\nStudent Not Found!\n";
    }

    void updateRoom()
    {
        int id, room;

        cout << "\nEnter Student ID: ";
        cin >> id;

        for (int i = 0; i < count; i++)
        {
            if (students[i].getID() == id)
            {
                cout << "Enter New Room Number: ";
                cin >> room;

                students[i].updateRoom(room);

                cout << "\nRoom Updated Successfully!\n";
                return;
            }
        }

        cout << "\nStudent Not Found!\n";
    }

    void deleteStudent()
    {
        int id;

        cout << "\nEnter Student ID to Delete: ";
        cin >> id;

        for (int i = 0; i < count; i++)
        {
            if (students[i].getID() == id)
            {
                for (int j = i; j < count - 1; j++)
                {
                    students[j] = students[j + 1];
                }

                count--;

                cout << "\nStudent Deleted Successfully!\n";
                return;
            }
        }

        cout << "\nStudent Not Found!\n";
    }
};

// Main Function
int main()
{
    Login admin;
    Hostel hostel;

    if (!admin.login())
    {
        return 0;
    }

    int choice;

    do
    {
        cout << "\n========== HOSTEL MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Fee\n";
        cout << "5. Change Room\n";
        cout << "6. Delete Student\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            hostel.addStudent();
            break;

        case 2:
            hostel.showStudents();
            break;

        case 3:
            hostel.searchStudent();
            break;

        case 4:
            hostel.updateFee();
            break;

        case 5:
            hostel.updateRoom();
            break;

        case 6:
            hostel.deleteStudent();
            break;

        case 0:
            cout << "\nProgram Ended Successfully.\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}
