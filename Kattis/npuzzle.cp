#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	char sol[4][4] = {
		{'A', 'B', 'C', 'D'},
		{'E', 'F', 'G', 'H'},
		{'I', 'J', 'K', 'L'},
		{'M', 'N', 'O', '.'}
	};
	char grid[4][4];
	for(auto &i : grid)
		cin >> i;

	int d = 0;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < (i == 3 ? 3 : 4); j++)
			for(int x = 0; x < 4; x++)
				for(int y = 0; y < 4; y++)
					if (grid[x][y] == sol[i][j])
						d += abs(i - x) + abs(j - y);
	cout << d;

	return 0;
}