#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int p, k;
	vector<int> line(20);
	cin >> p;
	while(p--) {
		cin >> k;
		int steps = 0;
		for(int i = 0, h; i < 20; i++) {
			cin >> h;
			for(int j = 0; j <= i; j++) {
				if (line[j] > h || j == i) {
					steps += i - j;
					line.insert(begin(line) + j, h);
					break;
				}
			}
		}
		cout << k << " " << steps << endl;
	}		

	return 0;
}