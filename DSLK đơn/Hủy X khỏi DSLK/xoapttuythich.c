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

// Hàm để xóa phần tử tại vị trí tùy ý trong danh sách liên kết
struct Node* deleteNodeAtPosition(struct Node *head, int position) {
    if (head == NULL) {
        return NULL; // Danh sách rỗng
    }

    if (position == 1) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node *current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        printf("Vi tri xoa khong hop le.\n");
        return head;
    }

    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);

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

    int position;
    printf("Nhap vi tri can xoa: ");
    scanf("%d", &position);

    head = deleteNodeAtPosition(head, position);

    printf("Danh sach sau khi xoa phan tu tai vi tri %d: ", position);
    printList(head);

    return 0;
}
