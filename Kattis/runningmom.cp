#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<string, vector<string>> adj;
unordered_map<string, int> vis;
bool ans;

void dfs(string i){
	vis[i] = 1;
	for(auto &neighbor : adj[i]) {
   	if(vis[neighbor] == 0)
		dfs(neighbor);
	else if(vis[neighbor] == 1)
		ans = true;
	}
	vis[i] = 2;
}

int main(){
  	ios::sync_with_stdio(false);
	cin.tie(0);

  	int n;
  	string a, b;

  	cin >> n;
  	while(n--) {
    	cin >> a >> b;
    	adj[a].push_back(b);
  	}

  	while(cin >> a){
   		ans = false;
    	for(auto &i : adj)
      		vis[i.first] = 0;
    	dfs(a);
    	cout << a;
    	cout << (ans ? " safe" : " trapped") << endl;
  	}

  	return 0;
}