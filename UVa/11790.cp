#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n;
	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		cin >> n;
		vi w(n), h(n);
		for(int &i : h)
			cin >> i;
		for(int &i : w)
			cin >> i;

		vi len(n);
		int mi = 0;
		for(int i = 0; i < n; i++) {
			len[i] = w[i];
			for(int j = 0; j < i; j++)
				if (h[i] > h[j])
					len[i] = max(len[i], len[j] + w[i]);
			mi = max(mi, len[i]);
		}
		int md = 0;
		for(int i = n - 1; i >= 0; i--) {
			len[i] = w[i];
			for(int j = i + 1; j < n; j++)
				if (h[i] > h[j])
					len[i] = max(len[i], len[j] + w[i]);
			md = max(md, len[i]);
		}

		cout << "Case " << tc << ".";
		if (md > mi)
			cout << " Decreasing (" << md << "). Increasing (" << mi << ").\n";
		else
			cout << " Increasing (" << mi << "). Decreasing (" << md << ").\n";
	}


	return 0;
}