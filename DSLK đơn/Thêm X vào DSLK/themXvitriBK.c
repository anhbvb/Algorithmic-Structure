#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc nút trong danh sách liên kết đơn
struct Node {
    int data;
    struct Node *next;
};

// Hàm để tạo danh sách liên kết từ danh sách các phần tử nhập từ người dùng
struct Node* createLinkedList(int n) {
    struct Node *head = NULL;
    struct Node *current = NULL;

    for (int i = 0; i < n; i++) {
        // Tạo nút mới
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        
        int value;
        printf("Nhap gia tri thu %d: ", i + 1);
        scanf("%d", &value);

        new_node->data = value;
        new_node->next = NULL;

        // Liên kết nút mới vào danh sách liên kết
        if (head == NULL) {
            head = new_node;
            current = new_node;
        } else {
            current->next = new_node;
            current = new_node;
        }
    }

    return head;
}

// Hàm để thêm phần tử x vào vị trí pos trong danh sách liên kết
struct Node* insertAtPosition(struct Node *head, int x, int pos) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = x;

    if (pos == 1) {
        new_node->next = head;
        head = new_node;
        return head;
    }

    struct Node *current = head;
    for (int i = 1; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Vi tri %d khong hop le.\n", pos);
        free(new_node);
        return head;
    }

    new_node->next = current->next;
    current->next = new_node;

    return head;
}

// Hàm để in danh sách liên kết
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    int n;

    printf("Nhap so luong node: ");
    scanf("%d", &n);

    struct Node *head = createLinkedList(n);

    printf("Danh sach vua nhap: ");
    printList(head);

    int x, pos;
    printf("Nhap gia tri x can them: ");
    scanf("%d", &x);
    printf("Nhap vi tri can them x: ");
    scanf("%d", &pos);

    head = insertAtPosition(head, x, pos);

    printf("Danh sach sau khi them phan tu %d vao vi tri %d: ", x, pos);
    printList(head);

    return 0;
}
