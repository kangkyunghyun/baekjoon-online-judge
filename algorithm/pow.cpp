// O(log N)
int pow(int n, int k, int mod) {
    int ret = 1, base = n % mod;
    while (k) {
        if (k % 2)
            ret = (ret * base) % mod;
        base = (base * base) % mod;
        k /= 2;
    }
    return ret;
}