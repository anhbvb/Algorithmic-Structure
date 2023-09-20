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

// Hàm để tìm vị trí của phần tử x trong danh sách liên kết
int searchPosition(struct Node *head, int x) {
    struct Node *current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == x) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1; // Không tìm thấy
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

    int x;
    printf("Nhap gia tri x can tim: ");
    scanf("%d", &x);

    int position = searchPosition(head, x);

    if (position != -1) {
        printf("Tim thay gia tri %d tai vi tri %d trong danh sach.\n", x, position);
    } else {
        printf("Khong tim thay gia tri %d trong danh sach.\n", x);
    }

    return 0;
}
