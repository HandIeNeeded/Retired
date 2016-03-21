struct Node{
    int l, r, cnt;
    Node(int a = 0, int b = 0, int c = 0) : l(a), r(b), cnt(c) {}
}p[N * 20];

int head[N], node;

int New() {
    p[node] = Node();
    return node++;
}

void update(int pre, int &now, int num, int l, int r) {
    now = New();
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
        return p[x].cnt - p[y].cnt > 0;
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
