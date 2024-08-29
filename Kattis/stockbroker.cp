#include<iostream>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int d;
	cin >> d;

	ll m = 100;
	int o = 0, c, p;
	cin >> p;
	for(int i = 0; i < d - 1; i++) {
		cin >> c;
		int b;
		if (p < c)
			b = -min(m / (ll)p[i], 100000ll - (ll)o);
		else
			b = o;
		m += (ll)b * (ll)p[i];
		o -= b;
		c = p;
	}
	if (o)
		m += (ll)o * (ll)p[d - 1];

	cout << m;

	return 0;
}