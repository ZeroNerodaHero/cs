#include<iostream>

int main() {

    std::cout << "Please Type a number: " << std::flush;
    int num1;
    std::cin >> num1;

    std::cin.putback(num1);

    int num2;
    std::cin >> num2;

    std::cout << num1 <<"\t"<<num2<< std::endl; //Why doesnt num1 and num2 output the same value?

    return 0;
}
