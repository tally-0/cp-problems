#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a[100000000];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	int i = 0, gis[100000000];
	gis[0] = a[0];
	for(int j = 1; j < n; j++)
		if (a[j] > gis[i])
			gis[++i] = a[j];

	cout << i + 1 << endl;
	for(int j = 0; j < i; j++)
		cout << gis[j] << " ";
	cout << gis[i];

	return 0;
}