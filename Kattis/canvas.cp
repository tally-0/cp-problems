#include<iostream>
#include<queue>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		priority_queue<ll> pq;
		for(int i = 0, s; i < n; i++) {
			cin >> s;
			pq.push(-s);
		}

		ll ans = 0;
		while(pq.size() > 1) {
			ll a = pq.top();
			pq.pop();
			a += pq.top();
			pq.pop();
			ans += a;
			pq.push(a);
		}

		cout << -ans << endl;
	}

	return 0;
}