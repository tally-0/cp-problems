#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x[100], s = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x[i];
		s += x[i];
	}

	bool mem[100000] = { false };
	mem[0] = true;
	for(int i = 0; i < n; i++)
		for(int j = s - x[i]; j >= 0; j--)
			mem[j + x[i]] |= mem[j];

	int ans = 0;
	for(int i = 1; i <= s; i++)
		if (mem[i])
			ans++;

	cout << ans << endl;
	for(int i = 1; i <= s; i++)
		if (mem[i])
			cout << i << " ";

	return 0;
}