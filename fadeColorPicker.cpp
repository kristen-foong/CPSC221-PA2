#include "fadeColorPicker.h"

fadeColorPicker::fadeColorPicker(double fade)
{
    /* your code here */
    fadeFactor = fade;
}

HSLAPixel fadeColorPicker::operator()(point p)
{
    /* your code here */
    HSLAPixel color = p.c.color;
    // double dist = sqrt(pow(p.c.x - p.x,2) + pow(p.c.y - p.y,2));
    double dist = sqrt((p.c.x-p.x)*(p.c.x-p.x) + (p.c.y-p.y)*(p.c.y-p.y));
    color.l = p.c.color.l * pow(fadeFactor,dist);
    return color;
}
