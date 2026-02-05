#include <iostream>
#include <unordered_set>
#include <vector>

std::string removeDuplicatesFromString(const std::string& str) {
    std::unordered_set<char> seen;
    std::string result;
    for (char ch : str) {
        if (seen.find(ch) == seen.end()) {
            seen.insert(ch);
            result += ch;
        }
    }
    return result;
}

std::vector<int> removeDuplicatesFromVector(const std::vector<int>& vec) {
    std::unordered_set<int> seen;
    std::vector<int> result;
    for (int num : vec) {
        if (seen.find(num) == seen.end()) {
            seen.insert(num);
            result.push_back(num);
        }
    }
    return result;
}

int main() {
    std::string input = "programming";
    std::string output = removeDuplicatesFromString(input);
    std::cout << "Original string: " << input << std::endl;
    std::cout << "String after removing duplicates: " << output << std::endl;

    std::vector<int> vec = {1, 2, 2, 3, 4, 4, 5};
    std::vector<int> vecOutput = removeDuplicatesFromVector(vec);
    std::cout << "Original vector: ";
    for (auto& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Vector after removing duplicates: ";
    for (auto& num : vecOutput) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}