#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	unordered_map<char, int> lookup = {
		{'r', 0},
		{'o', 1},
		{'y', 2},
		{'g', 3},
		{'b', 4}
	};

	char alloc[100][5];
	string in;
	while(cin >> in && in != "#") {
		int n = 0;
		for(int i = 0; i < 5; i++) alloc[n][lookup[in[i*4]]] = in[i*4+2];
		while(cin >> in && in[0] != 'e') {
			n++;
			for(int i = 0; i < 5; i++) alloc[n][lookup[in[i*4]]] = in[i*4+2];
		}
		n++;
		int minc = INT_MAX, mini = -1;
		for(int i = 0; i < n; i++) {
			int c = 0;
			for(int j = 0; j < n; j++) {
				if (j == i) continue;
				for(int k = 0; k < 5; k++) {
					if (alloc[i][k] != alloc[j][k]) c++;
				}
			}
			if (c < minc) {
				minc = c;
				mini = i;
			}
		}

		cout << ++mini << endl;
	}			

	return 0;
}