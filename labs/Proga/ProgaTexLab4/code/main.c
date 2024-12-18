#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK       0
#define NI       1
#define LONG     2

typedef struct Node {
    char val;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct LList {
    Node* head;
    Node* tail;
} LList;

// Создает новый узел
Node* createNode(char val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Создает новый список
LList* createList() {
    LList* list = (LList*)malloc(sizeof(LList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Добавляет символ в список
void append(LList* list, char val) {
    Node* newNode = createNode(val);
    if (!list->head) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// Удаляет последний символ из списка
void remLast(LList* list) {
    if (list->tail) {
        Node* temp = list->tail;
        if (list->tail->prev) {
            list->tail = list->tail->prev;
            list->tail->next = NULL;
        } else {
            list->head = NULL;
            list->tail = NULL;
        }
        free(temp);
    }
}

// Преобразует список в строку
char* toString(LList* list) {
    int length = 0;
    Node* current = list->head;
    while (current) {
        length++;
        current = current->next;
    }

    char* res = (char*)malloc(length + 1);
    current = list->head;
    for (int i = 0; i < length; i++) {
        res[i] = current->val;
        current = current->next;
    }
    res[length] = '\0';
    return res;
}

// Обрабатывает последовательность
char* processSeq(const char* seq) {
    LList* list = createList();
    int i = 0;

    while (seq[i] != '\0') {
        if (seq[i] == 'C' && seq[i + 1] == 'h') {
            remLast(list); // Удалить последний символ из списка
            i += 2; // Пропустить "Ch"
        } else {
            append(list, seq[i]); // Добавить текущий символ в список
            i++;
        }
    }

    char* res = toString(list);

    // Освобождаем память
    while (list->head) {
        remLast(list);
    }
    free(list);

    return res;
}

// Ввод пользовательской строки из консоли
int getLine (char* in, size_t size) {
    int ch, extra;

    if (fgets (in, size, stdin) == NULL)
        return NI;

    if (in[strlen(in)-1] != '\n') {
        extra = 0;
        while ((ch = getchar()) != '\n')
            extra = 1;
        return (extra == 1) ? LONG : OK;
    }

    in[strlen(in)-1] = '\0';
    return OK;
}

int main() {
    char inSeq[101];
    int input;

    while (1) { // Бесконечный цикл для консольного приложения
        printf("Введите последовательность (оканчивающуюся точкой, введите * для выхода): ");
        input = getLine(inSeq, sizeof(inSeq));

        if (input == NI) {
            printf ("\nНет ввода :(\n");
            continue;
        }

        if (input == LONG) {
            printf ("Последовательность слишком длинная [%s]\nЛимит символов: 100\n", inSeq);
            continue;
        }

        if (strcmp(inSeq, "*") == 0) { // Условие выхода
            printf("Выход из программы.\n");
            break;
        }

        char* outSeq = processSeq(inSeq);
        printf("Результат: %s\n", outSeq);
        free(outSeq);
    }

    return 0;
}
