#include <iostream>
#include <map>
#include <string>
#include <stack>

using namespace std;

map <string, int> mp;

stack <int> ch_n;

stack <pair <string, int>> ch_vals;

int main(int argc[], int argn[]){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);	

	string inp = "";
	
	int cur_ch_n = 0;
	
	while (cin >> inp){
		if (inp == "{"){
			ch_n.push(cur_ch_n);
			cur_ch_n = 0;
		}
		else if (inp == "}"){
			for (int i = 0; i < cur_ch_n; i++){
				mp[ch_vals.top().first] = ch_vals.top().second;
				ch_vals.pop();
			}
			
			cur_ch_n = ch_n.top();
			ch_n.pop();
		}
		else {
			int i = 0;
			string str1 = "", str2 = "";
			int num=0;
			for (; inp[i]!='='; str1 += inp[i++]);
			i++;
			if ((inp[i] >= '0' && inp[i] <= '9') || inp[i] == '-'){
				bool f = false;
				if (inp[i] == '-'){
					i++;
					f = true;
				}
				for (; i < inp.length(); num*=10, num += (inp[i] - '0'), i++);
				
				if (f)
					num *= -1;
			}
			else{
				for (; i < inp.length(); str2 += inp[i++]);
				num = mp[str2];
				cout << num << "\n";
			}
			cur_ch_n++;
			ch_vals.push(pair<string, int>{str1, mp[str1]});
			mp[str1] = num;
		}
	}
	return 0;
}	
