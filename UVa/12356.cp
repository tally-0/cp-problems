#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int s, b, left[100001], right[100001];
	while(cin >> s >> b && (s || b)) {
		for(int i = 1; i <= s; i++) {
			left[i] = i - 1;
			right[i] = i + 1;
		}
		left[1] = -1;
		right[s] = -1;
		
		int l, r;
		while(b--) {
			cin >> l >> r;
			
			if (left[l] < 0)
				cout << "* ";
			else
				cout << left[l] << " ";
			if (right[r] < 0)
				cout << "*" << endl;
			else
				cout << right[r] << endl;

			left[right[r]] = left[l];
			right[left[l]] = right[r];
		}
		cout << "-" << endl;
	}

	return 0;
}