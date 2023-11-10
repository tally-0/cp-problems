#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x, c[100];
	cin >> n >> x;
	for(int i = 0; i < n; i++)
		cin >> c[i];

	int mem[1000001];
	mem[0] = 0;
	for(int i = 1; i <= x; i++) {
		mem[i] = 2000000;
		for(int j = 0; j < n; j++)
			if (c[j] <= i)
				mem[i] = min(mem[i], 1 + mem[i - c[j]]);
	}
	cout << (mem[x] < 2000000 ? mem[x] : -1);

	return 0;
}