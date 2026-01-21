#include <iostream>
#include <memory>

class Person {
    private:
        int age;

    public:
        Person(int age) {
            std::cout << "Person Class" << std::endl;
            this->age = age;
        }
        virtual void Say()  = 0;
        ~Person() = default;
};

class Student : public Person {
    public:
        Student(int age) : Person(age) {};
        void Say()  override {
            std::cout << "Student says Hello!" << std::endl;
        }
};

class Worker : public Person {
    public:
        Worker(int age) : Person(age) {};
        void Say()  override {
            std::cout << "Worker says Hello!" << std::endl;
        }
};

void greet(Person& p) {
    p.Say();
}

int main() {
    Student s(18);
    Worker w(45);
    greet(s);
    greet(w);
    return 0;
}