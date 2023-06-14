#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> e;
vector <int> order;
vector <bool> used;

void dfs_order(int v, int mx){
	if(used[v])
		return;
	used[v] = true;
	for (int i = 0; i < e.size(); i++){
		if (i != v && e[v][i] <= mx){
			//cout << v << "->" << i << "\n";
			dfs_order(i, mx);
		}
	}
	order.push_back(v);
}

void dfs(int v, int mx){;
	if (used[v])
		return;
	used[v] = true;
	for (int i = 0; i < e.size(); i++){
		if (i != v && e[i][v] <= mx){
			//cout << v << "->" << i << "\n";
			dfs(i, mx);
		}
	}
}

bool scc_check(int mx){
	//cout << "scc_check " << mx <<":\n";
	int ans = 0;
	int n = e.size();
	order.clear();
	used.assign(n, 0);
	for(int i = 0; i < n; i++)
		dfs_order(i, mx);
		
	used.assign(n, 0);
	for (int i = 0; i < n; i++){
		int v = order[n - 1 - i];
		//cout << v << ": ";
		if (!used[v]){
			ans++;
			dfs(v, mx);
		}
	}
	return ans == 1;
}

int binsearch(int l, int r){
	while (r - l > 1){
		int m = (r + l) / 2;
		//cout << l << " " << m << " " << r <<"\n";
		if (scc_check(m))
			r = m;
		else
			l = m;
	}
	return r;
}

int main(){
	int n;
	cin >> n;
	int l = 1e9, r = 0;
	e.assign(n, {});
	for (int i = 0; i < n; 
		e[i].assign(n, 0),
		i++);
		
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> e[i][j];
			if (i != j){
				l = min(l, e[i][j]);
				r = max(r, e[i][j]);
			}
		}
	}
	cout << binsearch(l, r);
}