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
    // if(p.x <= borderSize || p.y <= borderSize || p.x >= img.width()-borderSize || p.y >= img.height()-borderSize) {
    //   newFill = fillColor;
    // }
    //if a single point outside p is within the tolerance, and p is outside the tolerance, we color p with the fillColor
    int left = (int)p.x - borderSize;
    int up = (int)p.y - borderSize;
    int dis = (p.x-left)*(p.x-left) + (p.y-up)*(p.y-up);
    int bord = borderSize*borderSize;
    if ((left < 0 || up < 0 || left >= (int)img.width() || up >= (int)img.height()) && dis <= bord){
      return fillColor;
    }
    for(int i = (int)(p.x - borderSize); i <= (int)(p.x + borderSize); i++) {
      for(int j = (int)(p.y - borderSize); j <= (int)(p.y + borderSize); j++) {
        HSLAPixel curr = *img.getPixel(i,j);
        if(p.c.color.dist(curr) >= tolerance && dis <= bord) {
          return fillColor;
        }
      }
    }
    return *img.getPixel(p.x,p.y);
}
