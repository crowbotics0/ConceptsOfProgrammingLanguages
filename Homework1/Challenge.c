#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(char data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void appendList(struct Node** head, char data)
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp-> next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertList(struct Node** head, int data, int position) {
    if (position < 1) {
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deletefromList(struct Node** head, int position) {
    if (*head == NULL) {
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}

int findInList(struct Node* head, char key) {
    struct Node* current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        position++;
        current = current->next;
    }
    return -1;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    appendList(&head, 'H');
    appendList(&head, 'e');
    appendList(&head, 'l');
    appendList(&head, 'l');
    appendList(&head, 'o');
    appendList(&head, ' ');
    appendList(&head, 'W');
    appendList(&head, 'o');
    appendList(&head, 'r');
    appendList(&head, 'l');
    appendList(&head, 'd');
    appendList(&head, '!');
    printList(head);
    insertList(&head, 'w', 5);
    printList(head);
    deletefromList(&head, 5);
    printList(head);
    printf("%d", findInList(head, '!'));
    printf("\n");

    return 0;
}