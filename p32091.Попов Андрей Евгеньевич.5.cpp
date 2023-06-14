#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;

vector <int> v;

bool check(int l){
	int bk = k - 1;
	int i = 0, prev_i = 0;
	while (bk > 0 && i < n){
		if (v[i] - v[prev_i] >= l){
			prev_i = i;
			bk--;
		}
		i++;
	}
	return bk == 0;
}

int binsearch(int l, int r){
	while (r - l > 1){
		int m = (r + l)/2;
		if (check(m))
			l = m;
		else
			r = m;
	}
	return l;
}

int main(){
	cin >> n >> k;
	for (int i = 0, a; i < n; cin >> a, v.push_back(a), i++);
	
	cout << binsearch(0, v[n - 1]);
}