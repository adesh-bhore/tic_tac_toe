#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char board[3][3];
char user1[40];
char user2[40];
char zero = 'O', cross = 'X', ch;
int choice, user1_score = 0, user2_score = 0;
void initialize_board();
void play_game();
char win_loss();
void design();
void display_board();
void display_score();
int main()
{
        printf("\t\t\t**************************************************************************************************\n");
        printf("\t\t\t************************************  GAME STARTS HERE  ******************************************\n");
        printf("\t\t\t**************************************************************************************************\n\n");
        printf("\t\t\tenter player 1 name :\n");
        scanf("\t\t\t%s", &user1);
        printf("\t\t\tenter player 2 name :\n");
        scanf("\t\t\t%s", &user2);
        design();
        int playAgain = 1;
        while (playAgain)
        {
                initialize_board();

                play_game();

                printf("\n\n\t\t\tDO YOU WANT TO PLAY AGAIN : (1 FOR YES / 0 FOR NO )\n ");
                scanf("%d", &playAgain);
        }

        printf("\n\n\t\t\t THANKS FOR PLAYING IN OUR ARENA !!!!\n");
        printf("\n\n\t\t\t ********** FINAL SCORES ***********\n");
        printf("\n\n\t\t\t  %s\t|\t%s", user1, user2);
        printf("\n\t\t\t  %d\t|\t%d", user1_score, user2_score);
}

void initialize_board()
{
        for (int i = 0; i < 3; i++)
        {
                for (int j = 0; j < 3; j++)
                {
                        board[i][j] = ' ';
                }
        }
}
void design()
{
        printf("\n\n\n\t\t\tguidelines for play - remember this number scenario ...\n\n\n");

        printf("\t\t\t|\t1|\t2|\t3|\n");
        printf("\t\t\t-------------------------\n");
        printf("\t\t\t|\t4|\t5|\t6|\n");
        printf("\t\t\t-------------------------\n");
        printf("\t\t\t|\t7|\t8|aa\t9|\n");
        printf("\t\t\t-------------------------\n");

        printf("\n\n\t\t\t %s your dice is : O ", user1);
        printf("\n\t\t\t %s your dice is : X ", user2);
}
void display_board()
{

        printf("\t\t\t|    %c  |    %c  |    %c  |\n", board[0][0], board[0][1], board[0][2]);
        printf("\t\t\t-------------------------\n");
        printf("\t\t\t|    %c  |    %c  |    %c  |\n", board[1][0], board[1][1], board[1][2]);
        printf("\t\t\t-------------------------\n");
        printf("\t\t\t|    %c  |    %c  |    %c  |\n", board[2][0], board[2][1], board[2][2]);
        printf("\t\t\t-------------------------\n");
}
void play_game()
{
        int count = 0, arr[9];
        char winner;
        while (1)
        {

        retry1:
                printf("\n\n\t\t\t %s it's your turn (1 to 9): \n\n", user1);
                scanf("%d", &choice);

                for (int i = 0; i < count; i++)
                {
                        if (arr[i] == choice)
                        {
                                printf("\n\t\t\tchoosen place is already filled ....\n");
                                goto retry1;
                        }
                }

                arr[count] = choice;

                count++;
                if (choice < 1 || choice > 9)
                {
                        printf("\n\t\t\twrong choice made correct it ....\n\n");
                        goto retry1;
                }

                switch (choice)
                {
                case 1:

                        board[0][0] = zero;

                        break;
                case 2:

                        board[0][1] = zero;

                        break;
                case 3:

                        board[0][2] = zero;

                        break;
                case 4:

                        board[1][0] = zero;

                        break;
                case 5:

                        board[1][1] = zero;

                        break;
                case 6:

                        board[1][2] = zero;

                        break;
                case 7:

                        board[2][0] = zero;

                        break;
                case 8:

                        board[2][1] = zero;

                        break;
                case 9:

                        board[2][2] = zero;

                        break;

                default:
                        printf("\nwrong choice code ");

                        break;
                }
                display_board();
                winner = win_loss();

                if (winner == 'O')
                {
                        printf("\n\n///////  congratulations %s you wins the game  //////////\n\n", user1);
                        user1_score++;
                        break;
                }
                else if (winner == 'X')
                {
                        printf("\n\n///////  congratulations %s you wins the game  //////////\n\n", user2);
                        user2_score++;
                        break;
                }

                if (count == 9)
                {
                        printf("\n\n\t\t\tGAME ENDS NO ONE WINS .....\n\n");
                        break;
                }

        retry2:
                printf("\n\n\t\t\t %s it's your turn (1 to 9): \n\n", user2);
                scanf("%d", &choice);

                for (int i = 0; i < count; i++)
                {
                        if (arr[i] == choice)
                        {
                                printf("\n\t\t\tchoosen place is already filled ....\n");
                                goto retry2;
                        }
                }

                arr[count] = choice;

                count++;
                if (choice < 1 || choice > 9)
                {
                        printf("\n\t\t\twrong choice made correct it ....\n\n");
                        goto retry2;
                }

                switch (choice)
                {
                case 1:

                        board[0][0] = cross;

                        break;
                case 2:

                        board[0][1] = cross;

                        break;
                case 3:

                        board[0][2] = cross;

                        break;
                case 4:

                        board[1][0] = cross;

                        break;
                case 5:

                        board[1][1] = cross;

                        break;
                case 6:

                        board[1][2] = cross;

                        break;
                case 7:

                        board[2][0] = cross;

                        break;
                case 8:

                        board[2][1] = cross;

                        break;
                case 9:

                        board[2][2] = cross;

                        break;

                default:
                        printf("\nwrong choice code ");

                        break;
                }

                display_board();
                winner = win_loss();

                if (winner == 'O')
                {
                        printf("\n\n///////  congratulations %s you wins the game  //////////\n\n", user1);
                        user1_score++;
                        break;
                }
                else if (winner == 'X')
                {
                        printf("\n\n///////  congratulations %s you wins the game  //////////\n\n", user2);
                        user2_score++;
                        break;
                }

                if (count == 9)
                {
                        printf("\n\n\t\t\tGAME ENDS NO ONE WINS .....\n\n");
                        break;
                }
        }
}
char win_loss()
{
        for (int i = 0; i < 3; i++)
        {
                if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
                        return board[i][0];
                if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
                        return board[0][i];
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
                return board[0][0];
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
                return board[0][2];

        printf("z");
}
