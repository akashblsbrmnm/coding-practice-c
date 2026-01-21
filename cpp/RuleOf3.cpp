#include <iostream>
#include <cstring>
using namespace std;

class Movie {
public:
    char* title;

    Movie(const char* t) {
        title = new char[strlen(t)+1];
        strcpy(title, t);
    }

    // Destructor
    ~Movie() {
        cout << "Destructor called" <<endl;
        delete[] title;
    }

    // Copy constructor
    Movie(const Movie& other) {
        cout << "Copy constructor is called" << endl;
        title = new char[strlen(other.title)+1];
        strcpy(title, other.title);
    }

    // Copy assignment operator
    Movie& operator=(const Movie& other) {
        cout << "Copy assignment operator is called" << endl;
        if (this == &other) return *this;

        delete[] title;
        title = new char[strlen(other.title)+1];
        strcpy(title, other.title);

        return *this;
    }

};


int main() {
    Movie m1("Inception");
    Movie m2("Interstellar");

    cout << "m1.title: " << m1.title << endl;
    cout << "m2.title: " << m2.title << endl;

    m2 = m1;
    cout << "m2.title: " << m2.title << endl;

    Movie m3 = m1;
    cout << "m3.title: " << m2.title << endl;

    return 0;
}
