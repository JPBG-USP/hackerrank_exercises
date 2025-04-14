#include <iostream>
#include <cstdio>
using namespace std;

int max_of_four(int a, int b, int c, int d){
  
  int temp1 , temp2;
  
  if (a > b) {
    temp1 = a;
  }else {
    temp1 = b;
  }
  
  if (c > d){
    temp2 = c;
  }else {
    temp2 = d;
  }
  
  if (temp1 > temp2){
    return  temp1;
  }
    return  temp2;
};

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
