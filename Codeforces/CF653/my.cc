/*************************************************************************
	> File Name: F.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sat 19 Mar 2016 05:33:55 PM CST
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rank hehe
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int N = 500005;

template<typename T = int>
struct SuffixArray {
    int s[N], sa[N], a[N], b[N], c[N], n;
    int rank[N], height[N]; 
    //sa[i] 0base sa[0] = n 后缀数组排名i的后缀是第几个后缀
    //rank[i] 0base 第i个后缀在后缀数组里面的排名
    //height[i] sa[i]和sa[i-1]的最长公共前缀, height[0] = 0, height[1] = 0;
    //结构体里的n比实际串长大1

    void build(const T *str, int x, int m = 256) {//x 是未处理的str的长度
        n = x;
        REP(i, n) s[i] = str[i];
        s[n++] = int('$'), s[n] = 0;
        getSA(m), getHeight();
    }

    void getSA(int m) {//m 字符集大小
        int *x = a, *y = b;
        fill(c, c + m, 0);
        REP(i, n) c[x[i] = s[i]]++;
        REPP(i, 1, m - 1) c[i] += c[i - 1];
        for (int i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
        for(int k = 1; k <= n; k <<= 1) {
            int p = 0;
            for (int i = n - k; i < n; ++i) y[p++] = i;
            REP(i, n) if (sa[i] >= k) y[p++] = sa[i] - k;
            REP(i, m) c[i] = 0;
            REP(i, n) c[x[y[i]]]++;
            REPP(i, 1, m - 1) c[i] += c[i - 1];
            for (int i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
            swap(x, y);
            p = 1; x[sa[0]] = 0;
            REPP(i, 1, n - 1) {
                x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
            }
            if (p >= n) break;
            m = p;
        }
    }

    void getHeight(){
        REP(i, n) rank[sa[i]] = i;
        int k = 0;
        REP(i, n) {
            if (k) k--;
            int j = sa[rank[i] - 1];
            while (s[i + k] == s[j + k]) k++;
            height[rank[i]] = k;
        }
    }

    void print(){
        REP(i, n) cout << sa[i] << " \n"[i == n - 1];
        REP(i, n) cout << rank[i] << " \n"[i == n - 1];
        REP(i, n) cout << height[i] << " \n"[i == n - 1];
    }
};
SuffixArray<char> SA;

char str[N];
int prefix[N], id[N];
vector<int> number;

struct SGT{
	int l, r, cnt;
	SGT(int a = 0, int b = 0, int c = 0) : l(a), r(b), cnt(c) {}
}p[N * 20];

int head[N], node;

int New_Node() {
	p[node] = SGT();
	return node++;
}

void update(int pre, int &now, int num, int l, int r) {
	now = New_Node();
	if (l == r) {
		p[now].cnt = p[pre].cnt + 1;
	}
	else {
		int mid = l + r >> 1;
		if (num <= mid) {
			update(p[pre].l, p[now].l, num, l, mid);
			p[now].r = p[pre].r;
		}
		else {
			update(p[pre].r, p[now].r, num, mid + 1, r);
			p[now].l = p[pre].l;
		}
		p[now].cnt = p[p[now].l].cnt + p[p[now].r].cnt;
	}
}

int query(int x, int y, int num, int l, int r) {
	if (l == r) {
		return p[x].cnt - p[y].cnt;
	}
	else {
		int mid = l + r >> 1;
        if (num <= mid) {
            return query(p[x].l, p[y].l, num, l, mid);
        }
        else {
            return query(p[x].r, p[y].r, num, mid + 1, r);
        }
	}
}
//New_Node() 0号节点作为空节点, head[0] = 1是空树的根, 从1开始标号
//head 每棵线段树的起始点 val　每个节点上存的数字 fa 每个节点的父亲节点

int seg[N << 2];
int ql, qr;

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

void build(int x, int l, int r) {
    if (l == r) {
        seg[x] = prefix[l];
    }
    else {
        build(LC), build(RC);
        seg[x] = min(seg[L], seg[R]);
    }
}

int query(int x, int l, int r) {
    if (ql <= l && qr >= r) {
        return seg[x];
    }
    else {
        int a = INT_MAX, b = INT_MAX;
        if (ql <= MID) a = query(LC);
        if (qr > MID) b = query(RC);
        return min(a, b);
    }
}

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

    ios::sync_with_stdio(0);
    int n;
    cin >> n >> str;
    SA.build(str, n);
    REPP(i, 1, n) {
        if (str[i - 1] == '(') prefix[i] = prefix[i - 1] + 1;
        else prefix[i] = prefix[i - 1] - 1;
    }
    REPP(i, 1, n) {
        number.push_back(prefix[i]);
    }
    number.push_back(0);
    sort(number.begin(), number.end());
    number.resize(unique(number.begin(), number.end()) - number.begin());
    int tot = number.size();
    REPP(i, 0, n) id[i] = lower_bound(number.begin(), number.end(), prefix[i]) - number.begin() + 1;
    head[0] = New_Node();
    REPP(i, 1, n) {
        update(head[i - 1], head[i], id[i], 1, tot);
    }
    build(1, 1, n);
    int *sa = SA.sa, *h = SA.height;
    LL ans = 0;
    //SA.print();
    REPP(i, 1, n) {
        if (str[sa[i]] == ')') continue;
        int lcp = h[i];
        int pos = sa[i] + 1;
        //cout << "pos: " << pos << ' ' << prefix[pos] << endl;
        int lo = pos + 1, hi = n + 1;
        while (lo + 1 < hi) {
            int mid = (lo + hi) >> 1;
            ql = pos + 1, qr = mid;
            if (query(1, 1, n) < prefix[pos - 1]) hi = mid;
            else lo = mid;
        }
        //cout << "lo: " << lo << endl;
        ql = pos + lcp;
        qr = lo;
        //cout << i << ' ' << ql << ' ' << qr << endl;
        if (ql > qr) continue;
        ans += query(head[qr], head[ql - 1], id[pos - 1], 1, tot);
    }
    cout << ans << endl;
    return 0;
}

