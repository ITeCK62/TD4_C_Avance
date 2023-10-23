/*
 * TD4 C Avancé
 *
 * @author Julien Cointe
 */
 
#include <stdio.h>
#include <stdlib.h>

// Structure pour représenter un noeud dans une liste chaînée
typedef struct Node {
    // Entier représentant le nombre dans le noeud
    int nbr;
    // Entier représentant le nombre d'occurrences du nombre
    int count;
    // Pointeur vers le prochain noeud dans la liste chaînée
    struct Node* next;
    // Pointeur vers le précédent noeud dans la liste chaînée
    struct Node* previous;
} Node;

// Fonction pour créer un nouveau noeud
Node* createNode(int* nbr) {
    // Allouer de la mémoire pour le nouveau noeud
    Node* newNode = (Node*) malloc(sizeof(Node));
    // Copier le nobmre dans le nouveau noeud
    newNode->nbr = nbr;
    // Initialiser le compteur du nouveau noeud à 1
    newNode->count = 1;
    // Initialiser le pointeur suivant du nouveau noeud à NULL
    newNode->next = NULL;
    // Initialiser le pointeur précédent du nouveau noeud à NULL
    newNode->previous = NULL;
    // Retourner le nouveau noeud
    return newNode;
}

// Fonction pour ajouter un noeud à la liste chaînée via le début
void insertNodeUp(Node** head, int* nbr) {
    // Si la liste est vide
    if (*head == NULL) {
        // Créer un nouveau nœud
        *head = createNode(nbr);
        return;
    }

    // Pointeur pour parcourir la liste
    Node* current = *head;

    // Tant que le noeud suivant n'est pas NULL
    while (current->next != NULL) {
        // Si le nombre du noeud actuel est identique au nombre à insérer
        if (current->nbr == nbr) {
            // Incrémenter le compteur du noeud actuel
            current->count++;
            return;
        }
        // Passer au noeud suivant
        current = current->next;
    }

    // Si le nombre du noeud actuel est égal au nombre à insérer
    if (current->nbr == nbr) {
        // Incrémenter le compteur du noeud actuel
        current->count++;
        return;
    }

    // Si le nombre à insérer est différent du nombre du noeud actuel
    if (current->nbr != nbr) {
        // Créer un nouveau noeud
        Node* newNode = createNode(nbr);
        // Le nouveau noeud pointe vers le noeud actuel
        newNode->next = *head;
        // Le noeud actuel pointe vers le nouveau noeud
        *head = newNode;
    } else {
        // Le noeud actuel pointe vers le nouveau noeud
        current->next = createNode(nbr);
    }
}

// Fonction pour ajouter un noeud à la liste chaînée via la fin
void insertNodeDown(Node** tail, int* nbr) {
    // Si la liste est vide
    if (*tail == NULL) {
        // Créer un nouveau nœud
        *tail = createNode(nbr);
        return;
    }

    // Pointeur pour parcourir la liste
    Node* current = *tail;

    // Tant que le noeud précédent n'est pas NULL
    while (current->previous != NULL) {
        // Si le nombre du noeud actuel est identique au nombre à insérer
        if (current->nbr == nbr) {
            // Incrémenter le compteur du noeud actuel
            current->count++;
            return;
        }
        // Passer au noeud précédent
        current = current->previous;
    }

    // Si le nombre du noeud actuel est égal au nombre à insérer
    if (current->nbr == nbr) {
        // Incrémenter le compteur du noeud actuel
        current->count++;
        return;
    }

    // Si le nombre à insérer est différent du nombre du noeud actuel
    if (current->nbr) != nbr) {
        // Créer un nouveau noeud
        Node* newNode = createNode(nbr);
        // Le nouveau noeud pointe vers le noeud actuel
        newNode->previous = *tail;
        // Le noeud actuel pointe vers le nouveau noeud
        *tail = newNode;
    } else {
        // Le noeud actuel pointe vers le nouveau noeud
        current->previous = createNode(nbr);
    }
}

// Fonction pour afficher la liste du début vers la fin
void printListUp(Node* head) {
    // Pointeur pour parcourir la liste
    Node* current = head;
    // Tant que le pointeur actuel n'est pas NULL
    while (current != NULL) {
        // Afficher le nombre et le compteur
        printf("%d - %d\n", current->nbr, current->count);
        // Passer au nœud suivant
        current = current->next;
    }
}

// Fonction pour afficher la liste de la fin vers le début
void printListDown(Node* tail) {
    // Pointeur pour parcourir la liste
    Node* current = tail;
    // Tant que le pointeur actuel n'est pas NULL
    while (current != NULL) {
        // Afficher le nombre et le compteur
        printf("%d - %d\n", current->nbr, current->count);
        // Passer au nœud précédent
        current = current->previous;
    }
}

// Fonction pour afficher la liste entière du début à la fin
void printFullListUp(Node* hasard){
    // Pointeur pour parcourir la liste
    Node* current = hasard;
    // Remonte jusqu'à la tête de liste
    while(!isHead(current)){
        current=current->previous;
    }
    // Tant que le pointeur actuel n'est pas NULL
    while(current != NULL){
        // Afficher le nombre et le compteur
        printf("%d - %d\n", current->nbr, current->count);
        // Passer au noeud suivant
        current = current->next;
    }
}

// Fonction pour afficher la liste entière de la fin au début
void printFullListDown(Node* hasard){
    // Pointeur pour parcourir la liste
    Node* current = hasard;
    // Remonte jusqu'à la fin de liste
    while(!isTail(current)){
        current=current->next;
    }
    // Tant que le pointeur actuel n'est pas NULL
    while(current != NULL){
        // Afficher le nombre et le compteur
        printf("%d - %d\n", current->nbr, current->count);
        // Passer au noeud précédent
        current = current->previous;
    }
}

// Fonction qui retourne 0 si le noeud est en tête de la liste
int isHead(Node* node){
    // Regarde si le noeud existe, si il ne posséde pas de précédent
    if(node != NULL && node->previous == NULL){
        // Affiche que le noeud est bien en tête de liste
        printf("Noeud en tête de liste");
        return 0;
    }
    else{
        // Affiche que le noeud n'est pas en tête de liste
        printf("Noeud pas en tête de liste");
        return 1;
    }
}

// Fonction qui retourne 0 si le noeud est en fin de la liste
int isTail(Node* node){
    // Regarde si le noeud existe, si il ne posséde pas de suivant
    if(node != NULL && node->next == NULL){
        // Affiche que le noeud est bien en fin de liste
        printf("Noued en fin de liste");
        return 0;
    }
    else{
        // Affiche que le noeud n'est pas en fin de liste
        printf("Noeud pas en fin de liste");
        return 1;
    }
}

int main(){
    return 0;
}