#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> e(100);
vector <int> order;
vector <bool> used;
int ans = 0;

void dfs_order(int v){
	if(used[v])
		return;
	used[v] = true;
	for (auto i : e[v])
		dfs_order(i);
	order.push_back(v);
}
void dfs(int v){;
	if (used[v])
		return;

	used[v] = true;
	for (auto i : e[v])
		dfs(i);
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		e[--a].push_back(i);
	}
	used.assign(n, 0);
	for(int i = 0; i < n; i++){
		dfs_order(i);
	}
	
	used.clear();
	used.assign(n, 0);
	for (int i = 0; i < n; i++){
		int v = order[n - 1 - i];
		if (!used[v]){
			ans++;
			dfs(v);
		}
	}
	cout << ans;
}