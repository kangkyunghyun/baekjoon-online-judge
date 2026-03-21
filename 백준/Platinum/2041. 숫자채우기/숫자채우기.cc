#include<iostream>
int main(){int n,m;std::cin>>n>>m;int a=1,b=2*n*m-n-m+1,i=0,j;for(;i<n;i++){for(j=0;j<m;j++)std::cout<<((i+j)%2?b--:a++)<<' ';a+=m/2;b-=m/2;if(m%2==0)i%2?a--:b++;std::cout<<'\n';}}