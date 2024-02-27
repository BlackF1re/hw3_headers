#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prototypes.h"

int main() {
    SetConsoleOutputCP(1251);
    int data, isDigit, userInput;
    FILE* file;

    //char filename[100];
    //printf("������� ���� � �����: ");
    //isDigit = scanf("%s", filename);
    //if (isDigit != 1)
    //    openError();

    file = fopen("input.txt", "r");
    if (file == NULL) {
        openError();
    }

    //������ �����
    int length;
    isDigit = fscanf(file, "%d", &length);
    if (isDigit != 1)
        readingError();
    int* array = malloc(length * sizeof(int));

    //������ ��������� data � ������
    for (int i = 0; i < length; i++) {
        isDigit = fscanf(file, "%d", &data);
        if (isDigit != 1)
            readingError();
        array[i] = data;
    }
    fclose(file);

    Node* patientZero = createNode(data); //�������� �������� ���������� ����

    //���������� ����������� ����������� ����� � ������������������
    for (int i = 1; i < length; i++) {
        add(&patientZero, array[i]);
    }

    printf("�������������� ������� � �����������: ");
    while (!isEmpty(&patientZero)) {
        printf("%d ", headData(&patientZero));
        removeHead(&patientZero);
    }

    //������������ ����� �������� switch\case � ����-����
    printf("\n������� ��������, �� �������� ����� �������������� ����� ���������� ��������� � �������:\n");
    isDigit = scanf("%d", &userInput);
    if (isDigit != 1)
        inputError();
    searchByData(&patientZero, userInput);
    //
    printf("\n������� ��������, �� �������� ����� �������������� �������� �� �������:\n");
    isDigit = scanf("%d", &userInput);
    if (isDigit != 1)
        inputError();
    deleteByData(&patientZero, userInput);
    //
    printf("\n������� ������ ��������, ������� ���������� ��������:\n");
    int oldValue, newValue;
    isDigit = scanf("%d", &oldValue);
    if (isDigit != 1)
        inputError();

    printf("\n������� ����� ��������, �� ������� ���������� �������� ������:\n");
    isDigit = scanf("%d", &newValue);
    if (isDigit != 1)
        inputError();

    Node* current = patientZero;
    while (current != NULL) {
        if (current->data == oldValue) {
            changeData(current, newValue, &patientZero);
            break;
        }
        current = current->next;
    }

    Node* nodeToChange = search(&patientZero, oldValue);//����� ������������ � ��������� ����
    if (nodeToChange != NULL) {
        changeData(nodeToChange, newValue, &patientZero);
        printQueue(&patientZero);
    }

    free(array);
    return 0;
}
