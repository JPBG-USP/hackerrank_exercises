#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>


int main() {
    // setting variables
    int length, queries;
    std::vector<std::vector<int>> vector;

    // scan length of vector "a" and total queries
    scanf("%d %d", &length, &queries);

    // for each variable sized array
    for (int i = 0; i < length; i++) {
        int k;
        // get the size of that variable
        scanf("%d", &k);

        // get the values of a[i][j]
        std::vector<int> temp;
        for (int j = 0; j < k; j++) {
            int value;
            scanf("%d", &value);
            temp.push_back(value);
        }

        vector.push_back(temp);
    }

    // Queries
    for (int k = 0; k < queries; k++) {
        int i, j;
        scanf("%d %d", &i, &j);
        printf("%d\n", vector[i][j]);
    }

    return 0;
}
