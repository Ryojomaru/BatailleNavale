#include <stdio.h>
#include <stdlib.h>
#define TAILLE_TABLEAU 20
#define NOMBRE_TABLEAU 3
#define JOUEUR_1 1
#define JOUEUR_2 2
#define CORVETTE 1
#define DESTROYER 3
#define CROISEUR 4
#define PORTE_AVION 6
#define INFOS 3

void PlacementBateauxJoueur(int tableau[TAILLE_TABLEAU][TAILLE_TABLEAU][NOMBRE_TABLEAU],int joueur){
    PlacementCorvette(tableau,joueur);
    PlacementDestroyer(tableau,joueur);
    PlacementCroiseur(tableau,joueur);
    PlacementPorteAvion(tableau,joueur);
}

void PlacementCorvette(int tableau[TAILLE_TABLEAU][TAILLE_TABLEAU][NOMBRE_TABLEAU],int joueur){
    int x,y;
    int buffer = 0;
    printf("Ou voulez-vous placer votre Corvette Capitaine ? : \n");
    while(buffer != 1){
    printf("Placement de la corvette en X : \n");
    scanf("%d",&x);
    fflush(stdin);
    printf("Placement de la corvette en Y : \n");
    scanf("%d",&y);
    fflush(stdin);
    if(tableau[x][y][joueur] != 9 || x<0 || x>20 || y<0 || y>20){
        printf("Désolé votre placement est invalide Capitaine \n");
    }else{
        tableau[x][y][joueur] = 8;
        tableau[x][y][INFOS] = 1;
        printf("Placement effectue Capitaine ! \n");
        AfficherTableau(tableau,joueur);
        buffer += 1;
        }
    }
}

void PlacementDestroyer(int tableau[TAILLE_TABLEAU][TAILLE_TABLEAU][NOMBRE_TABLEAU],int joueur){
    int i,j,x,y,choix;
    int buffer = 0;
    printf("Comment voulez-vous placer vos Destroyer Capitaine ? : \n");
    for (i=0;i<2;i++){
        printf("1 : Horizontalement \n");
        printf("2 : Verticalement \n");
        scanf("%d",&choix);
        fflush(stdin);
        buffer = 0;
        switch(choix){
            case 1:
                while(buffer != 1){
                printf("Placement du Destroyer en X : \n");
                scanf("%d",&x);
                fflush(stdin);
                printf("Placement du Destroyer en Y : \n");
                scanf("%d",&y);
                fflush(stdin);
                if(tableau[x][y][joueur] != 9 || tableau[x+3][y][joueur] != 9 || x<0 || x>20 || y<0 || y>20){
                    printf("Desole votre placement est invalide Capitaine \n");
                }else{
                    for (j=0;j<3;j++){
                        tableau[x+j][y][joueur] = 8;
                        tableau[x+j][y][INFOS] = 2;
                        }
                    printf("Placement effectue Capitaine ! \n");
                    buffer += 1;
                    }
                }
                AfficherTableau(tableau,joueur);
                break;
            case 2:
                while(buffer != 1){
                printf("Placement du Destroyer en X : \n");
                scanf("%d",&x);
                fflush(stdin);
                printf("Placement du Destroyer en Y : \n");
                scanf("%d",&y);
                fflush(stdin);
                if(tableau[x][y][joueur] != 9 || tableau[x][y+3][joueur] != 9){
                    printf("Désolé votre placement est invalide Capitaine \n");
                }else{
                    for (j=0;j<3;j++){
                        tableau[x][y+j][joueur] = 8;
                        tableau[x][y+j][INFOS] = 2;
                        }
                    printf("Placement effectue Capitaine ! \n");
                    buffer += 1;
                    }
                }
                AfficherTableau(tableau,joueur);
                break;
        }
    }
}

void PlacementCroiseur(int tableau[TAILLE_TABLEAU][TAILLE_TABLEAU][NOMBRE_TABLEAU],int joueur){
    int i,j,x,y,choix;
    int buffer = 0;
    printf("Comment voulez-vous placer vos Croiseur Capitaine ? : \n");
    for (i=0;i<2;i++){
        printf("1 : Horizontalement \n");
        printf("2 : Verticalement \n");
        scanf("%d",&choix);
        fflush(stdin);
        buffer = 0;
        switch(choix){
            case 1:
                while(buffer != 1){
                printf("Placement du Croiseur en X : \n");
                scanf("%d",&x);
                fflush(stdin);
                printf("Placement du Croiseur en Y : \n");
                scanf("%d",&y);
                fflush(stdin);
                if(tableau[x][y][joueur] != 9 || tableau[x+4][y][joueur] != 9){
                    printf("Desole votre placement est invalide Capitaine \n");
                }else{
                    for (j=0;j<4;j++){
                        tableau[x+j][y][joueur] = 8;
                        tableau[x+j][y][INFOS] = 3;
                        }
                    printf("Placement effectue Capitaine ! \n");
                    buffer += 1;
                    }
                }
                AfficherTableau(tableau,joueur);
                break;
            case 2:
                while(buffer != 1){
                printf("Placement du Destroyer en X : \n");
                scanf("%d",&x);
                fflush(stdin);
                printf("Placement du Destroyer en Y : \n");
                scanf("%d",&y);
                fflush(stdin);
                if(tableau[x][y][joueur] != 9 || tableau[x][y+4][joueur] != 9){
                    printf("Désolé votre placement est invalide Capitaine \n");
                }else{
                    for (j=0;j<4;j++){
                        tableau[x][y+j][joueur] = 8;
                        tableau[x][y+j][INFOS] = 3;
                        }
                    printf("Placement effectue Capitaine ! \n");
                    buffer += 1;
                    }
                }
                AfficherTableau(tableau,joueur);
                break;
        }
    }
}

void PlacementPorteAvion(int tableau[TAILLE_TABLEAU][TAILLE_TABLEAU][NOMBRE_TABLEAU],int joueur){
    int i,j,x,y,choix;
    int buffer = 0;
    printf("Comment voulez-vous placer vos Destroyer Capitaine ? : \n");
    printf("1 : Horizontalement \n");
    printf("2 : Verticalement \n");
    scanf("%d",&choix);
    fflush(stdin);
    buffer = 0;
    switch(choix){
        case 1:
            while(buffer != 1){
            printf("Placement du Destroyer en X : \n");
            scanf("%d",&x);
            fflush(stdin);
            printf("Placement du Destroyer en Y : \n");
            scanf("%d",&y);
            fflush(stdin);
            if(tableau[x][y][joueur] != 9 || tableau[x+6][y][joueur] != 9){
                printf("Desole votre placement est invalide Capitaine \n");
            }else{
                for (j=0;j<6;j++){
                    tableau[x+j][y][joueur] = 8;
                    tableau[x+j][y][INFOS] = 4;
                    }
                printf("Placement effectue Capitaine ! \n");
                buffer += 1;
                }
            }
            AfficherTableau(tableau,joueur);
            break;
        case 2:
            while(buffer != 1){
            printf("Placement du Destroyer en X : \n");
            scanf("%d",&x);
            fflush(stdin);
            printf("Placement du Destroyer en Y : \n");
            scanf("%d",&y);
            fflush(stdin);
            if(tableau[x][y][joueur] != 9 || tableau[x][y+6][joueur] != 9){
                printf("Désolé votre placement est invalide Capitaine \n");
            }else{
                for (j=0;j<6;j++){
                    tableau[x][y+j][joueur] = 8;
                    tableau[x][y+j][INFOS] = 4;
                    }
                printf("Placement effectue Capitaine ! \n");
                buffer += 1;
                }
            }
            AfficherTableau(tableau,joueur);
            break;
    }
}

