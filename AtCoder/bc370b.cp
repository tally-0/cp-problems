#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a[101][101];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			cin >> a[i][j];
	int i = 1;
	for(int j = 1; j <= n; j++)
		i = a[max(i, j)][min(i, j)];

	cout << i;

	return 0;
}