#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

#define endl '\n'

int n, lens[105], len, used[105];
 
bool backtrack(int j, int sum, int k) {
    if(j == n)
		return true;
    for(int i = k ;  i < n; i++) {
        if(used[i] == 0) {
            if(sum + lens[i] <  len) {
                used[i] = true;
                if(backtrack(j+1, sum + lens[i], i+1))
					return true;
                used[i] = false;
                if(sum == 0)
					return false;
                while(i + 1 < n && lens[i] == lens[i + 1])
					i++;
            }
            if(sum + lens[i] == len) {
                used[i] = true;
                if(backtrack(j+1, 0, 0))
					return true; 
                used[i] = false;
                return false;
            }
        }
    }
    return false;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    while(cin >> n && n) {
        int sum = 0;
		len = 0;
        for(int i = 0; i < n; i ++) {
			cin >> lens[i];
            sum += lens[i];
        }

        sort(lens, lens + n, greater<int>());
		if (n == 1) {
			cout << lens[0] << endl;
			continue;
		}
		for(int i = n; i >= 1; i--) {
			if (sum % i)
				continue;
			len = sum / i;
			if (len < lens[0])
				continue;
			memset(used, false, sizeof(used));
			if (backtrack(0, 0, 0))
				break;
		}
		cout << len << endl;
    }

    return 0;
}