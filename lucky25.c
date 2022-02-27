/*
 * diceGame.c
 *
 *  Created on: Sep 15, 2021
 *      Author: Jakob
 */
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

int total = 0;

int diceRoll(){  //function that rolls the dice
    int die1;
    int die2;
    //int total=0;
    char rollAgain;

    srand(time(NULL)); //sets roll to random everytime

    die1 = 1 + rand() % 6; //rand number from 1-6
    die2 = 1 + rand() % 6;

    total = die1 + die2; //add the die up

    if (die1 != die2) { //if they do not equal each other roll is outputted
        //total = die1 + die2;
        printf("You rolled: %d\n", total);
    }

    else if (die1 == die2){ //if they equal each other option to keep or re roll
        //total = die1 + die2;
        printf("You rolled doubles %d and %d = %d!! To re roll enter 'a' or 'y' to keep it.\n", die1, die2, total);
        scanf("%s", &rollAgain);
        if (rollAgain == 'y'){
            printf("You kept your roll of %d\n", total);
        }
        else if (rollAgain == 'a'){ //if re roll selected new total is equal to function again
            total = diceRoll();
        }
    }
    return total;
}

int player = 0;

int diceGame(){ //main game function
    char roll;
    scanf("%s", &roll);
    if (roll == 'r'){
        char cont;
        player = diceRoll(); //player keeps track of score from each dice roll
        do { //do loop for player to keep rolling until they press q
            printf("\nPress 'r' to continue. Press 'q' to end your turn.\n");
            scanf("%s", &cont);
            if (cont == 'r') {
                player += diceRoll(); //adding the total everytime loop is done
                printf("Your new score is: %d\n", player);
                if (player > 25){ //if over 25 player busts and gets set to 0
                    printf("\nYou busted! Better luck next time :(\n");
                    player = 0;
                    break;
                }
                else if (player == 25){ //if they get 25 they win unless someone ties
                    printf("\nYOU GOT 25, YOU WIN!!! Unless someone else hits 25.\n");
                    break;
                }
            }
            else if (cont == 'q'){ //exits do loop
                printf("\nTurn ended. Your final total: %d\n", player);
                break;
            }

        }while (cont == 'r');

    }
    return player; //total score returned
}

char name1[50], name2[50], name3[50];
int player1 = 0;
int player2 = 0;
int player3 = 0;

int main() {
    //char name1[50], name2[50], name3[50];
    char gameStart;
    char roll;

    printf("Welcome to LUCKY 25! Enter g to start.\n\n");
    printf("Rules: Each player will be prompted to the roll the dice. The goal is to get exactly 25 or as close as possible.\n");
    printf("If you roll doubles will have the option to replace the value you rolled, to prevent busting.\nOnce you are satisfied with your score you may end your turn.\n");
    printf("Very similar to blackjack, but you want 25 or as close as possible, and you have a chance to prevent busting.\n\n");

    scanf("%c", &gameStart);

    if (gameStart == 'g') {
        printf("\nSelect the number of players by entering 1 or 2:\n");
        printf("\n1. 2 players\n2. 3 players\n");
        int numOfPlay;
        scanf("%d", &numOfPlay); //selection of 2 or 3 players

        if (numOfPlay == 1) {
            printf("\n~~2 PLAYERS SELECTED~~\n");
            printf("\nEnter players 1 name:\n");
            scanf("%s", name1);
            //printf("You entered: %s\n", &name1[20]);
            printf("\nEnter players 2 name:\n");
            scanf("%s", name2);
            printf("\nPlayer 1: %s\nPlayer 2: %s\n\n", name1, name2); //getting player names
            printf("%s's turn. Enter 'r' to roll the dice.\n\n", name1);
            player1 = diceGame(); //players scores are equal to the return value of dicegame function
            //printf("\n%d\n", player1);
            printf("%s's turn. Enter 'r' to roll the dice.\n\n", name2);
            player2 = diceGame();
            if (player1 > player2){ //comparing player scores for each case scenario
                printf("\n");
                printf("%s WINS! GAME OVER\n\n", name1);
            }
            else if (player2 > player1){
                printf("\n");
                printf("%s WINS! GAME OVER\n\n", name2);
            }
            else if (player1 == player2){
                printf("\n");
                printf("IT'S A DRAW! GOOD GAME!\n\n");
            }
            int scoreBoard[2][3]; //2d array as final scoreboard, shows 1,2,3 with player score underneath
            for (int i = 0; i < 2; i++){
                for (int j = 0; j < 3; j++){
                    if (i == 0 && j == 0){
                        scoreBoard[i][j] = 1;
                    }if (i == 1 && j == 0){
                        scoreBoard[i][j] = player1;
                    }
                    if (i == 0 && j == 1){
                        scoreBoard[i][j] = 2;
                    }
                    if (i == 1 && j == 1){
                        scoreBoard[i][j] = player2;
                    }
                    if (i == 0 && j == 2){
                        scoreBoard[i][j] = 3;
                    }
                    if (i == 1 && j == 2){
                        scoreBoard[i][j] = 0;
                    }
                }
            }
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 3; j++) {
                    printf("%d\t", scoreBoard[i][j]);
                }
                printf("\n");
            }
        }
        else if (numOfPlay == 2){ //same thing as 2 player but one extra player score
            printf("\n~~3 PLAYERS SELECTED~~\n");
            printf("\nEnter players 1 name:\n");
            scanf("%s", name1);
            printf("\nEnter players 2 name:\n");
            scanf("%s", name2);
            printf("\nEnter players 3 name:\n");
            scanf("%s", name3);
            printf("\nPlayer 1: %s\nPlayer 2: %s\nPlayer 3: %s\n\n", name1, name2, name3);
            printf("%s's turn. Enter 'r' to roll the dice.\n\n", name1);
            player1 = diceGame();
            printf("%s's turn. Enter 'r' to roll the dice.\n\n", name2);
            player2 = diceGame();
            printf("%s's turn. Enter 'r' to roll the dice.\n\n", name3);
            player3 = diceGame();
            if (player1 > player2 && player1 > player3){
                printf("\n%s WINS! GAME OVER\n", name1);
            }
            else if (player2 > player1 && player2 > player3){
                printf("\n%s WINS! GAME OVER\n", name2);
            }
            else if (player3 > player1 && player3 > player2){
                printf("\n%s WINS! GAME OVER\n", name3);
            }
            else if (player1 == player2 && player1 == player3 && player3 == player2){
                printf("\nIT'S A DRAW! GOOD GAME!\n");
            }
            int scoreBoard[2][3];
            for (int i = 0; i < 2; i++){
                for (int j = 0; j < 3; j++){
                    if (i == 0 && j == 0){
                        scoreBoard[i][j] = 1;
                    }if (i == 1 && j == 0){
                        scoreBoard[i][j] = player1;
                    }
                    if (i == 0 && j == 1){
                        scoreBoard[i][j] = 2;
                    }
                    if (i == 1 && j == 1){
                        scoreBoard[i][j] = player2;
                    }
                    if (i == 0 && j == 2){
                        scoreBoard[i][j] = 3;
                    }
                    if (i == 1 && j == 2){
                        scoreBoard[i][j] = player3;
                    }
                }
            }
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 3; j++) {
                    printf("%d\t", scoreBoard[i][j]);
                }
                printf("\n");
            }
        }
    }
    printf("FINAL SCORE\n");
    return 0;
}