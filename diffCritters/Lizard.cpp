/*
 * @file: Lizard.cpp
 * @author: Joe Noonan
 * @ "Seattle University, CPSC 2430, Spring 2018"
 */

#include "Lizard.h"
#include "RGB.h"

Lizard::Lizard(int row, int col) : r(row), c(col){
  state = BUNCHED;
  heading = EAST;
}

void Lizard::move(){
  if(heading == NORTH){
    if(state == STRAIGHT){
      state = BUNCHED;
    }
    else{
      state = STRAIGHT;
      r--;
      r--;
    }
  }
  else if(heading == SOUTH){
    if(state == STRAIGHT){
      state = BUNCHED;
    }
    else{
      state = STRAIGHT;
      r++;
      r++;
    }
  }
  else if(heading == EAST){
    if(state == STRAIGHT){
      state = BUNCHED;
    }
    else{
      state = STRAIGHT;
      c++;
      c++;
    }
  }
  else if(heading == WEST){
    if(state == STRAIGHT){
      state = BUNCHED;
    }
    else{
      state = STRAIGHT;
      c--;
      c--;
    }
  }
}

void Lizard::reverse(){
  if(heading == NORTH)
    heading = SOUTH;
  else if(heading == EAST)
    heading = WEST;
  else if(heading == SOUTH)
    heading = NORTH;
  else
    heading = EAST;
}

void Lizard::rotate(){
  if(heading == NORTH)
    heading = EAST;
  else if(heading == EAST)
    heading = SOUTH;
  else if(heading == SOUTH)
    heading = WEST;
  else
    heading = NORTH;
}

void Lizard::render(PixelMatrix &pxm) const {
  pxm.paint(r, c, RGB::RED);
  //RGB color;
  int row, col;
  pxm.getSize(row, col);
  if(state == STRAIGHT){
    if(eastwest()){
       pxm.paint(r, c - 1, RGB::RED);
       pxm.paint(r, c - 2, RGB::RED);
       pxm.paint(r, c - 3, RGB::RED);
       pxm.paint(r, c - 4, RGB::RED);
       pxm.paint(r, c - 5, RGB::RED);
       pxm.paint(r, c - 6, RGB::RED);
	   pxm.paint(r, c - 7, RGB::RED);
	   pxm.paint(r - 1, c - 2, RGB::RED);
	   pxm.paint(r + 1, c - 1, RGB::RED);
	   pxm.paint(r - 1, c - 6, RGB::RED);
	   pxm.paint(r + 1, c - 5, RGB::RED);
    }
    else {
       pxm.paint(r - 1, c, RGB::RED);
       pxm.paint(r - 2, c, RGB::RED);
       pxm.paint(r - 3, c, RGB::RED);
       pxm.paint(r - 4, c, RGB::RED);
       pxm.paint(r - 5, c, RGB::RED);
       pxm.paint(r - 6, c, RGB::RED);
	   pxm.paint(r - 7, c, RGB::RED);
	   pxm.paint(r - 2, c - 1, RGB::RED);
	   pxm.paint(r - 1, c + 1, RGB::RED);
	   pxm.paint(r - 6, c - 1, RGB::RED);
	   pxm.paint(r - 5, c + 1, RGB::RED);
    }
  }
  else {
    if(eastwest()){
		pxm.paint(r, c - 1, RGB::RED);
		pxm.paint(r, c - 2, RGB::RED);
		pxm.paint(r, c - 3, RGB::RED);
		pxm.paint(r, c - 4, RGB::RED);
		pxm.paint(r, c - 5, RGB::RED);
		pxm.paint(r, c - 6, RGB::RED);
		pxm.paint(r, c - 7, RGB::RED);
		pxm.paint(r - 1, c - 1, RGB::RED);
		pxm.paint(r + 1, c - 2, RGB::RED);
		pxm.paint(r - 1, c - 5, RGB::RED);
		pxm.paint(r + 1, c - 6, RGB::RED);
    }
    else {
		pxm.paint(r - 1, c, RGB::RED);
		pxm.paint(r - 2, c, RGB::RED);
		pxm.paint(r - 3, c, RGB::RED);
		pxm.paint(r - 4, c, RGB::RED);
		pxm.paint(r - 5, c, RGB::RED);
		pxm.paint(r - 6, c, RGB::RED);
		pxm.paint(r - 7, c, RGB::RED);
		pxm.paint(r - 1, c - 1, RGB::RED);
		pxm.paint(r - 2, c + 1, RGB::RED);
		pxm.paint(r - 5, c - 1, RGB::RED);
		pxm.paint(r - 6, c + 1, RGB::RED);
    }
  }
}

bool InchWorm::eastwest() const {
  return (heading == EAST || heading == WEST);
}

int InchWorm::sign() const {
  if(heading == EAST || heading == SOUTH)
    return +1;
  else
    return -1;
}
