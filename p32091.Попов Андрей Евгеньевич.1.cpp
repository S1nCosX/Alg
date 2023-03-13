#include <iostream>

using namespace std;

int main(int argc[], int argn[]){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, max_ln = 0;
	
	cin >> n;
	
	int arr[n][2];
	arr[0][1] = 0;
	
	for (int i = 0; i < n; i++){
		cin >> arr[i][0];
		if (i > 1 && arr[i-2][0] == arr[i-1][0] && arr[i-1][0] == arr[i][0])
			arr[i][1] = 1;
			
		else if (i > 0) 
			arr[i][1] = arr[i-1][1] + 1;
			
		//cout << arr[i][0] << " : " << arr[i][1] << "\n";
		max_ln = max(max_ln, arr[i][1]);
	}
	
	for(int i = 0; i < n; i++)
		if (arr[i][1] == max_ln){
			i++;
			cout << i - max_ln << " " << i;
			return 0;
		}
	return 0;
}	
