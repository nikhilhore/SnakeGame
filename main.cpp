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
    cout << "\n\t\t\tFOOD POS: " << food_pos.X << " " << food_pos.Y
        << "  |  SNAKE POS: " << snake_pos.X << " " << snake_pos.Y
        << "  |  SCORE: " << score << "\n\t\t\tLeft click to Pause or Press 'n' to exit the game\n\n";

    for (int i=0; i<height; ++i){
        cout << "\t\t\t#";
        for (int j=0; j<width-2; ++j){
            if (i==0 || i==height-1) cout << "#";
            else if (i==snake_pos.Y && j+1==snake_pos.X) cout << "@";
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
            char get_char= getch();
            if (get_char=='n') break;
            switch(get_char){
                case 'w': snake.direction('u'); break;
                case '8': snake.direction('u'); break;
                case 's': snake.direction('d'); break;
                case '2': snake.direction('d'); break;
                case 'a': snake.direction('l'); break;
                case '4': snake.direction('l'); break;
                case 'd': snake.direction('r'); break;
                case '6': snake.direction('r'); break;
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
    if (game_over) cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t#\tGAME OVER!\t\t SCORE: "
                            << score << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t";
    return 0;
}
