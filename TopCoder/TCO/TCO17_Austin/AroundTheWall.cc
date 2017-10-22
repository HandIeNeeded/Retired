#include <vector>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <utility>
#include <sstream>
#include <fstream>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cassert>
#include <numeric>
#include <iomanip>
using namespace std;

class AroundTheWall {
public:
  double minDistance(int r, int x1, int y1, int x2, int y2);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; int Arg3 = -2; int Arg4 = 0; double Arg5 = 3.605551275463989; verify_case(0, Arg5, minDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = -7; int Arg2 = -1; int Arg3 = 1; int Arg4 = 7; double Arg5 = 11.41897054604164; verify_case(1, Arg5, minDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 7; int Arg3 = -1; int Arg4 = -7; double Arg5 = 17.853981633974485; verify_case(2, Arg5, minDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 25; int Arg1 = -7; int Arg2 = 24; int Arg3 = -15; int Arg4 = -20; double Arg5 = 55.35743588970452; verify_case(3, Arg5, minDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

using LL = long double;

const LL eps = 1e-10;
const LL pi = std::acosl(-1.0);

inline int dcmp(LL x) {
    return x < -eps ? -1 : x > eps;
}

struct Point;
using Vector = Point;
using Polygon = std::vector<Point>;

struct Point {
    LL x,y;

    Point() {}

    Point(LL _x,LL _y) : x(_x),y(_y) {}

    Point operator + (const Point &rhs) const {
        return Point(x + rhs.x,y + rhs.y);
    }

    Point operator - (const Point &rhs) const {
        return Point(x - rhs.x,y - rhs.y);
    }

    Point operator * (LL t) const {
        return Point(x * t,y * t);
    }

    bool operator == (const Point &rhs) const {
        return dcmp(x - rhs.x) == 0 && dcmp(y - rhs.y) == 0;
    }

    LL length() const {
        return hypot(x,y);
    }

    // *this 绕 o 逆时针旋转 angle 角度
    Point rotate(const Point &o,LL angle) const {
        Point t = (*this) - o;
        LL c = cos(angle),s = sin(angle);
        return Point(o.x + t.x * c - t.y * s,o.y + t.x * s + t.y * c);
    }

    // *this 向量的单位法向量(左转90度，长度归一化)
    Vector normal() const {
        LL L = length();
        return Vector(-y / L,x / L);
    }

};

LL det(const Point &a,const Point &b) {
    return a.x * b.y - a.y * b.x;
}

LL dot(const Point &a,const Point &b) {
    return a.x * b.x + a.y * b.y;
}

// 用于极角排序的cmp函数
bool polar_cmp(const Point &a,const Point &b) {
    if (dcmp(a.y) * dcmp(b.y) <= 0) {
        if (dcmp(a.y) > 0 || dcmp(b.y) > 0) return dcmp(a.y - b.y) < 0;
        if (dcmp(a.y) == 0 && dcmp(b.y) == 0) return dcmp(a.x - b.x) < 0;
    }
    return dcmp(det(a,b)) > 0;
}

// 直线与直线的交点
Point intersection_line_line(Point p,Vector v,Point q,Vector w) {
    Vector u = p - q;
    LL t = det(w,u) / det(v,w);
    return p + v * t;
}

// 点到直线距离
LL distance_point_line(Point p,Point a,Point b) {
    Vector v1 = b - a,v2 = p - a;
    return std::abs(det(v1,v2)) / v1.length();
}

// 点到线段距离
LL distance_point_segment(Point p,Point a,Point b) {
    if (a == b) return (p - a).length();
    Vector v1 = b - a,v2 = p - a,v3 = p - b;
    if (dcmp(dot(v1,v2)) < 0) return v2.length();
    else if (dcmp(dot(v1,v3)) > 0) return v3.length();
    else return std::abs(det(v1,v2)) / v1.length();
}

// 点在直线上的投影
Point projection_point_line(Point p,Point a,Point b) {
    Vector v = b - a;
    return a + v * (dot(v,p - a) / dot(v,v));
}

// 线段规范相交判定
bool intersection_proper_segment_segment(Point a1,Point a2,Point b1,Point b2) {
    LL c1 = det(a2 - a1,b1 - a1),c2 = det(a2 - a1,b2 - a1),
           c3 = det(b2 - b1,a1 - b1),c4 = det(b2 - b1,a2 - b1);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

// 点在线段上判定(端点也算)
bool on_point_segment(Point p,Point a1,Point a2) {
    return dcmp(det(a1 - p,a2 - p)) == 0 && dcmp(dot(a1 - p,a2 -p)) <= 0;
}

// 线段相交判定(交在点上也算)
bool intersection_segment_segment(Point a1,Point a2,Point b1,Point b2) {
    if (intersection_proper_segment_segment(a1,a2,b1,b2)) return true;
    return on_point_segment(a1,b1,b2) || on_point_segment(a2,b1,b2)
        || on_point_segment(b1,a1,a2) || on_point_segment(b2,a1,a2);
}

// 点在多边形内判定
bool in_point_polygon(Point o,const Polygon &poly,bool flag) {
    // 传入flag表示在边界上算不算在里面
    int t = 0;
    Point a,b;
    int n = poly.size();
    for (int i = 0; i < n; ++ i) {
        if (on_point_segment(o,poly[i],poly[(i + 1) % n]))
            return flag;
    }
    for (int i = 0; i < n; ++ i) {
        a = poly[i];
        b = poly[(i + 1) % n];
        if (dcmp(a.y - b.y) > 0) std::swap(a,b);
        if (dcmp(det(a - o,b - o)) < 0 && 
                dcmp(a.y - o.y) < 0 && dcmp(o.y - b.y) <= 0)
            ++ t;
    }
    return t & 1;
}


double AroundTheWall::minDistance(int r, int x1, int y1, int x2, int y2) {
  Vector A(x1, y1), B(x2, y2);
  Vector direct = (A - B).normal().rotate(B, pi / 2.0) * r;
  Vector corner = B + direct;
  Polygon poly{corner};
  direct = Vector(0, 0) - direct;
  corner = B + direct;
  poly.push_back(corner);


}// Created by Yuan Lei

// BEGIN CUT HERE
AroundTheWall solver;

int main() {
  solver.run_test(-1);
  
  cerr << "-----------------------------------" << endl;
  cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  return 0;
}

// END CUT HERE



