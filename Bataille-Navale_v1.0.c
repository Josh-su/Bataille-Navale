/*
* Auteur:      Joshua Surico
* Date :       01.01.2023
* Titre:       bataille navale
* Description: Ce programme est le jeu de la bataille navale, mais pour 1 joueur
* Version:     1.1
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define TAILLE_MAX 1000

int NbTire, x, y, axeX, axeY, ToucheMax, touche, rate_, exit_, choix, BateauA, BateauB, BateauC, BateauD, BateauE, evenement, choix_option, choix_couleur = 1, NbScoreAffiche, couleur, couleur_grille;

void play(), color(int front,int back), couleur_actuelle(), definir_grille(), logs(), goToMenu(), enreg_scores(), affi_scores(), enreg_pseudo(), clearGrid(), drawGrid(), Change(), toucher(), Fin(), rules(), date_heure(), changer_couleur(), options(), AskColumn(), AskLine(), fullscreen();//declaration des fonctions

char lettre = ' ', Pseudo[300] = "";

boolean isPseudoSet = FALSE;

char tableBateaux[10][10] = //cette table représente les bateaux sur la grille.
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
int tableEnCour[10][10] =  //cette table sert à sauvegarder les case sur les quelle, on a tiré
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
                printf("UNKNOWN VALUE!!");
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

//choisi aléatoirement une des 5 grilles
void definir_grille() {
    srand(time(NULL));
    int r;
    r = rand() % 5;
    FILE *fichier = NULL;
    switch (r) {
        case 0:
            fichier = fopen("Grilles/grille0.txt", "r");
            break;
        case 1:
            fichier = fopen("Grilles/grille1.txt", "r");
            break;
        case 2:
            fichier = fopen("Grilles/grille2.txt", "r");
            break;
        case 3:
            fichier = fopen("Grilles/grille3.txt", "r");
            break;
        case 4:
            fichier = fopen("Grilles/grille4.txt", "r");
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

//écrit les différents logs
void logs() {
    SYSTEMTIME t;
    GetLocalTime(&t);
    FILE *fichier = NULL;
    fichier = fopen("LogsScores/Logs.txt", "a");
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
        else if (evenement == 4){
            if(isPseudoSet){
                fprintf(fichier, "%s a fermer le programme le %d.%d.%d a %d:%d:%d \n", Pseudo, t.wDay, t.wMonth, t.wYear,
                        t.wHour, t.wMinute, t.wSecond);
            }else{
                fprintf(fichier, "le programme a été fermé le %d.%d.%d a %d:%d:%d \n", t.wDay, t.wMonth, t.wYear,
                        t.wHour, t.wMinute, t.wSecond);
            }
        }
        evenement = 0;
        fclose(fichier);
    }
}

//enregistre les scores
void enreg_scores() {
    FILE *fichier = NULL;
    fichier = fopen("../LogsScores/Scores.txt", "r+");
    if (fichier != NULL) {
        rewind(fichier);
        fprintf(fichier, "%s %d\n", Pseudo, NbTire);
        fclose(fichier);
    }
}

//affiche les 5 derniers scores
void affi_scores() {
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
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL).
        {
            printf("\t\t-  %s", chaine); // On affiche la chaîne qu'on vient de lire
            NbScoreAffiche++;
            if (NbScoreAffiche == 5) fclose(fichier);
        }
    }
    printf("\n\t\t");
    system("pause");
    goToMenu();
}

//enregistre le pseudo
void enreg_pseudo() {
    printf("inscrit ton pseudo : ");
    fflush(stdin);
    scanf("%s", &Pseudo);
    isPseudoSet = TRUE;
}

//réinitialiser la grille et les variables
void clearGrid() {
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++) {
            tableEnCour[x][y] = 0;
        }
    }
    axeX = -1, axeY = -1, NbTire = 0, ToucheMax = 0, BateauA = 2, BateauB = 3, BateauC = 3, BateauD = 4, BateauE = 5, couleur_grille = 0;
}

//affiche toute la grille
void drawGrid() {
    rate_ = 0;
    touche = 0;
    couleur_grille = 1;
    system("cls");
    printf("   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐\n");
    printf("   │  A  │  B  │  C  │  D  │  E  │  F  │  G  │  H  │  I  │  J  │\n");
    printf("┌──┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤\n");//affiche la 1er ligne
    for (x = 0; x < 10; x++) {
        //print les numéros à gauche
        if (x != 9) {
            printf("│%x │", x + 1);
        } else {
            printf("│10│");
        }
        for (y = 0; y < 10; y++) {
            if (axeY == x && axeX == y) {
                if (tableEnCour[x][y] != 2) tableEnCour[x][y] = 1;//sauvegarde la case touchée
                if (tableBateaux[x][y] == 'A' || tableBateaux[x][y] == 'B' || tableBateaux[x][y] == 'C' ||
                    tableBateaux[x][y] == 'D' || tableBateaux[x][y] == 'E')//on vérifie si il y a un bateau
                    touche++;// si oui un ajouté 1 à la variable 'touche' si non, on ajoute 1 à la variable 'rate_'
                else rate_++;
            }
            if (tableEnCour[x][y] == 1 || tableEnCour[x][y] == 2) {
                if (tableBateaux[x][y] == 'A' || tableBateaux[x][y] == 'B' || tableBateaux[x][y] == 'C' ||
                    tableBateaux[x][y] == 'D' ||
                    tableBateaux[x][y] == 'E') {//verifi s'il y a un bateau dans les cases ou on a deja tirer dessus
                    color(15, 4);
                    printf("  !  ");//si oui, on affiche un point d'exclamation en rouge
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
                printf("  ~  ");//si la case n'a pas ete tirer dessus, on affiche le signe environ en bleu
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

//défini la variable 'axeX' par rapport à la variable 'lettre'
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
    lettre = ' ';
}

//Gère la vie des bateaux
void healthShip() {
    if (tableBateaux[axeY][axeX] == 'A' && BateauA != 0) BateauA--;
    if (tableBateaux[axeY][axeX] == 'B' && BateauB != 0) BateauB--;
    if (tableBateaux[axeY][axeX] == 'C' && BateauC != 0) BateauC--;
    if (tableBateaux[axeY][axeX] == 'D' && BateauD != 0) BateauD--;
    if (tableBateaux[axeY][axeX] == 'E' && BateauE != 0) BateauE--;
}

//Vérifie si la case sélectionnée est touché/coulé/raté/déjàTirer
void toucher() {
    if (touche == 1 && tableEnCour[axeY][axeX] != 2) {
        if (BateauA == 0 && tableBateaux[axeY][axeX] == 'A' || BateauB == 0 && tableBateaux[axeY][axeX] == 'B' ||
            BateauC == 0 && tableBateaux[axeY][axeX] == 'C' || BateauD == 0 && tableBateaux[axeY][axeX] == 'D' ||
            BateauE == 0 && tableBateaux[axeY][axeX] == 'E' && tableEnCour[axeY][axeX] == 1) {
            healthShip();
            tableEnCour[axeY][axeX] = 2;
            printf("\tCouler  !!\n");
            ToucheMax++;
        } else {
            tableEnCour[axeY][axeX] = 2;
            printf("\tTouché !!\n");
            ToucheMax++;
        }
    } else if (rate_ == 1 && tableEnCour[axeY][axeX] != 2) {
        printf("\tPlouf !!\n");
        tableEnCour[axeY][axeX] = 2;
    } else if (tableEnCour[axeY][axeX] == 2) {
        printf("\ttu as déjà tiré sur cette case !!\n");
    }
}

//affiche le pseudo de la personne qui gagner et en combien de fois, elle a tiré pour finir
void Fin() {
    printf("\n\t╔═════════════════════════════════════════════════╗");
    printf("\n\t   BRAVO %s tu as gagner en %d tires !!", Pseudo, NbTire);//affiche combien de fois, tu as tiré pour finir
    printf("\n\t╚═════════════════════════════════════════════════╝\n\t   ");
    system("pause");
    evenement = 3;
    logs();
    enreg_scores();
    goToMenu();
}

//affiche les règles du jeu
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
    printf("       La grille est numérotée de 1 a 10 verticalement\n");
    printf("       et de A a J horizontalement. Vous allez \"tirer\"\n");
    printf("       sur une case de l'adversaire: exemple, B.3. le but est\n");
    printf("       donc de couler les bateaux adverses.\n");
    printf("       Au fur et a mesure des marqueurs serons affiche afin de se\n");
    printf("       souvenir de vos tirs passes.\n\n       ");
    system("pause");
    goToMenu();
}

//la fonction va chercher le jour, le mois, l'année, l'heure, la minute et la seconde actuelle et va l'afficher
void date_heure() {
    SYSTEMTIME t;
    GetLocalTime(&t);
    printf("\n %d.%d.%d  %d:%d:%d \n\n ", t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute, t.wSecond);
    system("pause");
}

//affiche le menu pour changer la couleur du texte
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
        printf(" [9] Retour\n\n\t\t");
        scanf("%d", &choix_couleur);
        couleur_actuelle();
    } while (choix_couleur != 9);
}

//affiche le menu des options
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
                    printf("UNKNOWN VALUE!!");
                    printf("\n\t\t");
                    fflush(stdin);
                    system("pause");
                }
                break;
        }
    } while (choix_option != 3);
    goToMenu();
}

//demande la coordonnée horizontal
void AskColumn() {
    printf("\tVeuillez choisir un colonne (A-J) : ");
    fflush(stdin);
    scanf("%c", &lettre);
    Change();
}

//demande la coordonnée vertical
void AskLine() {
    printf("\tVeuillez choisir une ligne (1-10) : ");
    fflush(stdin);
    scanf("%d", &axeY);
    axeY = axeY - 1;
}

//Demande les coordonnées et affiche si on a touché ou manqué un bateau.
void play() {
    clearGrid();
    definir_grille();
    evenement = 2;
    logs();
    do {
        drawGrid();
        healthShip();
        toucher();
        if (ToucheMax != 17) {//→ si pas tous les case avec un bateau ont été touché
            AskColumn();
            if (axeX >= 10)
                AskColumn();//vérifie que la donnée enregistrée soit bien un numéro plus petit que 10 sinon redemander
            AskLine();
            if (axeY >= 10) AskLine();
            NbTire++;
        }
    } while (ToucheMax != 17);
    Fin();
}

void goToMenu() {//affiche le menu
    SYSTEMTIME t;
    GetLocalTime(&t);
    couleur_grille = 0;
    do {
        system("cls");
        printf("\n\t\t\t\t\t\t ____         _          _  _ _        _   _                  _"
               "\n\t\t\t\t\t\t| __ )   __ _| |_   __ _(_)| | | ___  | \\ | | __ ___   ____ _| | ___"
               "\n\t\t\t\t\t\t|  _ \\  / _` | __| / _` | || | |/ _ \\ |  \\| |/ _` \\ \\ / / _` | |/ _ \\ "
               "\n\t\t\t\t\t\t| |_) || (_| | |_ | (_| | || | |  __/ | |\\  | (_| |\\ V / (_| | |  __/"
               "\n\t\t\t\t\t\t|____/  \\__,_|\\__| \\__,_|_||_|_|\\___| |_| \\_|\\__,_| \\_/ \\__,_|_|\\___|\n");
        printf("\t\t\t\t\t\t\t\t\tby moi\n\n\n");
        printf("\t\t\t\t\t\t\t\t\tMENU PRINCIPAL\n\n");
        printf("\n\t\t\t\t\t\t\t\t\tJouer   [1]\n");
        printf("\n\t\t\t\t\t\t\t\t\tScores  [2]\n");
        printf("\n\t\t\t\t\t\t\t\t\tRègles  [3]\n");
        printf("\n\t\t\t\t\t\t\t\t\tOptions [4]\n");
        printf("\n\t\t\t\t\t\t\t\t\tQuitter [5]\n");
        printf("\n\t\t\t\t\t\t\t\tIndiquez votre choix : ");
        fflush(stdin);
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
            case 5 :
                printf("\n\n\n\t\t\tVeut tu vraiment quitter ? 1->NON / 2->OUI : ");
                fflush(stdin);
                scanf("%d", &exit_);
                if (exit_ == 1) {
                    goToMenu();
                } else if (exit_ == 2) {
                    evenement = 4;
                    logs();
                    system("exit");
                }
                break;
            default:
                if (choix == 7) {
                    printf("              _         _   \n"
                           "  ___   __ _ | | _   _ | |_ \n"
                           " / __| / _` || || | | || __|\n"
                           " \\__ \\| (_| || || |_| || |_ \n"
                           " |___/ \\__,_||_| \\__,_| \\__|\n");
                    system("pause");
                } else {
                    printf("\n\t\t");
                    printf("UNKNOWN VALUE!!");
                    printf("\n\t\t");
                    fflush(stdin);
                    system("pause");
                }
        }
    } while (choix != 5);
}

//Cela met la fenêtre en plein écran
void fullscreen() {
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

int main() {
    fullscreen();
    evenement = 1;
    SetConsoleOutputCP(65001);//cela sert à afficher les caractères spéciaux(les accents,...)
    logs();
    color(15, 0);//on met la couleur du texte en blanc
    goToMenu();
    return 0;
}
