#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int main()
{
    int op;
    int num, guess, tries = 0;
    int temp, remainder, reverse = 0;
    float a, b, c;
    float celsius, fahrenheit, raiz;

    do{
        system("cls");
        printf("1 - Guess the number game\n");
        printf("2 - Reverse a number\n");
        printf("3 - Celsius to fahrenheit\n");
        printf("4 - Quadratic Formula\n");
        printf("5 - Leave\n\n");
        printf("Option = ");
        scanf("%d", &op);
        system("cls");

        switch(op){
        case 1:


            srand(time(0));
            num = rand() % 100 + 1;

            printf("Guess My Number Game\n\n");

            do{
                printf("Enter a Guess: ");
                scanf("%d", &guess);

                tries++;

                if(guess > num){
                    printf("To high!\n\n");
                }else if(guess == -69){
                    printf("Number = %d\n\n", num);
                }else if(guess < num){
                    printf("To low!\n\n");
                }else{
                    printf("\nCorrect! You got it in %d guesses!", tries);
                    delay(2000);
                }

            }while(guess != num);

            break;

            case 2:
                printf("Enter a number: ");
                scanf("%d", &num);

                temp = num;

                while(temp > 0){
                    remainder = temp % 10;
                    reverse = reverse * 10 + remainder;
                    temp /= 10;
                }

                printf("The reverse of %d is %d", num, reverse);
                delay(2000);
                break;

            case 3:
                printf("Enter the temperature in celsius: ");
                scanf("%f", &celsius);

                fahrenheit = 9.0 / 5 * celsius + 32;
                printf("%0.2fC = %0.2fF", celsius, fahrenheit);
                delay(2000);
                break;
            case 4:
                printf("Enter a: ");
                scanf("%f", &a);
                printf("Enter b: ");
                scanf("%f", &b);
                printf("Enter c: ");
                scanf("%f", &c);

                raiz = (b * b) - 4 * a * c;
                printf("raiz = %f", raiz);
                delay(2000);

                break;

        }

    }while(op != 5);



    return 0;
}
