#include<iostream>
#include<cmath>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, h[100001];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> h[i];

	int mem[100001];
	mem[0] = 0;
	mem[1] = abs(h[0] - h[1]);
	for(int i = 2; i < n; i++)
		mem[i] = min(abs(h[i - 1] - h[i]) + mem[i - 1], abs(h[i - 2] - h[i]) + mem[i - 2]);
	cout << mem[n - 1];

	return 0;
}