#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int o[100000];
int nums[100000];
	
int main(int argc[], int argn[]){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	stack <pair<char, int>> st;
	string s;

	cin >> s;

	for (int i = 0, n = 1; i < s.length(); i++){
		if (!st.empty()){
			if (st.top().first - 'a' == s[i] - 'A'){
				o[i] = nums[st.top().second];
				st.pop();
			}
			else if (st.top().first - 'A' == s[i] - 'a'){
				o[st.top().second] = n++;
				st.pop();
			}
			else{
				if (s[i] >='a' && s[i] <='z')
					nums[i] = n++;
				
					st.push({s[i], i});
			}
		}
		else{
			if (s[i] >='a' && s[i] <='z')
				nums[i] = n++;
			
				st.push({s[i], i});
		}
	}
	
	if(!st.empty()){
		cout << "Impossible";
		return 0;
	}
	cout << "Possible\n";
	for (int i = 0; i < s.length(); i++)
		if (o[i] > 0)
			cout << o[i] << " ";
	return 0;
}	
