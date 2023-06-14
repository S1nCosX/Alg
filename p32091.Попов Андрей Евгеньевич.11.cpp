#include <stdio.h>
#include <set>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second - a.first <= b.second - b.first;
}

int main(){
	multiset <pair <int, int>> s;
	int n, m;
	scanf("%d%d", &n, &m);
	
	pair <int, int> cuts[m];
	s.insert({1, n});
	for (int a, i = 0; i < m; i++){
		scanf("%d", &a);
		if (a > 0){
			pair <int, int> cut = {0, 0};
			
			pair <int, int> block = {0,0};
        s.upper_bound({0, a}, cmp);
			if (block != cut){
				cut = {block.first, block.first+a-1};
				s.erase(block);
				if(block.first+a <= block.second)
					s.insert({block.first+a, block.second});
				cuts[i] = cut;
			}
			else{
				cut = {-1, 0};
			}
			printf("%d\n", cut.first);
		}
		else{
			pair <int, int> null_cut = {0, 0};
			if(cuts[-a-1]!= null_cut){
				pair<int, int> block1 = {0,0}, block2 = {0,0};
				for(auto j : s){
					if(j.second == cuts[-a-1].first - 1){
						block1 = j;
					}
					if(j.first - 1 >= cuts[-a-1].second){
						block2 = j;
						break;
					}
				}
				
            if(block1 != null_cut){
            		s.erase(s.find(block1));
					cuts[-a-1].first = block1.first;
            }
            if(block2 != null_cut){
            		s.erase(s.find(block2));
					cuts[-a-1].second = block2.second;
            }
					
				s.insert(cuts[-a-1]);
				cuts[-a-1]=null_cut;
			}
		}
	}
	
	return 0;
}
