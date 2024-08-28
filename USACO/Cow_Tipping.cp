#include<iostream>
#include<fstream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ifstream cin("cowtip.in");
	ofstream cout("cowtip.out");

	int n, mat[10][10];
	cin >> n;
	string s;
	for(int i = 0; i < n; i++) {
		cin >> s;
		for(int j = 0; j < n; j++)
			mat[i][j] = s[j] - '0';
	}
	
	int ans = 0;
	for(int i = n - 1; i >= 0; i--) {
		for(int j = n - 1; j >= 0; j--) {
			if (mat[i][j]) {
				ans++;
				for(int g = 0; g <= i; g++)
					for(int h = 0; h <= j; h++)
						mat[g][h] = (mat[g][h] + 1) % 2;
			}
		}
	}
	cout << ans;

	return 0;
}