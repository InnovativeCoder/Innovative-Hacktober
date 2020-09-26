#include <bits/stdc++.h>
using namespace std;
#define Int long long int

const int MAX = 55;
int t, n;
Int H[MAX], M[MAX], mod;
pair<Int,Int> ans[MAX];

long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
    return m * m + 1;
}

long long get_fibonacci_huge(long long n, long long m) {
    long long remainder = n % get_pisano_period(m);

    long long first = 0;
    long long second = 1;

    long long res = remainder;

    for (int i = 1; i < remainder; i++) {
        res = (first + second) % m;
        first = second;
        second = res;
    }

    return res % m;
}

int main(){
	std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++)	cin >> H[i];
		for(int i = 0; i < n; i++)	cin >> M[i];
		for(int i = 0; i < n; i++){
			mod = M[i];
			ans[i] = {get_fibonacci_huge(H[i], M[i]), i + 1};
		}
		sort(ans, ans + n);
		bool f = 0;
		for(int i = 0; i < n; i++){
			if(ans[i].first){
				f = 1;
				cout << ans[i].second << " " << ans[i].first << "\n";
				break;
			}
		}
		if(!f)	cout << "-1\n";
	}

	return 0;
}
