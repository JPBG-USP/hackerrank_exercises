#include <sstream>
#include <vector>
#include <iostream>

std::vector<int> parseInts(std::string str) {
	char ch;
    int value;
    std::vector<int> result;
    
    std::stringstream ss(str);
    
    while (!ss.eof()) {
        ss >> value >> ch;
        result.push_back(value);
    }
    
    return result;
}

int main() {
    std::string str;
    std::cin >> str;
    std::vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        std::cout << integers[i] << "\n";
    }
    
    return 0;
}