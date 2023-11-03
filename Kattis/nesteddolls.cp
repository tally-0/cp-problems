#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, m;
	pii dolls[100001];
	cin >> t;
	while(t--) {
		cin >> m;
		for(int i = 0; i < m; i++)
			cin >> dolls[i].first >> dolls[i].second;
		sort(dolls, dolls + m, [](const pii &lhs, pii &rhs) {
    		if(lhs.first == rhs.first)
				return  lhs.second > rhs.second;
    		return lhs.first < rhs.first;
		});

		int mem[100001], len = 0;
		for(int i = m - 1; i >= 0; i--) {
			int j = upper_bound(mem, mem + len, dolls[i].second) - mem;
			mem[j] = dolls[i].second;
			if (j == len)
				len++;
		}

		cout << len << endl;
	}

	return 0;
}