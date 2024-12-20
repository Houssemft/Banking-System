#include <stdio.h>
#include <string.h>

typedef struct {
    int numero;
    float solde;
} compte;

compte COMPTES[10];
int nbr_comp = 0;

typedef struct {
    char type_op[20];
    char etat[20];
    float montant;
    int main;
    int aux;
} operation;

operation TAB_OPERATIONS[20];
int nbr_oper = 0;

/* MANIPULATION DE COMPTES */

// Fonction Ajout de compte
void ajout() {
    if (nbr_comp < 10) {
        printf("Donner le numero de compte: ");
        scanf("%d", &COMPTES[nbr_comp].numero);
        printf("Donner le solde: ");
        scanf("%f", &COMPTES[nbr_comp].solde);
        nbr_comp++;
        printf("Compte ajouté avec succès !\n");
    } else {
        printf("Erreur: Nombre maximum de comptes atteint !\n");
    }
}

// Fonction Recherche de compte (retourne l'indice ou -1 si non trouvé)
int recherche(int numero_cmpt) {
    for (int i = 0; i < nbr_comp; i++) {
        if (COMPTES[i].numero == numero_cmpt) {
            return i;
        }
    }
    return -1; // Non trouvé
}

// Fonction Suppression de compte
void supprime(int numero) {
    int indice = recherche(numero);
    if (indice == -1) {
        printf("Erreur: Compte non trouvé !\n");
        return;
    }
    for (int i = indice; i < nbr_comp - 1; i++) {
        COMPTES[i] = COMPTES[i + 1];
    }
    nbr_comp--;
    printf("Compte supprimé avec succès !\n");
}

// Fonction de modification de compte
void modification(int numero) {
    int indice = recherche(numero);
    if (indice == -1) {
        printf("Erreur: Compte non trouvé !\n");
        return;
    }
    printf("Donner le nouveau numero de compte: ");
    scanf("%d", &COMPTES[indice].numero);
    printf("Donner le nouveau solde: ");
    scanf("%f", &COMPTES[indice].solde);
    printf("Compte modifié avec succès !\n");
}

/* OPERATIONS BANCAIRES */

// Opération de retrait
void RETRAIT(int numero, float montant) {
    int indice = recherche(numero);
    if (indice == -1) {
        printf("Erreur: Compte non trouvé !\n");
        return;
    }
    if (montant > COMPTES[indice].solde) {
        printf("Erreur: Solde insuffisant !\n");
    } else {
        COMPTES[indice].solde -= montant;
        printf("Retrait effectué avec succès !\n");

        // Historique de l'opération
        strcpy(TAB_OPERATIONS[nbr_oper].type_op, "RETRAIT");
        TAB_OPERATIONS[nbr_oper].montant = montant;
        TAB_OPERATIONS[nbr_oper].main = numero;
        strcpy(TAB_OPERATIONS[nbr_oper].etat, "TERMINE");
        nbr_oper++;
    }
}

// Opération de dépôt
void DEPOT(int numero, float montant) {
    int indice = recherche(numero);
    if (indice == -1) {
        printf("Erreur: Compte non trouvé !\n");
        return;
    }
    COMPTES[indice].solde += montant;
    printf("Dépôt effectué avec succès !\n");

    // Historique de l'opération
    strcpy(TAB_OPERATIONS[nbr_oper].type_op, "DEPOT");
    TAB_OPERATIONS[nbr_oper].montant = montant;
    TAB_OPERATIONS[nbr_oper].main = numero;
    strcpy(TAB_OPERATIONS[nbr_oper].etat, "TERMINE");
    nbr_oper++;
}

// Opération de transfert
void TRANSFERT(int numero1, int numero2, float montant) {
    int indice1 = recherche(numero1);
    int indice2 = recherche(numero2);
    if (indice1 == -1 || indice2 == -1) {
        printf("Erreur: L'un des comptes n'existe pas !\n");
        return;
    }
    if (montant > COMPTES[indice1].solde) {
        printf("Erreur: Solde insuffisant !\n");
    } else {
        COMPTES[indice1].solde -= montant;
        COMPTES[indice2].solde += montant;
        printf("Transfert effectué avec succès !\n");

        // Historique de l'opération
        strcpy(TAB_OPERATIONS[nbr_oper].type_op, "TRANSFERT");
        TAB_OPERATIONS[nbr_oper].montant = montant;
        TAB_OPERATIONS[nbr_oper].main = numero1;
        TAB_OPERATIONS[nbr_oper].aux = numero2;
        strcpy(TAB_OPERATIONS[nbr_oper].etat, "TERMINE");
        nbr_oper++;
    }
}

int main() {
    int choix, numero, numero2;
    float montant;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("0: Retrait\n");
        printf("1: Dépôt\n");
        printf("2: Transfert\n");
        printf("3: Ajout de compte\n");
        printf("4: Suppression de compte\n");
        printf("5: Modification de compte\n");
        printf("6: Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 0:
                printf("Donner le numero de compte: ");
                scanf("%d", &numero);
                printf("Donner le montant à retirer: ");
                scanf("%f", &montant);
                RETRAIT(numero, montant);
                break;
            case 1:
                printf("Donner le numero de compte: ");
                scanf("%d", &numero);
                printf("Donner le montant à déposer: ");
                scanf("%f", &montant);
                DEPOT(numero, montant);
                break;
            case 2:
                printf("Donner le numero de compte de l'expéditeur: ");
                scanf("%d", &numero);
                printf("Donner le numero de compte du bénéficiaire: ");
                scanf("%d", &numero2);
                printf("Donner le montant à transférer: ");
                scanf("%f", &montant);
                TRANSFERT(numero, numero2, montant);
                break;
            case 3:
                ajout();
                break;
            case 4:
                printf("Donner le numero de compte à supprimer: ");
                scanf("%d", &numero);
                supprime(numero);
                break;
            case 5:
                printf("Donner le numero de compte à modifier: ");
                scanf("%d", &numero);
                modification(numero);
                break;
            case 6:
                printf("Au revoir !\n");
                return 0;
            default:
                printf("Choix invalide !\n");
        }
    }
}
