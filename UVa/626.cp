#include<iostream>
#include<unordered_map>
#include<set>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, mat[100][100];
	while(cin >> n) {
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> mat[i][j];

		int ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if (!mat[i][j])
					continue;
				for(int k = 0; k < n; k++) {
					if (!mat[j][k] || !mat[k][i])
						continue;
					if (!(i < j && j < k) && !(i > j && j > k))
						continue;
					cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
					ans++;
				}
			}
		}
		cout << "total:" << ans << endl << endl;
	}
	cout << endl;

	return 0;
}