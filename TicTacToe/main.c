#include <stdio.h>

int main()
{
    int op;

    do{
        printf("1 - Guess the number game\n");
        printf("2 - Leave\n\n");
        printf("Option = ");
        scanf("%d", op);

        switch(){

        case 1:

            int num, guess, tries = 0;

            srand(time(0));
            num = rand() % 100 + 1;

            printf("Guess My Number Game\n\n");

            do{
                printf("Enter a Guess: ");
                scanf("%d", &guess);

                tries++;

                if(guess > num){
                    printf("To high!\n\n");
                }else if(guess < num){
                    printf("To low!\n\n");
                }else{
                    printf("\nCorrect! You got it in %d guesses!", tries);
                }

            }while(guess != num);

            break;

        }

    }while(op != 2)



    return 0;
}
