#ifndef FOOD_H
#define FOOD_H

#include <windows.h>
#include <cstdlib>

#define width 50
#define height 25

class Food
{
private:
    COORD pos;

public:
    void gen_food();
    COORD get_pos();
};

#endif // FOOD_H
