#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>

#define inf 1e9

using namespace std;
/*
6 5 5 5 4 2
WW.W#
.W.WW
.##.#
..W##
WWW#.
#.W..
*/
int main(){
	int n, m;
	cin >> n >> m;
	int x, y;
	cin >> x >> y;
	int fx, fy;
	cin >> fx >> fy;
	vector <vector<int>> e;
	e.assign(n, vector<int> (m));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			char a;
			cin >> a;
			if (a == '.')
				e[i][j] = 1;
			if (a == 'W')
				e[i][j] = 2;
			if (a == '#')
				e[i][j] = inf;
		}
		
	vector <vector<int>> path_v;
	path_v.assign(n, vector<int> (m, inf));
	vector <vector <pair<int, int>>> parent;
	parent.assign(n, vector <pair<int, int>> (m));
	
	vector <queue <pair<int, int>>> q(3);
	vector <vector<bool>> used;
	used.assign(n, vector<bool> (m, 0));
	
	parent[--x][--y] = {-1, -1};
	path_v[x][y] = 0;
	q[0].push({x, y});
	int pos = 0, k = 1;
	
	while (k){
		while(q[pos].empty()){ 
			pos = (pos + 1) % (3);
			//cout << pos << " " <<q[pos].empty();
		}
			
		pair <int, int> v = q[pos].front();
		k--;
		//cout << v.first << " " << v.second << "\n";
		q[pos].pop();
		if (used[v.first][v.second])
			continue;
		used[v.first][v.second] = true;
			
		if (v.first - 1 >= 0 && e[v.first - 1][v.second] != inf && path_v[v.first - 1][v.second] > path_v[v.first][v.second] + e[v.first - 1][v.second]){
			parent[v.first - 1][v.second] = v;
			path_v[v.first - 1][v.second] = path_v[v.first][v.second] + e[v.first - 1][v.second];
			q[(e[v.first - 1][v.second] + pos)%3].push({v.first - 1, v.second});
			k++;
		}
		if (v.first + 1 < n && e[v.first + 1][v.second] != inf && path_v[v.first + 1][v.second] > path_v[v.first][v.second] + e[v.first + 1][v.second]){
			parent[v.first + 1][v.second] = v;
			path_v[v.first + 1][v.second] = path_v[v.first][v.second] + e[v.first + 1][v.second];
			q[(e[v.first + 1][v.second] + pos)%3].push({v.first + 1, v.second});
			k++;
		}
		if (v.second - 1 >= 0 && e[v.first][v.second - 1] != inf && path_v[v.first][v.second - 1] > path_v[v.first][v.second] + e[v.first][v.second - 1]){
			parent[v.first][v.second - 1] = v;
			path_v[v.first][v.second - 1] = path_v[v.first][v.second] + e[v.first][v.second - 1];
			q[(e[v.first][v.second - 1] + pos)%3].push({v.first, v.second - 1});
			k++;
		}
		if (v.second + 1 < m && e[v.first][v.second + 1] != inf && path_v[v.first][v.second + 1] > path_v[v.first][v.second] + e[v.first][v.second + 1]){
			parent[v.first][v.second + 1] = v;
			path_v[v.first][v.second + 1] = path_v[v.first][v.second] + e[v.first][v.second + 1];
			q[(e[v.first][v.second + 1] + pos)%3].push({v.first, v.second + 1});
			k++;
		}
	}
	if (path_v[--fx][--fy] == inf){
		cout << -1;
		return 0;
	}
	
	cout << path_v[fx][fy] << "\n";
	stack <char> path;
	pair <int, int> cur = {fx, fy};
	pair <int, int> end = {-1, -1};
	/*for (auto i : parent){
		for (auto j : i)
			cout <<"["<< j.first << ";" << j.second <<"] ";
		cout <<"\n";
	}*/
	while (cur != end){
		pair <int, int> p = parent[cur.first][cur.second];
		if (p == end)
			break;
		if (p.first == cur.first - 1){
			path.push('S');
		}
		if (p.first == cur.first + 1){
			path.push('N');
		}
		if (p.second == cur.second - 1){
			path.push('E');
		}
		if (p.second == cur.second + 1){
			path.push('W');
		}
		cur = p;
	}
	while(!path.empty()){
		cout << path.top();
		path.pop();
	}
}