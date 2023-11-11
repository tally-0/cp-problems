#include <iostream>
#include <cstring>

using namespace std;

#define endl '\n'

int t, a, b;
int mem[5000000][2];

int dp(int f, bool u){
	if(mem[f][u] != -1)
		return mem[f][u];
	if(f > t)
		return 0;
	mem[f][u] = f;
	mem[f][u] = max(mem[f][u], dp(f + a, u));
	mem[f][u] = max(mem[f][u], dp(f + b, u));
	if(!u)
		mem[f][u] = max(mem[f][u], dp(f / 2, true));
	return mem[f][u];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    freopen("feast.in","r",stdin);
    freopen("feast.out","w",stdout);

	cin >> t >> a >> b;
	memset(mem, -1, sizeof(mem));
	cout << dp(0,0);

	return 0;
}