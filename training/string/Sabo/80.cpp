#include <bits/stdc++.h>

using namespace std;

string s;

int x, y, z;
char c;

int main(){
	scanf("%d%c%d=%d", &x, &c, &y, &z);
	char e;
	scanf("%c", &e);
	if (e - '\n' || !strchr("-+/*", c)) return puts("ERROR"), 0;

	if (c == '/' && (y == 0 || x%y)) return puts("NO"), 0;

	switch(c) {
		case '-':
			x-=y;
			break;
		case '*':
			x *= y;
			break;
		case '+':
			x += y;
			break;
		case '/':
			x /= y;
			break;
	}

	cout << (x == z ? "YES\n" : "NO\n");
	return 0;
}