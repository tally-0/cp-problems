#include<iostream>
#include<sstream>
#include<map>
#include<cstring>
#include<algorithm>
#include<vector>


using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	int a[26], m[2001], n;
	while(getline(cin, s)) {
		stringstream ss(s);
		for(n = 0; ss >> a[n]; n++);
		sort(a, a + n);
		memset(m, 0, sizeof(m));
		for(int i = 0; i < n - 1; i++)
			for(int j = i + 1; j < n; j++) 
				m[a[j] - a[i]]++;
		vector<int> v;
		bool rul = true;
		for(int i = 1; i <= (a[n-1] - a[0]); i++) {
			if (m[i] > 1) {
				rul = false;
				break;
			} else if (m[i] == 0)
				v.push_back(i);
		}
		if (!rul)
			cout << "not a ruler";
		else if (!v.size())
			cout << "perfect";
		else {
			cout << "missing";
			for(const int &i : v)
				cout << " " << i;
		}
		cout << endl;
	}

	return 0;
}