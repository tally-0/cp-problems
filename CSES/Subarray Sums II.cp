#include<iostream>
#include<map>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;

	map<ll, int> sarrs;
	ll s = 0, ans = 0;
	sarrs[0] = 1;
	while(n--) {
		int a;
		cin >> a;
		s += a;
		ans += sarrs[s-x];
		sarrs[s]++;
	}

	cout << ans << endl;

	return 0;
}