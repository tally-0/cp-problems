
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

#define endl '\n'
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m;
	while(cin >> m) {
		vpii a, b;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < m; j++) {
				char c;
				cin >> c;
				if (c == '3')
					a.push_back({ i, j });
				else if (c == '1')
					b.push_back({ i, j });
			}
		}

		int ans = 1;
		for(const pii &c : b) {
      		int e = INT_MAX;
			for(const pii &d : a)
				e = min(e, (abs(c.first - d.first) + abs(c.second - d.second)));
      		ans = max(ans, e);
    	}

		cout << ans << endl;
	}

	return 0;
}