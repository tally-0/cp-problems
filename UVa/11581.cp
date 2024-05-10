#include<iostream>

using namespace std;

#define endl '\n'

int g[3][3];

void f() {
	int h[3][3] = { 0 };
	
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if (i - 1 >= 0)
				h[i][j] += g[i - 1][j];
			if (i + 1 < 3)
				h[i][j] += g[i + 1][j];
			if (j - 1 >= 0)
				h[i][j] += g[i][j - 1];
			if (j + 1 < 3)
				h[i][j] += g[i][j + 1];
			h[i][j] %= 2;
		}
	}
	
	for(int i = 0; i < 3; i++) 
		for(int j = 0; j < 3; j++)
			g[i][j] = h[i][j];
}
				

int sum() {
	int ans = 0;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			ans += g[i][j];
	cerr << ans << endl;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		string s;
		for(int i = 0; i < 3; i++) {
			cin >> s;
			for(int j = 0; j < 3; j++)
				g[i][j] = (int)s[j] - (int)'0';
		}

		int i = -1;
		while(sum() > 0) {
			f();
			i++;
		}
		
		cout << i << endl;
	}

	return 0;
}