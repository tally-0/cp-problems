#include<iostream>
#include<cmath>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x[100];
	cin >> n;
	for(int i = 0; i < n; i++) 
		cin >> x[i];

	int a = 0;
	for(int i = 0; i < n; i++)
		a += x[i];
	a = round((float)a / n);
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans += (a - x[i]) * (a - x[i]);

	cout << ans;

	return 0;
}