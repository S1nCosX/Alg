#include<iostream>
#include<queue>
#include<set>
using namespace std;

int main(){
	
	int n, k;
	cin >> n >> k;
	
	queue <int> q;
	
	multiset <int> s;
	
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		if (q.size() < k){
			q.push(a);
			s.insert(a);
		}
		else{
			cout << *s.begin() << " ";
			s.erase(s.find(q.front()));
			q.pop();
			q.push(a);
			s.insert(a);
		}
	}
	
			cout << *s.begin() << " ";
	return 0;
}