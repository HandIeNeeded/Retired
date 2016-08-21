#include <bits/stdc++.h>
using LL = long long;

const int kN = 2000 + 5;
int n, m, K;
std::vector<std::tuple<int, int, int>> garlands[kN];
std::vector<std::tuple<int, int, int, int>> queries;
std::vector<int> touch[kN];

LL bits[kN][kN];
LL result[kN];

void modify(LL *c, int p, int dt)
{
    for (int i = p; i <= m; i += i & -i)
        c[i] += dt;
}

LL query(LL *c, int p)
{
    LL ret = 0;
    for (int i = p; i > 0; i -= i & -i)
        ret += c[i];
    return ret;
}

void modify2(int x, int y, int dt)
{
    for (int i = x; i <= n; i += i & -i)
        modify(bits[i], y, dt);
}

LL query2(int x, int y)
{
    LL ret = 0;
    for (int i = x; i > 0; i -= i & -i)
        ret += query(bits[i], y);
    return ret;
}

LL ask(int x1, int y1, int x2, int y2)
{
    return query2(x2, y2) - query2(x1 - 1, y2) - query2(x2, y1 - 1) + query2(x1 - 1, y1 - 1);
}

template<typename T>
inline void read(T &x)
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    for (x = 0; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
}

int main()
{
    read(n); read(m); read(K);
    for (int i = 0; i < K; ++ i) {
        int len;
        read(len);
        for (int j = 0; j < len; ++ j) {
            int x, y, w;
            read(x); read(y); read(w);
            garlands[i].emplace_back(x, y, w);
        }
    }
    int nq;
    read(nq);
    std::vector<bool> lights(K, true);
    for (int i = 0; i < nq; ++ i) {
        static char op[10];
        scanf("%s", op);
        if (op[0] == 'S') {
            int p;
            read(p); -- p;
            lights[p] = lights[p] ^ 1;
        } else {
            int x1, x2, y1, y2;
            read(x1); read(y1); read(x2); read(y2);
            for (int j = 0; j < K; ++ j) if (lights[j] == true) {
                touch[j].emplace_back(queries.size());
            }
            queries.emplace_back(x1, y1, x2, y2);
        }
    }

    for (int i = 0; i < K; ++ i) {
        if (touch[i].empty()) continue;
        for (const auto &t : garlands[i]) {
            int x, y, w;
            std::tie(x, y, w) = t;
            modify2(x, y, w);
        }
        for (auto id : touch[i]) {
            int x1, y1, x2, y2;
            std::tie(x1, y1, x2, y2) = queries[id];
            result[id] += ask(x1, y1, x2, y2);
        }
        for (const auto &t : garlands[i]) {
            int x, y, w;
            std::tie(x, y, w) = t;
            modify2(x, y, -w);
        }
    }

    for (int i = 0; i < (int)queries.size(); ++ i) {
        std::cout << result[i] << std::endl;
    }
}
