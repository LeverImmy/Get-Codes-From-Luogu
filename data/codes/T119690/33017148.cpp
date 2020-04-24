#include <bits/stdc++.h>
#define LL long long
#define DEBUG

const int N = 1e5 + 5;
const int M = 1e5 + 5;

int n, m, cnt, start;
int first[N], inq[N], dis[N];

struct EDGE {
	int to, _next;
} e[M << 1];

void Add_Edge(int u, int v) {
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void spfa(int st) {
	std::queue <int> q;
	memset(inq, 0, sizeof(inq));
	memset(dis, 0x3f, sizeof(dis));
	q.push(st), inq[st] = 1, dis[st] = 0;
	while(!q.empty()) {
		int x = q.front();
		q.pop(), inq[x] = 0;
		for(int i = first[x]; ~i; i = e[i]._next) {
			int y = e[i].to;
			if(dis[y] > dis[x] + 1) {
				dis[y] = dis[x] + 1;
				if(!inq[y]) {
					q.push(y), inq[y] = 1;
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	memset(first, -1, sizeof(first));
	for(int i = 1, l = 1, r = -1; i <= m; ++i) {
		int len, type;
		scanf("%d %d", &len, &type);
		r = l + len - 1;
		for(int j = l; j <= r; ++j) start |= (type << j - 1);
		l = r + 1;
	}
	for(int state = 0; state < 1 << n; ++state) {
		int nxt_1 = state ^ 1;
		int lowbit = state & -state;
		int nxt_2 = state ^ (lowbit << 1);
		Add_Edge(state, nxt_1);
		Add_Edge(state, nxt_2);
		if(!((state & 1) ^ (state & 2))) Add_Edge(state, state ^ 3);
//		printf("%d %d\n", state, nxt_1);
//		printf("%d %d\n", state, nxt_2);
	}
	spfa(start);
	printf("%d", dis[0] - 1);
	return 0;
}
/*
4
3
1 1
1 0
2 1

*/
