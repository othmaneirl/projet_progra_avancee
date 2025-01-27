#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jeton.h"
#include "analyseur_syntaxique.h"

void generation_tab1(typejeton T[]){
    //tableau au genere:"(-5)*x+cos(3/x)"
    int i=0;
    T[i].lexem=PAR_OUV;
    i++;
    T[i].lexem=FONCTION;
    T[i].valeur.fonction=VAL_NEG;
    i++;
    T[i].lexem=REEL;
    T[i].valeur.reel=5;
    i++;
    T[i].lexem=PAR_FERM;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=FOIS;
    i++;
    T[i].lexem=VARIABLE;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=PLUS;
    i++;
    T[i].lexem=FONCTION;
    T[i].valeur.fonction=COS;
    i++;
    T[i].lexem=PAR_OUV;
    i++;
    T[i].lexem=REEL;
    T[i].valeur.reel=3;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=DIV;
    i++;
    T[i].lexem=VARIABLE;
    i++;
    T[i].lexem=PAR_FERM;
    i++;
    T[i].lexem=FIN;
}

Arbre generation_arbre1(){
    typejeton jetonplus;
    jetonplus.lexem=OPERATEUR;
    jetonplus.valeur.operateur=PLUS;

    typejeton jetonfois;
    jetonfois.lexem=OPERATEUR;
    jetonfois.valeur.operateur=FOIS;

    typejeton jetondiv;
    jetondiv.lexem=OPERATEUR;
    jetondiv.valeur.operateur=DIV;

    typejeton jetonvar;
    jetonvar.lexem=VARIABLE;

    typejeton jetonvalneg;
    jetonvalneg.lexem=FONCTION;
    jetonvalneg.valeur.fonction=VAL_NEG;

    typejeton jetoncinq;
    jetoncinq.lexem=REEL;
    jetoncinq.valeur.reel=5;

    typejeton jetontrois;
    jetontrois.lexem=REEL;
    jetontrois.valeur.reel=3;

    typejeton jetoncos;
    jetoncos.lexem=FONCTION;
    jetoncos.valeur.fonction=COS;

    Arbre A= creer_noeud(
        jetonplus,
        creer_noeud(
            jetonfois,
            creer_noeud(
                jetonvalneg,NULL,
                creer_noeud(
                    jetoncinq,NULL,NULL
                )
            
            ),
            creer_noeud(
                jetonvar, NULL , NULL
            )
        ),
        creer_noeud(
            jetoncos,NULL,
            creer_noeud(
                jetondiv,
                creer_noeud(
                    jetontrois, NULL, NULL
                ),
                creer_noeud(
                    jetonvar, NULL, NULL
                )
            )
        )
    );
    return A;
}

void generation_tab2(typejeton T[]){
    //tableau au genere:"|-5|*x+cos(3/x)"
    int i=0;
    T[i].lexem=BAR;
    i++;
    T[i].lexem=FONCTION;
    T[i].valeur.fonction=VAL_NEG;
    i++;
    T[i].lexem=REEL;
    T[i].valeur.reel=5;
    i++;
    T[i].lexem=BAR;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=FOIS;
    i++;
    T[i].lexem=VARIABLE;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=PLUS;
    i++;
    T[i].lexem=FONCTION;
    T[i].valeur.fonction=COS;
    i++;
    T[i].lexem=PAR_OUV;
    i++;
    T[i].lexem=REEL;
    T[i].valeur.reel=3;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=DIV;
    i++;
    T[i].lexem=VARIABLE;
    i++;
    T[i].lexem=PAR_FERM;
    i++;
    T[i].lexem=FIN;
}

Arbre generation_arbre2(){
    typejeton jetonplus;
    jetonplus.lexem=OPERATEUR;
    jetonplus.valeur.operateur=PLUS;

    typejeton jetonfois;
    jetonfois.lexem=OPERATEUR;
    jetonfois.valeur.operateur=FOIS;

    typejeton jetondiv;
    jetondiv.lexem=OPERATEUR;
    jetondiv.valeur.operateur=DIV;

    typejeton jetonvar;
    jetonvar.lexem=VARIABLE;

    typejeton jetonvalneg;
    jetonvalneg.lexem=FONCTION;
    jetonvalneg.valeur.fonction=VAL_NEG;

    typejeton jetonabs;
    jetonabs.lexem=FONCTION;
    jetonabs.valeur.fonction=ABS;

    typejeton jetoncinq;
    jetoncinq.lexem=REEL;
    jetoncinq.valeur.reel=5;

    typejeton jetontrois;
    jetontrois.lexem=REEL;
    jetontrois.valeur.reel=3;

    typejeton jetoncos;
    jetoncos.lexem=FONCTION;
    jetoncos.valeur.fonction=COS;

    Arbre A= creer_noeud(
        jetonplus,
        creer_noeud(
            jetonfois,
            creer_noeud(
                jetonabs,NULL,
                creer_noeud(
                    jetonvalneg,NULL,
                    creer_noeud(
                        jetoncinq,NULL,NULL
                    )
                )
            ),
            creer_noeud(
                jetonvar, NULL , NULL
            )
        ),
        creer_noeud(
            jetoncos,NULL,
            creer_noeud(
                jetondiv,
                creer_noeud(
                    jetontrois, NULL, NULL
                ),
                creer_noeud(
                    jetonvar, NULL, NULL
                )
            )
        )
    );
    return A;
}

void generation_tab3(typejeton T[]){
    //tableau au genere:"(-2*|5|)+|-tan(3*x)|"
    int i=0;
    T[i].lexem=PAR_OUV;
    i++;
    T[i].lexem=FONCTION;
    T[i].valeur.fonction=VAL_NEG;
    i++;
    T[i].lexem=REEL;
    T[i].valeur.reel=2;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=FOIS;
    i++;
    T[i].lexem=BAR;
    i++;
    T[i].lexem=REEL;
    T[i].valeur.reel=5;
    i++;
    T[i].lexem=BAR;
    i++;
    T[i].lexem=PAR_FERM;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=PLUS;
    i++;
    T[i].lexem=BAR;
    i++;
    T[i].lexem=FONCTION;
    T[i].valeur.fonction=VAL_NEG;
    i++;
    T[i].lexem=FONCTION;
    T[i].valeur.fonction=TAN;
    i++;
    T[i].lexem=PAR_OUV;
    i++;
    T[i].lexem=REEL;
    T[i].valeur.reel=3;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=FOIS;
    i++;
    T[i].lexem=VARIABLE;
    i++;
    T[i].lexem=PAR_FERM;
    i++;
    T[i].lexem=BAR;
    i++;
    T[i].lexem=FIN;
}

Arbre generation_arbre3(){
    typejeton jetonplus;
    jetonplus.lexem=OPERATEUR;
    jetonplus.valeur.operateur=PLUS;

    typejeton jetonfois;
    jetonfois.lexem=OPERATEUR;
    jetonfois.valeur.operateur=FOIS;

    typejeton jetonvar;
    jetonvar.lexem=VARIABLE;

    typejeton jetonvalneg;
    jetonvalneg.lexem=FONCTION;
    jetonvalneg.valeur.fonction=VAL_NEG;

    typejeton jetonabs;
    jetonabs.lexem=FONCTION;
    jetonabs.valeur.fonction=ABS;

    typejeton jetoncinq;
    jetoncinq.lexem=REEL;
    jetoncinq.valeur.reel=5;

    typejeton jetondeux;
    jetondeux.lexem=REEL;
    jetondeux.valeur.reel=2;

    typejeton jetontrois;
    jetontrois.lexem=REEL;
    jetontrois.valeur.reel=3;

    typejeton jetontan;
    jetontan.lexem=FONCTION;
    jetontan.valeur.fonction=TAN;

    Arbre A= creer_noeud(
        jetonplus,
            creer_noeud(
                jetonfois,
                creer_noeud(
                    jetonvalneg,NULL,
                    creer_noeud(
                        jetondeux,NULL,NULL
                    )
                ),
                creer_noeud(
                    jetonabs,NULL,
                    creer_noeud(
                        jetoncinq,NULL,NULL
                    )
                )
            ),
        creer_noeud(
            jetonabs,NULL,
            creer_noeud(
                jetonvalneg,NULL,
                creer_noeud(
                    jetontan,NULL,
                    creer_noeud(
                        jetonfois,
                        creer_noeud(
                            jetontrois,NULL,NULL
                        ),creer_noeud(
                            jetonvar,NULL,NULL
                        )
                    )
                )
            )
        )
    );
    return A;
}

void generation_tab4(typejeton T[]){
    //tableau au genere:"x^2"
    int i=0;
    T[i].lexem=VARIABLE;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=PUIS;
    i++;
    T[i].lexem=REEL;
    T[i].valeur.reel=2;
    i++;
    T[i].lexem=FIN;
}

Arbre generation_arbre4(){
    typejeton jetondeux;
    jetondeux.lexem=REEL;
    jetondeux.valeur.reel=2;

    typejeton jetonpuis;
    jetonpuis.lexem=OPERATEUR;
    jetonpuis.valeur.operateur=PUIS;

    typejeton jetonvar;
    jetonvar.lexem=VARIABLE;

    Arbre A= creer_noeud(
        jetonpuis,
        creer_noeud(
            jetonvar,NULL,NULL
        ),
        creer_noeud(
            jetondeux,NULL,NULL
        )
    );
    return A;
}

void generation_tab5(typejeton T[]){
    //tableau au genere:"|-5|*x+cos(3/x"
    int i=0;
    T[i].lexem=BAR;
    i++;
    T[i].lexem=FONCTION;
    T[i].valeur.fonction=VAL_NEG;
    i++;
    T[i].lexem=REEL;
    T[i].valeur.reel=5;
    i++;
    T[i].lexem=BAR;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=FOIS;
    i++;
    T[i].lexem=VARIABLE;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=PLUS;
    i++;
    T[i].lexem=FONCTION;
    T[i].valeur.fonction=COS;
    i++;
    T[i].lexem=PAR_OUV;
    i++;
    T[i].lexem=REEL;
    T[i].valeur.reel=3;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=DIV;
    i++;
    T[i].lexem=VARIABLE;
    i++;
    T[i].lexem=FIN;
}
void generation_tab6(typejeton T[]){
    //tableau au genere:"|-5|*x+cos3/x)
    int i=0;
    T[i].lexem=BAR;
    i++;
    T[i].lexem=FONCTION;
    T[i].valeur.fonction=VAL_NEG;
    i++;
    T[i].lexem=REEL;
    T[i].valeur.reel=5;
    i++;
    T[i].lexem=BAR;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=FOIS;
    i++;
    T[i].lexem=VARIABLE;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=PLUS;
    i++;
    T[i].lexem=FONCTION;
    T[i].valeur.fonction=COS;
    i++;
    T[i].lexem=REEL;
    T[i].valeur.reel=3;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=DIV;
    i++;
    T[i].lexem=VARIABLE;
    i++;
    T[i].lexem=PAR_FERM;
    i++;
    T[i].lexem=FIN;
}
void generation_tab7(typejeton T[]){
    //tableau au genere:"|-5*x+cos(3/x)"
    int i=0;
    T[i].lexem=BAR;
    i++;
    T[i].lexem=FONCTION;
    T[i].valeur.fonction=VAL_NEG;
    i++;
    T[i].lexem=REEL;
    T[i].valeur.reel=5;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=FOIS;
    i++;
    T[i].lexem=VARIABLE;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=PLUS;
    i++;
    T[i].lexem=FONCTION;
    T[i].valeur.fonction=COS;
    i++;    
    T[i].lexem=PAR_OUV;
    i++;
    T[i].lexem=REEL;
    T[i].valeur.reel=3;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=DIV;
    i++;
    T[i].lexem=VARIABLE;
    i++;
    T[i].lexem=PAR_FERM;
    i++;
    T[i].lexem=FIN;
}

void generation_tab8(typejeton T[]){
    //tableau au genere:"ERREUR"
    int i=0;
    T[i].lexem=ERREUR;
    i++;
    T[i].lexem=FIN;
}
void generation_tab9(typejeton T[]){
    //tableau au genere:"cos(x+)"
    int i=0;
    T[i].lexem=FONCTION;
    T[i].valeur.fonction=COS;
    i++;    
    T[i].lexem=PAR_OUV;
    i++;
    T[i].lexem=VARIABLE;
    i++;
    T[i].lexem=OPERATEUR;
    T[i].valeur.operateur=PLUS;
    i++;
    T[i].lexem=PAR_FERM;
    i++;
    T[i].lexem=FIN;
}
int test_arbre(Arbre A, Arbre B){
    int tmp=0;
    printf("\033[1;33m");
    printf("%d=%d? ",A->jeton.lexem,B->jeton.lexem);
    printf("\033[0;0m");
    if ((A->jeton.lexem)==(B->jeton.lexem)){
        switch (B->jeton.lexem)
        {
        case FONCTION:
            printf("\033[1;33m");
            printf("test fonction detectee,valA %d=valB %d ?\n",A->jeton.valeur.fonction,B->jeton.valeur.fonction);
            printf("\033[0;0m");
            if ((A->jeton.valeur.fonction)==(B->jeton.valeur.fonction)){
                tmp=1;
            }else{
                tmp=0;
            }
            break;
        case OPERATEUR:
            printf("\033[1;33m");
            printf("test operateur detectee,valA %d=valB %d ?\n",A->jeton.valeur.operateur,B->jeton.valeur.operateur);
            printf("\033[0;0m");
            if ((A->jeton.valeur.operateur)==(B->jeton.valeur.operateur)){
                tmp=1;
            }else{
                tmp=0;
            }
            break;
        case VARIABLE:
            printf("\033[1;33m");
            printf("test variable detectee\n");
            printf("\033[0;0m");
            tmp=1;
            break;
        case REEL:
            printf("\033[1;33m");
            printf("test reel detectee,valA %f=valB %f ?\n",A->jeton.valeur.reel,B->jeton.valeur.reel);
            printf("\033[0;0m");
            if ((A->jeton.valeur.reel)==(B->jeton.valeur.reel)){
                tmp=1;
            }else{
                tmp=0;
            }
            break;        
        default:
            return 0;
            break;
        }
       
    }else{
        return 0;
    }
    if(A->fd!=NULL||B->fd!=NULL){
        printf("\033[1;33m");
        printf("debut verif fd\n");
        printf("\033[0;0m");
        tmp=tmp&&test_arbre(A->fd,B->fd);
    }else if(A->fd!=B->fd){
        return 1;
    }
    if(A->fg!=NULL||B->fg!=NULL){
        printf("\033[1;33m");
        printf("debut verif fg\n");
        printf("\033[0;0m");
        tmp=tmp&&test_arbre(A->fg,B->fg);
    }else if(A->fg!=B->fg){
        return 1;
    }
    return tmp;
}


int main(){
    int *erreur_pg;
    int erreur=0;
    erreur_pg=&erreur;
    //generation du tableau
    printf("generation du tableau 1\n");
    typejeton T[length_Tab];
    generation_tab1(T);
    printf("generation de l'arbre 1\n");
    //generation de l'arbre de test
    Arbre B =generation_arbre1();
    //passage de la fonction
    printf("envoi dans l'analyseur syntaxique 1\n");
    Arbre A;
    A=analyse_syntaxique(T,erreur_pg);
    //test de l'arbre
    printf("test de l'arbre 1\n");
    int egal =test_arbre(A ,B);
    if(egal!=1){
        printf("\033[1;31m");//passer le print en Rouge
        printf("Arbre non egaux\n");
        printf("\033[0;0m");
        return -1;
    }
    //test d'erreurs
    printf("recuperation des erreur prg 1\n");
    if(*erreur_pg!=000){
        printf("\033[1;31m");//passer le print en Rouge
        printf("%d",*erreur_pg);
        printf("\033[0;0m");
        return -1;
    }
    printf("\033[0;32m");//passer le print en Vert
    printf("==========================\ntest 1 passe\n==========================\n");
    printf("\033[0;0m");
    printf("\n");

    free(A);
    free(B);
    A=NULL;
    B=NULL;
    erreur=0;
    //generation du tableau
    printf("generation du tableau 2\n");
    generation_tab2(T);
    printf("generation de l'arbre 2\n");
    //generation de l'arbre de test
    B =generation_arbre2();
    //passage de la fonction
    printf("envoi dans l'analyseur syntaxique 2\n");
    A=analyse_syntaxique(T,erreur_pg);
    //test de l'arbre
    printf("test de l'arbre 2\n");
    egal =test_arbre(A ,B);
    if(egal!=1){
        printf("\033[1;31m");//passer le print en Rouge
        printf("Arbre non egaux\n");
        printf("\033[0;0m");
        return -1;
    }
    //test d'erreurs
    printf("recuperation des erreur prg 2\n");
    if(*erreur_pg!=000){
        printf("\033[1;31m");//passer le print en Rouge
        printf("%d",*erreur_pg);
        printf("\033[0;0m");
        return -1;
    }
    printf("\033[0;32m");//passer le print en Vert
    printf("==========================\ntest 2 passe\n==========================\n");
    printf("\033[0;0m");
    printf("\n");

    free(A);
    free(B);
    A=NULL;
    B=NULL;
    erreur=0;
    //generation du tableau
    printf("generation du tableau 3\n");
    generation_tab3(T);
    printf("generation de l'arbre 3\n");
    //generation de l'arbre de test
    B =generation_arbre3();
    //passage de la fonction
    printf("envoi dans l'analyseur syntaxique 3\n");
    A=analyse_syntaxique(T,erreur_pg);
    //test de l'arbre
    printf("test de l'arbre 3\n");
    egal =test_arbre(A ,B);
    if(egal!=1){
        printf("\033[1;31m");//passer le print en Rouge
        printf("Arbre non egaux\n");
        printf("\033[0;0m");
        return -1;
    }
    //test d'erreurs
    printf("recuperation des erreur prg 3\n");
    if(*erreur_pg!=000){
        printf("\033[1;31m");//passer le print en Rouge
        printf("%d",*erreur_pg);
        printf("\033[0;0m");
        return -1;
    }
    printf("\033[0;32m");//passer le print en Vert
    printf("==========================\ntest 3 passe\n==========================\n");
    printf("\033[0;0m");
    printf("\n");

    free(A);
    free(B);
    A=NULL;
    B=NULL;
    erreur=0;
    //generation du tableau
    printf("generation du tableau 4\n");
    generation_tab4(T);
    printf("generation de l'arbre 4\n");
    //generation de l'arbre de test
    B =generation_arbre4();
    //passage de la fonction
    printf("envoi dans l'analyseur syntaxique 4\n");
    A=analyse_syntaxique(T,erreur_pg);
    //test de l'arbre
    printf("test de l'arbre 4\n");
    egal =test_arbre(A ,B);
    if(egal!=1){
        printf("\033[1;31m");//passer le print en Rouge
        printf("Arbre non egaux\n");
        printf("\033[0;0m");
        return -1;
    }
    //test d'erreurs
    printf("recuperation des erreur prg 4\n");
    if(*erreur_pg!=000){
        printf("\033[1;31m");//passer le print en Rouge
        printf("%d",*erreur_pg);
        printf("\033[0;0m");
        return -1;
    }
    printf("\033[0;32m");//passer le print en Vert
    printf("==========================\ntest 4 passe\n==========================\n");
    printf("\033[0;0m");
    printf("\n");

    //test erreur 200
    free(A);
    free(B);
    A=NULL;
    B=NULL;
    erreur=0;
    //generation du tableau
    printf("generation du tableau 5\n");
    generation_tab5(T);
    //passage de la fonction
    printf("envoi dans l'analyseur syntaxique 5\n");
    A=analyse_syntaxique(T,erreur_pg);
    //test d'erreurs
    printf("recuperation des erreur prg 5\n");
    printf("erreur=%d,expected 200\n",*erreur_pg);
    if(*erreur_pg!=200){
        return -1;
    }
    printf("\033[0;32m");//passer le print en Vert
    printf("==========================\ntest 5 passe\n==========================\n");
    printf("\033[0;0m");
    printf("\n");

    //test erreur 201
    free(A);
    A=NULL;
    erreur=0;
    //generation du tableau
    printf("generation du tableau 6\n");
    generation_tab6(T);
    //passage de la fonction
    printf("envoi dans l'analyseur syntaxique 6\n");
    A=analyse_syntaxique(T,erreur_pg);
    //test d'erreurs
    printf("recuperation des erreur prg 6\n");
    printf("erreur=%d,expected 201\n",*erreur_pg);
    if(*erreur_pg!=201){
        return -1;
    }
    printf("\033[0;32m");//passer le print en Vert
    printf("==========================\ntest 6 passe\n==========================\n");
    printf("\033[0;0m");
    printf("\n");

    //test erreur 203
    free(A);
    A=NULL;
    erreur=0;
    //generation du tableau
    printf("generation du tableau 7\n");
    generation_tab7(T);
    //passage de la fonction
    printf("envoi dans l'analyseur syntaxique 7\n");
    A=analyse_syntaxique(T,erreur_pg);
    //test d'erreurs
    printf("recuperation des erreur prg 7\n");
    printf("erreur=%d,expected 203\n",*erreur_pg);
    if(*erreur_pg!=203){
        return -1;
    }
    printf("\033[0;32m");//passer le print en Vert
    printf("==========================\ntest 7 passe\n==========================\n");
    printf("\033[0;0m");
    printf("\n");

    //test erreur 202
    free(A);
    A=NULL;
    erreur=0;
    //generation du tableau
    printf("generation du tableau 8\n");
    generation_tab8(T);
    //passage de la fonction
    printf("envoi dans l'analyseur syntaxique 8\n");
    A=analyse_syntaxique(T,erreur_pg);
    //test d'erreurs
    printf("recuperation des erreur prg 8\n");
    printf("erreur=%d,expected 202\n",*erreur_pg);
    if(*erreur_pg!=202){
        return -1;
    }
    printf("\033[0;32m");//passer le print en Vert
    printf("==========================\ntest 8 passe\n==========================\n");
    printf("\033[0;0m");
    printf("\n");

    //test erreur 204
    free(A);
    A=NULL;
    erreur=0;
    //generation du tableau
    printf("generation du tableau 9\n");
    generation_tab9(T);
    //passage de la fonction
    printf("envoi dans l'analyseur syntaxique 9\n");
    A=analyse_syntaxique(T,erreur_pg);
    //test d'erreurs
    printf("recuperation des erreur prg 9\n");
    printf("erreur=%d,expected 204\n",*erreur_pg);
    if(*erreur_pg!=204){
        return -1;
    }
    printf("\033[0;32m");//passer le print en Vert
    printf("==========================\ntest 9 passe\n==========================\n");
    printf("\033[0;0m");
    printf("\n");

    printf("\033[1;32m");//passer le print en Vert
    printf("==========================\ntous les tests sont passes\n==========================\n");
    printf("\033[0;0m");
    return 0;
}