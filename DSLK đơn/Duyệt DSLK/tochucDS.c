#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc nút trong danh sách liên kết đơn
struct Node {
    char info[50];
    int count;
    struct Node *next;
};

// Hàm để tạo nút mới
struct Node* createNode(char *info) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    strcpy(new_node->info, info);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

// Hàm để thêm phần tử vào danh sách hoặc tăng số lần xuất hiện nếu đã tồn tại
struct Node* insertOrUpdate(struct Node *head, char *info) {
    if (head == NULL) {
        return createNode(info);
    }

    struct Node *current = head;
    while (current->next != NULL) {
        if (strcmp(current->info, info) == 0) {
            current->count++;
            return head;
        }
        current = current->next;
    }

    if (strcmp(current->info, info) == 0) {
        current->count++;
    } else {
        current->next = createNode(info);
    }

    return head;
}

// Hàm để in danh sách liên kết
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%s (xuat hien %d lan)\n", node->info, node->count);
        node = node->next;
    }
}

int main() {
    struct Node *head = NULL;
    char info[50];

    printf("Nhap thong tin (nhap 'end' de ket thuc):\n");

    while (1) {
        fgets(info, sizeof(info), stdin);
        info[strcspn(info, "\n")] = 0; // Loại bỏ ký tự newline (\n)
        
        if (strcmp(info, "end") == 0) {
            break;
        }

        head = insertOrUpdate(head, info);
        printf("Danh sach sau khi tao node moi:\n");
        printList(head);
        printf("\n");
    }

    return 0;
}
