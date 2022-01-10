//the dooz project
// created by mahdi khosravi & amir hossein sabry & ehsan alami


//libraries of project
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//array data
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

//prototype function
int checkwin();
void board();
int ai();
int user(int user);
void reset();

//the main function
int main()
{
    int player = 1, i,status,state = 1,win1 = 0,win2 = 0;
    time_t start,end;

    printf("Play Game with Bot Or User ? (Bot => 1 & User => 2)  :  ");
    scanf("%d",&status);

    while (state == 1)
    {
        do
        {
            board();
            player = (player % 2) ? 1 : 2;
            //condition for play with bot or user
            if (status == 1)
            {
                if (player == 1)
                {
                    user(player);
                }
                else
                {
                    ai();
                }
            }
            else
            {
                user(player);
            }
            i = checkwin();

            player++;
        }while (i ==  - 1);

        board();

        //condition for who win
        if (i == 1)
        {
            printf("==>\aPlayer %d win\n", --player);
            if(player == 1)
                win1++;
            else
                win2++;
        }
        else
            printf("==>\aGame draw\n");

        //condition for score
        if (status == 1)
        {
            printf("player => (%d) || Bot => (%d)\n",win1,win2);
        }
        else
        {
            printf("player1 => (%d) || player2 => (%d)\n",win1,win2);
        }

        //condition for play again
        printf("Do you want to play again? (yes => 1)   ");
        scanf("%d",&state);
        if(state == 1)
        {
            reset();
        }
    }
    



    return 0;
}
//declaration functions

int checkwin()//this function check to see the anyone win or no
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
             != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;     
}
void board()//this function show the game map
{
    //clear board
    printf("%c[H", 27);
	printf("%c[2J", 27);
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    //show row and column 
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}

//ai is function for computer move
int ai()
{
    int move = 0,choice;
    char mark = '@';

    while (move == 0)
    {
        srand(clock());
        choice = rand() % 9 + 1;

        if (choice == 1 && square[1] == '1')
        {
            square[1] = mark;
            move++;
        }
        else if (choice == 2 && square[2] == '2')
        {
            square[2] = mark;
            move++;
        }
        else if (choice == 3 && square[3] == '3')
        {
            square[3] = mark;
            move++;
        }
        else if (choice == 4 && square[4] == '4')
        {
            square[4] = mark;
            move++;
        }
        else if (choice == 5 && square[5] == '5')
        {
            square[5] = mark;
            move++;
        }
        else if (choice == 6 && square[6] == '6')
        {
            square[6] = mark;
            move++;
        }
        else if (choice == 7 && square[7] == '7')
        {
            square[7] = mark;
            move++;
        }
        else if (choice == 8 && square[8] == '8')
        {
            square[8] = mark;
            move++;
        }
        else if (choice == 9 && square[9] == '9')
        {
            square[9] = mark;
            move++;
        }
    }

    return 0;
}
//function for user move
int user(int user)
{
    int choice;
    char mark;
    mark = (user == 1) ? '#' : '@';
    printf("Player user %d, enter a number:  ",user);
    scanf("%d", &choice);

    if (choice == 1 && square[1] == '1')
        square[1] = mark;

    else if (choice == 2 && square[2] == '2')
        square[2] = mark;

    else if (choice == 3 && square[3] == '3')
        square[3] = mark;

    else if (choice == 4 && square[4] == '4')
        square[4] = mark;

    else if (choice == 5 && square[5] == '5')
        square[5] = mark;

    else if (choice == 6 && square[6] == '6')
        square[6] = mark;

    else if (choice == 7 && square[7] == '7')
        square[7] = mark;

    else if (choice == 8 && square[8] == '8')
        square[8] = mark;

    else if (choice == 9 && square[9] == '9')
        square[9] = mark;

    else
    {
        printf("Invalid move ");
        return 0;
    }
    return 0;
}
//reset board
void reset()
{
    square[0] = '0';
    square[1] = '1';
    square[2] = '2';
    square[3] = '3';
    square[4] = '4';
    square[5] = '5';
    square[6] = '6';
    square[7] = '7';
    square[8] = '8';
    square[9] = '9';
}
