#include <bits/stdc++.h>
int main(){int n,i;std::cin>>n;for(i=1;i<=n;i++)std::cout<<(i%7?(i%11?std::to_string(i):"Super!"):(i%11?"Hurra!":"Wiwat!"))<<'\n';}