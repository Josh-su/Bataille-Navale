#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int NomUtilisateur, Tire, NbTire;
int Score(int argc, char *argv[]){
    FILE* fichier = NULL;
    fichier = fopen("Logs+Scores/Scores.txt", "w");
    if (fichier != NULL)
    {
        // On demande le pseudo
        printf("veuiller écrire votre pseudo");
        scanf("%d",&NomUtilisateur);
        // On l'écrit dans le fichier
        fprintf(fichier, "Le Monsieur qui utilise le programme alias %c a fini en %d tires",NomUtilisateur,NbTire);
        fclose(fichier);
    }
    return 0;
}
int Scores()
{
    system("cls");
    FILE* fichier = NULL;
    int score[100] = {0}; // Tableau des 100 derniers scores
    fichier = fopen("C:\\SandBox\\Bataille-Navale\\Logs+Scores/Scores.txt", "r");
    if (fichier != NULL)
    {
        printf("Les scores sont :");
        for (int x = 0; x < 100; ++x) {
            fseek(fichier, 0, SEEK_END);
            fscanf(fichier, "%d", &score[x]);
            printf("\n- %d",score[x]);
        }
        fclose(fichier);
    }else{
        printf("erreur");
    }
    return 0;
}
char axeX, axeY;
int coordone=1;
int JEU(){
    system("cls");
    //(grilles/grille0.txt)
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
int RULES() {
    system("cls");
    printf("REGLE\n");
    printf("Votre flotte a 5 bateaux qui sont les suivant:\n");
    printf("-1 porte-avion(5 cases)\n");
    printf("-1 croiseur(4 cases)\n");
    printf("-1 contre-torpilleur(3 cases)\n");
    printf("-1 sous-marin(3 cases)\n");
    printf("-1 torpilleur (2 cases)\n");
    printf("Les bateaux ne sont pas colles entre eux.\n");
    printf("La grille est numerotee de 1 a 10 verticalement\n");
    printf("et de A a J horizontalement. Vous allez \"tirer\"\n");
    printf("sur une case de l'adversaire: exemple, B.3. le but est\n");
    printf("donc de couler les bateaux adverses.\n");
    printf("Au fur et a mesure des marqueurs serons affiche afin de se\n");
    printf("souvenir de vos tirs passes.\n");
    system("pause");
    return(0);
}
int choix;
void menuprincipal(void){
    do {
        system("cls");
        printf("\n                                                                                          ____        _        _ _ _        _   _                  _ "
               "\n                                                                                         | __ )  __ _| |_ __ _(_) | | ___  | \\ | | __ ___   ____ _| |"
               "\n                                                                                         |  _ \\ / _` | __/ _` | | | |/ _ \\ |  \\| |/ _` \\ \\ / / _` | |"
               "\n                                                                                         | |_) | (_| | || (_| | | | |  __/ | |\\  | (_| |\\ V / (_| | |"
               "\n                                                                                         |____/ \\__,_|\\__\\__,_|_|_|_|\\___| |_| \\_|\\__,_| \\_/ \\__,_|_|"
               "\n"
               "\n"
               "\n"
               "\n"
               "\n                                                                                      __  __                    ____       _            _             _"
               "\n                                                                                     |  \\/  | ___ _ __  _   _  |  _ \\ _ __(_)_ __   ___(_)_ __   __ _| |"
               "\n                                                                                     | |\\/| |/ _ \\ '_ \\| | | | | |_) | '__| | '_ \\ / __| | '_ \\ / _` | |"
               "\n                                                                                     | |  | |  __/ | | | |_| | |  __/| |  | | | | | (__| | |_) | (_| | |"
               "\n                                                                                     |_|  |_|\\___|_| |_|\\__,_| |_|   |_|  |_|_| |_|\\___|_| .__/ \\__,_|_|"
               "\n                                                                                                                                         |_|            "
               "\n"
               "\n                                                                                                   _               _                       "
               "\n                                                                                                  / |             | | ___  _   _  ___ _ __ "
               "\n                                                                                                  | |  _____   _  | |/ _ \\| | | |/ _ \\ '__|"
               "\n                                                                                                  | | |_____| | |_| | (_) | |_| |  __/ |   "
               "\n                                                                                                  |_|          \\___/ \\___/ \\__,_|\\___|_|"
               "\n                                                                                                ____            ____                          "
               "\n                                                                                               |___ \\          / ___|  ___ ___  _ __ ___  ___ "
               "\n                                                                                                 __) |  _____  \\___ \\ / __/ _ \\| '__/ _ \\/ __|"
               "\n                                                                                                / __/  |_____|  ___) | (_| (_) | | |  __/\\__ \\"
               "\n                                                                                               |_____|         |____/ \\___\\___/|_|  \\___||___/"
               "\n                                                                                                 _____           ____            _           "
               "\n                                                                                                |___ /          |  _ \\ ___  __ _| | ___  ___ "
               "\n                                                                                                  |_ \\   _____  | |_) / _ \\/ _` | |/ _ \\/ __|"
               "\n                                                                                                 ___) | |_____| |  _ <  __/ (_| | |  __/\\__ \\"
               "\n                                                                                                |____/          |_| \\_\\___|\\__, |_|\\___||___/"
               "\n                                                                                                                            |___/             "
               "\n                                                                                             _  _              ___        _   _                 "
               "\n                                                                                            | || |            / _ \\ _ __ | |_(_) ___  _ __  ___ "
               "\n                                                                                            | || |_   _____  | | | | '_ \\| __| |/ _ \\| '_ \\/ __|"
               "\n                                                                                            |__   _| |_____| | |_| | |_) | |_| | (_) | | | \\__ \\"
               "\n                                                                                               |_|            \\___/| .__/ \\__|_|\\___/|_| |_|___/"
               "\n                                                                                                                    |_|                          "
               "\n                                                                                                ____             ___        _ _   _            "
               "\n                                                                                               | ___|           / _ \\ _   _(_) |_| |_ ___ _ __ "
               "\n                                                                                               |___ \\   _____  | | | | | | | | __| __/ _ \\ '__|"
               "\n                                                                                                ___) | |_____| | |_| | |_| | | |_| ||  __/ |   "
               "\n                                                                                               |____/           \\__\\_\\\\__,_|_|\\__|\\__\\___|_|");
        printf("\n\t\t Indiquez votre choix : ") ;
        scanf("%d",&choix);
        switch(choix)
        {
            case 1 :
                JEU();
                choix=0;
            break;
            case 2 :
                Scores();
                choix=0;
            break;
            case 3 :
                RULES();
                choix=0;
                break;
            case 4 :
                printf("OPTIONS") ;
                choix=0;
                break;
            case 5 :
                choix=0;
                break;
            default:break;
        }
    } while ((choix != '1') && (choix != '2') && (choix != '3') && (choix != '4') && (choix != '5')) ;
    system("pause");
}
int main() {
    SetConsoleOutputCP(65001);
    //Scores();
    menuprincipal();
    //JEU();
    system("pause");
    return 0;
}