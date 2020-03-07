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
    int dist = sqrt(pow(p.c.x - p.x,2) + pow(p.c.y - p.y,2));
    color.l = p.c.color.l * pow(fadeFactor,dist);
    return color;
}
