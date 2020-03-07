#include "borderColorPicker.h"

borderColorPicker::borderColorPicker(unsigned int borderSize, HSLAPixel fillColor, PNG &img, double tolerance)
{
    /* your code here */
    this->borderSize = borderSize;
    this->fillColor = fillColor;
    this->img = img;
    this->tolerance = tolerance;
}

HSLAPixel borderColorPicker::operator()(point p)
{
    /* your code here */
    HSLAPixel newFill = p.c.color;
    if(p.c.x < borderSize || p.c.y < borderSize || p.c.x > img.width()-borderSize || p.c.y > img.height()-borderSize) {
      newFill = fillColor;
    }
    return newFill;
}
