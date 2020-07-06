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
char name[30];

int drawFruit(int rVal, int cVal);
void drawBorders ();
void printScore(int scr);



int main(){
    initscr();
    
    mvprintw(1, 3, "MOVE CURSOR ROUND THE BOX...");
    printw("Your gamer name: ");
    scanw("%s", name);
    refresh();

    drawBorders();
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
        if(rRow == iRow && rCol == iCol){
            drawFruit(iRow, iCol);
            scores += 10;
        }
        if (iRow == 27 || iRow == 3 || iCol == 80 || iCol == 1){
            break;
        }

        clear();
        drawBorders();
        mvprintw(rRow, rCol, fruit);
        mvprintw(iRow,iCol,show);
        printScore(scores);
        refresh();
    }
    mvprintw(29, 3, "\n Great! '%s' score: %d \n Your scores were: %d\n",name, scores);
  
    //getch();
    endwin();
    return 0;
}

/*Generate random Fruits*/
int drawFruit(int rVal, int cVal){  //Using row and columnn value to generate a random figure
    rCol = (rand() % (79 - 2 + 1)) + 2;     // rCol = rand()%30;
    rRow = (rand() % (26 - 4 + 1)) + 4;     //rRow = rand()%30;
    // number = (rand() % (upper - lower + 1)) + lower
}

/*Print the score on the top right corner*/
void printScore(int scr){
    mvprintw(2, 60, "Score: %d", scr);
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
    printw("  TIP\t");
    printw("  d -> right: \t");
    printw("a -> left \t");
    printw("w -> up \t");
    printw("s -> down \t");
    printw("q -> quit \n");
    printw("  Arrow keys also work... \n");
}