#include <iostream>
using namespace std;

class Student {
    private:
        string name;
        string surName;
        int age;
    public:
        Student(string studentName, string studentSurName, int studentAge) {
            name = studentName;
            surName = studentSurName;
            age = studentAge;
        }

        void getStudentDetails() {
            cout<<"The name of student is: "<<name<<endl;
            cout<<"The sur name of student is: "<<surName<<endl;
            cout<<"The age of student is: "<<age<<endl;
        }
};

int main() {
    Student obj = new Student("Parush", "ABC", 29);
    obj.getStudentDetails();
    return 0;
}