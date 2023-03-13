#include <iostream>
#include <cmath>

using namespace std;

int main(int argc[], int argn[]){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	long long a, b, c, d, k;
	
	cin >> a >> b >> c >> d >> k;
	
	if (a * b - c == a){
		cout << a;
    	return 0;
    }

	for (long long i = 0; i < k; i++){
		a*=b;
		a-=c;
		if (a >= d){
			cout << d;
			return 0;
		}
		if (a <= 0){
			cout << 0;
			return 0;
		}
	}
	
	cout << a;
	return 0;
}	
