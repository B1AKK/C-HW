#include <iostream>
#include <cstring>

using namespace std;

class Person
{
    char gender;
    string name;
    unsigned age;
public:
    Person() {}
    Person(string str, char c, unsigned n): name(str), gender(c), age(n) {}

    void input()
    {
        cout << "name: ";
        cin >> name;
        cout << "gender: ";
        cin >> gender;
        cout << "age: ";
        cin >> age;
    }

    void show()
    {
        cout << "name: " << name << endl;
        cout << "gender: " << gender << endl;
        cout << "age: " << age << endl;
    }
};

class Student: public Person
{
    int year;
    string group;
    string univ;
public:

    void input()
    {
        Person::input();
        cout << "year: ";
        cin >> year;
        cout << "group: ";
        cin >> group;
        cout << "univ: ";
        cin >> univ;
    }

    void show()
    {
        Person::show();
        cout << "year: " << year << endl;
        cout << "group: " << group << endl;
        cout << "univ: " << univ << endl;
    }
};

int main()
{
    Person p;
    p.input();
    p.show();
    Student st;
    st.input();
    st.show();
}

