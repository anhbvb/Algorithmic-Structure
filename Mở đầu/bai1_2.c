#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void insert(Node** head, int data, int pos) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        Node* prev = NULL;
        int Posi = 0;
        while (current != NULL && Posi < pos) {
            prev = current;
            current = current->next;
            Posi++;
        }
        newNode->next = current;
        newNode->prev = prev;
        if (prev != NULL) {
            prev->next = newNode;
        } else {
            *head = newNode;
        }
        if (current != NULL) {
            current->prev = newNode;
        }
    }
}
void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}
int main() {
    int a[] = {1,2,3};
    int n = sizeof(a) / sizeof(a[0]);
    Node* LinkedList = NULL;
    for (int i = 0; i < n; i++) {
        insert(&LinkedList, a[i], i);
    }
    printf("Danh sach lien ket doi la: ");
    display(LinkedList);
    return 0;
}
