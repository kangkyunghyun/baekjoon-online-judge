#include <bits/stdc++.h>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    a--, b--;
    while ((a/=2) != (b/=2)) answer++;
    return answer;
}