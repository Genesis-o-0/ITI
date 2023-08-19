#include <iostream>
#include <cstring>
using namespace std;

// base Class Person
class Person
{
private:
    char name[50];
    int id;
    int age;

public:
    // Default Constructor
    Person()
    {
        strcpy(name, "Unknown");
        id = 0;
        age = 0;
        cout << "Default constructor is called!\n";
    }
    // Parameterized constructor
    Person(const char _name[], int _id, int _age)
    {
        strcpy(name, _name);
        id = _id;
        age = _age;
    }
    // setting age
    void setAge(int _age)
    {
        age = _age;
    }
    // getting age
    int getAge()
    {
        return age;
    }
    // Setting id
    void setId(int _id)
    {
        id = _id;
    }
    // getting id
    int getId()
    {
        return id;
    }
    // setting name
    void setName(const char _name[])
    {
        strcpy(name, _name);
    }
    // getting name
    char* getName()
    {
        return name;
    }

    //Display Info
    void Display()
    {
        cout << "******The Person Data******\n";
        cout << "Name: " << name << ", Age: " << age << ", ID: " << id << endl;
    }

};

// Derived Class
class Student : public Person
{
private:
    int level;
    float GPA;
    char depart[100];
public:
    // Default Constructor
    Student()
    {
        level = 0;
        GPA = 0.0f;
        strcpy(depart, "Unknown");
    }
    // Parameterized constructor for the derived class
    Student(const char _name[], int _id, int _age, int _lev, float _GP,const char _depar[]) : Person(_name, _id, _age)
    {
        level = _lev;
        GPA = _GP;
        strcpy(depart, _depar);
    }
    // Setter
    void setLevel(int _level)
    {
        level = _level;
    }

    void setGPA(float _GPA)
    {
        GPA = _GPA;
    }

    void setDepart(const char _depart[])
    {
        strcpy(depart, _depart);
    }

    // Getter
    int getLevel()
    {
        return level;
    }

    float getGPA()
    {
        return GPA;
    }

    char* getDepart()
    {
        return depart;
    }

    // Overriding
    void Display()
    {
        // Re-usability of the base class member functions
        Person::Display();
        cout << "Level: " << level << " ,GPA: " << GPA << " ,Department: " << depart << endl;
    }
};

// Another class that inherits from 2 classes ( 1 base class and 1 derived class)
class postGraduateStudent : public Student
{
    char *researchInterest;

public:
    // Constructor
    postGraduateStudent(const char _name[], int _id, int _age, int _lev, float _GP,const char _depar[], const char _interest[]) : Student(_name, _id, _age, _lev, _GP, _depar)
    {
        researchInterest = new char [strlen(_interest) + 1];
        strcpy(researchInterest, _interest);
    }


    // Methods
    void setResearchInterest(const char interest[])
    {
        researchInterest = new char[strlen(interest) + 1];
        strcpy(researchInterest, interest);
    }
    char* getResearchInterest()
    {
        return researchInterest;
    }

    void Display()
    {
        Student::Display();
        cout << "Research Interest: " << researchInterest << endl;
    }


    // De-Constructor to delete the Dynamic array in heap (researchInterest)
    ~postGraduateStudent()
    {
        delete researchInterest;
    }
};







int main()
{
    /*
    // Testing Base Class Person
    Person Mohamed;
    cout << Mohamed.getName() << endl;
    cout << Mohamed.getId() << endl;
    cout << Mohamed.getAge() << endl;
    cout << "**************After setting**************" << endl;
    // Setting
    Mohamed.setAge(27);
    Mohamed.setId(1000);
    Mohamed.setName("Mohamed");
    // Reprinting
    cout << Mohamed.getName() << endl;
    cout << Mohamed.getId() << endl;
    cout << Mohamed.getAge() << endl;
    cout << "***************parameterized Constructor***************" << endl;
    // parameterized Constructor
    Person Aliaa("Aliaa", 1001, 29);
    cout << Aliaa.getName() << endl;
    cout << Aliaa.getId() << endl;
    cout << Aliaa.getAge() << endl;*/

    /*
    // Student Class
    Student Aliaa("Aliaa", 1000, 29, 3, 2.1, "Chemist");
    Aliaa.Display();
    */

    // PostGraduateStudent Class
    postGraduateStudent s1("Mohamed", 2000, 28, 4, 2.9, "Engineering", "Front-End");
    s1.Display();
    return 0;
}
