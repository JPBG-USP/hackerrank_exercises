#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


int main() {
    
    std::vector<int> int_vector;
    int vector_size;

    std::cin >> vector_size;

    for (int i = 0; i < vector_size; i++)
    {
        int num;
        std::cin >> num;
        int_vector.push_back(num);
    }

    std::sort(int_vector.begin(), int_vector.end());

    for (int i = 0; i < vector_size; i++)
    {
        std::cout << int_vector[i] << " ";
    }
    
    return 0;
}
