#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

int NbTire=0, choix, i, ii, axeX, axeY, ToucheMax;
char lettre;
char tableShips [2][10][10] =
        {
                {
                        {'~','~','~','~','~','~','~','~','~','~'},
                        {'~','~','~','~','~','~','~','~','~','~'},
                        {'~','~','~','~','~','~','~','~','~','~'},
                        {'~','~','~','~','~','~','~','~','~','~'},
                        {'~','~','~','~','~','~','~','~','~','~'},
                        {'~','~','~','~','~','~','~','~','~','~'},
                        {'~','~','~','~','~','~','~','~','~','~'},
                        {'~','~','~','~','~','~','~','~','~','~'},
                        {'~','~','~','~','~','~','~','~','~','~'},
                        {'~','~','~','~','~','~','~','~','~','~'}
                },
                {
                        { '#', 'A', '#', '#', '#', '#', '#', '#', '#', '#' },
                        { '#', 'A', '#', '#', '#', '#', '#', '#', '#', '#' },
                        { '#', '#', '#', '#', '#', '#', '#', '#', 'D', '#' },
                        { '#', '#', '#', '#', '#', '#', '#', '#', 'D', '#' },
                        { '#', '#', 'B', 'B', 'B', '#', '#', '#', 'D', '#' },
                        { '#', '#', '#', '#', '#', '#', '#', '#', 'D', '#' },
                        { '#', '#', 'E', 'E', 'E', 'E', 'E', '#', '#', '#' },
                        { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
                        { '#', '#', 'C', 'C', 'C', '#', '#', '#', '#', '#' },
                        { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' }
                }
        };
void color(int front, int back)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back*16 + front);
}
void drawGrid ()
{
    system("cls");
    color(15,0);
    printf("   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐\n");
    printf("   │  A  │  B  │  C  │  D  │  E  │  F  │  G  │  H  │  I  │  J  │\n");
    printf("┌──┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤\n");
    for(i = 0; i < 10; i++)
    {
        if (i!=9) {
            printf("│%x │", i+1);
        }else{
            printf("│10│");
        }
        for(ii = 0; ii < 10; ii++)
        {
            if(axeY==i&&axeX==ii) {
                if (tableShips[1][i][ii] == 'A'
                    || tableShips[1][i][ii] == 'B'
                    || tableShips[1][i][ii] == 'C'
                    || tableShips[1][i][ii] == 'D'
                    || tableShips[1][i][ii] == 'E') {
                    color(15, 4);
                    printf("  %c  ", tableShips[1][i][ii]);
                    color(15, 0);
                    printf("│");
                    ToucheMax++;
                } else {
                    color(15,2);
                    printf("  %c  ", tableShips[1][i][ii]);
                    color(15,0);
                    printf("│");
                }
            }else if(tableShips [0][i][ii] == '~')
            {
                color(15,1);
                printf("  %c  ", tableShips[0][i][ii]);
                color(15,0);
                printf("│");
            }
        }
        if (i!=9) {
            printf("\n├──┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤\n");
        }else{
            printf("\n└──┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘\n");
        }
    }
}
int Play(){
    do{
        drawGrid();
        printf("Veuilez choisir un colonne (A-J) : ");
        fflush(stdin);
        scanf("%c",&lettre);
        if (lettre=='A'||lettre=='a') axeX=0;
        if (lettre=='B'||lettre=='b') axeX=1;
        if (lettre=='C'||lettre=='c') axeX=2;
        if (lettre=='D'||lettre=='d') axeX=3;
        if (lettre=='E'||lettre=='e') axeX=4;
        if (lettre=='F'||lettre=='f') axeX=5;
        if (lettre=='G'||lettre=='g') axeX=6;
        if (lettre=='H'||lettre=='h') axeX=7;
        if (lettre=='I'||lettre=='i') axeX=8;
        if (lettre=='J'||lettre=='j') axeX=9;
        printf("veuillez choisir une ligne (1-10) : ");
        fflush(stdin);
        scanf("%d",&axeY);
        axeY=axeY-1;
        NbTire++;
    } while (ToucheMax!=17);
    printf("Tu a tiré %d",NbTire);
}
int SCORES(){
    system("cls");
    printf("\n\n         Travaille en cour\n\n         ");
    choix = 0;
    system("pause");
}
int RULES() {
    system("cls");
    printf("\n       RÈGLES\n\n");
    printf("       Votre flotte a 5 bateaux qui sont les suivant:\n");
    printf("       -1 porte-avion(5 cases)\n");
    printf("       -1 croiseur(4 cases)\n");
    printf("       -1 contre-torpilleur(3 cases)\n");
    printf("       -1 sous-marin(3 cases)\n");
    printf("       -1 torpilleur (2 cases)\n");
    printf("       Les bateaux ne sont pas colles entre eux.\n");
    printf("       La grille est numerotee de 1 a 10 verticalement\n");
    printf("       et de A a J horizontalement. Vous allez \"tirer\"\n");
    printf("       sur une case de l'adversaire: exemple, B.3. le but est\n");
    printf("       donc de couler les bateaux adverses.\n");
    printf("       Au fur et a mesure des marqueurs serons affiche afin de se\n");
    printf("       souvenir de vos tirs passes.\n\n       ");
    system("pause");
    return(0);
}
int OPTIONS(){
    system("cls");
    printf("\n\n         Travaille en cour\n\n         ");
    choix = 0;
    system("pause");
}
int goToMenu () {
    do {
        system("cls");
        printf("\n                                                                             ____         _          _  _ _        _   _                  _"
               "\n                                                                            | __ )   __ _| |_   __ _(_)| | | ___  | \\ | | __ ___   ____ _| | ___"
               "\n                                                                            |  _ \\  / _` | __| / _` | || | |/ _ \\ |  \\| |/ _` \\ \\ / / _` | |/ _ \\ "
               "\n                                                                            | |_) || (_| | |_ | (_| | || | |  __/ | |\\  | (_| |\\ V / (_| | |  __/"
               "\n                                                                            |____/  \\__,_|\\__| \\__,_|_||_|_|\\___| |_| \\_|\\__,_| \\_/ \\__,_|_|\\___|\n");
        printf("                                                                                                        by Joshua\n\n\n");
        printf("                                                                                                    MENU PRINCIPAL\n\n");
        printf("\n                                                                                                      Jouer   [1]\n");
        printf("\n                                                                                                      Scores  [2]\n");
        printf("\n                                                                                                      Règles  [3]\n");
        printf("\n                                                                                                      Options [4]\n");
        printf("\n                                                                                                      Quitter [5]\n");
        printf("\n\t\t\t\t\tIndiquez votre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1 :
                Play();
                choix = 0;
                break;
            case 2 :
                SCORES();
                break;
            case 3 :
                RULES();
                choix = 0;
                break;
            case 4 :
                OPTIONS();
                break;
            case 5 :
                system("cls");
                choix = 0;
                break;
            default:
                break;
        }
    } while (choix != 5);
    system("pause");
}
int main()
{
    SetConsoleOutputCP(65001);
    color(15,0);
    goToMenu(0);
    return 0;
}