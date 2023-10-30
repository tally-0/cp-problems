#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a;
	vector<int> b;
	while(cin >> n && n != 0) {
		b.clear();
		while(n--) {
			cin >> a;
			if (a > 0) b.push_back(a);
		}
		
		if(b.size()) {
			cout << b[0];
			for(int i = 1; i < b.size(); i++) cout << " " << b[i];
			cout << endl;
		} else cout << "0" << endl;
	}
	return 0;
}