#include "Snake.h"

Snake::Snake(COORD pos, int vel)
{
    this->pos= pos;
    this->vel= vel;
    len= 1;
    dir= 'n';
    body.push_back(pos);
}

void Snake::direction(char dir) {this->dir= dir;}
void Snake::grow(){len++;}
COORD Snake::get_pos(){ return pos;}

vector <COORD> Snake::get_body(){return body;}

void Snake::move_snake(){
    switch(dir){
        case 'u': pos.Y-= vel; break; // decrease y coordinate to move down
        case 'd': pos.Y+= vel; break; // increase y coordinate to move up
        case 'l': pos.X-= vel; break; // decrease x coordinate to move left
        case 'r': pos.X+= vel; break; // increase x coordinate to move right
    }
    // if (pos.X>width-2) pos.X=1;
    // if (pos.X<1) pos.X= width-2;
    // if (pos.Y>height-2) pos.Y=1;
    // if (pos.Y<1) pos.Y= height-2;

    body.push_back(pos);
    if (body.size()>len) body.erase(body.begin());
}

bool Snake::eaten(COORD food_pos) {
    if(food_pos.X==pos.X && food_pos.Y== pos.Y) return true;
    return false;
}

bool Snake::collided(){
    if (pos.X<1 || pos.X>width-2 || pos.Y<1 || pos.Y>height-2) return true;
    for (int i=0; i<len-1; ++i){
        if (pos.X==body[i].X && pos.Y==body[i].Y) return true;
    }
    return false;
}
