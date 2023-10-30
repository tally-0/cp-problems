#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n;
	string scenes[6];
	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> scenes[i];
		sort(scenes, scenes + n);
		int minlen = INT_MAX;
		do {
			string movie = scenes[0];
			for(int i = 1; i < n; i++) {
				int s = max(0, (int)(movie.length() - scenes[i].length()));
				for(int j = s; j <= movie.length(); j++) {
					bool f = true;
					for(int k = 0; k < scenes[i].length() && (j + k < movie.length()); k++) {
						if (scenes[i][k] == movie[j + k])
							continue;
						f = false;
						break; 
					}
					if (f) {
						for(int k = movie.length() - j; k < scenes[i].length(); k++)
							movie += scenes[i][k];
						break;
					}
				}
			}
			minlen = min(minlen, (int)movie.length());
		} while(next_permutation(scenes, scenes + n));

		cout << "Case " << tc << ": " << minlen << endl;
	}

	return 0;
}