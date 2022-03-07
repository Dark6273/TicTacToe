//the faradooz project
// created by mahdi khosravi & amir hossein sabry & ehsan alami


//library of project
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// array data
char mainboard[10] = {'0' ,'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9'}; //define main board arrays

char part1[10] = {'0' ,'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9'}; //defining arrays of the each square in the ultimate form
char part2[10] = {'0' ,'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9'};
char part3[10] = {'0' ,'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9'};
char part4[10] = {'0' ,'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9'};
char part5[10] = {'0' ,'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9'};
char part6[10] = {'0' ,'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9'};
char part7[10] = {'0' ,'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9'};
char part8[10] = {'0' ,'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9'};
char part9[10] = {'0' ,'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9'};

// function calling
int checkwin(char square[10]);
void board(char square[10]);
int move(int choice ,char square[10] ,char mark);
void moveUser(int boardSelect ,char mark ,int player);
void moveAi();
void reset();
void change(char board[10]);

int main()
{
    int mainStatus = -1,boardSelect ,counter = 0, player,status = 1,state = 1;
    char mark;
    printf("\n                   ////welcome to the ultimate tic tac toe game\\\\\\\n");
    time_t t;   // not a primitive datatype
    time(&t);

    printf("\ndate and time : %s\n", ctime(&t)); //function which show the time and date

    printf("exit : type '0'\n");
    printf("Play Game with Bot Or User ? (Bot => 1 & User => 2)  :  "); //choose which type of the game do you want
    scanf("%d",&status);

    while (state == 1)
    {
        while (mainStatus == -1)
        {
            player = counter % 2 + 1; //swaping between X and O while each round ends
            if (player == 1)
            {
                mark = 'X';
            }
            else
            {
                mark = 'O';
            }

            printf("Main Board \n");
            board(mainboard); //calling main board function

            if (player == 1) // print which user should play
            {
                printf("The turn of player number one (%c)\n",mark);
            }
            else
            {
                if (status == 1) //in case you choice bot this is gonna print
                {
                    printf("The turn of Bot :)\n");
                }
                else
                {
                    printf("The turn of player number two (%c)\n",mark);
                }
            }

            if(status == 1 && player == 2)
            {
                boardSelect = 0;
            }
            else
            {
                printf("Select Board Your Move =>  "); // ask which square of the ult tic tac toe you want to play in
                scanf("%d",&boardSelect);
            }
            printf("\n");


            if (mainboard[boardSelect] == 'X' || mainboard[boardSelect] == 'O') // if user choice a full or invalid square program print this
            {
                printf("You Cant Select Number");
            }
            else
            {
                if (status == 1 && player == 2)
                {
                    moveAi(); //calling bot if you had been choose 1 vs AI version of the game
                }
                else
                {
                    moveUser(boardSelect ,mark ,player); // if you had been choice 1 vs 1 program will call this function
                }
            }
            counter++;
            mainStatus = checkwin(mainboard); //checking win rate after each move
        }

        if (mainStatus == 1) //if return of the check win function was 1 program will show the winner
        {
            printf("player %d Win!!! \n",player);
        }
        else // other way program will show define
        {
            printf("Even !!");
        }

        printf("Do you want to play again ? (Send number 1 to continue)\n");
        scanf("%d",&state);
        if (state == 1)
        {
            mainStatus = -1;
            reset();
        }
        else
        {
            printf("Bye. Hoping to play again !!\n");
        }
    }


}


void moveAi() // function which maintaing ai moves by time.h
{
    int boardSelect,status = 0,choice;
    char mark = 'O';

    while (status == 0)
    {
        srand(clock());
        boardSelect = rand() % 9 + 1; //generating random number between 1 and 10

        if (mainboard[boardSelect] != 'O' && mainboard[boardSelect] != 'X') //check the invalid or full rooms
        {
            status = 1;
        }
    }

    status = 0;

    while (status == 0)
    {
        srand(clock());
        choice = rand() % 9 + 1; //generating random number for each house in the main function by using switch case

        switch (boardSelect)
        {
        case 1:
            printf("     Board %d",boardSelect);
            status = move(choice, part1, mark);
            board(part1);
            break;
        case 2:
            printf("     Board %d",boardSelect);
            status = move(choice, part2, mark);
            board(part2);            break;
        case 3:
            printf("     Board %d",boardSelect);
            status = move(choice, part3, mark);
            board(part3);
            break;
        case 4:
            printf("     Board %d",boardSelect);
            status = move(choice, part4, mark);
            board(part4);
            break;
        case 5:
            printf("     Board %d",boardSelect);
            status = move(choice, part5, mark);
            board(part5);
            break;
        case 6:
            printf("     Board %d",boardSelect);
            status = move(choice, part6, mark);
            board(part6);
            break;
        case 7:
            printf("     Board %d",boardSelect);
            status = move(choice, part7, mark);
            board(part7);
            break;
        case 8:
            printf("     Board %d",boardSelect);
            status = move(choice, part8, mark);
            board(part8);
            break;
        case 9:
            printf("     Board %d",boardSelect);
            status = move(choice, part9, mark);
            board(part9);
            break;
        default:
            break;
        }
    }
}

void moveUser(int boardSelect ,char mark ,int player) //function which track the users movement
{
    int moveSelect,result;


    if (boardSelect == 1)
    {
        printf("     Board 1\n\n"); //show which house you playing in
        board(part1);

        if (player == 1)//show which player have to move
        {
            printf("The turn of player number one (%c)\n",mark);
        }
        else
        {
            printf("The turn of player number two (%c)\n",mark);
        }

        printf("Select Number For Move =>  ");
        scanf("%d",&moveSelect);// scaning the room which player had been choose
        move(moveSelect, part1 ,mark);

        printf("The move of the number %d player was done !!\n",player); // just a text for know each player has done his own move
        board(part1);
        printf("-----------------------------------------------------\n\n");

        result = checkwin(part1); // check win after each move of the players
    }
                               //the next 9 command will do the same previus explaintions
    else if (boardSelect == 2)
    {
        printf("     Board 2\n\n");
        board(part2);

        if (player == 1)
        {
            printf("The turn of player number one (%c)\n",mark);
        }
        else
        {
            printf("The turn of player number two (%c)\n",mark);
        }

        printf("Select Number For Move =>  ");
        scanf("%d",&moveSelect);
        move(moveSelect, part2 ,mark);

        printf("The move of the number %d player was done !!\n",player);
        board(part2);
        printf("-----------------------------------------------------\n\n");

        result = checkwin(part2);
    }

    else if (boardSelect == 3)
    {
        printf("     Board 3\n\n");
        board(part3);

        if (player == 1)
        {
            printf("The turn of player number one (%c)\n",mark);
        }
        else
        {
            printf("The turn of player number two (%c)\n",mark);
        }

        printf("Select Number For Move =>  ");
        scanf("%d",&moveSelect);
        move(moveSelect, part3 ,mark);

        printf("The move of the number %d player was done !!\n",player);
        board(part3);
        printf("-----------------------------------------------------\n\n");
        result = checkwin(part3);
    }

    else if (boardSelect == 4)
    {
        printf("     Board 4\n\n");
        board(part4);

        if (player == 1)
        {
            printf("The turn of player number one (%c)\n",mark);
        }
        else
        {
            printf("The turn of player number two (%c)\n",mark);
        }

        printf("Select Number For Move =>  ");
        scanf("%d",&moveSelect);
        move(moveSelect, part4 ,mark);

        printf("The move of the number %d player was done !!\n",player);
        board(part4);
        printf("-----------------------------------------------------\n\n");
        result = checkwin(part4);
    }

    else if (boardSelect == 5)
    {
        printf("     Board 5\n\n");
        board(part5);

        if (player == 1)
        {
            printf("The turn of player number one (%c)\n",mark);
        }
        else
        {
            printf("The turn of player number two (%c)\n",mark);
        }

        printf("Select Number For Move =>  ");
        scanf("%d",&moveSelect);
        move(moveSelect, part5 ,mark);

        printf("The move of the number %d player was done !!\n",player);
        board(part5);
        printf("-----------------------------------------------------\n\n");
        result = checkwin(part5);
    }

    else if (boardSelect == 6)
    {
        printf("     Board 6\n\n");
        board(part6);

        if (player == 1)
        {
            printf("The turn of player number one (%c)\n",mark);
        }
        else
        {
            printf("The turn of player number two (%c)\n",mark);
        }

        printf("Select Number For Move =>  ");
        scanf("%d",&moveSelect);
        move(moveSelect, part6 ,mark);

        printf("The move of the number %d player was done !!\n",player);
        board(part6);
        printf("-----------------------------------------------------\n\n");
        result = checkwin(part6);
    }

    else if (boardSelect == 7)
    {
        printf("     Board 7\n\n");
        board(part7);

        if (player == 1)
        {
            printf("The turn of player number one (%c)\n",mark);
        }
        else
        {
            printf("The turn of player number two (%c)\n",mark);
        }

        printf("Select Number For Move =>  ");
        scanf("%d",&moveSelect);
        move(moveSelect, part7 ,mark);

        printf("The move of the number %d player was done !!\n",player);
        board(part7);
        printf("-----------------------------------------------------\n\n");
        result = checkwin(part7);
    }

    else if (boardSelect == 8)
    {
        printf("     Board 8\n\n");
        board(part8);

        if (player == 1)
        {
            printf("The turn of player number one (%c)\n",mark);
        }
        else
        {
            printf("The turn of player number two (%c)\n",mark);
        }

        printf("Select Number For Move =>  ");
        scanf("%d",&moveSelect);
        move(moveSelect, part8 ,mark);

        printf("The move of the number %d player was done !!\n",player);
        board(part8);
        printf("-----------------------------------------------------\n\n");
        result = checkwin(part8);
    }

    else if (boardSelect == 9)
    {
        printf("     Board 9\n\n");
        board(part9);

        if (player == 1)
        {
            printf("The turn of player number one (%c)\n",mark);
        }
        else
        {
            printf("The turn of player number two (%c)\n",mark);
        }

        printf("Select Number For Move =>  ");
        scanf("%d",&moveSelect);
        move(moveSelect, part9 ,mark);

        printf("The move of the number %d player was done !!\n",player);
        board(part9);
        printf("-----------------------------------------------------\n\n");
        result = checkwin(part9);
    }

    if (result == 1) //check the player's moves and win rate by check win again in the ultimate form of the game
    {
        move(boardSelect, mainboard ,mark);
    }
    else if(result == 0) //check if the game is tie or not
    {
        printf("Even !!");
        move(boardSelect ,mainboard ,'!');
    }
}

int move(int choice ,char square[10] ,char mark) //swap numbers of the each colmun by the users marks X or O
{
    if (choice == 1 && square[1] == '1')
    {
        square[1] = mark;
        return 1;
    }
    else if (choice == 2 && square[2] == '2')
    {
        square[2] = mark;
        return 1;
    }
    else if (choice == 3 && square[3] == '3')
    {
        square[3] = mark;
        return 1;
    }
    else if (choice == 4 && square[4] == '4')
    {
        square[4] = mark;
        return 1;
    }
    else if (choice == 5 && square[5] == '5')
    {
        square[5] = mark;
        return 1;
    }
    else if (choice == 6 && square[6] == '6')
    {
        square[6] = mark;
        return 1;
    }
    else if (choice == 7 && square[7] == '7')
    {
        square[7] = mark;
        return 1;
    }
    else if (choice == 8 && square[8] == '8')
    {
        square[8] = mark;
        return 1;
    }
    else if (choice == 9 && square[9] == '9')
    {
        square[9] = mark;
        return 1;
    }
    else
    {
        printf("Invalid move "); // print an error if the user had been chooice an invalid or full room
        return 0;
    }
}

int checkwin(char square[10]) // check the win
{
    if (square[1] == square[2] && square[2] == square[3]) //check win in a row
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])//check win in a row
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])//check win in a row
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])//check win in a column
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])//check win in a column
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])//check win in a column
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])//check win in a diameter
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])//check win in a diameter
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
                                                                         != '7' && square[8] != '8' && square[9] != '9') //in other case return the default varibles

        return 0;
    else // return of this function is 0 or 1 so this line and the next command is to be sure that program work clearly
        return  - 1;
}

void board(char square[10]) // and the syntax graphical design for the rooms of the tic tac toe unfortunatly we could'nt afford true graphical and colorize form
{

    // printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


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


void reset()  // reset board
{
    change(mainboard);
    change(part1);
    change(part2);
    change(part3);
    change(part4);
    change(part5);
    change(part6);
    change(part7);
    change(part8);
    change(part9);
}

void change(char board[10]) // reset board
{
    board[0] = '0';
    board[1] = '1';
    board[2] = '2';
    board[3] = '3';
    board[4] = '4';
    board[5] = '5';
    board[6] = '6';
    board[7] = '7';
    board[8] = '8';
    board[9] = '9';
}