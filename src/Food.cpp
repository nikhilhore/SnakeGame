#include "Food.h"

void Food::gen_food(){
    pos.X= (rand() % (width-1))+ 2;
    pos.Y= (rand() % (height-1))+ 2;
}

COORD Food::get_pos(){ return pos; }
