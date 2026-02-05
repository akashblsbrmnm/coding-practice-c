
#include <iostream>
class Person {
    private:
        std::string name;
        int age;
        int uid;
    public:
        Person(std::string name, int age, int uid) : name(name), age(age), uid(uid) {};
        friend void GetInfo(Person& p);
        void SetAge(int age) {
            this->age = age;
        }
};

void GetInfo(Person& p) {
    std::cout << "Name: " << p.name << std::endl;
    std::cout <<"UID: "<< p.uid << std::endl;
    std::cout <<"Age: "<< p.age << std::endl;
}

int main()
{
    Person p("Sam", 45, 112812);
    Person p2 = p;
    p2.SetAge(67);
    GetInfo(p);
    GetInfo(p2);
    return 0;
}