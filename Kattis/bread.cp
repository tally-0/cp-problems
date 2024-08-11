#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int arr[100001], aux[100001];

int swaps(int l, int r) {
	if (r <= l)
		return 0;
	int m = (r + l) >> 1;
	int ret = swaps(l, m) + swaps(m + 1, r);
	int li = l, ri = m + 1, gi = 0;
	while(li <= m && ri <= r) {
		if (arr[li] <= arr[ri])
			aux[gi++] = arr[li++];
		else {
			aux[gi++] = arr[ri++];
			ret += m - li + 1;
		}
	}
	if (li <= m)
		memcpy(aux + gi, arr + li, (m - li + 1) * sizeof(int));
	else if (ri <= r)
		memcpy(aux + gi, arr + ri, (r - ri + 1) * sizeof(int));
	memcpy(arr + l, aux, (r - l + 1) * sizeof(int));
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int a = swaps(0, n - 1);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int b = swaps(0, n - 1);

	if ((a - b) % 2)
		cout << "Impossible";
	else
		cout << "Possible";

	return 0;
}