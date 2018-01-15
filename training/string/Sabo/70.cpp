#include <bits/stdc++.h>

using namespace std;

string s;
int n;

int main(){
	cin >> s >> n;
	if (n > 0) {
		for(int i = 0; i < min(1023, n*int(s.size())); i++) {
			cout << s[i % int(s.size())];
		}
	}
	else if(n < 0) {
		n = -n;
		if(int(s.size()) % n != 0) return puts("NO SOLUTION"), 0;
		n = s.size() / n;
		for (int i = n; i < s.size(); i++) {
			if (s[i - n] != s[i]) {
				return puts("NO SOLUTION"), 0;
			}
        }
		for (int i = 0; i < min(1023, n); i++) {
			cout << s[i];
		}
	}
	return 0;
}