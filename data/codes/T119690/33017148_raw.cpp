#include <bits/stdc++.h>
int main(){printf("#include <bits\/stdc++.h>\r\n#define LL long long\r\n#define DEBUG\r\n\r\nconst int N = 1e5 + 5;\r\nconst int M = 1e5 + 5;\r\n\r\nint n, m, cnt, start;\r\nint first[N], inq[N], dis[N];\r\n\r\nstruct EDGE {\r\n\tint to, _next;\r\n} e[M << 1];\r\n\r\nvoid Add_Edge(int u, int v) {\r\n\te[cnt].to = v;\r\n\te[cnt]._next = first[u];\r\n\tfirst[u] = cnt++;\r\n}\r\n\r\nvoid spfa(int st) {\r\n\tstd::queue <int> q;\r\n\tmemset(inq, 0, sizeof(inq));\r\n\tmemset(dis, 0x3f, sizeof(dis));\r\n\tq.push(st), inq[st] = 1, dis[st] = 0;\r\n\twhile(!q.empty()) {\r\n\t\tint x = q.front();\r\n\t\tq.pop(), inq[x] = 0;\r\n\t\tfor(int i = first[x]; ~i; i = e[i]._next) {\r\n\t\t\tint y = e[i].to;\r\n\t\t\tif(dis[y] > dis[x] + 1) {\r\n\t\t\t\tdis[y] = dis[x] + 1;\r\n\t\t\t\tif(!inq[y]) {\r\n\t\t\t\t\tq.push(y), inq[y] = 1;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n}\r\n\r\nint main() {\r\n\tscanf(\"%%d %%d\", &n, &m);\r\n\tmemset(first, -1, sizeof(first));\r\n\tfor(int i = 1, l = 1, r = -1; i <= m; ++i) {\r\n\t\tint len, type;\r\n\t\tscanf(\"%%d %%d\", &len, &type);\r\n\t\tr = l + len - 1;\r\n\t\tfor(int j = l; j <= r; ++j) start |= (type << j - 1);\r\n\t\tl = r + 1;\r\n\t}\r\n\tfor(int state = 0; state < 1 << n; ++state) {\r\n\t\tint nxt_1 = state ^ 1;\r\n\t\tint lowbit = state & -state;\r\n\t\tint nxt_2 = state ^ (lowbit << 1);\r\n\t\tAdd_Edge(state, nxt_1);\r\n\t\tAdd_Edge(state, nxt_2);\r\n\t\tif(!((state & 1) ^ (state & 2))) Add_Edge(state, state ^ 3);\r\n\/\/\t\tprintf(\"%%d %%d\\n\", state, nxt_1);\r\n\/\/\t\tprintf(\"%%d %%d\\n\", state, nxt_2);\r\n\t}\r\n\tspfa(start);\r\n\tprintf(\"%%d\", dis[0] - 1);\r\n\treturn 0;\r\n}\r\n\/*\r\n4\r\n3\r\n1 1\r\n1 0\r\n2 1\r\n\r\n*\/\r\n");return 0;}