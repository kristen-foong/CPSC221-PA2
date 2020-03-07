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
    // if(p.x <= borderSize || p.y <= borderSize || p.x >= img.width()-borderSize || p.y >= img.height()-borderSize) {
    //   newFill = fillColor;
    // }
    //if a single point outside p is within the tolerance, and p is outside the tolerance, we color p with the fillColor
    for(int i = p.x - borderSize; i < p.x + borderSize; i++) {
      for(int j = p.y - borderSize; j < p.y + borderSize; j++) {
        HSLAPixel curr = *(img.getPixel(i,j));
        int bord = borderSize*borderSize;
        int dist = (p.x-i)*(p.x-i) + (p.y-j)*(p.y-j);
        if ((i < 0 || j < 0 || i >= (int)img.width() || j >= (int)img.height()) && dist < bord){
          return fillColor;
        }
        else if(p.c.color.dist(curr) >= tolerance && dist < bord && curr != fillColor) {
          return fillColor;
        }
      }
    }
    return newFill;
}
