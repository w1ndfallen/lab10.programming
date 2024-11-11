#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    string name;
    int age;
    float gpa;
};

void saveStudentToFile(const Student &student, const string &filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    file << "Name: " << student.name << endl;
    file << "Age: " << student.age << endl;
    file << "GPA: " << student.gpa << endl;
    file << "----------------------" << endl;
    file.close();
}

int main() {
    Student student1;
    cout << "Enter student's name: ";
    getline(cin, student1.name);
    cout << "Enter student's age: ";
    cin >> student1.age;
    cout << "Enter average student's grade (GPA): ";
    cin >> student1.gpa;

    string filename = "students.txt";

    saveStudentToFile(student1, filename);

    cout << "The student's data is recorded in a file " << filename << endl;

    return 0;
}
