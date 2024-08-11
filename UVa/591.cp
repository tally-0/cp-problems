#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, stacks[51];
	for(int set = 1; cin >> n && n; set++) {
		int sum = 0;
		for(int i = 0; i < n; i++) {
			cin >> stacks[i];
			sum += stacks[i];
		}
		int height = sum / n;
		int moves = 0;
		for(int i = 0; i < n; i++)
			moves += abs(stacks[i] - height);
		moves >>= 1;

		cout << "Set #" << set << endl;
		cout << "The minimum number of moves is " << moves << "." << endl << endl;
	}

	return 0;
}