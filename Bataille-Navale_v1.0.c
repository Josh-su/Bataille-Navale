/*
* Auteur:      Joshua Surico
* Date :       02.04.2021
* Titre:       bataille navale
* Description: Ce programme est le jeu de la bataille navale mais pour 1 joueur
* Version:     1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define TAILLE_MAX 1000

int NbTire, x, y, axeX, axeY, ToucheMax, touche, rate_, exit_, choix, BateauA, BateauB, BateauC, BateauD, BateauE, evenement, choix_option, choix_couleur = 1, NbScoreAffiche, couleur, couleur_grille, choix_quitter, partie_en_cour = 0;

void retourMenu();//declaration des fonctions
char lettre, Pseudo[300];
char tableBateaux[10][10] = //cette table represente les bateaux sur la grille
        {
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
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

void color(int front, int back) {//variable pour mettre des couleurs
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back * 16 + front);
}

void couleur_actuelle() {
    switch (choix_couleur) {
        case 1 :
            color(15, 0);
            couleur = choix_couleur;
            break;
        case 2 :
            color(4, 0);
            couleur = choix_couleur;
            break;
        case 3 :
            color(3, 0);
            couleur = choix_couleur;
            break;
        case 4 :
            color(10, 0);
            couleur = choix_couleur;
            break;
        case 5 :
            color(13, 0);
            couleur = choix_couleur;
            break;
        case 6 :
            color(5, 0);
            couleur = choix_couleur;
            break;
        case 7 :
            color(6, 0);
            couleur = choix_couleur;
            break;
        case 8 :
            color(11, 0);
            couleur = choix_couleur;
            break;
        default:
            if (choix_couleur != 9) {
                printf("\n\t\t");
                printf("UNKNOW VALUE!!");
                printf("\n\t\t");
                fflush(stdin);
                system("pause");
                choix_couleur = 0;
            }
            break;
    }
    if (couleur_grille == 1) {
        choix_couleur = couleur;
        couleur_grille = 0;
        couleur_actuelle();
    }
}

void definir_grille() {//choisi aleatoirement une des 5 grilles
    srand(time(NULL));
    int r;
    r = rand() % 5;
    FILE *fichier = NULL;
    switch (r) {
        case 0:
            fichier = fopen("../grilles/grille0.txt", "r");
            break;
        case 1:
            fichier = fopen("../grilles/grille1.txt", "r");
            break;
        case 2:
            fichier = fopen("../grilles/grille2.txt", "r");
            break;
        case 3:
            fichier = fopen("../grilles/grille3.txt", "r");
            break;
        case 4:
            fichier = fopen("../grilles/grille4.txt", "r");
            break;
        default:
            break;
    }
    if (fichier != NULL) {
        for (int k = 0; k < 10; ++k) {
            for (int l = 0; l < 10; ++l) {
                char buff = fgetc(fichier);
                if (buff == '\n') {
                    buff = fgetc(fichier);
                }
                tableBateaux[k][l] = buff == '0' ? ' ' : buff;
            }
        }
    }
}

void logs() {
    SYSTEMTIME t;
    GetLocalTime(&t);
    FILE *fichier = NULL;
    fichier = fopen("../LogsScores/Logs.txt", "a");
    fseek(fichier, 2, SEEK_END);
    if (fichier != NULL) {
        if (evenement == 1)
            fprintf(fichier, "le programme a ete lance le %d.%d.%d a %d:%d:%d \n", t.wDay, t.wMonth, t.wYear, t.wHour,
                    t.wMinute, t.wSecond);
        else if (evenement == 2)
            fprintf(fichier, "%s a lancer une partie le %d.%d.%d a %d:%d:%d \n", Pseudo, t.wDay, t.wMonth, t.wYear,
                    t.wHour, t.wMinute, t.wSecond);
        else if (evenement == 3)
            fprintf(fichier, "%s a fini une partie le %d.%d.%d a %d:%d:%d et a gagner en %d tires\n", Pseudo, t.wDay,
                    t.wMonth, t.wYear, t.wHour, t.wMinute, t.wSecond, NbTire);
        else if (evenement == 4)
            fprintf(fichier, "%s a fermer le programme le %d.%d.%d a %d:%d:%d \n", Pseudo, t.wDay, t.wMonth, t.wYear,
                    t.wHour, t.wMinute, t.wSecond);
        evenement = 0;
        fclose(fichier);
    }
}

void enreg_scores() {//enregistre les scores
    FILE *fichier = NULL;
    fichier = fopen("../LogsScores/Scores.txt", "r+");
    if (fichier != NULL) {
        rewind(fichier);
        fprintf(fichier, "%s %d\n", Pseudo, NbTire);
        fclose(fichier);
    }
}

void affi_scores() {//affiche les 5 derniers scores
    system("cls");
    FILE *fichier = NULL;
    char chaine[TAILLE_MAX] = "5";
    NbScoreAffiche = 0;
    fichier = fopen("../LogsScores/Scores.txt", "r+");
    if (fichier != NULL) {
        printf(" __     __      _        _    _               ____         _                     _                                                    \n"
               " \\ \\   / /___  (_)  ___ (_)  | |  ___  ___   | ___|     __| |  ___  _ __  _ __  (_)  ___  _ __  ___   ___   ___  ___   _ __  ___  ___ \n"
               "  \\ \\ / // _ \\ | | / __|| |  | | / _ \\/ __|  |___ \\    / _` | / _ \\| '__|| '_ \\ | | / _ \\| '__|/ __| / __| / __|/ _ \\ | '__|/ _ \\/ __|\n"
               "   \\ V /| (_) || || (__ | |  | ||  __/\\__ \\   ___) |  | (_| ||  __/| |   | | | || ||  __/| |   \\__ \\ \\__ \\| (__| (_) || |  |  __/\\__ \\\n"
               "    \\_/  \\___/ |_| \\___||_|  |_| \\___||___/  |____/    \\__,_| \\___||_|   |_| |_||_| \\___||_|   |___/ |___/ \\___|\\___/ |_|   \\___||___/\n"
               "                                                            \n\n\n");
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("\t\t-  %s", chaine); // On affiche la chaîne qu'on vient de lire
            NbScoreAffiche++;
            if (NbScoreAffiche == 5) fclose(fichier);
        }
    }
    printf("\n\t\t");
    system("pause");
}

void enreg_pseudo() {//enregistre le pseudo
    printf("inscrit ton pseudo : ");
    fflush(stdin);
    scanf("%s", &Pseudo);
}

void clearGrid() {//réinitialiser la grille et les variables
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++) {
            tableencour[x][y] = 0;
        }
    }
    axeX = -1, axeY = -1, NbTire = 0, ToucheMax = 0, BateauA = 2, BateauB = 3, BateauC = 3, BateauD = 4, BateauE = 5, couleur_grille = 0;
}

void drawGrid() {//affiche toute la grille
    rate_ = 0;
    touche = 0;
    couleur_grille = 1;
    system("cls");
    printf("   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐\n");
    printf("   │  A  │  B  │  C  │  D  │  E  │  F  │  G  │  H  │  I  │  J  │\n");
    printf("┌──┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤\n");//affiche la 1er ligne
    for (x = 0; x < 10; x++) {
        //print les numeros a gauche
        if (x != 9) {
            printf("│%x │", x + 1);
        } else {
            printf("│10│");
        }
        for (y = 0; y < 10; y++) {
            if (axeY == x && axeX == y) {
                if (tableencour[x][y] != 2) tableencour[x][y] = 1;//sauvegarde la case touché
                if (tableBateaux[x][y] == 'A' || tableBateaux[x][y] == 'B' || tableBateaux[x][y] == 'C' ||
                    tableBateaux[x][y] == 'D' || tableBateaux[x][y] == 'E')//on verifie si il y a un bateau
                    touche++;// si oui un ajoute 1 a la variable 'touche' si non on ajoute 1 a la variable 'rate_'
                else rate_++;
            }
            if (tableencour[x][y] == 1 || tableencour[x][y] == 2) {
                if (tableBateaux[x][y] == 'A' || tableBateaux[x][y] == 'B' || tableBateaux[x][y] == 'C' ||
                    tableBateaux[x][y] == 'D' ||
                    tableBateaux[x][y] == 'E') {//verifie si il y a un bateau dans les cases ou on a deja tirer dessus
                    color(15, 4);
                    printf("  !  ");//si oui on affiche un point d'exlamation en rouge
                    couleur_grille = 1;
                    couleur_actuelle();
                    printf("│");
                } else {
                    color(15, 3);
                    printf("  #  ");//si non on affiche un hashtag en bleu clair
                    couleur_grille = 1;
                    couleur_actuelle();
                    printf("│");
                }
            } else {
                color(15, 1);
                printf("  ~  ");//si la case n'a pas ete tirer dessus on affiche le signe environ en bleu
                couleur_grille = 1;
                couleur_actuelle();
                printf("│");
            }
        }
        if (x != 9) {
            printf("\n├──┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤\n");
        } else {
            printf("\n└──┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘\n");
        }
    }
}

void Change() {//defini la variable 'axeX' par rapport a la variable 'lettre'
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
}

void healthShip() {
    if (tableBateaux[axeY][axeX] == 'A' && BateauA != 0) BateauA--;
    if (tableBateaux[axeY][axeX] == 'B' && BateauB != 0) BateauB--;
    if (tableBateaux[axeY][axeX] == 'C' && BateauC != 0) BateauC--;
    if (tableBateaux[axeY][axeX] == 'D' && BateauD != 0) BateauD--;
    if (tableBateaux[axeY][axeX] == 'E' && BateauE != 0) BateauE--;
}

void toucher() {
    if (touche == 1 && tableencour[axeY][axeX] != 2) {
        if (BateauA == 0 && tableBateaux[axeY][axeX] == 'A' || BateauB == 0 && tableBateaux[axeY][axeX] == 'B' ||
            BateauC == 0 && tableBateaux[axeY][axeX] == 'C' || BateauD == 0 && tableBateaux[axeY][axeX] == 'D' ||
            BateauE == 0 && tableBateaux[axeY][axeX] == 'E' && tableencour[axeY][axeX] == 1) {
            healthShip();
            tableencour[axeY][axeX] = 2;
            printf("\tCouler  !!\n");
            ToucheMax++;
        } else {
            tableencour[axeY][axeX] = 2;
            printf("\tTouché !!\n");
            ToucheMax++;
        }
    } else if (rate_ == 1 && tableencour[axeY][axeX] != 2) {
        printf("\tPlouf !!\n");
        tableencour[axeY][axeX] = 2;
    } else if (tableencour[axeY][axeX] == 2) {
        printf("\ttu as déjà tiré sur cette case !!\n");
    }
}

void Fin() {//affiche le pseudo de la personne qui gagner et en combien de fois elle a tire pour finir
    printf("\n\t╔═════════════════════════════════════════════════╗");
    printf("\n\t   BRAVO %s tu as gagner en %d tires !!", Pseudo, NbTire);//affiche combien de fois tu a tire pour finir
    printf("\n\t╚═════════════════════════════════════════════════╝\n\t   ");
    system("pause");
    evenement = 3;
    logs();
    enreg_scores();
}

void rules() {//affiche les regle du jeu
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

void
date_heure() {//sa vas chercher le jour, le mois, l'année, l'heure, la minute et la seconde actuelle et vas l'afficher
    SYSTEMTIME t;
    GetLocalTime(&t);
    printf("\n %d.%d.%d  %d:%d:%d \n\n ", t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute, t.wSecond);
    system("pause");
}

void changer_couleur() {
    do {
        system("cls");
        printf("   ____               _                             \n"
               "  / ___| ___   _   _ | |  ___  _   _  _ __  ___   _ \n"
               " | |    / _ \\ | | | || | / _ \\| | | || '__|/ __| (_)\n"
               " | |___| (_) || |_| || ||  __/| |_| || |   \\__ \\  _ \n"
               "  \\____|\\___/  \\__,_||_| \\___| \\__,_||_|   |___/ (_)\n\n\n");
        printf(" [1] Par défaut (blanc)\n");
        printf(" [2] Rouge\n");
        printf(" [3] Bleu\n");
        printf(" [4] Vert\n");
        printf(" [5] Rose\n");
        printf(" [6] Violet\n");
        printf(" [7] Jaune\n");
        printf(" [8] Turquoise\n");
        printf(" [9] Retour\n  ");
        scanf("%d", &choix_couleur);
        couleur_actuelle();
    } while (choix_couleur != 9);
}

void options() {
    do {
        system("cls");
        choix_option = 0;
        printf("                _    _               \n"
               "   ___   _ __  | |_ (_)  ___   _ __  \n"
               "  / _ \\ | '_ \\ | __|| | / _ \\ | '_ \\ \n"
               " | (_) || |_) || |_ | || (_) || | | |\n"
               "  \\___/ | .__/  \\__||_| \\___/ |_| |_|\n"
               "        |_|                          ");
        printf("\n\n [1]  Afficher la date et l'heure\n\n");
        printf(" [2]  Changer la couleur du texte\n\n");
        printf(" [3]  Retour\n\n\t\t");
        scanf("%d", &choix_option);
        switch (choix_option) {
            case 1:
                date_heure();
                choix_option = 0;
                break;
            case 2:
                changer_couleur();
                choix_option = 0;
                break;
            default:
                if (choix_option != 3) {
                    printf("\n\t\t");
                    printf("UNKNOW VALUE!!");
                    printf("\n\t\t");
                    fflush(stdin);
                    system("pause");
                }
                break;
        }
    } while (choix_option != 3);
}

int play() {//demande les coordonee et affiche si on a touche ou rater un bateau
    clearGrid();
    definir_grille();
    evenement = 2;
    logs();
    do {
        drawGrid();
        healthShip();
        toucher();
        if (ToucheMax != 17) {//--> si pas toute les case avec un bateau on ete touche
            retourMenu();
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
    } while (ToucheMax != 17);
    Fin();
}

int goToMenu() {//affiche le menu
    SYSTEMTIME t;
    GetLocalTime(&t);
    couleur_grille = 0;
    do {
        system("cls");
        printf("\n                                                                             ____         _          _  _ _        _   _                  _"
               "\n                                                                            | __ )   __ _| |_   __ _(_)| | | ___  | \\ | | __ ___   ____ _| | ___"
               "\n                                                                            |  _ \\  / _` | __| / _` | || | |/ _ \\ |  \\| |/ _` \\ \\ / / _` | |/ _ \\ "
               "\n                                                                            | |_) || (_| | |_ | (_| | || | |  __/ | |\\  | (_| |\\ V / (_| | |  __/"
               "\n                                                                            |____/  \\__,_|\\__| \\__,_|_||_|_|\\___| |_| \\_|\\__,_| \\_/ \\__,_|_|\\___|\n");
        printf("                                                                                                          by moi\n\n\n");
        printf("                                                                                                    MENU PRINCIPAL\n\n");
        printf("\n                                                                                                      Jouer   [1]\n");
        printf("\n                                                                                                      Scores  [2]\n");
        printf("\n                                                                                                      Règles  [3]\n");
        printf("\n                                                                                                      Options [4]\n");
        printf("\n                                                                                                      Quitter [5]\n");
        if (partie_en_cour == 1)
            printf("\n                                                                                                      Rejouer [6]\n");
        printf("\n\t\t\t\t\t\t\t\tIndiquez votre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1 :
                enreg_pseudo();
                play();
                choix = 0;
                break;
            case 2 :
                affi_scores();
                choix = 0;
                break;
            case 3 :
                rules();
                choix = 0;
                break;
            case 4 :
                options();
                choix = 0;
                break;
            default:
                if (choix == 6) {
                    if (partie_en_cour == 1) {}
                    else {
                        printf("              _         _   \n"
                               "  ___   __ _ | | _   _ | |_ \n"
                               " / __| / _` || || | | || __|\n"
                               " \\__ \\| (_| || || |_| || |_ \n"
                               " |___/ \\__,_||_| \\__,_| \\__|\n");
                        system("pause");
                    }
                } else if (choix != 5) {
                    printf("\n\t\t");
                    printf("UNKNOW VALUE!!");
                    printf("\n\t\t");
                    fflush(stdin);
                    system("pause");
                }
        }
    } while (choix != 5);
    printf("\n\n\n\t\t\tVeut tu vraiment quitter ? 1->NON / 2->OUI");
    scanf("%d", &exit_);
    if (exit_ == 2) {
        goToMenu();
    } else if (exit_ == 1) {
        evenement = 4;
        logs();
        system("exit");
    }
}

void retourMenu() {// Définition de la fonction (code) elle sert a quitter une partie en cour
    char k;
    k = getch();
    if (k == 27) {
        printf("Veux tu vraiment retourner au menu? \nla Partie sera sauvegarder! \n1->Oui /2->Non");
        scanf("%d", &choix_quitter);
        if (choix_quitter == 1) goToMenu(), partie_en_cour = 1;
    }
}

void fullscreen() {//Cela met la fenetre en plein ecran
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

int main() {
    fullscreen();
    evenement = 1;
    SetConsoleOutputCP(65001);//cela sert a afficher les caractere speciaux(les accents,...)
    logs();
    color(15, 0);//on met la couleur du texte en blanc
    goToMenu();
    return 0;
}

