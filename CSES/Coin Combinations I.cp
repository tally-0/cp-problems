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

	int mem[1000001] = { 0 };
	mem[0] = 1;
	for(int i = 1; i <= x; i++)
		for(int j = 0; j < n; j++)
			if (i >= c[j])
				mem[i] = (mem[i] + mem[i - c[j]]) % 1000000007;

	cout << mem[x];

	return 0;
}