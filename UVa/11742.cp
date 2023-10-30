#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int find(int a, int arr[]) {
	for(int i = 0; i < 8; i++) {
		if (arr[i] == a) return i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	int constraints[20][3];
	while(cin >> n >> m && n + m) {
		for(int i = 0; i < m; i++) {
			cin >> constraints[i][0] >> constraints[i][1] >> constraints[i][2];
		}
		
		int arr[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
		int res = 0;
		do {
			cerr << "a" << endl;
			bool isValid = true;
			for(int i = 0; i < m; i++) {
				int a = find(constraints[i][0], arr);
				int b = find(constraints[i][1], arr);
				if (constraints[i][2] > 0) {
					if(abs(a - b) > constraints[i][2]) {
						isValid = false;
						break;
					}
				} else if(abs(a - b) < (-constraints[i][2])) {
					isValid = false;
					break;
				}
			}
			if (isValid) res++;
		} while (next_permutation(arr, arr + n));

		cout << res << endl;
	}

	return 0;
}