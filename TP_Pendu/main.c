#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 100
void Saisie_Mot(char Mot[],char MotTrouve[]);
void Vie_Joueur(int vie);
int Verification_lettre (char Mot[], char Lettre[],char MotTrouve[], int *vie);



int main ()
{
    int rejouer = 1;
    while(rejouer == 1)
    {
        char Mot[TAILLE];
        char MotTrouve[TAILLE];
        char Lettre;
        int vie = 10, i = 0;
        int estPareil = 0, aTrouverUneLettre = 0;

        Saisie_Mot(Mot,MotTrouve);


        while(estPareil != 1 && vie != 0)
        {
             fflush(stdin);
             printf(" nombre de vie %d\n",vie);
             printf("Avancement du mot:\n%s", MotTrouve);

             printf("Entrer une lettre: ");
             scanf("%c", &Lettre);

            aTrouverUneLettre = Verification_lettre (Mot,Lettre,MotTrouve,&vie);// Recherche des lettres


             i = 0;
             while(i < strlen(Mot) && MotTrouve[i] == Mot[i])
                i++;

             if(i == strlen(Mot))
                estPareil = 1;
             else
                estPareil = 0;



        }

        Vie_Joueur(vie);

        printf("Tu veux rejouer? (Oui = 1;Non = 0)");
        scanf("%i", &rejouer);
    }


    system("pause");
    return 0;
}

void Saisie_Mot ( char Mot[],char  MotTrouve[]){

    int i = 0;

        do{
            printf("Entrer votre mot: ");// saisie du MOT
            scanf("%s",Mot);
            printf("le mot fait %i lettre\n", strlen(Mot));
        }while (strlen(Mot) > TAILLE || strlen(Mot) < 3);

        for(i=0;i<strlen(Mot);i++) // remplie le mot de -
            MotTrouve[i] = '-';


            MotTrouve[i]='\0';

}

void Vie_Joueur(int vie){

     if(vie != 0)// condition de victoire defaite
        {
            printf("Bien jouer, ta gagner allez a+\n");
        }
        else
        {
            printf("Ca te dirais d'ouvrir un dico ?\n");
        }





}

int Verification_lettre (char Mot[], char Lettre[],char MotTrouve[], int *vie){

int i = 0;
int aTrouverUneLettre = 0;


     for(i = 0; i < strlen(Mot); i++) // verification de lettre juste
             {
                 if(Lettre == Mot[i])
                 {
                     MotTrouve[i] = Lettre;
                     printf("Une occurence %c a ete trouve!\n", Lettre);
                     aTrouverUneLettre = 1;
                 }
             }

             if(aTrouverUneLettre != 1){ // en cas de faute
                    *vie -= 1;
             }

             aTrouverUneLettre = 0;

             return aTrouverUneLettre;

}
/*

{ Algorithme Pendu
But : Creer un pendu jouable
Entree : Un mot � deviner et des lettres
Sortie : Le nombre de vie/Les lettres trouv�/Le gagne ou perdu plus rejouabilit�

CONST TAILLE = 100

var
     Lettre : charactere
     vie,cpt,i,estPareil,aTrouverUneLettre, rejouer: ENTIER
     Mot : Chaine
     MotTouver : chaine
DEBUT
TANT QUE (Rejouer = 1)
    REPETER
        ECRIRE ("Saisir votre mot")
        LIRE (Mot)
        ECRIRE ("Le mot fait,"&(longueur(Mot)),"Lettre")
    JUSQU'A (longueur(Mot) > TAILLE )OU(longueur(Mot) < 3)

    POUR i = 0 jusqu'a (longueur(Mot) FAIRE
        MotTrouver[i] <-- '-'
        i <-- i+1
    FIN POUR

    TANT QUE (estPareil <> 1) et (vie <> 0 )

             ECRIRE (" nombre de ",&vie);
             ECRIRE ("Avancement du mot: ",&MotTrouve);

             ECRIRE ("Entrer une lettre: ");
             LIRE(Lettre);
             POUR i = 0 Jusqu'a i < longueur(Mot) FAIRE

                 SI(Lettre = Mot[i]) ALORS
                     MotTrouve[i] <-- Lettre
                     ECRIRE("Une occurence",&Lettre," a ete trouve!")
                     aTrouverUneLettre <-- 1
                     i <-- i +1
                 FINSI
            FINPOUR

                 SI (aTrouverUneLettre <> 1) ALORS
                    vie <-- vie - 1
                SINON
                    aTrouverUneLettre <-- 0


                i <-- 0
             TANT QUE (i < Longueur(Mot))ET (MotTrouve[i] = Mot[i])
                i <-- i+1;
                 SI (i = Longueur(Mot)) ALORS
                    estPareil <-- 1
                SINON
                    estPareil <-- 0
    FIN TANT QUE
    SI(vie <> 0)

            ECRIRE("Bien jouer, ta gagner allez a+");

       SINON

            ECRIRE("Ca te dirais d'ouvrir un dico ?");


    ECRIRE("Tu veux rejouer? (Oui = 1;Non = 0)");
    LIRE(rejouer);
FIN TANT QUE
FIN







*/

