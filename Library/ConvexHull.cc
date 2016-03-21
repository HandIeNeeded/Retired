struct Point{
    int x, y, id;
    Point (int x = 0, int y = 0, int id = 0) :x(x), y(y), id(id) {}

    Point operator - (const Point &a) const {
        Point res;
        res.x = x - a.x, res.y = y - a.y;
        return res;
    }
}p[N];

long long det(const Point &a, const Point &b) {
    return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

bool cmp(const Point &a, const Point &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

void get(vector<Point>& points, vector<Point> &result) {
    sort(points.begin(), points.end(), cmp);
    result.clear();
    int n = points.size(), m;
    for (int i = 0; i < n; i++) {
        while ((m = result.size()) > 1 && det(result[m - 1] - result[m - 2], points[i] - result[m - 2]) < EPS) result.pop_back();
        result.push_back(points[i]);
    }
    int k = result.size();
    for (int i = n - 2; i >= 0; i--) {
        while ((m = result.size()) > k && det(result[m - 1] - result[m - 2], points[i] - result[m - 2]) < EPS) result.pop_back();
        result.push_back(points[i]);
    }
    if (n > 1) result.pop_back();
}
