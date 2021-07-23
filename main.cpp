#include <iostream>
#include <conio.h>
#include <ctime>

#include <Snake.h>
#include <Food.h>

#define width 50
#define height 25

using namespace std;

Snake snake({width/2, height/2}, 1);
Food food;

int score;

void board(){
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();

    vector <COORD> snake_body = snake.get_body();
    cout << "\n\t\t\tSCORE: " << score << "\t\tPress 'n' to exit" << "\n\n";

    for (int i=0; i<height; ++i){
        cout << "\t\t\t#";
        for (int j=0; j<width-2; ++j){
            if (i==0 || i==height-1) cout << "#";
            else if (i==snake_pos.Y && j+1==snake_pos.X) cout << "0";
            else if (i==food_pos.Y && j+1==food_pos.X) cout << "*";
            else {
                bool isBodyPart = false;
                for (int k=0; k<snake_body.size()-1; ++k){
                    if (i==snake_body[k].Y && j+1==snake_body[k].X){
                        cout << 'o';
                        isBodyPart= true;
                        break;
                    }
                }
                if (!isBodyPart) cout << ' ';
            }
        }
        cout << "#\n";
    }
}

int main(){
    score=0;
    srand(time(0));
    food.gen_food();
    bool game_over= false;
    while(!game_over){
        board();
        if (kbhit()){
            char prev='n';
            char get_char= getch();
            if (prev==get_char) break;
            switch(get_char){
                case 'w': snake.direction('u'); prev='s'; break;
                case '8': snake.direction('u'); prev='2'; break;
                case 's': snake.direction('d'); prev='w'; break;
                case '2': snake.direction('d'); prev='8'; break;
                case 'a': snake.direction('l'); prev='d'; break;
                case '4': snake.direction('l'); prev='6'; break;
                case 'd': snake.direction('r'); prev='a'; break;
                case '6': snake.direction('r'); prev='4'; break;
            }
        }
        if (snake.collided()) game_over= true;
        if (snake.eaten(food.get_pos())){
            food.gen_food();
            snake.grow();
            score+=10;
        }
        snake.move_snake();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }
    return 0;
}
