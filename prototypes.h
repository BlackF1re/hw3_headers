typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data);
int headData(Node** head);
void removeHead(Node** head);
void add(Node** head, int data);
int isEmpty(Node** head);

void deleteByData(Node** head, int key);
void searchByData(Node** head, int key);
void changeData(Node* n, int newValue, Node** head);
void printQueue(Node** head);
Node* search(Node** head, int key);

int openError();
int inputError();
int readingError();