#ifndef DICE_H
#define DICE_H

#include <cstdlib>

class dice
{
public:
    dice();
    static int roll(int numDice = 1, int sides = 20, int bonus = 0);
};

#endif // DICE_H
