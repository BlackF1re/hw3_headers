#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

//�������� ���� �������, ������� ��������� �� ����� ����
Node* createNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

//������� �������� ������
int headData(Node** head) { 
    return (*head)->data;
}

//�������� ������ �� �������
void removeHead(Node** head) {
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

//�������� � ���������� ������ ���� �� ��������� data � �������, �������� ���������� �� ��������
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

//�������� ���� �� ��������
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
            printf("������� �� ������.\n");
            return;
        }

        prev->next = temp->next;
        free(temp);
    }

    printf("���������� �������: ");
    Node* current = *head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void searchByData(Node** head, int sampleData) {
    Node* current = *head; //������� � ������ ����
    int counter = 0;
    //������� ���������� ��������� ��������� ��������
    while (current != NULL) {
        if (current->data == sampleData) {
            counter++;
            printf("�������� %d ������� %d ���.\n", sampleData, counter);
            return;
        }
        current = current->next;
    }
    printf("�������� %d �� �������.\n", sampleData);
}

void changeData(Node* target, int userValue, Node** head) {
    target->data = userValue;

    printf("����������� �������: ");
    Node* current = *head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

//���� �������
void printQueue(Node** head) {
    Node* current = *head;
    printf("����������� ������:\n");
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

//����� ���� �� data
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
    printf("������: ���������� ������� ����.");
    exit(1);
}

int inputError() {
    printf("������: ������� ������������ ��������.");
    exit(1);
}

int readingError() {
    printf("������: ���������� ��������� ��������.");
    exit(1);
}
#pragma endregion