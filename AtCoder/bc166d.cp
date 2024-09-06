#include<iostream>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll x;
	cin >> x;
	for(ll a = -127; a <= 127; a++) {
		for(ll b = -127; b <= 127; b++) {
			if (a * a * a * a * a - b * b * b * b * b == x) {
				cout << a << " " << b;
				return 0;
			}
		}
	}

	return 0;
}