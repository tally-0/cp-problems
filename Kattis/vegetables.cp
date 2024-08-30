#include<iostream>
#include<queue>

using namespace std;

#define endl '\n'
typedef pair<double,double> dd;

class comp {
	public:
	bool operator() (const dd& l, const dd& r) {
		return l.first / l.second < r.first / r.second;
	};
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	double t;
	int n;
	cin >> t >> n;
	priority_queue<dd, vector<dd>, comp> w;
	double m = 10000000, a;
	for(int i = 0; i < n; i++) {
		cin >> a;
		m = min(a, m);
		w.push({ a, 1 });
	}

	int ans = 0;
	while(m * w.top().second / w.top().first < t) {
		m = min(m, w.top().first / (w.top().second + 1));
		w.push({ w.top().first, w.top().second + 1 });
		w.pop();
		ans++;
	}

	cout << ans;

	return 0;
}