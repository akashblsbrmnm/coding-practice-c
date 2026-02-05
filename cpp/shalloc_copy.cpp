#include <iostream>
#include <memory>

class Shallow {
public:
    int* data;

    Shallow(int value) {
        data = new int(value);
    }

    ~Shallow() {
        delete data;
    }
    
    void SetData(int value) {
        delete data;
        data = new int(value);
    }
};

class Deep {
public:
    int* data;

    Deep(int value) {
        data = new int(value);
    }

    // COPY CONSTRUCTOR
    Deep(const Deep& other) {
        data = new int(*other.data);
    }

    // COPY ASSIGNMENT
    Deep& operator=(const Deep& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    ~Deep() {
        delete data;
    }
};

int main() {
    Shallow a(10);
    Shallow b = a;   // 🚨 shallow copy
    b.SetData(7);

    std::cout << *a.data << std::endl;
    std::cout << *b.data << std::endl;

    std::unique_ptr<int> p3 = std::make_unique<int>(42);
    std::unique_ptr<int> p4 = p3;   // ❌ ERROR

    return 0; // 💥 double delete from shallow copy
}
