#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

const int P = 13;

ll h[1000010], p[1000010];


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int n = int(s.size());
	p[0] = 1;
	for(int i = 1; i < n; i++) p[i] = p[i-1] * P;

	for(int i = 0; i < s.size(); i++){
		h[i] = int(s[i] - 'a' + 1) * p[i];
		if(i) h[i] += h[i-1];
	}
	ll res = 0;

	for(int l = n; l >= 1; l--){
		for(int i = 0; i < n; i++){
			
		}	
	}






}