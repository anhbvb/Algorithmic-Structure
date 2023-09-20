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

// Hàm kiểm tra số nguyên tố
int isPrime(int num) {
    if (num <= 1) {
        return 0; // Không phải số nguyên tố
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0; // Không phải số nguyên tố
        }
    }
    return 1; // Là số nguyên tố
}

// Hàm để tách danh sách liên kết thành hai danh sách: nguyên tố và không phải nguyên tố
void splitLists(struct Node *head, struct Node **primeList, struct Node **nonPrimeList) {
    *primeList = NULL;
    *nonPrimeList = NULL;

    struct Node *current = head;
    struct Node *primeTail = NULL;
    struct Node *nonPrimeTail = NULL;

    while (current != NULL) {
        if (isPrime(current->data)) {
            if (*primeList == NULL) {
                *primeList = primeTail = current;
            } else {
                primeTail->next = current;
                primeTail = current;
            }
        } else {
            if (*nonPrimeList == NULL) {
                *nonPrimeList = nonPrimeTail = current;
            } else {
                nonPrimeTail->next = current;
                nonPrimeTail = current;
            }
        }
        current = current->next;
    }

    if (primeTail != NULL) {
        primeTail->next = NULL;
    }
    if (nonPrimeTail != NULL) {
        nonPrimeTail->next = NULL;
    }
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

    struct Node *primeList = NULL;
    struct Node *nonPrimeList = NULL;

    splitLists(head, &primeList, &nonPrimeList);

    printf("Danh sach cac so nguyen to: ");
    printList(primeList);

    printf("Danh sach cac so khong phai nguyen to: ");
    printList(nonPrimeList);

    return 0;
}
