#include <stdio.h>

// array data
char mainboard[10] = {'0' ,'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9'};

char part1[10] = {'0' ,'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9'};
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

int main()
{
    int mainStatus = -1,boardSelect ,counter = 0, player,moveSelect,result;
    char mark;

    while (mainStatus == -1)
    {
        player = counter % 2 + 1;
        if (player == 1)
        {
            mark = 'X';
        }
        else
        {
            mark = 'O';
        }

        printf("Main Board \n");
        board(mainboard);

        if (player == 1)
        {
            printf("The turn of player number one (%c)\n",mark);
        }
        else
        {
            printf("The turn of player number two (%c)\n",mark);
        }

        printf("Select Board Your Move =>  ");
        scanf("%d",&boardSelect);
        printf("\n");


        if (mainboard[boardSelect] == 'X' || mainboard[boardSelect] == 'O')
        {
            printf("You Cant Select Number");
        }
        else
        {
            moveUser(boardSelect ,mark ,player);
        }
        counter++;
        mainStatus = checkwin(mainboard);
    }
    if (mainStatus == 1)
    {
        printf("player %d Win!!! \n",player);
    }
    else
    {
        printf("Even !!");
    }

}

void moveUser(int boardSelect ,char mark ,int player)
{
    int moveSelect,result;

    if (boardSelect == 1)
    {
        printf("     Board 1\n\n");
        board(part1);

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
        move(moveSelect, part1 ,mark);

        printf("The move of the number %d player was done !!\n",player);
        board(part1);
        printf("-----------------------------------------------------\n\n");

        result = checkwin(part1);      
    }

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

    if (result == 1)
    {
        move(boardSelect, mainboard ,mark);
    }
    else if(result == 0)
    {
        printf("Even !!");
        move(boardSelect ,mainboard ,'!');
    }  
}

int move(int choice ,char square[10] ,char mark)
{
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
}

int checkwin(char square[10])
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

void board(char square[10])
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