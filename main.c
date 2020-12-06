#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct Node* next;
    struct Node* previous;
} Node;

typedef struct structList {
    Node* head;
    Node* tail;
} List;

void inicializaDeque(List* l) {
    l->head = NULL;
    l->tail = NULL;
}

void insereInicioDeque(List* l, int info) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->info = info;
    node->next = l->head;
    node->previous = NULL;
    if (l->head != NULL) {
        l->head->previous = node;
    } else {
        l->tail = node;
    }
    l->head = node;
}

void insereFimDeque(List* l, int info) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->info = info;
    node->previous = l->tail;
    node->next = NULL;
    if (l->tail != NULL) {
        l->tail->next = node;
    } else {
        l->head = node;
    }
    l->tail = node;
}

void removeInicioDeque(List* l) {
    Node* node = l->head;
    printf("%d\n", node->info);
    if (node->next == NULL) {
        l->tail = NULL;
        l->head = NULL;
    } else {
        l->head = node->next;
        l->head->previous = NULL;    
    }
    free(node);
}

void removeFimDeque(List* l) {
    Node* node = l->tail;
    printf("%d\n", node->info);
    if (node->previous == NULL) {
        l->tail = NULL;
        l->head = NULL;
    } else {
        l->tail = node->previous;
        l->tail->next = NULL;    
    }
    free(node);
}

void libereDeque(List* l) {
    Node* node = l->head;
    int count = 0;
    while (node != NULL) {
        count++;
        Node* temp = node->next;
        free(node);
        node = temp;
    }
    printf("%d\n", count);
}

int main() {
    List* list = (List*)malloc(sizeof(List));
    inicializaDeque(list);
    
    insereInicioDeque(list, 22);
    insereInicioDeque(list, 32);
    insereInicioDeque(list, 42);
   
    removeFimDeque(list);
    removeFimDeque(list);
    removeFimDeque(list);
    libereDeque(list);
}
