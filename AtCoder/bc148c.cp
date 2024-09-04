#include<iostream>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;
	for(ll i = max(a, b); i <= a * b; i += max(a, b)) {
		if (i % min(a, b) == 0) {
			cout << i;
			return 0;
		}
	}

	return 0;
}