#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int JEU(){
    printf("d");
}
int rules() {
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
        switch (choix)
        {
            case 1 :
                JEU();
                system("pause");
            case 2 :
                printf("SCORE") ;
                system("pause");
            case 3 :
                rules();
                system("pause");
            case 4 :
                printf("OPTIONS") ;
                system("pause");
        }
    }while(choix!=5);
}
int main() {
    SetConsoleOutputCP(65001);
    menuprincipal();
    system("pause");
    return 0;
}