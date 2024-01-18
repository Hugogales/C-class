#include <iostream>

int main() {
    int num;
    std::cout << "Please enter a number: " << std::endl ;
    std::cin >> num;
    std::cout << "The cube of "<< num << " is " << num*num*num << std::endl;
    return 0;
}
