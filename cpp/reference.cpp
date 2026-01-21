#include <iostream>
#include <vector>

void addFifty(int& value) {
    value += 50;
}

int main() {
    int a = 50;
    int& ref = a;

    std::cout << "Ref: " << ref << std::endl;

    addFifty(ref);
    std::cout << "after ref: " << ref << std::endl;
    std::cout << "after a: " << a << std::endl;

    ref = 7;
    std::cout << "Ref: " << ref << std::endl;
    std::cout << "a: " << a << std::endl;

    std::vector<int> vec = {1,2,3,4,5};
    for(auto num : vec) {
        num = num * 10 ;
    }

    for(auto num : vec) {
        std::cout << " - " << num << std::endl;
    }
    return 0;

}