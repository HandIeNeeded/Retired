int a[N], b[N]; //b[N] -> tmp a[N] -> data

LL Merge(int l,int r) {
    if(l >= r) return 0; 
    int mid = l + r >> 1;
    Merge(l, mid);
    Merge(mid + 1, r);

    for (int i = l, j = mid + 1, k = l; k <= r; k++) {
        if (j > r || i <= mid && a[i] < a[j]) {
            b[k] = a[i++];
        }
        else if (j > r || i <= mid && a[i] == a[j]) {
            b[k] = a[i++];
        }
        else {
            b[k] = a[j++];
        }
    }

    REPP(i, l, r) a[i] = b[i];
    return 0;
}
