#ifndef SNAKE_H
#define SNAKE_H

#include <windows.h>
#include <vector>

#define width 50
#define height 25

using namespace std;

class Snake
{
private:
    COORD pos; // position
    int len; // length
    int vel; // velocity
    char dir;
    vector <COORD> body;

public:
    Snake(COORD pos, int vel); // constructor
    void direction(char dir); // change direction of the snake
    void move_snake(); // move the snake in the direction
    COORD get_pos(); // get current position of the snake
    vector <COORD> get_body();

    bool eaten(COORD food_pos);
    void grow();
    bool collided();

};

#endif
