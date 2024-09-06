#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

#define endl '\n'
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n;
	pii o[1100000];
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> o[i].second >> o[i].first;
		
		sort(o, o + n);
		priority_queue<int> pq;
		int c = 0;
		for(int i = 0; i < n; i++) {
			c += o[i].second;
			pq.push(o[i].second);
			if (c > o[i].first) {
				c -= pq.top();
				pq.pop();
			}
		}

		cout << pq.size() << endl;
		if (t)
			cout << endl;
	}

	return 0;
}