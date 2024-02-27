#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

//создание узла очереди, возврат указателя на новый узел
Node* createNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

//возврат значения головы
int headData(Node** head) { 
    return (*head)->data;
}

//удаление головы из очереди
void removeHead(Node** head) {
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

//создание и добавление нового узла со свойством data в очередь, соблюдая сортировку по убыванию
void add(Node** head, int data) {
    Node* start = (*head);
    Node* temp = createNode(data);

    if ((*head)->data > data) {
        temp->next = *head;
        (*head) = temp;
    }
    else {
        while (start->next != NULL && start->next->data < data) {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

int isEmpty(Node** head) {
    return (*head) == NULL;
}

//удаление узла по значению
void deleteByData(Node** head, int sampleData) {
    Node* temp = *head;
    //Node* temp = *head, * prev;

    Node* prev = NULL;
    if (temp != NULL && temp->data == sampleData) {
        *head = temp->next;
        free(temp);
    }
    else {
        while (temp != NULL && temp->data != sampleData) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Элемент не найден.\n");
            return;
        }

        prev->next = temp->next;
        free(temp);
    }

    printf("Измененная очередь: ");
    Node* current = *head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void searchByData(Node** head, int sampleData) {
    Node* current = *head; //перебор с головы вниз
    int counter = 0;
    //подсчет количества вхождений заданного значения
    while (current != NULL) {
        if (current->data == sampleData) {
            counter++;
            printf("Значение %d найдено %d раз.\n", sampleData, counter);
            return;
        }
        current = current->next;
    }
    printf("Значение %d не найдено.\n", sampleData);
}

void changeData(Node* target, int userValue, Node** head) {
    target->data = userValue;

    printf("Обновленная очередь: ");
    Node* current = *head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

//выод очереди
void printQueue(Node** head) {
    Node* current = *head;
    printf("Обновленная чередь:\n");
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

//поиск узла по data
Node* search(Node** head, int data) {
    Node* current = *head;

    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

#pragma region errors
int openError() {
    printf("Ошибка: невозможно открыть файл.");
    exit(1);
}

int inputError() {
    printf("Ошибка: введено некорректное значение.");
    exit(1);
}

int readingError() {
    printf("Ошибка: невозможно прочитать значение.");
    exit(1);
}
#pragma endregion