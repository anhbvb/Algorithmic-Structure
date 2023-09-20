#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một node trong danh sách liên kết vòng
struct Node {
    int data;
    struct Node *next;
};

// Hàm xóa phần tử đầu tiên trong danh sách liên kết vòng
void deleteFirstNode(struct Node **head) {
    if (*head == NULL) {
        printf("Danh sach rong, khong the xoa\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *lastNode = *head;

    while (lastNode->next != *head) {
        lastNode = lastNode->next;
    }

    *head = temp->next;
    lastNode->next = *head;
    free(temp);

    // Nếu chỉ còn một phần tử sau khi xóa
//     if (*head == lastNode) {
//         *head = NULL;
//     }
}

// Hàm in danh sách liên kết vòng
void printCircularLinkedList(struct Node *head) {
    if (head == NULL) {
        printf("Danh sach rong\n");
        return;
    }

    struct Node *current = head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main() {
    struct Node *head = NULL;

    // Tạo danh sách liên kết vòng với các phần tử
    // Đây chỉ là ví dụ, bạn có thể thay đổi giá trị và số phần tử
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;

    head->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->data = 20;

    // head->next->next = (struct Node *)malloc(sizeof(struct Node));
    // head->next->next->data = 30;
    
    // head->next->next->next = (struct Node *)malloc(sizeof(struct Node));
    // head->next->next->next->data = 40;

    // Kết nối phần tử cuối với phần tử đầu, tạo thành danh sách liên kết vòng
    head->next->next = head;

    printf("Danh sach truoc khi xoa: ");
    printCircularLinkedList(head);

    deleteFirstNode(&head);

    printf("Danh sach sau khi xoa: ");
    printCircularLinkedList(head);

    return 0;
}
