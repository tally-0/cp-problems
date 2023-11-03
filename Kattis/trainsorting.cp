#include<iostream>
 
using namespace std;

#define endl '\n'
 
int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin >> n;
    int w[2000];
    for(int i = 0; i < n; i++)
		cin >> w[i];
        
    int leni[2000], lend[2000], ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        leni[i] = lend[i] = 1;
       	for(int j = i + 1; j < n; j++) {
        	if(w[i] < w[j])
                leni[i] = max(leni[i], leni[j] + 1);
            if(w[i] > w[j])
                lend[i] = max(lend[i], lend[j] + 1);
        }           
        ans = max(leni[i] + lend[i] - 1, ans);
    }
         
    cout << ans << endl;
    
    return 0;
}