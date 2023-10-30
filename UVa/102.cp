#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	char lookup[3] = { 'B', 'C', 'G' };

	int arr[9];
	while(cin >> arr[0] >> arr[2] >> arr[1] >> arr[3] >> arr[5] >> arr[4] >> arr[6] >> arr[8] >> arr[7]) {
		int a = 0, b = 0, c = 0;
		for(int i = 0; i < 3; i++) a += arr[i];
		for(int i = 3; i < 6; i++) b += arr[i];
		for(int i = 6; i < 9; i++) c += arr[i];

		int perm[3] = { 0, 1, 2 }, min = INT_MAX, minPerm[3];
		do {
			int sum = 0;
			sum += a - arr[perm[0]];
			sum += b - arr[perm[1] + 3];
			sum += c - arr[perm[2] + 6];
			if (sum < min) {
				min = sum;
				copy(perm, perm + 3, minPerm);
			}
		} while(next_permutation(perm, perm + 3));

		cout << lookup[minPerm[0]] << lookup[minPerm[1]] << lookup[minPerm[2]] << " " << min << endl;
	}

	return 0;
}