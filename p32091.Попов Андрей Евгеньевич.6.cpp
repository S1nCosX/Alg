#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> v;

string str;

bool cmp(string a, string b){
	string bufa = a + b;
	string bufb = b + a;
			
	return bufa > bufb;
}

int main(){
	int n;
	cin >> n;	
	int j = 0;
	while (j++<n){
		cin >> str;
		v.push_back(str);
	}
	
	sort (v.begin(), v.end(), cmp);
	
	for (int i = 0; i < v.size(); cout << v[i++]);
}