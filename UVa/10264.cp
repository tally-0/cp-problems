#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, w[32768], p[32768];
	while(cin >> n) {
		for(int i = 0; i < (1 << n); i++)
			cin >> w[i];
		for(int i = 0; i < (1 << n); i++) {
			int sum = 0;
			for(int j = 0; j < n; j++)
				sum += w[i ^ (1 << j)];
			p[i] = sum;
		}
		int ans = 0;
		for(int i = 0; i < (1 << n); i++)
			for(int j = 0; j < n; j++)
				ans = max(ans, p[i] + p[i ^ (1 << j)]);
		cout << ans << endl;
	}

	return 0;
}