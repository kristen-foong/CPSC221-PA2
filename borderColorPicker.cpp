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
    if(p.x-borderSize < borderSize || p.y - borderSize < borderSize) {
      newFill = fillColor;
    }
    // if(p.x + ) {
    //
    // }
    return newFill;
}
