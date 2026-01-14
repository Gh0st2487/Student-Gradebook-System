#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <stack>
using namespace std;
bool flag = false;

class Node {
public:
    string name;
    string id;
    string grades[5];
    map<string, bool> attendance;
    float gpa;

    void calculateGPA() {
        float total = 0;

        for (int i = 0; i < 5; i++) {

            if (grades[i] == "A") {
                total += 4.0;
            }
            else if (grades[i] == "B") {
                total += 3.0;
            }
            else if (grades[i] == "C") {
                total += 2.0;
            }
            else if (grades[i] == "D") {
                total += 1.0;
            }
            else {
                total += 0.0;
            }
        }
        gpa = total / 5.0;
    }
};

class GradeBook {
public:
    Node* stud;
    int size;
    stack<Node> deletedNodes;
    stack<Node> undoNodes;

    GradeBook(int size) {
        this->size = size;
        stud = new Node[size];
        for (int i = 0; i < size; i++) {
            stud[i].name = "NULL";
        }
    }

    ~GradeBook() {
        delete[] stud;
    }

    int hashFunction(string name) {
        int x = name.length() % size;
        int i = 0;
        while (stud[x].name != "NULL" && stud[x].name != name) {
            x = (x + i) % size;
            i++;
        }
        return x;
    }

    void insert(string name, string id, string grades[5]) {
        int index = hashFunction(name);
        stud[index].name = name;
        stud[index].id = id;

        for (int i = 0; i < 5; i++) {
            stud[index].grades[i] = grades[i];
        }
        stud[index].calculateGPA();
    }

    void search(string name) {
        int index = hashFunction(name);
        int i = 0;

        if (stud[index].name == name) {
            cout << "Name: " << stud[index].name << endl;
            cout << "ID: " << stud[index].id << endl;
            cout << "Grades: ";
            for (int j = 0; j < 5; j++) {
                cout << stud[index].grades[j] << " ";
            }
            cout << endl;
            cout << "GPA: " << stud[index].gpa << endl;
        }
        else {
            cout << "Student not found" << endl;
        }
    }
    void display() {
        for (int i = 0; i < size; i++) {
            if (stud[i].name == "NULL") {
                continue;
            }
            else {
                cout << "Name: " << stud[i].name << endl;
                cout << "ID: " << stud[i].id << endl;
                cout << "Grades: ";
                for (int j = 0; j < 5; j++) {
                    cout << stud[i].grades[j] << " ";
                }
                cout << endl;
                cout << "GPA: " << stud[i].gpa << endl;
            }
        }
    }

    void markAttendance(string name, string date) {
        int index = hashFunction(name);
        int i = 0;
        if (stud[index].name == name) {
            stud[index].attendance[date] = true;
        }
        else {
            cout << "Student not found" << endl;
        }
    }

    void displayAttendance(string date) {
        for (int i = 0; i < size; i++) {

            if (stud[i].name != "NULL") {
                cout << "Name: " << stud[i].name;
                if (stud[i].attendance.count(date) > 0) {
                    if (stud[i].attendance[date]) {
                        cout << " - Present" << endl;
                    }
                    else {
                        cout << " - Absent" << endl;
                    }
                }
                else {
                    cout << " - Attendance not marked" << endl;
                }
            }
        }
    }

    void deleteNode(string name) {
        int index = hashFunction(name);

        if (index >= 0 && index < size) {
            deletedNodes.push(stud[index]);

            for (int i = 0; i < 5; i++) {
                stud[index].grades[i] = "";
            }
            stud[index].gpa = 0.0;
            stud[index].name = "NULL";
            stud[index].id = "NULL";
            cout << "Student data successfully deleted " << endl;
        }
        else {
            cout << "Student not found" << endl;
        }
    }

    void undoDelete() {
        if (!deletedNodes.empty()) {
            stud[hashFunction(deletedNodes.top().name)] = deletedNodes.top();
            deletedNodes.pop();
            cout << "Undo delete operation successful" << endl;
        }
        else {
            cout << "No deleted student to restore" << endl;
        }
    }

    float averageGPA() {
        float totalGPA = 0;
        int sc = 0;
        for (int i = 0; i < size; i++) {
            if (stud[i].name == "NULL") {
                continue;
            }
            else {
                sc++;
                totalGPA += stud[i].gpa;
            }
        }
        return totalGPA / sc;
    }
};

class admin
{
    string username;
    string password;

public:
    void reg(string unn, string ps)
    {

        ofstream file;
        file.open(unn + ".txt");
        file << unn << endl
            << ps;
        file.close();
        cout << "Account created succesfully!" << endl;
    }

    void login(string user, string pass)
    {
        ifstream read(user + ".txt");
        getline(read, username);
        getline(read, password);
        if (user == username && pass == password)
        {
            flag = true;
            cout << "Welcome " << username << endl;
        }
        else
        {
            cout << "Incorrect credentials!" << endl;
        }
    }
};

int main() {
    GradeBook st(100);
    admin l;
    int ch = 0, con = 5;
    string name, id, grades[5], date, u, p;

    while (flag != true) {
        cout << "Enter username: ";
        cin >> u;
        cout << "Enter Password: ";
        cin >> p;
        l.login(u, p);

    }


    while (ch != 9) {
        cout << endl << "===== MENU =====" << endl;
        cout << "1. Insert data" << endl;
        cout << "2. Search for a node" << endl;
        cout << "3. Display all nodes" << endl;
        cout << "4. Mark attendance for a node" << endl;
        cout << "5. Display attendance for all nodes on a specific date" << endl;
        cout << "6. Delete a node" << endl;
        cout << "7. Undo delete operation" << endl;
        cout << "8. Calculate average GPA" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter: ";
        cin >> ch;

        switch (ch) {
        case 1: {
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Id: ";
            cin >> id;
            for (int i = 0; i < con; i++) {
                cout << "Enter grade for course " << i + 1 << " ";
                cin >> grades[i];
            }
            st.insert(name, id, grades);
            break;
        }
        case 2: {
            cout << "Enter student name you want to search: ";
            cin.ignore();
            getline(cin, name);
            st.search(name);
            break;
        }
        case 3: {
            st.display();
            break;
        }
        case 4: {
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter date: ";
            cin >> date;
            st.markAttendance(name, date);
            break;
        }
        case 5: {
            cout << "Enter date: ";
            cin >> date;
            st.displayAttendance(date);
            break;
        }
        case 6: {
            cout << "Enter student name you want to delete: ";
            cin.ignore();
            getline(cin, name);
            st.deleteNode(name);
            break;
        }
        case 7: {
            st.undoDelete();
            break;
        }

        case 8: {
            cout << "Average GPA: " << st.averageGPA() << endl;
            break;
        }
        case 9: {
            cout << "Exiting program.\nAcha chalta hoon duaon mei yaad rkhna" << endl;
            break;
        }
        default: {
            cout << "Invalid input." << endl;
            break;
        }
        }
    }
}