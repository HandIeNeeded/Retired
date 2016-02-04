/*************************************************************************
  > File Name: C.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > created Time: Sat 30 Jan 2016 01:22:55 AM CST
 ************************************************************************/
#include <bits/stdc++.h>
const int N = 1e5 + 5;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std; 

///////////////////////////////////////////////////////////////////
//常量区
const double INF        = 1e10;     // 无穷大 
const double EPS        = 1e-22;    // 计算精度 
const int LEFT          = 0;        // 点在直线左边 
const int RIGHT         = 1;        // 点在直线右边 
const int ONLINE        = 2;        // 点在直线上 
const int CROSS         = 0;        // 两直线相交 
const int COLINE        = 1;        // 两直线共线 
const int PARALLEL      = 2;        // 两直线平行 
const int NOTCOPLANAR   = 3;        // 两直线不共面 
const int INSIDE        = 1;        // 点在图形内部 
const int OUTSIDE       = 2;        // 点在图形外部 
const int BORDER        = 3;        // 点在图形边界 
const int BAOHAN        = 1;        // 大圆包含小圆
const int NEIQIE        = 2;        // 内切
const int XIANJIAO      = 3;        // 相交
const int WAIQIE        = 4;        // 外切
const int XIANLI        = 5;        // 相离
/////////////////////////////////////////////////////////////////// 

///////////////////////////////////////////////////////////////////
//类型定义区
struct Point {              // 二维点或矢量 
    double x, y; 
    double angle, dis; 
    Point() {} 
    Point(double x0, double y0): x(x0), y(y0) {} 
}; 
struct Point3D {            //三维点或矢量 
    double x, y, z; 
    Point3D() {} 
    Point3D(double x0, double y0, double z0): x(x0), y(y0), z(z0) {} 
}; 
struct Line {               // 二维的直线或线段 
    Point p1, p2; 
    Line() {} 
    Line(Point p10, Point p20): p1(p10), p2(p20) {} 
}; 
struct Line3D {             // 三维的直线或线段 
    Point3D p1, p2; 
    Line3D() {} 
    Line3D(Point3D p10, Point3D p20): p1(p10), p2(p20) {} 
}; 
struct Rect {              // 用长宽表示矩形的方法 w, h分别表示宽度和高度 
    double w, h; 
    Rect() {}
    Rect(double _w,double _h) : w(_w),h(_h) {}
}; 
struct Rect_2 {             // 表示矩形，左下角坐标是(xl, yl)，右上角坐标是(xh, yh) 
    double xl, yl, xh, yh; 
    Rect_2() {}
    Rect_2(double _xl,double _yl,double _xh,double _yh) : xl(_xl),yl(_yl),xh(_xh),yh(_yh) {}
}; 
struct Circle {            //圆
    Point c;
    double r;
    Circle() {}
    Circle(Point _c,double _r) :c(_c),r(_r) {}
};
typedef vector<Point> Polygon;      // 二维多边形     
typedef vector<Point> Points;       // 二维点集 
typedef vector<Point3D> Points3D;   // 三维点集 
/////////////////////////////////////////////////////////////////// 

///////////////////////////////////////////////////////////////////
//基本函数区
inline double max(double x,double y) 
{ 
    return x > y ? x : y; 
} 
inline double min(double x, double y) 
{ 
    return x > y ? y : x; 
} 
inline bool ZERO(double x)              // x == 0 
{ 
    return (fabs(x) < EPS); 
} 
inline bool ZERO(Point p)               // p == 0 
{ 
    return (ZERO(p.x) && ZERO(p.y)); 
} 
inline bool ZERO(Point3D p)              // p == 0 
{ 
    return (ZERO(p.x) && ZERO(p.y) && ZERO(p.z)); 
} 
inline bool EQ(double x, double y)      // eqaul, x == y 
{ 
    return (fabs(x - y) < EPS); 
} 
inline bool NEQ(double x, double y)     // not equal, x != y 
{ 
    return (fabs(x - y) >= EPS); 
} 
inline bool LT(double x, double y)     // less than, x < y 
{ 
    return ( NEQ(x, y) && (x < y) ); 
} 
inline bool GT(double x, double y)     // greater than, x > y 
{ 
    return ( NEQ(x, y) && (x > y) ); 
} 
inline bool LEQ(double x, double y)     // less equal, x <= y 
{ 
    return ( EQ(x, y) || (x < y) ); 
} 
inline bool GEQ(double x, double y)     // greater equal, x >= y 
{ 
    return ( EQ(x, y) || (x > y) ); 
} 
// 注意！！！ 
// 如果是一个很小的负的浮点数 
// 保留有效位数输出的时候会出现-0.000这样的形式， 
// 前面多了一个负号 
// 这就会导致错误！！！！！！ 
// 因此在输出浮点数之前，一定要调用次函数进行修正！ 
inline double FIX(double x) 
{ 
    return (fabs(x) < EPS) ? 0 : x; 
} 
////////////////////////////////////////////////////////////////////////////////////// 

/////////////////////////////////////////////////////////////////////////////////////
//二维矢量运算 
bool operator==(Point p1, Point p2)  
{ 
    return ( EQ(p1.x, p2.x) &&  EQ(p1.y, p2.y) ); 
} 
bool operator!=(Point p1, Point p2)  
{ 
    return ( NEQ(p1.x, p2.x) ||  NEQ(p1.y, p2.y) ); 
} 
bool operator<(Point p1, Point p2) 
{ 
    if (NEQ(p1.x, p2.x)) { 
        return (p1.x < p2.x); 
    } else { 
        return (p1.y < p2.y); 
    } 
} 
Point operator+(Point p1, Point p2)  
{ 
    return Point(p1.x + p2.x, p1.y + p2.y); 
} 
Point operator-(Point p1, Point p2)  
{ 
    return Point(p1.x - p2.x, p1.y - p2.y); 
} 
double operator*(Point p1, Point p2) // 计算叉乘 p1 × p2 
{ 
    return (p1.x * p2.y - p2.x * p1.y); 
} 
double operator&(Point p1, Point p2) { // 计算点积 p1·p2 
    return (p1.x * p2.x + p1.y * p2.y); 
} 
double Norm(Point p) // 计算矢量p的模 
{ 
    return sqrt(p.x * p.x + p.y * p.y); 
} 
// 把矢量p旋转角度angle (弧度表示) 
// angle > 0表示逆时针旋转 
// angle < 0表示顺时针旋转 
Point Rotate(Point p, double angle) 
{ 
    Point result; 
    result.x = p.x * cos(angle) - p.y * sin(angle); 
    result.y = p.x * sin(angle) + p.y * cos(angle); 
    return result; 
} 
////////////////////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////////////////////// 
//三维矢量运算 
bool operator==(Point3D p1, Point3D p2)  
{ 
    return ( EQ(p1.x, p2.x) && EQ(p1.y, p2.y) && EQ(p1.z, p2.z) ); 
} 
bool operator<(Point3D p1, Point3D p2) 
{ 
    if (NEQ(p1.x, p2.x)) { 
        return (p1.x < p2.x); 
    } else if (NEQ(p1.y, p2.y)) { 
        return (p1.y < p2.y); 
    } else { 
        return (p1.z < p2.z); 
    } 
} 
Point3D operator+(Point3D p1, Point3D p2)  
{ 
    return Point3D(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z); 
} 
Point3D operator-(Point3D p1, Point3D p2)  
{ 
    return Point3D(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z); 
} 
Point3D operator*(Point3D p1, Point3D p2) // 计算叉乘 p1 x p2 
{ 
    return Point3D(p1.y * p2.z - p1.z * p2.y, 
            p1.z * p2.x - p1.x * p2.z, 
            p1.x * p2.y - p1.y * p2.x );         
} 
double operator&(Point3D p1, Point3D p2) { // 计算点积 p1·p2 
    return (p1.x * p2.x + p1.y * p2.y + p1.z * p2.z); 
} 
double Norm(Point3D p) // 计算矢量p的模 
{ 
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z); 
} 

////////////////////////////////////////////////////////////////////////////////////// 

/////////////////////////////////////////////////////////////////////////////////////
//几何题面积计算
//
// 根据三个顶点坐标计算三角形面积 
// 面积的正负按照右手旋规则确定 
double Area(Point A, Point B, Point C) //三角形面积 
{ 
    return ((B-A)*(C-A) / 2.0); 
}    
// 根据三条边长计算三角形面积 
double Area(double a, double b, double c) //三角形面积 
{ 
    double s = (a + b + c) / 2.0; 
    return sqrt(s * (s - a) * (s - b) * (s - c)); 
} 
double Area(const Circle & C)      
{          
    return 3.14 * C.r * C.r;      
}    
// 计算多边形面积 
// 面积的正负按照右手旋规则确定 
double Area(const Polygon& poly) //多边形面积
{ 
    double res = 0; 
    int n = poly.size(); 
    if (n < 3) return 0; 
    for(int i = 0; i < n; i++) { 
        res += poly[i].x * poly[(i+1)%n].y; 
        res -= poly[i].y * poly[(i+1)%n].x; 
    } 
    return (res / 2.0); 
} 
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//点.线段.直线问题
//
double Distance(Point p1, Point p2) //2点间的距离
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double Distance(Point3D p1, Point3D p2) //2点间的距离,三维
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
}
double Distance(Point p, Line L) // 求二维平面上点到直线的距离 
{ 
    return ( fabs((p - L.p1) * (L.p2 - L.p1)) / Norm(L.p2 - L.p1) ); 
} 
double Distance(Point3D p, Line3D L)// 求三维空间中点到直线的距离 
{ 
    return ( Norm((p - L.p1) * (L.p2 - L.p1)) / Norm(L.p2 - L.p1) ); 
} 
bool OnLine(Point p, Line L) // 判断二维平面上点p是否在直线L上 
{ 
    return ZERO( (p - L.p1) * (L.p2 - L.p1) ); 
} 
bool OnLine(Point3D p, Line3D L) // 判断三维空间中点p是否在直线L上 
{ 
    return ZERO( (p - L.p1) * (L.p2 - L.p1) ); 
} 
int Relation(Point p, Line L) // 计算点p与直线L的相对关系 ,返回ONLINE,LEFT,RIGHT
{ 
    double res = (L.p2 - L.p1) * (p - L.p1); 
    if (EQ(res, 0)) { 
        return ONLINE; 
    } else if (res > 0) { 
        return LEFT; 
    } else { 
        return RIGHT; 
    } 
} 
bool SameSide(Point p1, Point p2, Line L) // 判断点p1, p2是否在直线L的同侧 
{ 
    double m1 = (p1 - L.p1) * (L.p2 - L.p1); 
    double m2 = (p2 - L.p1) * (L.p2 - L.p1); 
    return GT(m1 * m2, 0); 
} 
bool OnLineSeg(Point p, Line L) // 判断二维平面上点p是否在线段l上 
{ 
    return ( ZERO( (L.p1 - p) * (L.p2 - p) ) && 
            LEQ((p.x - L.p1.x)*(p.x - L.p2.x), 0) && 
            LEQ((p.y - L.p1.y)*(p.y - L.p2.y), 0) ); 
} 
bool OnLineSeg(Point3D p, Line3D L) // 判断三维空间中点p是否在线段l上 
{ 
    return ( ZERO((L.p1 - p) * (L.p2 - p)) && 
            EQ( Norm(p - L.p1) + Norm(p - L.p2), Norm(L.p2 - L.p1)) ); 
} 
Point SymPoint(Point p, Line L) // 求二维平面上点p关于直线L的对称点 
{ 
    Point result; 
    double a = L.p2.x - L.p1.x; 
    double b = L.p2.y - L.p1.y; 
    double t = ( (p.x - L.p1.x) * a + (p.y - L.p1.y) * b ) / (a*a + b*b); 
    result.x = 2 * L.p1.x + 2 * a * t - p.x; 
    result.y = 2 * L.p1.y + 2 * b * t - p.y; 
    return result; 
} 
bool Coplanar(Points3D points) // 判断一个点集中的点是否全部共面 
{ 
    int i; 
    Point3D p; 

    if (points.size() < 4) return true; 
    p = (points[2] - points[0]) * (points[1] - points[0]); 
    for (i = 3; i < points.size(); i++) { 
        if (! ZERO(p & points[i]) ) return false; 
    } 
    return true; 
} 
bool LineIntersect(Line L1, Line L2) // 判断二维的两直线是否相交 
{ 
    return (! ZERO((L1.p1 - L1.p2)*(L2.p1 - L2.p2)) );  // 是否平行 
} 
bool LineIntersect(Line3D L1, Line3D L2) // 判断三维的两直线是否相交 
{ 
    Point3D p1 = L1.p1 - L1.p2; 
    Point3D p2 = L2.p1 - L2.p2; 
    Point3D p  = p1 * p2; 
    if (ZERO(p)) return false;      // 是否平行 
    p = (L2.p1 - L1.p2) * (L1.p1 - L1.p2); 
    return ZERO(p & L2.p2);         // 是否共面 
} 
bool LineSegIntersect(Line L1, Line L2) // 判断二维的两条线段是否相交 
{ 
    return ( GEQ( max(L1.p1.x, L1.p2.x), min(L2.p1.x, L2.p2.x) ) && 
            GEQ( max(L2.p1.x, L2.p2.x), min(L1.p1.x, L1.p2.x) ) && 
            GEQ( max(L1.p1.y, L1.p2.y), min(L2.p1.y, L2.p2.y) ) && 
            GEQ( max(L2.p1.y, L2.p2.y), min(L1.p1.y, L1.p2.y) ) && 
            LEQ( ((L2.p1 - L1.p1) * (L1.p2 - L1.p1)) * ((L2.p2 -  L1.p1) * (L1.p2 - L1.p1)), 0 ) && 
            LEQ( ((L1.p1 - L2.p1) * (L2.p2 - L2.p1)) * ((L1.p2 -  L2.p1) * (L2.p2 - L2.p1)), 0 ) );              
} 
bool LineSegIntersect(Line3D L1, Line3D L2) // 判断三维的两条线段是否相交 
{ 
    // todo 
    return true; 
} 
// 计算两条二维直线的交点，结果在参数P中返回 
// 返回值说明了两条直线的位置关系:  COLINE   -- 共线  PARALLEL -- 平行  CROSS    -- 相交 
int CalCrossPoint(Line L1, Line L2, Point& P) 
{ 
    double A1, B1, C1, A2, B2, C2; 

    A1 = L1.p2.y - L1.p1.y; 
    B1 = L1.p1.x - L1.p2.x; 
    C1 = L1.p2.x * L1.p1.y - L1.p1.x * L1.p2.y; 

    A2 = L2.p2.y - L2.p1.y; 
    B2 = L2.p1.x - L2.p2.x; 
    C2 = L2.p2.x * L2.p1.y - L2.p1.x * L2.p2.y; 

    if (EQ(A1 * B2, B1 * A2))    { 
        if (EQ( (A1 + B1) * C2, (A2 + B2) * C1 )) { 
            return COLINE; 
        } else { 
            return PARALLEL; 
        } 
    } else { 
        P.x = (B2 * C1 - B1 * C2) / (A2 * B1 - A1 * B2); 
        P.y = (A1 * C2 - A2 * C1) / (A2 * B1 - A1 * B2); 
        return CROSS; 
    } 
} 
// 计算两条三维直线的交点，结果在参数P中返回 
// 返回值说明了两条直线的位置关系 COLINE   -- 共线  PARALLEL -- 平行  CROSS    -- 相交  NONCOPLANAR -- 不公面 
int CalCrossPoint(Line3D L1, Line3D L2, Point3D& P) 
{ 
    // todo 
    return 0; 
} 
// 计算点P到直线L的最近点 
Point NearestPointToLine(Point P, Line L)  
{ 
    Point result; 
    double a, b, t; 

    a = L.p2.x - L.p1.x; 
    b = L.p2.y - L.p1.y; 
    t = ( (P.x - L.p1.x) * a + (P.y - L.p1.y) * b ) / (a * a + b * b); 

    result.x = L.p1.x + a * t; 
    result.y = L.p1.y + b * t; 
    return result; 
} 
// 计算点P到线段L的最近点 
Point NearestPointToLineSeg(Point P, Line L)  
{ 
    Point result; 
    double a, b, t; 

    a = L.p2.x - L.p1.x; 
    b = L.p2.y - L.p1.y; 
    t = ( (P.x - L.p1.x) * a + (P.y - L.p1.y) * b ) / (a * a + b * b); 

    if ( GEQ(t, 0) && LEQ(t, 1) ) { 
        result.x = L.p1.x + a * t; 
        result.y = L.p1.y + b * t; 
    } else { 
        if ( Norm(P - L.p1) < Norm(P - L.p2) ) { 
            result = L.p1; 
        } else { 
            result = L.p2; 
        } 
    } 
    return result; 
} 
// 计算险段L1到线段L2的最短距离 
double MinDistance(Line L1, Line L2)  
{ 
    double d1, d2, d3, d4; 

    if (LineSegIntersect(L1, L2)) { 
        return 0; 
    } else { 
        d1 = Norm( NearestPointToLineSeg(L1.p1, L2) - L1.p1 ); 
        d2 = Norm( NearestPointToLineSeg(L1.p2, L2) - L1.p2 ); 
        d3 = Norm( NearestPointToLineSeg(L2.p1, L1) - L2.p1 ); 
        d4 = Norm( NearestPointToLineSeg(L2.p2, L1) - L2.p2 ); 

        return min( min(d1, d2), min(d3, d4) ); 
    } 
} 
// 求二维两直线的夹角， 
// 返回值是0~Pi之间的弧度 
double Inclination(Line L1, Line L2) 
{ 
    Point u = L1.p2 - L1.p1; 
    Point v = L2.p2 - L2.p1; 
    return acos( (u & v) / (Norm(u)*Norm(v)) ); 
} 
// 求三维两直线的夹角， 
// 返回值是0~Pi之间的弧度 
double Inclination(Line3D L1, Line3D L2) 
{ 
    Point3D u = L1.p2 - L1.p1; 
    Point3D v = L2.p2 - L2.p1; 
    return acos( (u & v) / (Norm(u)*Norm(v)) ); 
} 
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//多边行问题:
//
// 判断点p是否在凸多边形poly内 
// poly的顶点数目要大于等于3 
// 返回值为： 
// INSIDE  -- 点在poly内 
// BORDER  -- 点在poly边界上 
// OUTSIDE -- 点在poly外 
int InsideConvex(Point p, const Polygon& poly) // 判断点p是否在凸多边形poly内 
{ 
    Point q(0, 0); 
    Line side; 
    int i, n = poly.size(); 

    for (i = 0; i < n; i++) { 
        q.x += poly[i].x; 
        q.y += poly[i].y; 
    } 
    q.x /= n; 
    q.y /= n; 
    for (i = 0; i < n; i++) { 
        side.p1 = poly[i]; 
        side.p2 = poly[(i+1)%n]; 
        if (OnLineSeg(p, side)) { 
            return BORDER; 
        } else if (!SameSide(p, q, side)) { 
            return OUTSIDE; 
        } 
    } 
    return INSIDE; 
} 

// 判断多边形poly是否是凸的 
bool IsConvex(const Polygon& poly) // 判断多边形poly是否是凸的 
{ 
    int i, n, rel; 
    Line side; 

    n = poly.size(); 
    if (n < 3) return false; 
    side.p1 = poly[0]; 
    side.p2 = poly[1]; 
    rel = Relation(poly[2], side); 
    for (i = 1; i < n; i++) { 
        side.p1 = poly[i]; 
        side.p2 = poly[(i+1)%n]; 
        if (Relation(poly[(i+2)%n], side) != rel) return false; 
    } 
    return true; 
} 
// 判断点p是否在简单多边形poly内, 多边形可以是凸的或凹的 
// poly的顶点数目要大于等于3 
// 返回值为： 
// INSIDE  -- 点在poly内 
// BORDER  -- 点在poly边界上 
// OUTSIDE -- 点在poly外 
int InsidePolygon(const Polygon& poly, Point p) // 判断点p是否在简单多边形poly内, 多边形可以是凸的或凹的 
{ 
    int i, n, count; 
    Line ray, side; 

    n = poly.size(); 
    count = 0;     
    ray.p1    = p; 
    ray.p2.y  = p.y; 
    ray.p2.x  = - INF; 

    for (i = 0; i < n; i++) {                 
        side.p1 = poly[i]; 
        side.p2 = poly[(i+1)%n]; 

        if( OnLineSeg(p, side) ) { 
            return BORDER; 
        } 
        // 如果side平行x轴则不作考虑 
        if ( EQ(side.p1.y, side.p2.y) ) { 
            continue; 
        } 
        if (OnLineSeg(side.p1, ray)) { 
            if (GT(side.p1.y, side.p2.y)) count++; 
        } else if (OnLineSeg(side.p2, ray)) { 
            if ( GT(side.p2.y, side.p1.y)) count++; 
        } else if (LineSegIntersect(ray, side)) { 
            count++; 
        } 
    }    
    return ((count % 2 == 1) ? INSIDE : OUTSIDE); 
} 
// 判断线段是否在多边形内 (线段的点可能在多边形上)
// 多边形可以是任意简单多边形 
bool InsidePolygon(const Polygon& poly, Line L) // 判断线段是否在多边形内 (线段的点可能在多边形上)
{    
    bool result; 
    int n, i; 
    Points points; 
    Point p; 
    Line side; 

    result = ( (InsidePolygon(poly, L.p1) != OUTSIDE) &&  
            (InsidePolygon(poly, L.p2) != OUTSIDE) ); 

    if (!result) return false; 

    n = poly.size();     
    for (i = 0; i < n; i++) { 
        side.p1 = poly[i]; 
        side.p2 = poly[(i+1)%n]; 

        if ( OnLineSeg(L.p1, side) ) { 
            points.push_back(L.p1); 
        } else if ( OnLineSeg(L.p2, side) ) { 
            points.push_back(L.p2); 
        } else if ( OnLineSeg(side.p1, L) ) { 
            points.push_back(side.p1); 
        } else if ( OnLineSeg(side.p2, L) ) { 
            points.push_back(side.p2); 
        } else if( LineSegIntersect(side, L) ) { 
            return false; 
        } 
    } 
    // 对交点进行排序 
    sort(points.begin(), points.end()); 

    for (i = 1; i < points.size(); i++) { 
        if (points[i-1] != points[i]) { 
            p.x = (points[i-1].x + points[i].x) / 2.0; 
            p.y = (points[i-1].y + points[i].y) / 2.0; 
            if ( InsidePolygon(poly, p) == OUTSIDE ) { 
                return false; 
            } 
        } 
    } 
    return true;   
} 
// 寻找凸包 graham 扫描法 
// 生成的多边形顶点按逆时针方向排列 
bool GrahamComp(const Point& left, const Point& right) 
{ 
    if (EQ(left.angle, right.angle)) { 
        return (left.dis < right.dis); 
    } else { 
        return (left.angle < right.angle); 
    } 
} 

void GrahamScan(Points& points, Polygon& result) 
{ 
    int i, k, n; 
    Point p; 

    n = points.size(); 
    result.clear(); 

    if (n < 3) return; 

    // 选取points中y坐标最小的点points[k]， 
    // 如果这样的点有多个，则取最左边的一个 
    k = 0; 
    for (i = 1; i < n; i++ ) { 
        if (EQ(points[i].y, points[k].y)) { 
            if (points[i].x <= points[k].x) k = i; 
        } else if (points[i].y < points[k].y) { 
            k = i; 
        }        
    } 
    swap(points[0], points[k]); 

    // 现在points中y坐标最小的点在points[0] 
    // 计算每个点相对于points[0]的极角和距离 
    for (i = 1; i < n; i++) { 
        points[i].angle = atan2(points[i].y - points[0].y, points[i].x - points[0].x); 
        points[i].dis   = Norm(points[i] - points[0]); 
    } 

    // 对顶点按照相对points[0]的极角从小到大进行排序 
    // 对于极角相同的按照距points[0]的距离从小到大排序 
    sort(points.begin() + 1, points.end(), GrahamComp); 

    // 下面计算凸包 
    result.push_back(points[0]); 
    for (i = 1; i < n; i++) { 
        // 如果有极角相同的点，只取相对于points[0]最远的一个 
        if ((i + 1 < n) && EQ(points[i].angle, points[i+1].angle)) continue; 
        if (result.size() >= 3) { 
            p = result[result.size() - 2]; 
            while ( GEQ((points[i] - p)*(result.back() - p), 0) ) 
            { 
                result.pop_back(); 
                p = result[result.size() - 2]; 
            } 
        } 
        result.push_back( points[i] );       
    } 
} 
// 用有向直线line切割凸多边形， 
// result[LEFT]和result[RIGHT]分别保存被切割后line的左边和右边部分 
// result[ONLINE]没有用到，只是用来作为辅助空间 
// 返回值是切割多边形的切口的长度， 
// 如果返回值是0 则说明未作切割。 
// 当未作切割时，如果多边形在该直线的右侧，则result[RIGHT]等于该多边形，否则result[LEFT]等于该多边形 
// 注意：被切割的多边形一定要是凸多边形，顶点按照逆时针排列 
// 可利用这个函数来求多边形的核，初始的核设为一个很大的矩形，然后依次用多边形的每条边去割 
double CutConvex(const Polygon& poly, const Line& line, Polygon result[3]) 
{ 
    vector<Point> points; 
    Line side; 
    Point p; 
    int i,n, cur, pre; 

    result[LEFT].clear(); 
    result[RIGHT].clear(); 
    result[ONLINE].clear(); 
    n = poly.size(); 
    if (n == 0) return 0; 
    pre = cur = Relation(poly[0], line);     

    for (i = 0; i < n; i++) { 
        cur = Relation(poly[(i+1)%n], line); 
        if (cur == pre) { 
            result[cur].push_back(poly[(i+1)%n]); 
        } else { 
            side.p1 = poly[i]; 
            side.p2 = poly[(i+1)%n]; 
            CalCrossPoint(side, line, p);            
            points.push_back(p); 
            result[pre].push_back(p); 
            result[cur].push_back(p); 
            result[cur].push_back(poly[(i+1)%n]); 
            pre = cur; 
        } 
    } 

    sort(points.begin(), points.end()); 

    if (points.size() < 2) { 
        return 0; 
    } else {         
        return Norm(points.front() - points.back()); 
    } 
} 
// 求多边形的重心，适用于凸的或凹的简单多边形 
// 该算法可以一边读入多边性的顶点一边计算重心 
Point CenterOfPolygon(const Polygon& poly) 
{ 
    Point p, p0, p1, p2, p3; 
    double m, m0; 

    p1 = poly[0]; 
    p2 = poly[1]; 
    p.x = p.y = m = 0; 
    for (int i = 2; i < poly.size(); i++) { 
        p3 = poly[i]; 
        p0.x = (p1.x + p2.x + p3.x) / 3.0; 
        p0.y = (p1.y + p2.y + p3.y) / 3.0; 
        m0 = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x; 
        if (ZERO(m + m0)) { 
            m0 += EPS;  // 为了防止除0溢出，对m0做一点点修正 
        } 
        p.x = (m * p.x + m0 * p0.x) / (m + m0); 
        p.y = (m * p.y + m0 * p0.y) / (m + m0); 
        m = m + m0; 
        p2 = p3; 
    } 
    return p; 
} 
// 判断两个矩形是否相交 
// 如果相邻不算相交 
bool Intersect(Rect_2 r1, Rect_2 r2) 
{ 
    return ( max(r1.xl, r2.xl) < min(r1.xh, r2.xh) && 
            max(r1.yl, r2.yl) < min(r1.yh, r2.yh) ); 
} 
// 判断矩形r2是否可以放置在矩形r1内 
// r2可以任意地旋转 
//发现原来的给出的方法过不了OJ上的无归之室这题，
//所以用了自己的代码
bool IsContain(Rect r1, Rect r2)      //矩形的w>h
{ 
    if(r1.w >r2.w && r1.h > r2.h) return true;
    else
    {
        double r = sqrt(r2.w*r2.w + r2.h*r2.h) / 2.0;
        double alpha = atan2(r2.h,r2.w);
        double sita = asin((r1.h/2.0)/r);
        double x = r * cos(sita - 2*alpha);
        double y = r * sin(sita - 2*alpha);
        if(x < r1.w/2.0 && y < r1.h/2.0 && x > 0 && y > -r1.h/2.0) return true;
        else return false;
    }
} 
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
//圆
Point Center(const Circle & C) //圆心
{      
    return C.c;      
}    

double CommonArea(const Circle & A, const Circle & B) //两个圆的公共面积       
{      
    double area = 0.0;      
    const Circle & M = (A.r > B.r) ? A : B;      
    const Circle & N = (A.r > B.r) ? B : A;      
    double D = Distance(Center(M), Center(N));      
    if ((D < M.r + N.r) && (D > M.r - N.r))      
    {      
        double cosM = (M.r * M.r + D * D - N.r * N.r) / (2.0 * M.r * D);      
        double cosN = (N.r * N.r + D * D - M.r * M.r) / (2.0 * N.r * D);      
        double alpha = 2.0 * acos(cosM);      
        double beta  = 2.0 * acos(cosN);      
        double TM = 0.5 * M.r * M.r * sin(alpha);      
        double TN = 0.5 * N.r * N.r * sin(beta);      
        double FM = (alpha / 360.0) * Area(M);      
        double FN = (beta / 360.0) * Area(N);      
        area = FM + FN - TM - TN;      
    }      
    else if (D <= M.r - N.r)      
    {      
        area = Area(N);      
    }      
    return area;      
} 

bool IsInCircle(const Circle & C, const Rect_2 & rect)//判断圆是否在矩形内(不允许相切)
{      
    return (GT(C.c.x - C.r, rect.xl)
            &&  LT(C.c.x + C.r, rect.xh)
            &&  GT(C.c.y - C.r, rect.yl)
            &&  LT(C.c.y + C.r, rect.yh));      
}  

//判断2圆的位置关系
//返回: 
//BAOHAN   = 1;        // 大圆包含小圆
//NEIQIE   = 2;        // 内切
//XIANJIAO = 3;        // 相交
//WAIQIE   = 4;        // 外切
//XIANLI   = 5;        // 相离
int CirCir(const Circle &c1, const Circle &c2)//判断2圆的位置关系
{
    double dis = Distance(c1.c,c2.c);
    if(LT(dis,fabs(c1.r-c2.r))) return BAOHAN;
    if(EQ(dis,fabs(c1.r-c2.r))) return NEIQIE;
    if(LT(dis,c1.r+c2.r) && GT(dis,fabs(c1.r-c2.r))) return XIANJIAO;
    if(EQ(dis,c1.r+c2.r)) return WAIQIE;
    return XIANLI;
}
////////////////////////////////////////////////////////////////////////

Point p[N];
pair<double, int> ans[N];

int main() {

    int n;
    scanf("%d", &n);
    REPP(i, 1, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        p[i] = Point(x, y);
    }
    Line line = Line(p[1], p[2]);
    REPP(i, 3, n) {
        ans[i] = {Distance(p[i], line), i};
    }
    //REPP(i, 1, n) {
    //    cout << ans[i].first << ' ' << ans[i].second << endl;
    //}
    sort(ans + 3, ans + n + 1);
    //REPP(i, 1, n) {
    //    cout << ans[i].first << ' ' << ans[i].second << endl;
    //}
    REPP(i, 3, n) if (ans[i].first > EPS) {
        cout << 1 << ' ' << 2 << ' ' << ans[i].second << endl;
        return 0;
    }
    assert(0);

    return 0;
}
