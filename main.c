#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "placement.h"



void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);
}

int Random(int startVal, int endVal){
    waitFor(0.05);
    srand(time(NULL)*rand());
    if(startVal == 0 && endVal == 1){
        return rand() % 2;
    }else{
        return (rand() % ((endVal + startVal -1)) + startVal);
    }
}

void color(int t,int f){
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}

void BatailleNavale(){

}

void Options(){
}

void SauvegardeJeu(int tableau[TAILLE_TABLEAU][TAILLE_TABLEAU][NOMBRE_TABLEAU]){
    FILE * Sauvegarde;
    Sauvegarde = fopen("./Sauvegarde.txt","w+");
    int i,j,k;
    for (i=0;i<TAILLE_TABLEAU;i++){
        for (j=0;j<TAILLE_TABLEAU;j++){
            for (k=0;k<NOMBRE_TABLEAU;k++){
                fprintf(Sauvegarde,"%c",(char)tableau[i][j][k]);
            }
        }
    }
    fclose(Sauvegarde);
}

void ChargementJeu(int tableau[TAILLE_TABLEAU][TAILLE_TABLEAU][NOMBRE_TABLEAU]){
    FILE* Sauvegarde;
    int i,j,k;
    char x;
    for (i=0;i<TAILLE_TABLEAU;i++){
        for (j=0;j<TAILLE_TABLEAU;j++){
            for (k=0;k<TAILLE_TABLEAU;k++){
                x = fgetc(Sauvegarde);
                if( feof(Sauvegarde) )
                {
                    break;
                }
                tableau[i][j][k]=(int)x;
            }
        }
    }
}

void InitialisationTableau(int tableau[TAILLE_TABLEAU][TAILLE_TABLEAU][NOMBRE_TABLEAU]){
    int i,j;
    for (i=0;i<TAILLE_TABLEAU;i++){
        for (j=0;j<TAILLE_TABLEAU;j++){
            tableau[i][j][JOUEUR_1] = 9;
            tableau[i][j][JOUEUR_2] = 9;
            tableau[i][j][INFOS] = 0;
        }
    }
}

void AfficherTableau(int tableau[TAILLE_TABLEAU][TAILLE_TABLEAU][NOMBRE_TABLEAU],int joueur){
    int i,j;
    for(i = 0;i < TAILLE_TABLEAU; i++){
        for(j = 0;j < TAILLE_TABLEAU; j++){
                if(tableau[i][j][joueur] == 9){
                    color(9,9);
                    printf("%d ",tableau[i][j][joueur]);
                    color(15,0);
                }else if(tableau[i][j][joueur] == 8){
                    color(10,10);
                    printf("%d ",tableau[i][j][joueur]);
                    color(15,0);
                }else if(tableau[i][j][INFOS] == 1){
                    color(9,9);
                    printf("%d ",tableau[i][j][joueur]);
                    color(15,0);
                }else if(tableau[i][j][INFOS] == 2){
                    color(14,14);
                    printf("%d ",tableau[i][j][joueur]);
                    color(15,0);
                }else if(tableau[i][j][INFOS] == 3){
                    color(12,12);
                    printf("%d ",tableau[i][j][joueur]);
                    color(15,0);
                }
        }
        printf("\n");
    }
    color(15,0);
}

/*void PlacementBateauxJoueur(int tableau[TAILLE_TABLEAU][TAILLE_TABLEAU][NOMBRE_TABLEAU],int joueur){
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
}*/

void Jeu(int tableau[TAILLE_TABLEAU][TAILLE_TABLEAU][NOMBRE_TABLEAU],int joueur){

    int x,y,buffer;
    printf("Nos ennemis sont devant nous, ou voulez-vous tirer Capitaine ? \n");
    do{
    printf("Position en X : \n");
    scanf("%d",&x);
    fflush(stdin);
    if(x<0 || x>20){
        printf("Capitaine, cette position n'est pas bonne, la mer est de l'autre côté !\n");
    }
    }while(x<0 || x>20);
    do{
    printf("Position en Y : \n");
    scanf("%d",&y);
    fflush(stdin);
    if(y<0 || y>20){
        printf("Capitaine, c'est nous que vous visez là ! Changer vos coordonées !\n");
    }
    }while(y<0 || y>20);
   /* while(buffer=!1){
        if(tableau[x][y][joueur])
    }*/
}
int main() {
    int i,j;
    int tableau[TAILLE_TABLEAU][TAILLE_TABLEAU][NOMBRE_TABLEAU];
    InitialisationTableau(tableau);
    AfficherTableau(tableau,JOUEUR_1);
    PlacementBateauxJoueur(tableau,JOUEUR_1);
}
