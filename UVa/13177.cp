#include<iostream>
#include<queue>

using namespace std;

#define endl '\n'
typedef pair<int, int> pii;

auto comp = [](const pii& l, const pii& r) {
	return (float)l.first / (float)l.second < (float)r.first / (float)r.second;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int p, n;
	while(cin >> p >> n) {
		priority_queue<pii, vector<pii>, decltype(comp)> pq(comp);
		for(int i = 0, a; i < n; i++) {
			cin >> a;
			pq.push({ a, 1 });
		}
		p -= n;
		while(p) {
			pq.push({ pq.top().first, pq.top().second + 1 });
			pq.pop();
			p--;
		}
		cout << (pq.top().first - 1) / pq.top().second + 1 << endl;
	}

	return 0;
}