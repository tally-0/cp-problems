#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, tmp, idx1, idx2, max[12];
	string str;
	long long minn, maxn, min[12];
	char op;

	cin >> n;
	while(n--) {
		cin >> str;
		idx1 = 0; idx2 = 0;
		op = '+';

		for (int i = 0; i <= str.length(); i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				tmp = tmp * 10 + str[i] - '0';
			} else {
				cerr << tmp << endl;
				if (op == '+') {
					if (!idx1) max[idx1++] = tmp;
					else max[idx1 - 1] += tmp;
					min[idx2++] = tmp;
				} else {
					if (!idx2) min[idx2++] = tmp;
					else min[idx2 - 1] *= tmp;
					max[idx1++] = tmp;
				}
				op = str[i]; tmp = 0;
			}
		}

		minn = min[0]; maxn = max[0];
		for(int i = 1; i < idx1; i++) maxn *= max[i];
		for(int i = 1; i < idx2; i++) minn += min[i];

		cout << "The maximum and minimum are " << maxn << " and " << minn << endl;
	}

	return 0;
}