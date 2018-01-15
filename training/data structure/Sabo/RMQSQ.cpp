#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 101010;
const int K = 25;
const int INF = int(1e9) + 7;

int t[N+10][K+1], a[N+10], LLL[N+10];
int n, q;

// int tree[4*N];

// void build(int v, int l, int r) {
// 	if(l == r) {
// 		tree[v] = a[l];
// 		return;
// 	}
// 	int mid = (l + r) >> 1;
// 	build(v + v, l, mid);
// 	build(v + v + 1, mid + 1, r);
// 	tree[v] = min(tree[v + v], tree[v + v + 1]);
// }

// int getmin(int v, int tl, int tr, int l, int r) {
// 	if(l > r) return INF;
// 	if(l == tl and r == tr) return tree[v];
// 	int mid = (tl + tr) >> 1;
// 	return min(getmin(v + v, tl, mid, l, min(mid, r)), getmin(v + v + 1, mid + 1, tr, max(l, mid + 1), r));
// }

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	// build(1, 0, N - 1);
	for (int i = 2; i <= N; i++) LLL[i] = LLL[i/2] + 1;
	for (int i = 0; i < n; i++) t[i][0] = a[i];
	for (int j = 1; j <= K; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) {
			t[i][j] = min(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
		}
	}
	scanf("%d", &q);
	for (int i = 0, l, r; i < q; i++) {
		scanf("%d%d", &l, &r);
		// printf("%d\n", getmin(1, 0, N - 1, l, r));
		int j = LLL[r - l + 1];
		printf("%d\n", min(t[l][j], t[r - (1 << j) + 1][j]));
	}
	return 0;
}