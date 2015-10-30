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
double distance (struct point z, struct point q);
double CircleRadius (double perimeter, double a);

//returns area of triangle
double area (struct triangle t)
{
    double s;

    s = 0.5 * fabs ((t.b.x - t.a.x) * (t.c.y - t.a.y) - (t.c.x -
            t.a.x) * (t.b.y - t.a.y));
    return s;
}


//calculate distance
double distance (struct point z, struct point q)
{
    double dist;

    dist = sqrt ((q.x - z.x) * (q.x - z.x) + (q.y - z.y) * (q.y - z.y));
    return dist;
}

//calculate radius of inscribed cirlce
double CircleRadius (double perimeter, double a){

    double radius;
    radius = (2 * a) / perimeter;
    printf ("The radius of the inscribed cirlce is %f \n", radius);
    return radius;
}


int main (void)
{
    struct triangle t = (struct triangle) { {0., 0.}, {3., 0}, {0., 4.} };

    double a = area (t);

    printf ("area = %f\n", a);

    struct point z = (struct point) { 2., 2. };
    struct point q = (struct point) { 4., 4. };
    struct point g = (struct point) { 8., 8. };
    double d = distance (z, q); //calculates distance between points z, q
    double f = distance (z, g); //calculates distance between points gz
    double k = distance (g, q); //calculates distance between points qg

    printf ("distance between z, q is %f \n", d);
    printf ("distance between z, g is %f \n", f);
    printf ("distance between q, g is %f \n", k);

    double perimeter = d + f + k;
    double radius = CircleRadius(perimeter, a);
    printf ("radius of circle inscribed is %f \n", radius);  

    return 0;
}
