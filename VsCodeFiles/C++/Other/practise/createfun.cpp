#include <iostream>
#include <string>
using namespace std;

class Person
{
    public:
    Person()
    {
        cout << "Ĭ�Ϲ��캯������" << endl;
    }

    Person(int age ,string name)
    {
        Age=age;
        Name=name;
        cout << "���κ�������" << endl;
    }

    Person(const Person &person)
    {
        cout << "�������캯������" << endl;
    }

    ~Person()
    {
        cout << "������������"  << endl;
    }

    private:
    int Age;
    string Name;
};
void test1()
{
    Person Jack;
}

void test2()
{
    Person Tom=Person(20,"Tom");
    Person Alis=Person(Tom);
}

int main(void)
{
    test1();

    test2();

    return 0;
}