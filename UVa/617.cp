#include<iostream>
#include<cmath>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	double lights[6][4];
	int n;	
	for(int t = 1; cin >> n && n > -1; t++) {
		for(int i = 0; i < n; i++)
			cin >> lights[i][0] >> lights[i][1] >> lights[i][2] >> lights[i][3];

		bool pos[61];
		for(int i = 30; i <= 60; i++) {
			bool f = true;
			for(int j = 0; j < n && f; j++) {
				double time = lights[j][0] * 3600.0 / i;
				int totcycl = lights[j][1] + lights[j][2] + lights[j][3];
				f = fmod(time, totcycl) <= lights[j][1] + lights[j][2];
			}
			pos[i] = f;
		}

		cout << "Case " << t << ":";
		bool hassol = false, first = true;
		for(int i = 30, j; i <= 60; i++) {
			if (!pos[i])
				continue;
			hassol = true;
			for(j = i; j <= 60 && pos[j]; j++);
			j--;
			if (!first)
				cout << ",";
			cout << " ";
			first = false;
			if (j == i)
				cout << i;
			else
				cout << i << "-" << j;
			i = j;
		}
		if (!hassol)
			cout << " No acceptable speeds.";
		cout << endl;
	}

	return 0;
}