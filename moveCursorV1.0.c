#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


char key;
int row=24;
int col=80;
int iCol=12, iRow=20; //initial column and row
char show[2];
int scores;
char fruit[2] = {'f'};
int rRow =8, rCol = 6; //Random row, random column
int rVal, cVal;

int drawFruit(int rVal, int cVal);
void drawBorders ();


int main(){
    initscr();

    mvprintw(1, 3, "MOVE CURSOR ROUND THE BOX...\n");
    refresh();

    while(key != 'q'){
        key = getch();
        if(key== 'd' || key == KEY_RIGHT){    //d --> right
            iCol += 1;
            show[0] = '>'; 
        }
        else if(key == 'a' || key == KEY_LEFT){    //a --> left
            iCol -= 1;
            show[0]= '<';
        }
        else if(key == 'w' || key == KEY_UP){    //w --> up
            iRow -= 1;
            show[0] = '^';
        }
        else if(key == 's' || key == KEY_DOWN){    //s --> down
            iRow += 1;
            show[0] = 'v';
        }
        if(rRow== iRow && rCol == iCol){
            drawFruit(iRow, iCol);
            scores += 10;
        }

        clear();
        drawBorders();
        mvprintw(rRow, rCol, fruit);
        mvprintw(iRow,iCol,show);
        refresh();
    }
    printw("\n     Your scores were: %d\n", scores);
    getch();

    endwin();
    return 0;
}

/*Generate random Fruits*/
int drawFruit(int rVal, int cVal){  //Using row and columnn value to generate a random figure
    rCol = rand()%30;
    rRow = rand()%30;
    // number = (rand() % (upper - lower + 1)) + lower
 //   return rCol, rRow;
}

/*Draw the borders of the Game and Show tips*/
void drawBorders (){
    mvprintw(2,3,"Designed by ALVINO\n");
    for(int i=0; i<=24; i++)
    {
        printw("|");
        for(int j=0; j<=80; j++)
        {
            if(i==0 || j==80 || i==24)
            {
                printw("|");
            }
            else{
                printw(" ");
            }
        }
        printw("\n");
    }
    printw("  TIP\n");
    printw("  d -> right: \t");
    printw("a -> left \t");
    printw("w -> up \t");
    printw("s -> down \t");
    printw("q -> quit \n");
    printw("  Arrow keys also work... \n");
}