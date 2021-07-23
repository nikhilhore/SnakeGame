#include "Food.h"

void Food::gen_food(){
    pos.X= 1+ (rand() % (width-2));
    pos.Y= 1+ (rand() % (height-2));
}

COORD Food::get_pos(){ return pos; }
