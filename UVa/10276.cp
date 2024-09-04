#include<iostream>
#include<cmath>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ans[51] = { -1, 1, 3, 7, 11, 17, 23, 31, 39, 49, 59, 71, 83, 97, 111, 127, 143, 161, 179, 199, 219, 241, 263, 287, 311, 337, 363, 391, 419, 449, 479, 511, 543, 577, 611, 647, 683, 721, 759, 799, 839, 881, 923, 967, 1011, 1057, 1103, 1151, 1199, 1249, 1299 };

	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;

		cout << ans[n] << endl;
		/*ll p[50] = { 0 };
		int ans = 1;
		while(true) {
			bool f = false;
			for(int j = 0; j < n && !f; j++) {
				if (!p[j] || (ll)sqrt(p[j] + ans) * (ll)sqrt(p[j] + ans) == p[j] + ans) {
					p[j] = ans;
					f = true;
				}
			}
			if (!f)
				break;
			ans++;
		}

		cout << ans - 1 << endl;*/
	}

	return 0;
}