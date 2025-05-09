#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::vector<int> int_vector;
    int vector_size;

    std::cin >> vector_size;

    for (int i = 0; i < vector_size; i++) {
        int num;
        std::cin >> num;
        int_vector.push_back(num);
    }  

    int erase_index;
    std::cin >> erase_index;
    int_vector.erase(int_vector.begin() + (erase_index - 1)); 

    int range_min, range_max;
    std::cin >> range_min >> range_max;
    
    int_vector.erase(int_vector.begin() + (range_min - 1), int_vector.begin() + (range_max - 1));

    std::cout << int_vector.size() << std::endl;
    for (size_t i = 0; i < int_vector.size(); i++) {
        std::cout << int_vector[i] << " ";
    }

    return 0;
}