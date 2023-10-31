/*
Solved usign recursive Backtracking as per Halim's Competitive Programming 4.

Can be solved in simpler ways.
*/

#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int telephone[4][3]  = {
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9},
	{10, 0, 10}
};
int nums[1000];

void backtrack(int n, int mult, int x, int y) {
	if (x < 0 || x >= 4 || y < 0 || y >= 3 || telephone[x][y] > 9)
		return;
	backtrack(n, mult, x, y + 1);
	backtrack(n, mult, x + 1, y);
	backtrack(n, mult, x + 1, y + 1);
	if (mult == 1) {
		n += telephone[x][y] * mult;
		nums[n] = true;
		return;
	}
	n += telephone[x][y] * mult;
	backtrack(n, mult / 10, x, y);
	backtrack(n, mult / 10, x, y + 1);
	backtrack(n, mult / 10, x + 1, y);
	backtrack(n, mult / 10, x + 1, y + 1);
}
		
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(nums, false, sizeof(nums));
	backtrack(0, 100, 0, 0);
	backtrack(0, 10, 0, 0);
	backtrack(0, 1, 0, 0);
	int t, k;
	cin >> t;
	while(t--) {
		cin >> k;
		int i = 0;
		while(true) {
			if (k - i >= 0 && nums[k - i])
				break;
			if (k + i < 1000 && nums[k + i])
				break;
			i++;
		}
		cout << (nums[k - i] ? k - i : k + i) << endl;
	}

	return 0;
}