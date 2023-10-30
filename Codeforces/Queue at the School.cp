#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t;
	string a;
	cin >> n >> t >> a;
	while(t--) {
		for (int i = 0; i < a.size() - 1; i++) {
			if (a[i] == 'B' && a[i + 1] == 'G') {
				a[i] = 'G';
				a[++i] = 'B';
			}
		}
	}
	cout << a << endl;

	return 0;
}