#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void insertNode(int value, Node** head) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->value = value;
    newNode->next = *head;

    *head = newNode; // deixando como primeiro elemento da lista
}

void printList(Node* head) { // fun��o para exibir os itens da lista
    Node* current = head;

    while (current != NULL) {
        printf("%d ", current->value); // exibindo o item da lista

        current = current->next; // indo para o pr�ximo item da lista
    }
    printf("\n"); // adicionando nova linha para formata��o
}

int removeNode(Node** head) {
    if (*head == NULL) {
        printf("[ERRO] Lista vazia\n");
        return -1; // retornando valor de erro
    }

    Node* oldHead = *head;

    int value = oldHead->value; // buscando o valor do registro a ser apagado
    *head = oldHead->next;      // setando o pr�ximo elemento como o n� inicial

    free(oldHead); // liberando a mem�ria
    return value;
}

int main() {

    Node* head = NULL; // iniciando a lista vazia

    insertNode(30, &head);

    insertNode(60, &head);

    insertNode(90, &head);

    printf("Lista: ");
    printList(head);

    int removeValue = removeNode(&head);

    if (removeValue != -1) { // verificando se a remo��o foi bem sucedida
        printf("[AVISO] O %d foi removido\n", removeValue);
    }

    printf("Lista Atual: ");
    printList(head);

    return 0;
}
