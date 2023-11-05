#include<iostream>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll r[200000] = { 0 }, ans = 0;
	r[0] = 1;
	int cr = 0;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		cr = ((cr + a) % n + n) % n; // for neg
		ans += r[cr];
		r[cr]++;
	}

	cout << ans;

	return 0;
}