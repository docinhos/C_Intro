#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <conio.h>

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

/*******************************************************************
                    DESENHA A BOARD - TIC TAC TOE
********************************************************************/

void board(){
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Jogador 1 (X)  -  Jogador 2 (O)\n\n\n");

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

/*********************************************
FUNCAO QUE DA RETORNO AO ESTADO DO JOGO
1   - JOGO FINALIZADO COM RESULTADO
-1  - JOGO EM PROGRESSO
O   - JOGO ACABOU SEM RESULTADO
 **********************************************/

int checkwin(){
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

/*******************************************************************
                                MAIN
********************************************************************/

int main()
{
        int op;
        int vOpcoes = 11;

    do{

        /*******************************************************************
                                    OTHER VARIABLES
        ********************************************************************/

        int num, guess, teste[30], i, factorial = 1,tries = 0;
        int temp, remainder, contador = 0,reverse = 0;

        float a, b, c, x1, x2;
        float celsius, fahrenheit, raiz;

        double media = 0;

        /*******************************************************************
                                TIC TAC TOE VARIABLES
        ********************************************************************/

        int player = 1, z, choice;
        char mark;


        system("cls");
        printf("1 - Guess the number game\n");
        printf("2 - Reverse a number - (Algoritmia)\n");
        printf("3 - Celsius para fahrenheit - (Algoritmia)\n");
        printf("4 - Formula Quadrada - (Algoritmia)\n");
        printf("5 - Factorial - (Algoritmia)\n");
        printf("6 - Media de 30 - (Algoritmia)\n");
        printf("7 - Contar numeros negativos - (Algoritmia)\n");
        printf("8 - Maior de 10 - (Algoritmia)\n");
        printf("9 - Soma dos Algarismos- (Algoritmia)\n");
        printf("10 - Tic Tac Toe\n");
        printf("11 - Sair\n\n");


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

                if(raiz == 0){
                    x1 = -b / (2*a);
                    printf("Only 1 solution: x = %f", x1);
                }else if(raiz > 0){
                    x1 = (-b + sqrt(raiz)) / (2*a);
                    x2 = (-b - sqrt(raiz)) / (2*a);
                    printf("2 solution: x = %f || x = %f", x1, x2);
                }else{
                    printf("The roots are imaginary");
                }
                delay(2000);
                break;
            case 5:
                printf("Enter the number: ");
                scanf("%d", &num);
                for(i = 1; i <= num; i++){
                    factorial *= i;
                }
                printf("%d! = %d", num, factorial);
                delay(2000);
                break;
            case 6:
                srand(time(0));
                for(int c = 0; c < 30; c++){
                    teste[c] = rand() % 20 + 1;
                    media += teste[c];
//                    printf("teste[%d] = %d\n",c ,teste[c]);
                }
                media /= 30;
                printf("Media = %lf", media);
                getch();
                break;
            case 7:
                i = 0;
                    while(i < 9){
                        printf("Numero: ");
                        scanf("%d", &num);
                        if(num < 0){contador++;}
                        i++;
                    }
                    printf("Total de Numeros Negativos: %d", contador);
                    delay(4000);
                break;
            case 8:
                i = 2;
                printf("Numero 1: ");
                scanf("%d", &num);

                while(i < 11){
                    system("cls");
                    printf("Numero %d: ", i);
                    scanf("%d", &temp);
                    if(temp > num){num = temp;}
                    i++;
                }
                system("cls");
                printf("Maior: %d", num);
                delay(2000);
                break;
            case 9:
                printf("Entra um Numero Positivo: ");
                scanf("%d", &num);
                temp = num;
                while(temp > 0){
                    remainder = temp % 10;
                    contador += remainder;
                    temp /= 10;
                }
                printf("A soma dos digitos de %d = %d", num, contador);
                getch();
                break;
            case 10:

                do{
                    board();
                    player = (player % 2) ? 1 : 2;
                    printf("Jogador %d, entra um numero: ", player);
                    scanf("%d", &choice);

                    mark = (player == 1) ? 'X' : 'O';

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

                        player--;
                        getch();
                    }


                    i = checkwin();
                    player++;

                }while(i == -1);

                board();

                if(i == 1){
                    printf("==>\aPlayer %d win ", --player);
                }else{
                    printf("==>\aGame draw");
                }
                getch();

                break;
        }

    }while(op != vOpcoes);



    return 0;
}
