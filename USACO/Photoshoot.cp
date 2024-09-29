#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n; 
	if (n % 2)
		n--;
	string s;
	cin >> s;
	
	int ans = 0;
	for(int i = n - 1; i > 0; i -= 2) {
		if (ans % 2 == 0 && s[i] == 'H' && s[i - 1] == 'G')
			ans++;
		if (ans % 2 == 1 && s[i] == 'G' && s[i - 1] == 'H')
			ans++;
	}

	cout << ans;

	return 0;
}