#include <iostream>
#include <cstdio>
#include <map>

int main() {
    
    unsigned int a, b;
    std::map<int, std::string> number_names;
    number_names[1] = "one";
    number_names[2] = "two";
    number_names[3] = "three";
    number_names[4] = "four";
    number_names[5] = "five";
    number_names[6] = "six";
    number_names[7] = "seven";
    number_names[8] = "eight";
    number_names[9] = "nine";
    
    scanf("%d \n %d", &a, &b);
    
    for (int i = 0; i < (b-a+1); i++) {
        if ((a+i) <= 9) {
            printf("%s\n", number_names[(a+i)].c_str());
        }else {
            if ((a+i) % 2) {
                printf("odd\n");
            }else {
                printf("even\n");
            }
        }
    }
    
        
    return 0;
}
