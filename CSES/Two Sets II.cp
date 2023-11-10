#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int n;
int mem[501][125251];

int dp(int i, int rs) {
	if (rs == 0)
		return 1;
	if (i == n)
		return 0;
	if (mem[i][rs] == -1) {
		if (i > rs)
			mem[i][rs] = 0;
		else
			mem[i][rs] = (dp(i + 1, rs - i) + dp(i + 1, rs)) % 1000000007;
	}
	return mem[i][rs];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	if (n * (n + 1) % 4) {
		cout << 0;
		return 0;
	}
	memset(mem, -1, sizeof(mem));
	cout << dp(1, n * (n + 1) / 4);

	return 0;
}