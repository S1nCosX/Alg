#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; cin >> arr[i++]);
	int sum = 0;
	sort(arr, arr+n);
	if (n % k != 0){
		int i = 0;
		for (; i < n % k; sum += arr[i++]);
		for (; i < n; i++)
			if ((i - n % k) % k != 0)
				sum += arr[i];
	}
	else
		for (int i = 0; i < n; i++)
			if ((i - n % k) % k != 0)
				sum += arr[i];
	cout << sum;
}