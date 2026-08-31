#include <iostream>
using namespace std;

/*
    HDOJ 2056 Rectangles   
*/

struct Point{
    double x, y;
};

struct Rect {
    Point ld, rt;
};

Rect r1, r2, r3, r4;

int main() {
    while (cin >> r1.ld.x >> r1.ld.y >> r1.rt.x >> r1.rt.y >> r2.ld.x >> r2.ld.y >> r2.rt.x >> r2.rt.y) {
        r3.ld.x = min(r1.ld.x, r1.rt.x);
        r3.ld.y = min(r1.ld.y, r1.rt.y);
        r3.rt.x = max(r1.ld.x, r1.rt.x);
        r3.rt.y = max(r1.ld.y, r1.rt.y);

        r4.ld.x = min(r2.ld.x, r2.rt.x);
        r4.ld.y = min(r2.ld.y, r2.rt.y);
        r4.rt.x = max(r2.ld.x, r2.rt.x);
        r4.rt.y = max(r2.ld.y, r2.rt.y);

        double minX, maxX, minY, maxY;
        maxX = min(r3.rt.x, r4.rt.x);
        minX = max(r3.ld.x, r4.ld.x);
        maxY = min(r3.rt.y, r4.rt.y);
        minY = max(r3.ld.y, r4.ld.y);
        double width = maxX - minX;
        double height = maxY - minY;
        double area = 0.0;
        if( width > 0 && height > 0) {
            area = width * height;
        }
        printf("%.2lf\n", area);
    }
    
    return 0;
}