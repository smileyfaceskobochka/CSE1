#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Узел двунаправленного списка
typedef struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
} Node;

// Создание нового узла
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Удаление последнего узла
void deleteLastNode(Node** tail) {
    if (*tail == NULL) return;

    Node* temp = *tail;
    *tail = (*tail)->prev;
    if (*tail) {
        (*tail)->next = NULL;
    }
    free(temp);
}

// Добавление узла в конец
void appendNode(Node** head, Node** tail, char data) {
    Node* newNode = createNode(data);
    if (*tail == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

// Печать списка
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Освобождение памяти списка
void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    char input[100];
    printf("Enter the sequence (end with '.'): ");
    scanf("%s", input);

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; input[i] != '.'; ) {
        if (input[i] == 'C' && input[i + 1] == 'h') { // Проверяем "Ch"
            deleteLastNode(&tail);
            if (tail == NULL) {
                head = NULL;
            }
            i += 2; // Пропускаем оба символа "Ch"
        } else {
            appendNode(&head, &tail, input[i]);
            i++;
        }
    }

    printf("Resulting sequence: ");
    printList(head);

    freeList(head);
    return 0;
}
