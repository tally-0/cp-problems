#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int a[1000001], aux[1000001];

long long inversions(int l, int r) {
	if (r <= l)
		return 0;
	int m = (r + l) / 2;
	long long swaps = inversions(l, m) + inversions(m + 1, r);
	int li = l, ri = m + 1, gi = 0;
	while(li <= m && ri <= r) {
		if (a[li] <= a[ri])
			aux[gi++] = a[li++];
		else {
			aux[gi++] = a[ri++];
			swaps += m - li + 1;
		}
	}
	if (li <= m)
		memcpy(aux + gi, a + li, (m - li + 1) * sizeof(int));
	else if (ri <= r)
		memcpy(aux + gi, a + ri, (r - ri + 1) * sizeof(int));
	memcpy(a + l, aux, (r - l + 1) * sizeof(int));
	return swaps;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while(cin >> n && n) {
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << inversions(0, n - 1) << endl;
	}	

	return 0;
}