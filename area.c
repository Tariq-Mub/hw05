#include <stdio.h>
#include <math.h>


struct point
{
    double x;
    double y;
};


struct triangle
{
    struct point a;
    struct point b;
    struct point c;
};

double area (struct triangle t);

double area (struct triangle t)
{
    double s;

    s = 0.5 * fabs ((t.b.x - t.a.x) * (t.c.y - t.a.y) - (t.c.x -
            t.a.x) * (t.b.y - t.a.y));
    return s;
}

int main (void)
{
    struct triangle t = (struct triangle) { {0, 0.}, {3., 0}, {0., 4.} };

    double a = area (t);

    printf ("area = %f\n", a);

    return 0;
}
