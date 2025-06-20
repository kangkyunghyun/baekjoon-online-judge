// pow O(log N)
int pow(int a, int b) {
    if (b == 1)
        return a;
    if (b % 2)
        return a * pow(a * a, (b - 1) / 2);
    else
        return pow(a * a, b / 2);
}