/*
 * @file: Menagerie.cpp - Menagerie game
 * @author: Joe Noonan
 * @see "Seattle Iniversity, CPSC 2430, Spring 2018"
 */

#include "Menagerie.h"
#include "InchWorm.h"
#include "Cannon.h"
#include "Cannonball.h"
#include "adt/Display.h"
#include "QueueL.h"
#include "Terminal.h"
#include "adt/Critter.h"
#include "Pacer.h"

void Menagerie::resetGame(){
  clear();
  cannonballs = 0;
  int rows, cols;
  display.getSize(rows, cols);
  Cannon *c = new Cannon((int)rows - 2, (int)cols/2);
  critters.append(c);

  critters.append(new Pacer(.05));  

  InchWorm *worm = new InchWorm(10, 10);
  InchWorm *worm2 = new InchWorm(15, 15);
  InchWorm *worm3 = new InchWorm(20, 20);
  //Lizard lizard = new Lizard(5, 5);

  int cody = this->critters.append(worm);
  int cody2 = this->critters.append(worm2);
  int cody3 = this->critters.append(worm3);
  //int lizardy = this->critters.append(lizard);

  this->events.enqueue(Event(MOVE, cody));
  this->events.enqueue(Event(MOVE, cody2));
  this->events.enqueue(Event(MOVE, cody3));
  //this->events.enqueue(Event(MOVE, lizardy));
}

bool Menagerie::processEvent(){
  Event a = this->events.peek();
  
  if(a.type == MOVE){
    for(int i = 1; i < critters.size(); i++){
      if(critters.get(i) != nullptr){
        critters.get(i)->move();
      }
    }
    events.enqueue(Event(MOVE));
  }
  else if(a.data == 'q'){
    return false;
  }
  else if(a.data == 'h'){
    critters.get(0)->move();
  }
  else if(a.data == 'g'){
    critters.get(0)->reverse();
  }
  else if(a.data == 'i'){
    shoot();
  }

  this->events.dequeue();
  return true;
}

void Menagerie::processCollisions(){
  int rows, cols;
  display.getSize(rows, cols);

  for(int i = 0; i < pxms.size() - 1; i++)
    for(int j = i + 1; j < pxms.size(); j++)
      for(int r = 0; r < rows; r++)
        for(int c = 0; c < cols; c++)
          if(!(pxms.get(i).get(r, c).transparent) && !(pxms.get(j).get(r, c).transparent)) {
            killCritter(i);
            killCritter(j);
          }
}

bool Menagerie::compositeScene(){
  int rows, cols;
  display.getSize(rows, cols);
  scene = PixelMatrix(rows, cols, RGB::BLACK);
  PixelMatrix old = scene;
  
  for(int i = 0; i < pxms.size(); i++)
    scene.overlay(pxms.get(i));
  
  refreshDisplay();

  if(scene != old){
    lastMovement = eventCount;
  }
  else {
    log("no movement");
    eventCount++;
  }

  return eventCount - lastMovement <= NO_MOVEMENT;
}

void Menagerie::shoot(){
  int rows, cols;
  display.getSize(rows, cols);
  cols = critters.get(0)-> getColumn();
  if(cannonballs < CANNON_BALLS){
    Cannonball *c2 = new Cannonball(rows-4,cols);
    int ball = this->critters.append(c2);
    this->events.enqueue(Event(MOVE, ball));
    cannonballs++;
  }
}
