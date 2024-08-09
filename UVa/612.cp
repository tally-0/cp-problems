#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int inversions;

string mergesort(string s, int l, int r) {
	if (r <= l)
		return s;
	int m = (l + r) / 2;
	string ls = mergesort(s, l, m);
	string rs = mergesort(s, m + 1, r);
	int li = l, ri = m + 1, gi = l;
	while(li <= m && ri <= r) {
		if (ls[li] <= rs[ri])
			s[gi++] = ls[li++];
		else {
			s[gi++] = rs[ri++];
			inversions += m - li + 1;
		}
	}
	while(li <= m)
		s[gi++] = ls[li++];
	while(ri <= r)
		s[gi++] = rs[ri++];
	return s;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string dnas[101];
	pair<int, int> pos[101];
	int M, n, m;
	cin >> M;
	while(M--) {
		cin >> n >> m;
		for(int i = 0; i < m; i++) {
			cin >> dnas[i];
			inversions = 0;
			mergesort(dnas[i], 0, n);
			pos[i].first = inversions;
			pos[i].second = i;
		}
		sort(pos, pos + m);
		for(int i = 0; i < m; i++)
			cout << dnas[pos[i].second] << endl;
		if (M)
			cout << endl;
	}

	return 0;
}