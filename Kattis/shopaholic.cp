#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, p[200000];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> p[i];
		
	sort(p, p + n);
	int ans = 0;
	for(int i = n % 3; i < n; i += 3)
		ans += p[i];
	
	cout << ans << endl;

	return 0;
}