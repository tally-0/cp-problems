#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int n, arr[200], par[200];

void pp(int i) {
	if (i == -1)
		return;
	pp(par[i]);
	cout << " " << arr[i];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n && n) {
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		
		int mem[200], memi[200], len = 0, endi;
		for(int i = 0; i < n; i++) {
			int j = lower_bound(mem, mem + len, arr[i]) - mem;
			mem[j] = arr[i];
			memi[j] = i;
			par[i] = j ? memi[j - 1] : -1;
			if (j == len) {
				len++;
				endi = i;
			} else if (j + 1 == len && (arr[i] < arr[endi]))
				endi = i;
		}

		cout << len;
		pp(endi);
		cout << endl;
	}

	return 0;
}