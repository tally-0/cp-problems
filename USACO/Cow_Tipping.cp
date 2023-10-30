#include<iostream>
#include<vector>
#include<string>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);

	int n;
	cin >> n;
	vector<string> v(n);
	for(string &i : v) cin >> i;
	
	int flips = 0;
	bool isInv = false;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if ((isInv && v[i][j] == '0') || (!isInv && v[i][j] == '1')) {
				flips++;
				isInv = !isInv;
			}
		}
	}
	cout << flips << endl;

	return 0;
}