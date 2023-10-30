#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int i, j, k, n, scores[43] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60 };
	while(cin >> n && n > 0) {
		int combs = 0, perms = 0;
		for(i = 0; i < 43; i++) {
			if(scores[i] > n) break;
			for(j = 0; j < 43; j++) {
				if(scores[i] + scores[j] > n) break;
				for(k = 0; k < 43; k++) {
					if(scores[i] + scores[j] + scores[k] > n) break;
					if (scores[i] + scores[j] + scores[k] == n) perms++;
				}
			}
		}

		for(i = 0; i < 43; i++) {
			if(scores[i] > n) break;
			for(j = i; j < 43; j++) {
				if(scores[i] + scores[j] > n) break;
				for(k = j; k < 43; k++) {
					if(scores[i] + scores[j] + scores[k] > n) break;
					if (scores[i] + scores[j] + scores[k] == n) combs++;
				}
			}
		}

		if (combs) {
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << combs << "." << endl;
			cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << perms << "." << endl;
		} else {
			cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl;
		}
		cout << "**********************************************************************\n";
	}
	cout << "END OF OUTPUT\n";

	return 0;
}