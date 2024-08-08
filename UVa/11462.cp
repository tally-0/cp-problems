#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while(cin >> n && n) {
		int freq[100] = { 0 };
		for(int i = 0, tmp; i < n; i++) {
			cin >> tmp;
			freq[tmp]++;
		}
		int first = 0;
		for(int i = 0; i < 100; i++)
			while(freq[i]--)
				cout << (!first++ ? "" : " ") << i;
		cout << endl;
	}

	return 0;
}