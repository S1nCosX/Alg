#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

pair <char, pair <int, int>> v[26];

bool cmp(pair <char, pair <int, int>> a, pair <char, pair <int, int>> b){
	if ((a.first < 2) == (b.first < 2))
		return a.second.second < b.second.second;
	else
		return a.second.first < b.second.first;
}

int main(){
	string s;
	cin >> s;
	
	for (int i = 0; i < 26; cin >> v[i].second.second, v[i].second.first = 0, v[i].first='a'+i, i++);
	
	for (int i = 0; i < s.length(); v[(s[i] - 'a')].second.first++, i++);
	
	sort(v, v + 26, cmp);

	stack <char> face;
	queue <char> mid;
	queue <char> tail;
	
	for (int i = 0; i < 26; i++){
		if(v[i].second.first < 2)
			while(v[i].second.first > 0){
				mid.push(v[i].first);
				v[i].second.first--;
			}
			
		else{
			face.push(v[i].first);
			tail.push(v[i].first);
			while(v[i].second.first - 2 > 0){
				mid.push(v[i].first);
				v[i].second.first--;
			}
		}
	}
	
	while(!face.empty()){
		cout << face.top();
		face.pop();
	}
	while(!mid.empty()){
		cout << mid.front();
		mid.pop();
	}
	while(!tail.empty()){
		cout << tail.front();
		tail.pop();
	}		
}