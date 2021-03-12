#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int NbTire = 0, choix, i, j, axeX, axeY, ToucheMax, touche, rate, exit_;
char lettre;
char tableBateaux[10][10] = //cette table represente les bateaux sur la grille
        {
                {'#', 'A', '#', '#', '#', '#', '#', '#', '#', '#'},
                {'#', 'A', '#', '#', '#', '#', '#', '#', '#', '#'},
                {'#', '#', '#', '#', '#', '#', '#', '#', 'D', '#'},
                {'#', '#', '#', '#', '#', '#', '#', '#', 'D', '#'},
                {'#', '#', 'B', 'B', 'B', '#', '#', '#', 'D', '#'},
                {'#', '#', '#', '#', '#', '#', '#', '#', 'D', '#'},
                {'#', '#', 'E', 'E', 'E', 'E', 'E', '#', '#', '#'},
                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                {'#', 'C', 'C', 'C', 'C', '#', '#', '#', '#', '#'},
                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
        };
int tableencour[10][10] =  //cette table sert a sauvegarder les case sur les quelle on a tirer
        {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        };
void color(int front, int back) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back * 16 + front);
}//variable pour mettre des couleurs

void clearGrid() {
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tableencour[i][j] = 0;
        }
    }
    axeX = -1;
    axeY = -1;
    ToucheMax = 0;
}//renisialisé la grille

void drawGrid() {
    rate = 0;
    touche = 0;
    system("cls");
    color(15, 0);
    printf("   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐\n");
    printf("   │  A  │  B  │  C  │  D  │  E  │  F  │  G  │  H  │  I  │  J  │\n");
    printf("┌──┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤\n");//affiche la 1er ligne
    for (i = 0; i < 10; i++) {
        //print les numeros a gauche
        if (i != 9) {
            printf("│%x │", i + 1);
        } else {
            printf("│10│");
        }
        for (j = 0; j < 10; j++) {
            if (axeY == i && axeX == j) {
                tableencour[i][j] = 1;//sauvegarde la case touche
                if (tableBateaux[i][j] == 'A' || tableBateaux[i][j] == 'B' || tableBateaux[i][j] == 'C' ||
                    tableBateaux[i][j] == 'D' || tableBateaux[i][j] == 'E')//on verifie si il y a un bateau
                    touche++;// si oui un ajoute 1 a la variable 'touche' si non on ajoute 1 a la variable 'rate'
                else rate++;
            }
            if (tableencour[i][j] == 1 || tableencour[i][j] == 2) {
                if (tableBateaux[i][j] == 'A' || tableBateaux[i][j] == 'B' || tableBateaux[i][j] == 'C' ||
                    tableBateaux[i][j] == 'D' || tableBateaux[i][j] == 'E') {//verifie si il y a un bateau dans les cases ou on a deja tirer dessus
                    color(15, 4);
                    printf("  !  ");//si oui on affiche un point d'exlamation en rouge
                    color(15, 0);
                    printf("│");
                } else {
                    color(15, 3);
                    printf("  #  ");//si non on affiche un hashtag en bleu clair
                    color(15, 0);
                    printf("│");
                }
            } else {
                color(15, 1);
                printf("  ~  ");//si la case n'a pas ete tirer dessus on affiche le signe environ en bleu
                color(15, 0);
                printf("│");
            }
        }
        if (i != 9) {
            printf("\n├──┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤\n");
        } else {
            printf("\n└──┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘\n");
        }
    }
} //affiche toute la grille

void Change() {
    if (lettre == 'A' || lettre == 'a') axeX = 0;
    if (lettre == 'B' || lettre == 'b') axeX = 1;
    if (lettre == 'C' || lettre == 'c') axeX = 2;
    if (lettre == 'D' || lettre == 'd') axeX = 3;
    if (lettre == 'E' || lettre == 'e') axeX = 4;
    if (lettre == 'F' || lettre == 'f') axeX = 5;
    if (lettre == 'G' || lettre == 'g') axeX = 6;
    if (lettre == 'H' || lettre == 'h') axeX = 7;
    if (lettre == 'I' || lettre == 'i') axeX = 8;
    if (lettre == 'J' || lettre == 'j') axeX = 9;
}//defini la variable 'axeX' par rapport a la variable 'lettre'

int play() {
    clearGrid();
    while (ToucheMax != 17) {
        drawGrid();
        if (tableencour[axeY][axeX] == 2) {// le fait de ne pas pouvoir tirer plusieurs fois sur le meme bateau ne fonctionne pas
            printf("\tBateau déjà touché !!\n");
        }else if (touche == 1) {
            tableencour[axeY][axeX] = 2;
            printf("\tTouché !!\n");
            ToucheMax++;
        }
        if (rate == 1) {
            printf("\tPlouf !!\n");
        }
        printf("\tVeuilez choisir un colonne (A-J) : ");//demande la coordonee horizental
        fflush(stdin);
        scanf("%c", &lettre);
        Change();
        printf("\tveuillez choisir une ligne (1-10) : ");//demande la coordonee vertical
        fflush(stdin);
        scanf("%d", &axeY);
        axeY = axeY - 1;
        NbTire++;
    }
    system("pause");
    printf("\n\t\tBRAVO\n\n\tTu a fini en %d tire\n\t", NbTire - 1);//affiche combien de fois tu a tire pour finir
    system("pause");
}//demande les coordonee et affiche si on a touche ou rater un bateau

void scores() {
    system("cls");
    printf("\n\n         Travaille en cour\n\n         ");
    choix = 0;
    system("pause");
}

void rules() {
    system("cls");
    printf("\n       RÈGLES\n\n");
    printf("       Votre flotte a 5 bateaux qui sont les suivant:\n");
    printf("       -1 porte-avion(5 cases)\n");
    printf("       -1 croiseur(4 cases)\n");
    printf("       -1 contre-torpilleur(3 cases)\n");
    printf("       -1 sous-marin(3 cases)\n");
    printf("       -1 torpilleur (2 cases)\n");
    printf("       Les bateaux ne sont pas colles entre eux.\n");
    printf("       La grille est numerotée de 1 a 10 verticalement\n");
    printf("       et de A a J horizontalement. Vous allez \"tirer\"\n");
    printf("       sur une case de l'adversaire: exemple, B.3. le but est\n");
    printf("       donc de couler les bateaux adverses.\n");
    printf("       Au fur et a mesure des marqueurs serons affiche afin de se\n");
    printf("       souvenir de vos tirs passes.\n\n       ");
    system("pause");
}

void options() {
    system("cls");
    printf("\n\n         Travaille en cour\n\n         ");
    choix = 0;
    system("pause");
}

int goToMenu() {
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
                play();
                choix = 0;
                break;
            case 2 :
                scores();
                break;
            case 3 :
                rules();
                choix = 0;
                break;
            case 4 :
                options();
                break;
            default:
                printf("UNKNOW VALUE!!");
        }
    } while (choix != 5);
    printf("\n\n\n\t\t\tVeut vraiment quitter ? 1/NO-The rest/YES");
    scanf("%d", &exit_);
    if (exit_ == 1) {
        goToMenu();
    } else system("exit");
}//affiche le menu

int main() {
    SetConsoleOutputCP(65001);//cela sert a afficher les caractere speciaux(les accents,...)
    color(15, 0);//on met la couleur du texte en blanc
    goToMenu();
    return 0;
}