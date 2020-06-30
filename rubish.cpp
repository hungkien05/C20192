#include<bits/stdc++.h>
using namespace std;

int main () {
	freopen("1.inp", 'r', stdin);
	freopen("1.out", 'w', stdout);
	int x, sum = 0, cnt = 0;
	while(cin >> x) {
		cnt++;
		if(cnt % 2 == 0) 
			sum += x;
	}
	cout << sum << endl;
	return 0;
}
    
