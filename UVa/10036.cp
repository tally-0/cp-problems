#include <bits/stdc++.h>
using namespace std;

int k, n, arr[10000];
int mem[10000][200];

bool dp(int i,int mod) {
    if(i == n)
		return (mod == 0);
	if (mem[i][mod + k] != -1)
		return mem[i][mod + k];
	mem[i][mod + k] = (dp(i + 1, (mod + arr[i]) % k) || dp(i + 1, (mod - arr[i]) % k));
    return mem[i][mod + k];
}

int main() {
    int m;
	cin >> m;
    while(m--) {
		cin >> n >> k;
        for(int i = 0; i < n; i++) 
			cin >> arr[i];

        memset(mem, -1, sizeof(mem));
        if(dp(0, 0))
			cout << "Divisible\n";
        else
			cout << "Not divisible\n";
    }
    return 0;
}