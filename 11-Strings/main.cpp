#include <iostream>
#include <string>

int main() {
	std::string a,b;

    std::cin >> a;
    std::cin >> b;

    std::cout << a.size() << " " << b.size() << std::endl;

    std::cout << (a+b) << std::endl;

    char temp;

    temp = a[0];

    a[0] = b[0];

    b[0] = temp;

    std::cout << a << " " << b;

    return 0;
}