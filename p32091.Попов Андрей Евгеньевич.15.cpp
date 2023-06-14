#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> e(100);
vector <int> color(100);
	
bool colorable(int v, int c){
	if (color[v] == c)	
		return true;
	else if (color[v] != 0) return false;
	
	color[v] = c;
	for (auto i : e[v]){
		if(!colorable(i, 1 + (c)%2))
			return false;
	}
	return true;
}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		e[--a].push_back(--b);
		e[b].push_back(a);
	}
	
	bool f = 1;
	
	for (int i = 0; i < n; i++){
		if (color[i] == 0)
			f = f && colorable (i, 1);
	}
	
	if (f)
		cout << "YES";
	
	else
		cout << "NO";
}