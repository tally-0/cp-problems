#include<iostream>
#include<queue>

using namespace std;

#define endl '\n'
typedef pair<int, int> ii;

class comp {
	public:
	bool operator() (const ii& lhs, const ii& rhs) const {
		return ((lhs.first - 1) / lhs.second + 1) > ((rhs.first - 1) / rhs.second + 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, b;
	while(cin >> n >> b && n != -1 || b != - 1) {
		priority_queue<ii, vector<ii>, comp> pq;

		for(int i = 0, a; i < n; i++) {
			cin >> a;
			pq.push({ a, 1 });
		}

		b -= n;
		for(int i = 0; i < b; i++) {
			ii a = pq.top();
			pq.pop();
			a.second++;
			pq.push(a);
		}
	
		cout << ((pq.top().first - 1) / pq.top().second + 1) << endl;
	}

	return 0;
}