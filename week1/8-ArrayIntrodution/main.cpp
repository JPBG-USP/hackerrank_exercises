#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


int main() {
    int array_size;
    scanf("%d", &array_size);
    
    int* arr = new int[array_size];
    
    int data;
    for (int i = 0; i < array_size; i ++) {
        scanf("%d ", &data);
        arr[i] = data;
    }
    for (int i = array_size-1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }   
}
