/*
Top-Down O(n^2) DP -> TLE
For Implementation-Practice:

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

#define endl '\n'
typedef vector<int> vi;

vi arr, par, mem;
int n;

void pp(int i) {
	if (par[i] != -1)
		pp(par[i]);
	cout << arr[i] << endl;
}

int len(int i) {
	if (mem[i] != -1)
		return mem[i];
	mem[i] = 1;
	for(int j = 0; j < i; j++) {
		if (arr[j] < arr[i] && len(j) + 1 >= mem[i]) {
			mem[i] = len(j) + 1;
			par[i] = j;
		}
	}
	return mem[i];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a;
	while(cin >> a)
		arr.push_back(a);
	arr.push_back(INT_MAX);
	n = arr.size();
	mem.resize(n, -1);
	par.resize(n, -1);

	int ml = len(n - 1) - 1;
	cout << ml << endl << "-\n";
	pp(par[n - 1]);

	return 0;
}
*/

/*
Bottom-Up O(n^2) DP -> TLE

For Implementation-Practice:
#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'
typedef vector<int> vi;

vi par;

void pp(int i) {
	if (i == -1)
		return;
	pp(par[i]);
	cout << arr[i] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vi arr, len;
	int a;
	while(cin >> a)
		arr.push_back(a);
	arr.push_back(INT_MAX);
	int n = arr.size();
	par.resize(n, -1);

	for(int i = 0; i < n; i++) {
		len.push_back(1);
		for(int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && len[j] + 1 >= len[i]) {
				len[i] = len[j] + 1;
				par[i] = j;
			}
		}
	}

	cout << len[n - 1] - 1 << "\n-\n";
	pp(par[n-1]);

	return 0;
}
*/
#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'
typedef vector<int> vi;

vi arr, par;

void pp(int i) {
	if (i == -1)
		return;
	pp(par[i]);
	cout << arr[i] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a;
	while(cin >> a)
		arr.push_back(a);
	int n = arr.size();
	
	vi mem(n, -1), memi(n, -1);
	par.assign(n, -1);
	int len = 0, endi = 0;
	for(int i = 0; i < n; i++) {
		int j = lower_bound(mem.begin(), mem.begin() + len, arr[i]) - mem.begin();
		mem[j] = arr[i];
		memi[j] = i;
		par[i] = j ? memi[j - 1] : -1;
		if(j == len) {
			len++;
			endi = i;
		}
	}

	cout << len << "\n-\n";
	pp(endi);

	return 0;
}