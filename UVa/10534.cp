#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, arr[10000];
	while(cin >> n) {
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		
		int len[2][10000], mem[10000];
		int mlen = 0;
		for(int i = 0; i < n; i++) {
			int j = lower_bound(mem, mem + mlen, arr[i]) - mem;
			mem[j] = arr[i];
			len[0][i] = j + 1;
			if (j == mlen)
				mlen++;
		}
		mlen = 0;
		for(int i = n - 1; i >= 0; i--) {
			int j = lower_bound(mem, mem + mlen, arr[i]) - mem;
			mem[j] = arr[i];
			len[1][i] = j + 1;
			if (j == mlen)
				mlen++;
		}

		int ans = 0;
		for(int i = 0; i < n; i++)
			ans = max(ans, min(len[0][i], len[1][i]));
		cout << ans * 2 - 1 << endl;
	}

	return 0;
}