#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void push(struct Node** head, int data) {
    struct Node* new_node = newNode(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int pop(struct Node** head) {
    if (*head == NULL) {
        return -1; 
    } else {
        struct Node* temp = *head;
        int data = temp->data;
        *head = (*head)->next;
        free(temp);
        return data;
    }
}

int main() {
    struct Node* stack = NULL;

    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 9);
    push(&stack, 10);
    push(&stack, 11);
    push(&stack, 12);
    push(&stack, 13);
    push(&stack, 14);

    printf("\n- Danh sach ly thuyet: ");
    printList(stack);

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);

    push(&stack, 1);

    printf("\n- Danh sach yeu cau Queue: ");
    printList(stack);

    printf("\n...");

    return 0;
}
