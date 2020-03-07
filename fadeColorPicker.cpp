#include "fadeColorPicker.h"

fadeColorPicker::fadeColorPicker(double fade)
{
    /* your code here */
    fadeFactor = fade;
}

HSLAPixel fadeColorPicker::operator()(point p)
{
    /* your code here */
    int dist = pow(p.x - p.c.x,2) + pow(p.y - p.c.y,2);
    int newL = p.c.color.l * pow(fadeFactor,dist);
    return p.c.color;
}
