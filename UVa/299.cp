#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, l, ord[50];
	cin >> n;
	while(n--) {
		cin >> l;
		for(int i = 0; i < l; i++)
			cin >> ord[i];
		int swaps = 0;
		for(int i = 0; i < l; i++) {
			for(int j = l - 1; j > i; j--) {
				if (ord[j] < ord[j - 1]) {
					swap(ord[j], ord[j - 1]);
					swaps++;
				}
			}
		}
		cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
	}

	return 0;
}