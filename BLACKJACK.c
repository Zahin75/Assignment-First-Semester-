#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function Protoype
void play_blackjack(); //Line 48
void not_play_blackjack();//Line 73
void play(); //Line 80
void start_bet(); //Line 107
void start_play();//Line 122
void rules();//Line 199
void dealer();//Line 222
int random_card(); //Line 253
int spade();//Line 275
int heart();//Line 468
int club();//Line 338
int diamond();//Line 401
void bet(); //Line 211
void ask();//Line 527
void stay(); //Line 551
//Global Variables
int cash; //Total Cash
int point; //Stores player point
int dealer_point; //Stores dealer point
int bet_value; //Bet amount
int loss = 0; //Total loss
int win = 0; //Total win

int main(void) //Main Function
{
    printf("Do you want to play Blackjack?\nIf yes, press 'Y', if no, then press 'N': ");
    char decision;
    scanf(" %c", &decision);
    while(decision != 'y' && decision != 'Y' && decision != 'N' && decision != 'n')
    {
        printf("\n");
        printf("You have selected a wrong option! Please Enter 'Y' for Yes and 'N' for No: ");
        scanf(" %c", &decision);
    }
    if(decision == 'Y' || decision == 'y')
        play_blackjack(); //Line 48
    else
        not_play_blackjack(); //Line 73

    return 0;
}

void play_blackjack() //Ask for starting
{
    char decision_again;
    printf("\n\n\n\t\t\t\tWELCOME TO BLACKJACK\t\t\t\t\n\n\n");
    printf("Are you ready the GENIUS? :p\n");
    printf("____________________________\n");
    printf("Press 'y' for Yes an 'n' for No: ");
    scanf(" %c", &decision_again);
    while(decision_again != 'y' && decision_again != 'Y' && decision_again != 'N' && decision_again != 'n')
    {
        printf("\n");
        printf("\nYou have selected a wrong option! Please Enter Y for Yes and N for No: ");
        scanf(" %c", &decision_again);
    }
    if(decision_again == 'y' || decision_again == 'Y')
    {
        printf("\nHaha, I knew it. Let's start the game and see who between you and me wins all this fake money! XD\n");
        play();//Line 80
    }
    else
    {
        printf("\nAre you afraid of losing all this fake money?! I'm not insulting you, it's good to be scared! :D\n");
        not_play_blackjack();//Line 73
    }
}
void not_play_blackjack() //Quit
{
    printf("\n\nYou could make your day better.\nBut you can also make it better without playing this game if you want!\nHappy, happy, happy!\n");
    printf("\nPress any key to exit...\n");
    getchar();
}

void play() //Start play
{
    char decision;
    printf("\nEnter 1 to start playing Blackjack.\nEnter 2 to learn the rules of playing blackjack.\nPress 3 to exit. But I don't prefer it. :(\n\n");
    printf("\nPlease enter a number from 1 to 3: ");
    scanf(" %c", &decision);
    while(decision != '1' && decision != '2' && decision != '3')
    {
        printf("\n\nYou have entered a wrong option. Please chose carefully again from 1 to 3: ");
        scanf(" %c", &decision);
    }
    switch(decision)
    {
        case '1':
            start_bet();//Line 107
            break;
        case '2':
            rules();//Line 199
            break;
        case '3':
            not_play_blackjack(); //Line 73
            break;
        default:
            printf("\nError occurred! Exit the program!\n");
    }
}

void start_bet() //Starting beting
{
    printf("\n\nEnter how much money you want to start playing with: ");
    scanf("%d", &cash);
    if(cash > 0)
    {
        start_play();//Line 122
    }
    else
    {
        printf("\n\nYou have to need more than 0 Taka.\n");
        start_bet();//Line 107
    }
}

void start_play() //Start playing blackjack
{
    int i = 0;
    point = 0;
    dealer_point = 0;
    if(cash <= 0)
    {
        printf("You are penniless.\n \t\tGAME OVER!");
        ask();//Line 527
        return;
    }
    printf("\n\nYou have %d Taka!\n", cash);
    bet();
    point += random_card();
    printf("\n\nYour total point is %d\n", point);
    dealer();
    while(i <= 21)
    {
        if(point == 21)
        {
            printf("\n\nWOW! YOU WIN THE GAME!\n");
            cash += bet_value;
            win += 1;
            printf("\n\nYou won %d games and loss %d games!\n", win, loss);
            ask();//Line 527
        }
        else if(point > 21)
        {
            printf("Sorry, you have lost the game!\n");
            cash -= bet_value;
            loss += 1;
            printf("\nYou won %d games and loss %d games!\n", win, loss);
            ask();//Line 527
        }
        else if(point < 21)
        {
            char ch;
            printf("Would you want to HIT or STAY?\n");
            printf("\nIf you want 'HIT' press 'H', if you want to 'STAY' then press 'S': ");
            scanf("%c", &ch);
            fflush(stdin);
            while(ch != 'H' && ch != 'h' && ch != 'S' && ch != 's')
            {
                scanf("%c", &ch);
            }
            if(ch == 'h' || ch == 'H')
            {
                printf("\n\nYou have chosen to HIT at. Impressive move, huh?!\n", point);
                point += random_card();//Line 253
                printf("\nYour total point is %d\n", point);
                dealer();
                if(point == 21)
                {
                    printf("WOW! YOU WIN THE GAME!");
                    cash += bet_value;
                    win += 1;
                    printf("\n\nYou won %d games and loss %d games!\n", win, loss);
                    ask();//Line 527
                }
                else if(point > 21)
                {
                    printf("Sorry, you have lost the game!\n");
                    cash -= bet_value;
                    loss += 1;
                    printf("\nYou won %d games and loss %d games!\n", win, loss);
                    ask();//Line 527
                }
            }
            else
            {
                printf("\nYou have chosen to STAY at %d. Impressive move, huh?!\n", point);
                stay();
            }
        }
        i++;
    }
}
void rules()
{
    printf("\n\t\t\tRules of playing Blackjack\n");
    printf("\n\t\t\t__________________________\n");
    printf("\nRule 1:");
    printf("\n\tEach Card has a value.\n\t\tAll number cards (2-10) score the value indicated on them.\n\tThe face cards (Jack, Queen, King) score 10 points.\n\tAce or A can either be treated as 1 or 11.\n\tThe object of the game is to get closer to 21 than the dealer without going over 21.\n\tIf a hand goes over 21, it is called a “bust” or “break” and the wager is lost.\n");
    printf("\nRule 2:");
    printf("\n\tAfter the dealing of the first two cards, you must decide whether to HIT or STAY.\n\tStaying will keep you safe, hitting will add an another card.\n\tBecause you are competing against the dealer, you must beat his hand.\n\t\t\tBUT BE AWARE!!!\n\tIf your total goes over 21, you will LOSE!.\n\tBut the world is not over, because you can always play again.\n");
    printf("\nSome additional information: ");
    printf("\n\t\t\t\tThis program generates cards at random.\n\t\t\t\tIf you keep losing, you are very unlucky! :(\n\t\t");
    play();
}
void bet() //Take bet amount
{
    printf("\n\nEnter your bet: ");
    scanf("%d", &bet_value);
    if(bet_value > cash)
    {
        printf("\n\nYou have insufficient balance. Your balance is %d Taka. Please enter your bet less than or equal to your balance.", cash);
        bet();
    }

}
void dealer() //Dealer turns
{
    int z, d;

    if(dealer_point < 17)
    {
        srand((unsigned)time(NULL) + 2);
        z = rand() % 13 + 1;
        if(z <= 10)
        {
            d = z;
        }
        else if(z == 11)
        {
            if(dealer_point < 11)
            {
                d = 11;
            }
            else
            {
                d = 1;
            }
        }
        else
        {
            d = 10;
        }
        dealer_point += d;
    }
    printf("The dealer's total point is %d\n", dealer_point);
}
int random_card()//For random number
{
    srand((unsigned)time(NULL));
    int random_card = rand() % 4 + 1, p;
    if(random_card == 1)
    {
        p = spade();
    }
    else if(random_card == 2)
    {
        p = club();
    }
    else if(random_card == 3)
    {
        p = heart();
    }
    else
    {
        p = diamond();
    }
    return p;
}
int spade() //For spade
{
    srand((unsigned)time(NULL));
    int random_card = rand() % 13 + 1, p;
    if(random_card == 1 || random_card == 11)
    {
        printf(" ______________\n");
        printf("|              |\n");
        printf("|    SPADE     |\n");
        printf("|     *A*      |\n");
        printf("|    SPADE     |\n");
        printf("|______________|\n");
        if(point <= 10)
        {
            p = 11;
        }
        else
        {
            p = 1;
        }
    }
    else if(random_card <= 9)
    {
        printf(" ______________\n");
        printf("|              |\n");
        printf("|    SPADE     |\n");
        printf("|     *%d*     |\n", random_card);
        printf("|    SPADE     |\n");
        printf("|______________|\n");
        p = random_card;
    }
    else if(random_card == 10)
    {
        printf(" ______________\n");
        printf("|              |\n");
        printf("|    SPADE     |\n");
        printf("|     *J*      |\n");
        printf("|    SPADE     |\n");
        printf("|______________|\n");
        p = 10;
    }
    else if(random_card == 12)
    {
        printf(" ______________\n");
        printf("|              |\n");
        printf("|    SPADE     |\n");
        printf("|     *Q*      |\n");
        printf("|    SPADE     |\n");
        printf("|______________|\n");
        p = 10;
    }
    else if(random_card == 13)
    {
        printf(" ______________\n");
        printf("|              |\n");
        printf("|    SPADE     |\n");
        printf("|     *K*      |\n");
        printf("|    SPADE     |\n");
        printf("|______________|\n");
        p = 10;
    }
    return p;
}
int club() //For club
{
    srand((unsigned)time(NULL));
    int random_card = rand() % 13 + 1, p;
    if(random_card == 1 || random_card == 11)
    {
        printf(" ______________\n");
        printf("|              |\n");
        printf("|    CLUB      |\n");
        printf("|     *A*      |\n");
        printf("|    CLUB      |\n");
        printf("|______________|\n");
        if(point <= 10)
        {
            p = 11;
        }
        else
        {
            p = 1;
        }
    }
    else if(random_card <= 9)
    {
        printf(" ______________\n");
        printf("|              |\n");
        printf("|    CLUB      |\n");
        printf("|    *%d*      |\n", random_card);
        printf("|    CLUB      |\n");
        printf("|______________|\n");
        p = random_card;
    }
    else if(random_card == 10)
    {
        printf(" ______________\n");
        printf("|              |\n");
        printf("|    CLUB      |\n");
        printf("|     *J*      |\n");
        printf("|    CLUB      |\n");
        printf("|______________|\n");
        p = 10;
    }
    else if(random_card == 12)
    {
        printf(" ______________\n");
        printf("|              |\n");
        printf("|    CLUB      |\n");
        printf("|     *Q*      |\n");
        printf("|    CLUB      |\n");
        printf("|______________|\n");
        p = 10;
    }
    else if(random_card == 13)
    {
        printf(" ______________\n");
        printf("|              |\n");
        printf("|    CLUB      |\n");
        printf("|     *K*      |\n");
        printf("|    CLUB      |\n");
        printf("|______________|\n");
        p = 10;
    }
    return p;
}
int diamond() //For diamond
{
    srand((unsigned)time(NULL));
    int random_card = rand() % 13 + 1, p;
    if(random_card == 1 || random_card == 11)
    {
        printf(" ________________\n");
        printf("|                |\n");
        printf("|    DIAMOND     |\n");
        printf("|      *A*       |\n");
        printf("|    DIAMOND     |\n");
        printf("|________________|\n");
        if(point <= 10)
        {
            p = 11;
        }
        else
        {
            p = 1;
        }
    }
    else if(random_card <= 9)
    {
        printf(" ______________\n");
        printf("|              |\n");
        printf("|    DIAMOND   |\n");
        printf("|     *%d*      |\n", random_card);
        printf("|    DIAMOND   |\n");
        printf("|______________|\n");
        p = random_card;
    }
    else if(random_card == 10)
    {
        printf(" ______________\n");
        printf("|              |\n");
        printf("|    DIAMOND   |\n");
        printf("|      *J*     |\n");
        printf("|    DIAMOND   |\n");
        printf("|______________|\n");
        p = 10;
    }
    else if(random_card == 12)
    {
        printf(" ______________\n");
        printf("|              |");
        printf("|    DIAMOND   |\n");
        printf("|      *Q*     |\n");
        printf("|    DIAMOND   |\n");
        printf("|______________|\n");
        p = 10;
    }
    else if(random_card == 13)
    {
        printf(" ______________\n");
        printf("|              |");
        printf("|    DIAMOND   |\n");
        printf("|      *K*     |\n");
        printf("|    DIAMOND   |\n");
        printf("|______________|\n");
        p = 10;
    }
    return p;
}
int heart() //For heart
{
    srand((unsigned)time(NULL));
    int random_card = rand() % 13 + 1, p;
    if(random_card == 1 || random_card == 11)
    {
        printf(" ______________\n");
        printf("|              |\n");
        printf("|    HEART     |\n");
        printf("|     *A*      |\n");
        printf("|    HEART     |\n");
        printf("|______________|\n");
        if(point <= 10)
        {
            p = 11;
        }
        else
        {
            p = 1;
        }
    }
    else if(random_card <= 9)
    {
        printf(" ______________\n");
        printf("|              |\n");
        printf("|    HEART     |\n");
        printf("|     *%d*      |\n", random_card);
        printf("|    HEART     |\n");
        printf("|______________|\n");
        p = random_card;
    }
    else if(random_card == 10)
    {
        printf(" ______________\n");
        printf("|              |\n");
        printf("|    HEART     |\n");
        printf("|     *J*      |\n");
        printf("|    HEART     |\n");
        printf("|______________|\n");
        p = 10;
    }
    else if(random_card == 12)
    {
        printf(" ______________\n");
        printf("|              |\n");
        printf("|    HEART     |\n");
        printf("|     *Q*      |\n");
        printf("|    HEART     |\n");
        printf("|______________|\n");
        p = 10;
    }
    else if(random_card == 13)
    {
        printf(" ______________\n");
        printf("|              |\n");
        printf("|    HEART     |\n");
        printf("|     *K*      |\n");
        printf("|    HEART     |\n");
        printf("|______________|\n");
        p = 10;
    }
    return p;
}
void ask()//Asks user
{
    char ch;
    while(1)
    {
        printf("\n\nWould you like to play again?\nIf yes enter 'y' and if no then press 'n': ");
        scanf(" %c", &ch);
        if(ch == 'y' || ch == 'Y')
        {
            if(cash > 0)
                start_play();
            else
                start_bet();
        }
        else if(ch == 'n' || ch == 'n')
        {
            not_play_blackjack();
            return;
        }
        else
            printf("\n\nInvalid input.Please enter 'Y' or 'N'.\n");
    }
}

void stay() //Stay
{
    while(dealer_point < 17)
    {
        dealer();
        if(dealer_point > 21)
        {
            printf("\n\nWOW! YOU WIN THE GAME!\n");
            cash += bet_value;
            win += 1;
            printf("\n\nYou won %d games and loss %d games!\n", win, loss);
            ask();
            return;
        }
    }
    if(dealer_point < point)
    {
        printf("\n\nWOW! YOU WIN THE GAME!\n");
        cash += bet_value;
        win += 1;
        printf("\n\nYou won %d games and loss %d games!\n", win, loss);
        ask();
    }
    else if(dealer_point > 21)
    {
        printf("\n\nWOW! YOU WIN THE GAME!\n");
        cash += bet_value;
        win += 1;
        printf("\n\nYou won %d games and loss %d games!\n", win, loss);
        ask();
    }
    else if(dealer_point > point)
    {
        printf("\n\nSorry, you have lost the game!\n");
        cash -= bet_value;
        loss += 1;
        printf("\n\nYou won %d games and loss %d games!\n", win, loss);
        ask();
    }
    else if(dealer_point == point)
    {
        printf("\n\nPUSH! Neither you nor the dealer wins.\n");
        printf("\n\nYou won %d games and loss %d games!\n", win, loss);
        ask();
    }

}
