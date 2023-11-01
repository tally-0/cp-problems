#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, mat[100][100];
	while(cin >> n) {
	for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
      		cin >> mat[i][j];
      		if (j > 0)
				mat[i][j] += mat[i][j-1];
    	}
	}
  	
	int ms = -127*100*100;
  	for (int i = 0; i < n; ++i) {
    	for (int j = i; j < n; ++j) {
      		int s = 0;
      		for (int k = 0; k < n; ++k) {
				s += mat[k][j];
         		if (i > 0)
					s -= mat[k][i-1];
				ms = max(ms, s);
         		s = max(s, 0);
			} 
		}
	}

	cout << ms << endl;
	}

	return 0;
}