#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

#define vi vector<int>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ifstream cin("outofplace.in");
	ofstream cout("outofplace.out");

	int n;
	cin >> n;
	
	vi heights(n);
	for(int &height : heights) cin >> height;
	
	vector<int> original(heights);
	sort(original.begin(), original.end());
	int diff = 0;
	for (int i = 0; i < n; i++) {
		if (heights[i] != original[i]) diff++;
	}
	cout << diff - 1;

	return 0;
}


// IDK warum dieser O(n) alg nicht funktioniert
/*
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define vi vector<int>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	vi heights(n);
	int ii, ih, is;
	for (int i = 0; i < n; i++) {
		cin >> heights[i];
		if (heights[i] < heights[i-1]) {
			ii = i;
			ih = heights[i];
		}
	}

	if ((ii == 0 || heights[ii-1] < ih) && (ii == n - 1 || heights[ii+1] < ih)) is = 0;
	else is = 1;

	cout << ih << " " << ii << " " << is << endl;

	int swaps = 0;
	if (is) {
		int min = INT_MAX;
		while (heights[ii-1] > ih && ii > 1) {
			if (heights[ii-1] < min) {
				swaps++;
				min = heights[ii-1];
			}
			ii--;
		}
	} else {
		int max = INT_MIN;
		while (heights[ii+1] > ih && ii < (n-2)) {
			if (heights[ii+1] > max) {
				swaps++;
				max = heights[ii+1];
			}
			ii++;
		}
	}
	cout << swaps;

	return 0;
}
*/
