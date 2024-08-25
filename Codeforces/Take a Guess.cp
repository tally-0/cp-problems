#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

#define endl '\n'

int sum(int i, int j) {
	int o, a;
	cout << "or " << i << " " << j << endl;
	fflush(stdout);
	cin >> o;
	cout << "and " << i << " " << j << endl;
	fflush(stdout);
	cin >> a;
	return 2 * a + (~a & o);
}

int main() {
	int n, k, a[10000];
	cin >> n >> k;
	int ab = sum(1, 2);
	int bc = sum(2, 3);
	int ac = sum(1, 3);
	a[0] = (ab - bc + ac) / 2;
	a[1] = ab - a[0];
	a[2] = ac - a[0];
	for(int i = 3; i < n; i++)
		a[i] = sum(1, i + 1) - a[0];
	sort(a, a + n);
	cout << "finish " << a[k - 1] << endl;
	fflush(stdout);
	return 0;
}
