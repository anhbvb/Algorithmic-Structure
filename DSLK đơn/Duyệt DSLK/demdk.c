#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

// Hàm kiểm tra xem một số có phải là số nguyên tố hay không
int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Hàm để đếm số lượng phần tử là số nguyên tố trong danh sách liên kết và in ra danh sách các số nguyên tố
int countPrimesAndPrint(struct Node *node) {
    int count = 0;
    printf("Danh sach cac so nguyen to: ");
    while (node != NULL) {
        if (isPrime(node->data)) {
            printf("%d ", node->data);
            count++;
        }
        node = node->next;
    }
    printf("\n");
    return count;
}

int main() {
    int n;

    printf("Nhap so luong node: ");
    scanf("%d", &n);

    struct Node *head = createLinkedList(n);

    int primeCount = countPrimesAndPrint(head);
    printf("So luong phan tu la so nguyen to: %d\n", primeCount);

    return 0;
}
