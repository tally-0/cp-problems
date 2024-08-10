#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int seq[200001], aux[200001];

int mergesort(int l, int r) {
	if (r <= l)
		return 0;
	int m = (l + r) / 2;
	int swaps = mergesort(l, m) + mergesort(m + 1, r);
	int li = l, ri = m + 1, gi = 0;
	while(li <= m && ri <= r) {
		if (seq[li] < seq[ri])
			aux[gi++] = seq[li++];
		else {
			aux[gi++] = seq[ri++];
			swaps += m - li + 1;
		}
	}
	if(li <= m)
		memcpy(aux + gi, seq + li, (m - li + 1) * sizeof(int));
	if(ri <= r)
		memcpy(aux + gi, seq + ri, (r - ri + 1) * sizeof(int));
	memcpy(seq + l, aux, (r - l + 1) * sizeof(int));
	return swaps;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while(cin >> n && n) {
		for(int i = 0; i < n; i++)
			cin >> seq[i];
		if (mergesort(0, n - 1) % 2)
			cout << "Marcelo" << endl;
		else
			cout << "Carlos" << endl;
	}

	return 0;
}