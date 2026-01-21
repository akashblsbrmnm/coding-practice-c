#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<int> v = {354,1343,6542,134,53,786,54};
    v.push_back(14232);
    v.push_back(234);
    for(auto num : v)
        std::cout << num << std::endl;

    std::vector<std::string> names;
    names.push_back("Sam");
    names.push_back("Alice");
    names.push_back("John");

    for(auto num : names)
        std::cout << num << std::endl;

    int max = v[0];
    std::cout << "Initial elem: " << max << std::endl;
    for (const auto& num : v)
    {
        if(num > max)
            max = num;
    }
    std::cout << "Max Element is: " << max << std::endl;
    return 0;
}
