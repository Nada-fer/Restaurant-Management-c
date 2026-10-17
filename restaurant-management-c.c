#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct plat
{char nom[50];
char description[250];
float prix;
char categorie[50];
}Plat;
typedef struct noeudplat
{Plat* plat;
struct noeudplat* Next;
struct noeudplat* Previous;
}Noeudplat;
typedef struct restaurant
{char nom[25];
char adresse[50];
float note;
char specialite[50];
Noeudplat* Listplats;
}Restaurant;
typedef struct noeudrestaurant
{Restaurant* restaurant;
struct noeudrestaurant* Next;
struct noeudrestaurant* Previous;
}Noeudrestaurant;

Noeudplat* nouveaunoeudplat()
{Noeudplat* nouveaunoeudPlat=malloc(sizeof(Noeudplat));
if(nouveaunoeudPlat==NULL)
{printf("Echec Allocation!");
exit(1);}
Plat* nouveauPlat=malloc(sizeof(Plat));
if(nouveauPlat==NULL)
{printf("Echec Allocation!");
exit(1);}
printf("\n--- Saisie du nouveau plat ---\n");
printf("Nom : ");
scanf(" %[^\n]",nouveauPlat->nom);
do{
printf("Prix : ");
scanf("%f", &nouveauPlat->prix);
if(nouveauPlat->prix<=0)
{printf("Prix invalid!");}
}while(nouveauPlat->prix<=0);
printf("Description : ");
scanf(" %[^\n]",nouveauPlat->description);
printf("Categorie : ");
scanf(" %[^\n]",nouveauPlat->categorie);
nouveaunoeudPlat->plat=nouveauPlat;
nouveaunoeudPlat->Next=NULL;
nouveaunoeudPlat->Previous=NULL;
return nouveaunoeudPlat;}

void Ajoutplatdebut(Restaurant* restaurant)
{Noeudplat* nouveauPlat=nouveaunoeudplat();
if (restaurant->Listplats==NULL) {
restaurant->Listplats=nouveauPlat;}
else {nouveauPlat->Next=restaurant->Listplats;
restaurant->Listplats->Previous=nouveauPlat;
restaurant->Listplats=nouveauPlat;}
printf("\nLe plat [%s] a ete ajoute au debut du menu avec succes.",
nouveauPlat->plat->nom);
}

void Ajoutplatfin(Restaurant* restaurant) {
Noeudplat* nouveauPlat=nouveaunoeudplat();
if (restaurant->Listplats==NULL) {
restaurant->Listplats=nouveauPlat;}
else {Noeudplat* temp=restaurant->Listplats;
while (temp->Next!=NULL){
temp=temp->Next;}
temp->Next=nouveauPlat;
nouveauPlat->Previous=temp;}
printf("\nLe plat [%s] a ete ajoute a la fin du menu avec succes.",nouveauPlat->plat->nom);
}

void AjoutApresPlat(Restaurant* restaurant, char* platspe) {
if (restaurant->Listplats==NULL) {
printf("\nErreur : Le menu est vide. Impossible de trouver [%s].",platspe);
return;}
Noeudplat* temp=restaurant->Listplats;
while (temp!=NULL && strcmp(temp->plat->nom,platspe) != 0) {
temp=temp->Next;}
if (temp==NULL) {
printf("\nErreur : Le plat [%s] n'a pas ete trouve. Ajout annule.",platspe);
return;}
Noeudplat* nouveauPlat=nouveaunoeudplat();
nouveauPlat->Next=temp->Next;
nouveauPlat->Previous=temp;
if (temp->Next!=NULL) {
temp->Next->Previous=nouveauPlat;}
temp->Next=nouveauPlat;
printf("\nPlat [%s] insere apres [%s] avec succes.", nouveauPlat->plat->nom,platspe);
}

void modifierPlat(Restaurant* restaurant, char* platRecherche) {
if (restaurant->Listplats==NULL) {
printf("\nLe menu est vide !");
return;}
Noeudplat* temp = restaurant->Listplats;
while (temp!=NULL && strcmp(temp->plat->nom,platRecherche)!=0) {
temp=temp->Next;}
if (temp==NULL) {
printf("\nPlat [%s] non trouve dans le menu.", platRecherche);
return;}
int choix;
printf("\nPlat trouve : %s", temp->plat->nom);
printf("\nPrix : %.2f",temp->plat->prix);
printf("\n2. Description : %s",temp->plat->description);
printf("\n3. Categorie: %s",temp->plat->categorie);
printf("\nQue voulez-vous modifier ?");
printf("\n1. Prix ");
printf("\n2. Description");
printf("\n3. Categorie");
printf("\nVotre choix : ");
do{
scanf("%d", &choix);
if(choix!=0 && choix!=1 && choix!=2 && choix!=3)
{printf("\nChoix invalid!");}
}while(choix!=0 && choix!=1 && choix!=2 && choix!=3);
switch(choix) {
    case 1:
        printf("Nouveau prix : ");
        scanf("%f", &temp->plat->prix);
        break;
    case 2:
        printf("Nouvelle description : ");
        scanf(" %[^\n]", temp->plat->description);
        break;
    case 3:
        printf("Nouvelle categorie : ");
        scanf(" %[^\n]", temp->plat->categorie);
    }
printf("\nModification effectuee avec succes !");}

void SupprimerPlatDebut(Restaurant* restaurant) {
if (restaurant->Listplats==NULL) {
printf("\nErreur : Le menu est déjà vide !");
return;}
Noeudplat* temp=restaurant->Listplats;
restaurant->Listplats=restaurant->Listplats->Next;
if (restaurant->Listplats!=NULL) {
restaurant->Listplats->Previous=NULL;}
free(temp->plat);
free(temp);
printf("\nLe premier plat a ete supprime avec succes.");}

void SupprimerPlatFin(Restaurant* restaurant) {
if (restaurant->Listplats==NULL) {
printf("\nErreur : Le menu est déjà vide !");
return;}
Noeudplat* temp = restaurant->Listplats;
while (temp->Next != NULL) {
temp=temp->Next;}
if (temp->Previous == NULL) {
restaurant->Listplats=NULL;}
else {temp->Previous->Next=NULL;}
free(temp->plat); // On libère la fiche
free(temp);      // On libère la boîte
printf("\nLe dernier plat a ete supprime avec succes.");}

void supprimerPlatspe(Restaurant* restaurant, char* platspe) {
if (restaurant->Listplats==NULL) {
printf("\nErreur : Le menu est déjà vide !");
return;}
Noeudplat* temp=restaurant->Listplats;
while (temp!=NULL && strcmp(temp->plat->nom,platspe)!=0) {
temp = temp->Next;}
if (temp == NULL) {
printf("\nErreur : Le plat [%s] n'existe pas.",platspe);
return;}
if (temp->Previous == NULL) {
restaurant->Listplats=temp->Next;
if (restaurant->Listplats!=NULL) {
restaurant->Listplats->Previous=NULL;}}
else {
temp->Previous->Next=temp->Next;
if (temp->Next!=NULL) {
temp->Next->Previous=temp->Previous;}}
free(temp->plat);
free(temp);
printf("\nLe plat [%s] a ete supprime avec succes.",platspe);}

void rechercherPlatParNom(Restaurant* restaurant, char* nomRecherche) {
if (restaurant->Listplats == NULL) {
printf("\nLe menu est vide.");
return;
}
Noeudplat* temp = restaurant->Listplats;
int trouve = 0;
while (temp != NULL) {
if (strcmp(temp->plat->nom, nomRecherche) == 0) {
printf("\n--- Plat Trouve ---");
printf("\nNom : %s", temp->plat->nom);
printf("\nPrix : %.2f", temp->plat->prix);
printf("\nDescription : %s", temp->plat->description);
printf("\nCategorie : %s", temp->plat->categorie);
trouve = 1;
break;
}
temp = temp->Next;
}
if (trouve == 0) {
printf("\nLe plat [%s] n'existe pas dans ce restaurant.", nomRecherche);
}
}

void rechercherPlatsParCategorie(Restaurant* restaurant, char* catRecherche) {
if (restaurant->Listplats == NULL) {
printf("\nLe menu est vide.");
return;
}
Noeudplat* temp = restaurant->Listplats;
int compteur = 0;
printf("\n--- Liste des plats (Categorie : %s) ---", catRecherche);
while (temp != NULL) {
if (strcmp(temp->plat->categorie, catRecherche) == 0) {
printf("\n %s %.2f DH", temp->plat->nom, temp->plat->prix);
compteur++;
}
temp = temp->Next;
}
if (compteur == 0) {
printf("\nAucun plat trouve pour la categorie %s.", catRecherche);
}
}

void rechercheAvanceePrix(Restaurant* restaurant, float prixMax) {
if (restaurant->Listplats == NULL) {
printf("\nLe menu est vide.");
return;
}
Noeudplat* temp = restaurant->Listplats;
int trouve = 0;
printf("\n--- Plats avec un prix <= %.2f ---", prixMax);
while (temp != NULL) {
if (temp->plat->prix <= prixMax) {
printf("\n %s %.2f DH", temp->plat->nom, temp->plat->prix);
trouve = 1;
}
temp = temp->Next;
}
if (trouve == 0) {
printf("\nAucun plat ne correspond a ce budget.");
}
}

void afficherTousLesPlats(Restaurant* restaurant) {
if (restaurant->Listplats == NULL) {
printf("\nLe menu est vide.");
return;
}
Noeudplat* temp = restaurant->Listplats;
printf("\n--- Menu du restaurant : %s ---", restaurant->nom);
while (temp != NULL) {
printf("\nNom : %s | Prix : %.2f DH | Categorie : %s",
temp->plat->nom, temp->plat->prix, temp->plat->categorie);
temp = temp->Next;
}
printf("\n------------------------------");
}

void afficherCategoriesUniques(Restaurant* restaurant) {
if (restaurant->Listplats == NULL) {
printf("\nAucun plat enregistre, la liste des categories est vide.");
return;
}
Noeudplat* temp = restaurant->Listplats;
printf("\n--- Categories disponibles dans %s ---", restaurant->nom);
while (temp != NULL) {
int dejaVu = 0;
Noeudplat* verif = restaurant->Listplats;
while (verif != temp) {
if (strcmp(verif->plat->categorie, temp->plat->categorie) == 0) {
dejaVu = 1;
break;
}
verif = verif->Next;
}
if (!dejaVu) {
printf("\n %s", temp->plat->categorie);
}
temp = temp->Next;
}
}

void modifierNomCategorie(Restaurant* restaurant, char* ancienneCat, char* nouvelleCat) {
if (restaurant->Listplats == NULL) {
printf("\nLe menu est vide.");
return;
}
Noeudplat* temp = restaurant->Listplats;
int compteur = 0;
while (temp != NULL) {
if (strcmp(temp->plat->categorie, ancienneCat) == 0) {
strcpy(temp->plat->categorie, nouvelleCat);
compteur++;
}
temp = temp->Next;
}
if (compteur > 0) {
printf("\nSucces : %d plat(s) ont ete modifies de [%s] vers [%s].", compteur, ancienneCat, nouvelleCat);
} else {
printf("\nAucun plat trouve avec la categorie [%s].", ancienneCat);
}
}

void statistiquesCategories(Restaurant* restaurant) {
if (restaurant->Listplats == NULL) {
printf("\nMenu vide.");
return;
}
Noeudplat* temp = restaurant->Listplats;
printf("\n--- Nombre de plats par categorie ---");
while (temp != NULL) {
int dejaVu = 0;
Noeudplat* verif = restaurant->Listplats;
while (verif != temp) {
if (strcmp(verif->plat->categorie, temp->plat->categorie) == 0) {
dejaVu = 1;
break;
}
verif = verif->Next;
}
if (!dejaVu) {
int count = 0;
Noeudplat* tempCount = restaurant->Listplats;
while (tempCount != NULL) {
if (strcmp(tempCount->plat->categorie, temp->plat->categorie) == 0) {
count++;
}
tempCount = tempCount->Next;
}
printf("\n %s : %d plat(s)", temp->plat->categorie, count);
}
temp = temp->Next;
}
}

void supprimerCategorie(Restaurant* restaurant, char* catASupprimer) {
if (restaurant->Listplats == NULL) {
printf("\nLe menu est deja vide.");
return;
}
Noeudplat* courant = restaurant->Listplats;
Noeudplat* aSupprimer = NULL;
int compteur = 0;
while (courant != NULL) {
if (strcmp(courant->plat->categorie, catASupprimer) == 0) {
aSupprimer = courant;
courant = courant->Next;
if (aSupprimer->Previous == NULL) {
restaurant->Listplats = aSupprimer->Next;
if (restaurant->Listplats != NULL) {
restaurant->Listplats->Previous = NULL;
}
} else {
aSupprimer->Previous->Next = aSupprimer->Next;
if (aSupprimer->Next != NULL) {
aSupprimer->Next->Previous = aSupprimer->Previous;
}
}
free(aSupprimer->plat);
free(aSupprimer);
compteur++;
} else {
courant = courant->Next;
}
}
if (compteur > 0) {
printf("\nSucces : La categorie [%s] et ses %d plat(s) ont ete supprimes.", catASupprimer, compteur);
} else {
printf("\nAucun plat trouve pour la categorie [%s].", catASupprimer);
}
}

void trierRestaurantsParNote(Noeudrestaurant* ListResto) {
    if (ListResto == NULL || ListResto->Next == NULL) {
        printf("\nPas assez de restaurants pour effectuer un tri.");
        return;
    }

    int echange;
    Noeudrestaurant* ptr1;
    Noeudrestaurant* lptr = NULL;

    do {
        echange = 0;
        ptr1 = ListResto;
        while (ptr1->Next != lptr) {
            if (ptr1->restaurant->note < ptr1->Next->restaurant->note) {
                Restaurant* tempResto = ptr1->restaurant;
                ptr1->restaurant = ptr1->Next->restaurant;
                ptr1->Next->restaurant = tempResto;
                echange = 1;
            }
            ptr1 = ptr1->Next;
        }
        lptr = ptr1;
    } while (echange);

    printf("\n=== CLASSEMENT DES RESTAURANTS (Par Note) ===");
    Noeudrestaurant* temp = ListResto;
    int rang = 1;
    while (temp != NULL) {
        printf("\n%d. %s - Note: %.1f/5", rang, temp->restaurant->nom, temp->restaurant->note);
        temp = temp->Next;
        rang++;
    }
    printf("\n============================================\n");
}

void ajouterRestaurantComplet(Noeudrestaurant** ListResto) {
Noeudrestaurant* nouveauNR = malloc(sizeof(Noeudrestaurant));
if(nouveauNR == NULL) { exit(1); }
Restaurant* nouveauR = malloc(sizeof(Restaurant));
if(nouveauR == NULL) { exit(1); }
printf("\nNom du restaurant : ");
scanf(" %[^\n]", nouveauR->nom);
printf("Adresse : ");
scanf(" %[^\n]", nouveauR->adresse);
printf("Specialite : ");
scanf(" %[^\n]", nouveauR->specialite);
printf("Note (0-5) : ");
scanf("%f", &nouveauR->note);
nouveauR->Listplats = NULL;
char choix;
printf("\nVoulez-vous ajouter des plats ? (o/n) : ");
scanf(" %c", &choix);
while(choix == 'o' || choix == 'O') {
Ajoutplatfin(nouveauR);
printf("\nAjouter un autre plat ? (o/n) : ");
scanf(" %c", &choix);
}
nouveauNR->restaurant = nouveauR;
nouveauNR->Next = *ListResto;
nouveauNR->Previous = NULL;
if (*ListResto != NULL) {
(*ListResto)->Previous = nouveauNR;
}
*ListResto = nouveauNR;
printf("\nRestaurant [%s] enregistre.\n", nouveauR->nom);
}

void afficherTout(Noeudrestaurant* ListResto) {
if (ListResto == NULL) {
printf("\nListe vide.");
return;
}
Noeudrestaurant* tempR = ListResto;
while (tempR != NULL) {
printf("\n================================");
printf("\nRESTAURANT : %s", tempR->restaurant->nom);
printf("\nNote : %.1f | Specialite : %s", tempR->restaurant->note, tempR->restaurant->specialite);
printf("\n--------------------------------");
Noeudplat* tempP = tempR->restaurant->Listplats;
if (tempP == NULL) {
printf("\n(Aucun plat)");
} else {
while (tempP != NULL) {
printf("\n- %s : %.2f DH", tempP->plat->nom, tempP->plat->prix);
tempP = tempP->Next;
}
}
tempR = tempR->Next;
}
printf("\n================================\n");
}

Restaurant* rechercherRestaurant(Noeudrestaurant* ListResto, char* nomRecherche) {
if (ListResto == NULL) {
return NULL;
}
Noeudrestaurant* temp = ListResto;
while (temp != NULL) {
if (strcmp(temp->restaurant->nom, nomRecherche) == 0) {
return temp->restaurant;
}
temp = temp->Next;
}
return NULL;
}

int main() {
    Noeudrestaurant* ListResto = NULL;
    int choixP, choixM, choixS;
    char nomR[50], nomP[50], catP[50];
    float budget;

    do {
        printf("\n--- MENU PRINCIPAL ---");
        printf("\n1. Ajouter un nouveau restaurant");
        printf("\n2. Afficher tous les restaurants");
        printf("\n3. Rechercher un restaurant par nom");
        printf("\n4. Choisir un restaurant pour gerer son menu");
        printf("\n5. Options de tri des restaurants (Note)");
        printf("\n6. Quitter");
        printf("\nChoix : ");

        if (scanf("%d", &choixP) != 1) {
            while (getchar() != '\n');
            continue;
        }

        switch(choixP) {
            case 1:
                ajouterRestaurantComplet(&ListResto);
                break;
            case 2:
                afficherTout(ListResto);
                break;
            case 3:
                printf("Nom du restaurant a rechercher : ");
                scanf(" %[^\n]", nomR);
                Restaurant* res = rechercherRestaurant(ListResto, nomR);
                if(res) printf("\nTrouve : %s | Adresse : %s | Note : %.1f", res->nom, res->adresse, res->note);
                else printf("\nRestaurant introuvable.");
                break;
            case 4:
                printf("Nom du restaurant a gerer : ");
                scanf(" %[^\n]", nomR);
                Restaurant* r = rechercherRestaurant(ListResto, nomR);
                if (r != NULL) {
                    do {
                        printf("\n\n--- GESTION DU MENU : %s ---", r->nom);
                        printf("\n1. Ajouter un plat (Debut/Fin/Spe)");
                        printf("\n2. Supprimer un plat (Debut/Fin/Spe)");
                        printf("\n3. Modifier un plat");
                        printf("\n4. Rechercher un plat (Nom/Cat/Prix)");
                        printf("\n5. Afficher le menu complet");
                        printf("\n6. Afficher les categories disponibles");
                        printf("\n7. Supprimer une categorie complete");
                        printf("\n8. Statistiques des categories");
                        printf("\n9. Retour au menu principal");
                        printf("\nChoix : ");
                        scanf("%d", &choixM);

                        switch(choixM) {
                            case 1:
                                printf("\n1. Debut | 2. Fin | 3. Apres un plat precis : ");
                                scanf("%d", &choixS);
                                if(choixS == 1) Ajoutplatdebut(r);
                                else if(choixS == 2) Ajoutplatfin(r);
                                else if(choixS == 3) {
                                    printf("Apres quel plat ? ");
                                    scanf(" %[^\n]", nomP);
                                    AjoutApresPlat(r, nomP);
                                }
                                break;
                            case 2:
                                printf("\n1. Debut | 2. Fin | 3. Plat precis : ");
                                scanf("%d", &choixS);
                                if(choixS == 1) SupprimerPlatDebut(r);
                                else if(choixS == 2) SupprimerPlatFin(r);
                                else if(choixS == 3) {
                                    printf("Nom du plat a supprimer : ");
                                    scanf(" %[^\n]", nomP);
                                    supprimerPlatspe(r, nomP);
                                }
                                break;
                            case 3:
                                printf("Nom du plat a modifier : ");
                                scanf(" %[^\n]", nomP);
                                modifierPlat(r, nomP);
                                break;
                            case 4:
                                printf("\n1. Nom | 2. Categorie | 3. Budget : ");
                                scanf("%d", &choixS);
                                if(choixS == 1) {
                                    printf("Nom : "); scanf(" %[^\n]", nomP);
                                    rechercherPlatParNom(r, nomP);
                                } else if(choixS == 2) {
                                    printf("Categorie : "); scanf(" %[^\n]", catP);
                                    rechercherPlatsParCategorie(r, catP);
                                } else if(choixS == 3) {
                                    printf("Budget max (DH) : "); scanf("%f", &budget);
                                    rechercheAvanceePrix(r, budget);
                                }
                                break;
                            case 5: afficherTousLesPlats(r); break;
                            case 6: afficherCategoriesUniques(r); break;
                            case 7:
                                printf("Nom de la categorie a supprimer : ");
                                scanf(" %[^\n]", catP);
                                supprimerCategorie(r, catP);
                                break;
                            case 8: statistiquesCategories(r); break;
                        }
                    } while(choixM != 9);
                } else printf("\nErreur : Restaurant [%s] non trouve.", nomR);
                break;
            case 5:
                trierRestaurantsParNote(ListResto);
                break;
        }
    } while(choixP != 6);
    return 0;
}
