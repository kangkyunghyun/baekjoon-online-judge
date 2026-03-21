#include <iostream>
int main(){char c;int a=0,i=0;for(;i<6;i++){std::cin>>c;c=='W'?a++:0;}std::cout<<(a?4-(a+1)/2:-1);}