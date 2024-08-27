#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> k;
	while(k--) {
		cin >> n;

		int last = 0, ans = 0, a;
		while(n--) {
			cin >> a;
			if (a != last + 1)
				ans++;
			else
				last++;
		}
		
		cout << ans;
	}

	return 0;
}