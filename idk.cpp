#include <iostream>

int Fact(int n){
    if (n < 2) return 1;
    return n * Fact(n -1);
}

int main(){
    int x;
    std::cin >> x;
    std::cout << Fact(x) << std::endl;
}7