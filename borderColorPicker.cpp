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
    unsigned right = p.x + borderSize;
    unsigned down = p.y + borderSize;
    int bord = borderSize*borderSize;
    if (left < 0 || up < 0 || right >= img.width() || down >= img.height()){
      return fillColor;
    }
    for(unsigned k = (unsigned) left; k <= right; k++) {
      for(unsigned l = (unsigned) up; l <= down; l++) {
        int dis = (p.x-k)*(p.x-k) + (p.y-l)*(p.y-l);
        if (dis <= bord){
          // cout << k << "," << l << endl;
          // HSLAPixel curr = *img.getPixel(k,l);
          if(p.c.color.dist(*img.getPixel(k,l)) >= tolerance) {
            return fillColor;
          }
        }
      }
    }
    return *img.getPixel(p.x,p.y);
}
