#include<iostream>
#include<cstring>

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
	for(int i = 0; i < n; i++)
		for(int j = 1; j <= x; j++)
			if (j >= c[i])
				mem[j] = (mem[j] + mem[j - c[i]]) % 1000000007;

	cout << mem[x];

	return 0;
}