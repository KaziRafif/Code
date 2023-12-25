#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class User{
private:
    string name;
    int age;
public:
    void setUser(string n, int a) {
        name = n;
        age = a;
    }
    void getUser() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    User() {
        name = "Not Given";
        age = 0;
    }
    ~User() {
        cout << "User Destructor Called" << endl;
    }
};

class Student: public User{
private:
    string sID;
    vector<string> course;
public:
    void setStudent(string id) {
        sID = id;
    }
    void displayStudentInfo() {
        getUser();
        cout << "ID: " << sID << endl;
    }
    void displayCourses() {
        if(course.size()>1) {
            course.erase(course.begin());
        }
        cout << "Courses: " << endl;
        for(int i = 0; i<course.size(); i++) {
            cout << "Course Name: " << course[i] << endl;
        }
        cout << endl;
    }
    void addCourse(string c) {
        if(course.size()<=5) {
            course.push_back(c);
        } else {
            cout << "CANNOT ADD ANY MORE COURSES!" << endl << endl;
        }
    }
    Student() {
        sID = "Not Given";
        course = {"ERROR: STUDENT DOESN'T HAVE ANY COURSES YET!"};
    }
    ~Student() {
        cout << "Student Destructor Called" << endl;
    }
};

int main() {
    Student s1;
    string name, id;
    int age;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter ID: ";
    cin >> id;
    cout << endl << "-----------------Output-----------------" << endl;
    s1.setUser(name, age);
    s1.setStudent(id);
    s1.displayStudentInfo();
    s1.displayCourses();
    s1.addCourse("Physics");
    s1.addCourse("Chemistry");
    s1.addCourse("Math");
    s1.addCourse("Bangla");
    s1.addCourse("English");
    s1.addCourse("Engl");
    s1.displayCourses();


    return 0;
}
