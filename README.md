# Menagerie

Old-School Terminal Shoot-Em-Up Game

Continuing on from Inchworm we're going to build a bit more of a game that includes: several critters traipsing back and forth on the screen, a user cannon that can shoot 7 cannonballs at the critters and move side to side

You have to have at least two critters that are either InchWorms or critters of your own making that behave somewhat like InchWorms. You also have to have at least one cannon that fires cannonballs until they run out (number of cannonballs is controlled by a constant in Menagerie.h).

The user controls the cannon with three different keys:

i - shoots a cannon (if there are any left) <br />
h - moves the cannon in it's current direction <br />
g - reverses the current direction of the cannon <br />


# Menagerie.cpp:
resetGame - reset the game to original state ready to play
processEvent - process next event from event queue
processCollisions - look for and process each collision by killing the colliding critters
compositeScene - compositing  all the critters renditions onto the scene
shoot - shoot a cannonball from the cannon

# Components:
Critters: InchWorm.h InchWorm2.cpp Pacer.h Pacer.cpp Cannon.h Cannon.cpp Cannonball.h Cannonball.cpp <br />
Display: Terminal.h Terminal.cpp adt/Display.h PixelMatrix.h PixelMatrix.cpp RGB.h RBG.cpp <br />
Game: Menagerie.h Menagerie2.cpp p1.cpp <br />

This assignment was assigned by Professor Kevin Lundeen at Seattle University.
