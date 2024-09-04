#include<iostream>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a[100000];
	ll t, s = 0;
	cin >> n >> t;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}

	int i = 0;
	t %= s;
	while(t > a[i]) {
		t -= a[i];
		i = (i + 1) % n;
	}

	cout << i + 1 << " " << t;

	return 0;
}