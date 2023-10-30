#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<climits>

using namespace std;

#define endl '\n'
#define pb push_back

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> adj[8];

	string in;
	while(cin >> in && in != "#") {
		int len = -1;
		for(int i = 0; i < in.length(); i++) {
			int j = in[i++] - 'A';
			len = max(len, j);
			while(++i < in.length() && in[i] != ';') {
				int k = in[i] - 'A';
				len = max(len, k);
				adj[j].pb(k);
			}
		}
		if (len < 0) break;

		int perm[++len], revperm[len], minperm[len], minb = INT_MAX;
		iota(perm, perm + len, 0);
		do {
			for(int i = 0; i < len; i++) revperm[perm[i]] = i;
			int maxb = 0;
			for(int i = 0; i < len; i++) {
				for(int j : adj[perm[i]]) maxb = max(abs(revperm[j] - i), maxb);
			}
			if (maxb < minb) {
				minb = maxb;
				copy(perm, perm + len, minperm);
			}
		} while(next_permutation(perm, perm + len));

		for(int i : minperm) cout << (char)(i+'A') << " ";
		cout << "-> " << minb << endl;
	}

	return 0;
}