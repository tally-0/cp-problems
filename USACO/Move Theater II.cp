#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define vii vector<pair<int, int>>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vii movies(n);
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		movies[i] = make_pair(b, a); // inverted to make sorting easier
	}

	sort(movies.begin(), movies.end());

	int total = 0;
	multiset<int> ends;
	for (auto movie : movies) {
		if (!ends.size()) {
			ends.insert(-movie.first);
			total++;
		} else {
			auto it = ends.lower_bound(-movie.second);
			if (it == ends.end()) {
				if (ends.size() < k) {
					ends.insert(-movie.first);
					total++;
				}
			} else {
				ends.erase(it);
				ends.insert(-movie.first);
				total++;
			}
		}
	}

	cout << total;

	return 0;
}