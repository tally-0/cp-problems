#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	cin.ignore();
	while(t--) {
		cin.ignore();
		string str;
		stringstream ss;
		getline(cin, str);
		ss << str;
		vector<int> p;
		for(int a; ss >> a; p.push_back(a));
		getline(cin, str);
		ss.clear();
		ss << str;
		vector<string> arr(p.size());
		for(int i = 0; ss >> arr[p[i] - 1]; i++);
		for(const string& s : arr)
			cout << s << endl;
		if (t)
			cout << endl;
	}

	return 0;
}