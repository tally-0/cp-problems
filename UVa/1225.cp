#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int c[10] = {};
		for(int i = 1; i <= n; i++) {
			if (i >= 10) c[floor(i/10)%10+'0']++;
			c[i%10+'0']++;
		}
		for(int d : c) cout << d << " ";
		cout << endl;
	}

	return 0;
}