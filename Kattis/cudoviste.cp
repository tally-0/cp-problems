#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, c, grid[50][50];
	cin >> r >> c;
	for(int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < c; j++) {
			if (s[j] == '#')
				grid[i][j] = 2;
			else if (s[j] == 'X')
				grid[i][j] = 1;
			else
				grid[i][j] = 0;
		}
	}
	int squashed[5] = { 0 };
	for(int i = 0; i < r - 1; i++) {
			for(int j = 0; j < c - 1; j++) {
			if (grid[i][j] == 2 || grid[i+1][j] == 2 || grid[i+1][j+1] == 2 || grid[i][j+1] == 2)
				continue;
			squashed[grid[i][j]+grid[i+1][j]+grid[i+1][j+1]+grid[i][j+1]]++;
		}
	}
	for(const int &i : squashed)
		cout << i << endl;

	return 0;
}