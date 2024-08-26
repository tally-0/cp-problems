#include<iostream>
#include<priority_queue>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while(cin >> n && n) {
		priority_queue<int, vector<int>, greater<int>> pq();
		for(int i = 0, a; i < n; i++) {
			cin >> a;
			pq.push(a);
		}

		int ans = 0, sum = pq.top();
		pq.pop();
		n--;
		while(n--) {
			sum += pq.top();
			ans += sum;
			pq.top();
		}

		cout << ans;
	}

	return 0;
}