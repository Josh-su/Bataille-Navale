#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

int NomUtilisateur, Tire, NbTire=0,coordone=1, choix, i, ii, line, column;
char axeX, axeY;
int JEU(){
    system("cls");
    printf("╔══A═══B═══C═══D═══E═══F═══G═══H═══I═══J══╗\n1");
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i!=9) {
                printf("  ▓▓");
            }else{
                printf(" ▓▓ ");
            }
        }
        if (i!=9) {
            coordone++;
            printf(" ║\n║");
            for (int j = 0; j < 41; ++j) {
                printf(" ");
            }
            printf("║\n%d", coordone);
        }else{
            printf("║\n╚");
            for (int k = 0; k < 41; ++k) {
                printf("═");
            }
        }
    }
    printf("╝\n(A-J) : ");
    scanf("%c",&axeX);
    printf("(1-10) : ");
    scanf("%c",&axeY);

    scanf("%d",&Tire);
//    if (Tire==1||Tire==2||Tire==3||Tire==4||Tire==5) {
//        printf("touche!");
//    }
//    if(Tire==2){
//        printf("touche coule!");
//    }
//    if(Tire==0){
//        printf("Plouf!");
//    }
}
void clearBuffer();
char tableShips [2][10][10] =
        {
                {
                        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
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
int shipsPlace [2] = {0,0};
void color(int front, int back)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back*16 + front);
}
void startBoard(int board[][5])
{
    for(line=0 ; line < 5 ; line++ )
        for(column=0 ; column < 5 ; column++ )
            board[line][column]=-1;
}
void showBoard(int board[][5])
{
    color(15,0);
    printf("   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐\n");
    printf("   │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │\n");
    printf("┌──┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤\n");
    for(line=0 ; line < 5 ; line++ ){
        printf("%d", line + 1);
        for(column=0 ; column < 5 ; column++ ){
            if(board[line][column] == -1){
                color(15,1);
                printf("│ ~ │");
                color(15,0);
            }else if(board[line][column] == 0){
                color(15,1);
                printf("\t*");
                color(15,0);
            }else if(board[line][column] == 1){
                printf("\tX");
            }
        }
        printf("\n");
    }
}
void drawGrid (int playerturn)
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
            if(tableShips [playerturn][i][ii] == '#')
            {
                color(15,1);
                printf("  %c  ", tableShips[playerturn][i][ii]);
                color(15,0);
                printf("│");
            }
            if(tableShips [playerturn][i][ii] == 'A'
            ||tableShips [playerturn][i][ii] == 'B'
            ||tableShips [playerturn][i][ii] == 'C'
            ||tableShips [playerturn][i][ii] == 'D'
            ||tableShips [playerturn][i][ii] == 'E')
            {
                color(15,4);
                printf("  %c  ", tableShips [playerturn][i][ii]);
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
    drawGrid(0);
    printf("(A-J) : ");
    scanf("%c",&axeX);
    printf("(1-10) : ");
    scanf("%c",&axeY);
    NbTire++;
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
int goToMenu (int menuChoice) {
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
    int menuChoice = 0;
    SetConsoleOutputCP(65001);
    color(15,0);
    goToMenu(0);
    return 0;
}