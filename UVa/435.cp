#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, p, v[20], tv, pi[20];
	cin >> t;
	while(t--) {
		cin >> p;
		tv = 0;
		for(int i = 0; i < p; i++) {
			cin >> v[i];
			tv += v[i];
		}
		
		memset(pi, 0, sizeof(pi));
		for(int i = 0; i < (1 << p); i++) {
			int tot = 0;
			for(int j = 0; j < p; j++)
				if (i & (1 << j))
					tot += v[j];
			for(int j = 0; j < p; j++)
				if (i & (1 << j))
					if ((tot - v[j]) <= (tv / 2) && tot > (tv / 2))
						pi[j]++;
		}

		for(int i = 0; i < p; i++)
			cout << "party " << i + 1 << " has power index " << pi[i] << endl;
		cout << endl;
	}

	return 0;
}