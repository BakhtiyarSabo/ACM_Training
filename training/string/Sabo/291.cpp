#include <bits/stdc++.h>

using namespace std;

string s;
int n, ans = 0;
string a[1011];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sort(a[i].begin(), a[i].end());
	}

	cin >> s;
	sort(s.begin(), s.end());

	for(int i = 0; i < n; i++){
		int z = a[i].size();
		int p = 0;
		for(int j = 0; j < s.size(); j++){
			if(s[j] == a[i][p]){
				p++;
				z--;
			}
			if(z == 0){
				ans ++;
				break;
			}
		}
	}
	cout << ans;
}