/**
 * @file p1_test.cpp - tests for lab1 assignment
 * @author Kevin Lundeen 
 * @see "Seattle University, CPSC 2430, Spring 2018"
 */
#include <iostream>
#include <sstream>
#include <gtest/gtest.h>
#include "Menagerie.h"
#include "Terminal.h"
#include "Cannon.h"


using namespace std;


TEST(P1Test, Test_Reset) {
   Terminal t(false);  // false -> don't block on keystrokes
   Menagerie game(t);
   game.resetGame();
   Cannon* c;
   if ((c = dynamic_cast<Cannon*>(game.critters.get(0)))){
	  EXPECT_EQ(true, (c->getHeading() == Critter::Direction::EAST));
	  game.clear();
	  SUCCEED();
   }
   else
	   FAIL();
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

