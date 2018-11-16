/*
 * @file: InchWorm.cpp
 * @author: Joe Noonan
 * @ "Seattle University, CPSC 2430, Spring 2018"
 */

#include "InchWorm.h"
#include "RGB.h"

InchWorm::InchWorm(int row, int col) : r(row), c(col){
  state = BUNCHED;
  heading = EAST;
}

void InchWorm::move(){
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

void InchWorm::reverse(){
  if(heading == NORTH)
    heading = SOUTH;
  else if(heading == EAST)
    heading = WEST;
  else if(heading == SOUTH)
    heading = NORTH;
  else
    heading = EAST;
}

void InchWorm::rotate(){
  if(heading == NORTH)
    heading = EAST;
  else if(heading == EAST)
    heading = SOUTH;
  else if(heading == SOUTH)
    heading = WEST;
  else
    heading = NORTH;
}

void InchWorm::render(PixelMatrix &pxm) const {
  pxm.paint(r, c, RGB::WHITE);
  //RGB color;
  int row, col;
  pxm.getSize(row, col);
  if(state == STRAIGHT){
    if(eastwest()){
       pxm.paint(r, c - 1, RGB::GREEN);
       pxm.paint(r, c - 2, RGB::WHITE);
       pxm.paint(r, c - 3, RGB::GREEN);
       pxm.paint(r, c - 4, RGB::WHITE);
       pxm.paint(r, c - 5, RGB::GREEN);
       pxm.paint(r, c - 6, RGB::WHITE);
    }
    else {
       pxm.paint(r - 1, c, RGB::GREEN);
       pxm.paint(r - 2, c, RGB::WHITE);
       pxm.paint(r - 3, c, RGB::GREEN);
       pxm.paint(r - 4, c, RGB::WHITE);
       pxm.paint(r - 5, c, RGB::GREEN);
       pxm.paint(r - 6, c, RGB::WHITE);
    }
  }
  else {
    if(eastwest()){
       pxm.paint(r, c - 1, RGB::GREEN);
       pxm.paint(r - 1, c - 1, RGB::WHITE);
       pxm.paint(r - 1, c - 2, RGB::GREEN);
       pxm.paint(r - 1, c - 3, RGB::WHITE);
       pxm.paint(r, c - 3, RGB::GREEN);
       pxm.paint(r, c - 4, RGB::WHITE);      
    }
    else {
       pxm.paint(r - 1, c, RGB::GREEN);
       pxm.paint(r - 1, c - 1, RGB::WHITE);
       pxm.paint(r - 2, c - 1, RGB::GREEN);
       pxm.paint(r - 3, c - 1, RGB::WHITE);
       pxm.paint(r - 3, c, RGB::GREEN);
       pxm.paint(r - 4, c, RGB::WHITE);
    }
  }
  /*
  if(state == STRAIGHT) {
    if(heading == NORTH) {//correct
      for(int i = 0; i < 7; i++) {
        if(i % 2 == 0)
          color = RGB::WHITE;
        else
          color = RGB::GREEN;
        pxm.paint(r - i, c, color);
      }
    }
    if(heading == SOUTH) {//correct
      for(int i = 0; i < 7; i++) {
        if(i % 2 == 0)
          color = RGB::WHITE;
        else
          color = RGB::GREEN;
        pxm.paint(r + i, c, color);
      }
    }
    if(heading == EAST) {//correct
      for(int i = 0; i < 7; i++) {
        if(i % 2 == 0)
          color = RGB::WHITE;
        else
          color = RGB::GREEN;
        pxm.paint(r, c - i, color);
      }
    }
    if(heading == WEST) {//correct
      for(int i = 0; i < 7; i++) {
        if(i % 2 == 0)
          color = RGB::WHITE;
        else
          color = RGB::GREEN;
        pxm.paint(r, c + i, color);
      }
    }
  }
  else {
    if(heading == NORTH) {//correct
      for(int i = 0; i < 2; i++) {
        if(i % 2 == 0)
          color = RGB::WHITE;
        else
          color = RGB::GREEN;
        pxm.paint(r + i, c, color);
      }
      for(int i = 2; i < 5; i++) {
        if(i % 2 == 0)
          color = RGB::GREEN;
        else
          color = RGB::WHITE;
        pxm.paint(r + (i-1), c - 1, color);
      }
      for(int i = 5; i < 7; i++) {
        if(i % 2 == 0)
          color = RGB::WHITE;
        else
          color = RGB::GREEN;
        pxm.paint(r + i, c, color);
      }
    }
    else if(heading == SOUTH) {//incorrect
      for(int i = 0; i < 2; i++) {
        if(i % 2 == 0)
          color = RGB::WHITE;
        else
          color = RGB::GREEN;
        pxm.paint(r - i, c, color);
      }
      for(int i = 2; i < 5; i++) {
        if(i % 2 == 0)
          color = RGB::GREEN;
        else
          color = RGB::WHITE;
        pxm.paint(r - (i-1), c - 1, color);
      }
      for(int i = 5; i < 7; i++) {
        if(i % 2 == 0)
          color = RGB::WHITE;
        else
          color = RGB::GREEN;
        pxm.paint(r - i, c, color);
      }
    }
    else if(heading == EAST){//incorrect
      for(int i = 0; i < 2; i++) {
        if(i % 2 == 0)
          color = RGB::WHITE;
        else
          color = RGB::GREEN;
        pxm.paint(r, c - i, color);
      }
      for(int i = 2; i < 5; i++) {
        if(i % 2 == 0)
          color = RGB::GREEN;
        else
          color = RGB::WHITE;
        pxm.paint(r - 1, c - (i+1), color);
      }
      for(int i = 5; i < 7; i++) {
        if(i % 2 == 0)
          color = RGB::WHITE;
        else
          color = RGB::GREEN;
        pxm.paint(r, c - i, color);
      }
    }
    else if(heading == WEST){ //incorrect
      for(int i = 0; i < 2; i++) {
        if(i % 2 == 0)
          color = RGB::WHITE;
        else
          color = RGB::GREEN;
        pxm.paint(r, c + 1, color);
      }
      for(int i = 2; i < 5; i++) {
        if(i % 2 == 0)
          color = RGB::GREEN;
        else
          color = RGB::WHITE;
        pxm.paint(r - 1, c + (i-1), color);
      }
      for(int i = 5; i < 7; i++) {
        if(i % 2 == 0)
          color = RGB::WHITE;
        else
          color = RGB::GREEN;
        pxm.paint(r, c + i, color);
      }
    } 
  }
  */
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
