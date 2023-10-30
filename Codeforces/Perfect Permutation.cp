#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);

	if (n % 2) cout << -1;
	else {
		cout << 2 << " " << 1;
		for(int i = 3; i <= n; i += 2) cout << " " << i+1 << " " << i;
	}

	return 0;
}