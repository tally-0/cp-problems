#include <iostream>
#include <vector>

using namespace std;

#define vi vector<int>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vi order(6);
	auto read = [&] () {
		int sum = 0;
		for(int &i : order) {
			cin >> i;
			sum += i;
		}
		if (sum > 0) return true;
		return false;
	};
	
	int num, free;
	while(read()) {
		num = 0;

		num += order[5];

		num += order[4];
		order[0] -= 11 * order[4];

		num += order[3];
		order[1] -= 5 * order[3];

		num += (order[2] + 3) / 4;
		switch (order[2] % 4) {
		case 1:
			order[1] -= 5;
			order[0] -= 7;
			break;
		case 2:
			order[1] -= 3;
			order[0] -= 6;
			break;
		case 3:
			order[1] -= 1;
			order[0] -= 5;
			break;
		}

		if (order[1] > 0) {
			num += (order[1] + 8) / 9;
			order[1] -= 9 * ((order[1] + 8) / 9);
		}

		if (order[1] < 0) order[0] += order[1] * 4;
		if (order[0] > 0) num += (order[0] + 35) / 36;

		cout << num << endl;
	}

	return 0;
}