#include <iostream>
#include <cstring>

using namespace std;

int primes[1121], pn;
int mem[1121][1121][15];

int dp(int i, int n, int k){
    if(!n && !k)
        return 1;
    if(n < 0 || i == pn || !k)
        return 0;
    if(mem[i][n][k] == -1)
        mem[i][n][k] = dp(i + 1, n, k) + dp(i + 1, n - primes[i], k - 1);
    return mem[i][n][k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    bool isp[1121] = { false };
    isp[0] = isp[1] = 1;
    for(int i = 2; i * i < 1121; i++)
        if(!isp[i])
            for(int j = i * i; j < 1121; j += i)
                isp[j] = 1;
    pn = 0;
    for(int i = 2; i < 1121; i++)
        if(!isp[i])
            primes[pn++] = i;
    memset(mem, 0xff, sizeof(mem));

    int n, k;
    while(cin >> n >> k && n + k)
        cout << dp(0, n, k) << endl;

    return 0;
}