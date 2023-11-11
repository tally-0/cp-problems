#include<iostream>
#include<climits>
#include<cstring>

using namespace std;

#define endl '\n'

int l, n, c[51];
int mem[51][51];

int dp(int cl, int cr) {
	if (mem[cl][cr] != -1)
		return mem[cl][cr];
	if (cr - cl == 1)
		return mem[cl][cr] = 0;
	mem[cl][cr] = INT_MAX;
	for(int i = cl + 1; i < cr; i++)
		mem[cl][cr] = min(mem[cl][cr], dp(cl, i) + dp(i, cr) + c[cr] - c[cl]);
	return mem[cl][cr];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> l && l) {
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> c[i];
		c[0] = 0;
		c[n + 1] = l;
		
		memset(mem, -1, sizeof(mem));
		cout << "The minimum cutting is " << dp(0, n + 1) << "." << endl;
	}

	return 0;
}