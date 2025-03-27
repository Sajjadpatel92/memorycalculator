#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename U>
class Student {
private:
    T id;
    U name;

public:
    
    Student(T idValue, U nameValue) : id(idValue), name(nameValue) {}


    T getId() const { return id; }
    U getName() const { return name; }


    void setName(U newName) { name = newName; }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

template <typename T, typename U>
class StudentManager {
private:
    vector<Student<T, U>> students;

public:

    void addStudent(T id, U name) {
        students.push_back(Student<T, U>(id, name));
        cout << "Student added successfully!\n";
    }

    void removeStudent(T id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getId() == id) {
                students.erase(it);
                cout << "Student with ID " << id << " removed successfully!\n";
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }


    void searchStudent(T id) {
        for (const auto& student : students) {
            if (student.getId() == id) {
                cout << "Student found: ";
                student.display();
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }

  
    void displayAll() {
        if (students.empty()) {
            cout << "No students available.\n";
            return;
        }
        cout << "Student List:\n";
        for (const auto& student : students) {
            student.display();
        }
    }
};

int main() {
    StudentManager<int, string> manager;
    int choice, id;
    string name;

    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter Student Name: ";
                cin >> name;
                manager.addStudent(id, name);
                break;

            case 2:
                cout << "Enter Student ID to Remove: ";
                cin >> id;
                manager.removeStudent(id);
                break;

            case 3:
                cout << "Enter Student ID to Search: ";
                cin >> id;
                manager.searchStudent(id);
                break;

            case 4:
                manager.displayAll();
                break;

            case 5:
                cout << "Exiting Student Management System...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}