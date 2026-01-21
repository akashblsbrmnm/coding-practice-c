#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {12,42,54,23,654,232};
    vec.push_back(89);

    int first = -1;
    int second = -1;

    for(auto num : vec) {
        if(num > first) {
            second = first;
            first = num;
        }
        else if(num > second && second < first) {
            second = num;
        }
    }

    std::cout << "First Largest: " << first << std::endl;
    std::cout << "Second Largest: " << second << std::endl;
    return 0;
}