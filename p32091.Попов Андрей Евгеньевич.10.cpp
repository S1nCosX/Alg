#include<iostream>
#include<deque>

using namespace std;

int main(){
	int n;
	cin >> n;
	deque <int> q1, q2;
	
	for (int i = 0; i < n; i++){
		char type;
		int gob;
		cin >> type;
		if (type == '+'){
			cin >> gob;
			
			q2.push_back(gob);
			while (q1.size() < q2.size()){
				q1.push_back(q2.front());
				q2.pop_front();
			}
		}
		if (type == '*'){
			cin >> gob;;
			
			while (q1.size() - q2.size() > 1){
				q2.push_front(q1.back());
				q1.pop_back();
			}
			
			q1.push_back(gob);
		}
		if (type == '-'){
			cout << q1.front()<<"\n";
			q1.pop_front();
			while (q1.size() < q2.size()){
				q1.push_back(q2.front());
				q2.pop_front();
			}
		}
	}
	return 0;
}