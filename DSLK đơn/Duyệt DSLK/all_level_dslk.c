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
        printf("  + Gia tri thu %d: ", i + 1);
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
// Hàm để in danh sách liên kết
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Hàm để duyệt danh sách và đếm số lượng phần tử thỏa mãn điều kiện
int countConditionNodes(struct Node *node) {
    int count = 0;

    while (node != NULL) {
        if (node->data % 2 == 0) {
            count++;
        }
        node = node->next;
    }

    return count;
}

// Hàm để tính trung bình các số trong danh sách liên kết
float calculateAverage(struct Node *node) {
    float sum = 0;
    int count = 0;

    while (node != NULL) {
        sum += node->data;
        count++;
        node = node->next;
    }

    if (count == 0) {
        return 0; // Tránh chia cho 0
    }

    return sum / count;
}

// Hàm để tìm giá trị lớn nhất và vị trí của nó trong danh sách
void findMaxValue(struct Node *node, int *maxValue, int *maxPosition) {
    *maxValue = node->data;
    *maxPosition = 1;
    int currentPosition = 1;

    while (node != NULL) {
        if (node->data > *maxValue) {
            *maxValue = node->data;
            *maxPosition = currentPosition;
        }
        currentPosition++;
        node = node->next;
    }
}

// Hàm để tìm giá trị nhỏ nhất và vị trí của nó trong danh sách
void findMinValue(struct Node *node, int *minValue, int *minPosition) {
    *minValue = node->data;
    *minPosition = 1;
    int currentPosition = 1;

    while (node != NULL) {
        if (node->data < *minValue) {
            *minValue = node->data;
            *minPosition = currentPosition;
        }
        currentPosition++;
        node = node->next;
    }
}


// Hàm để chuyển các phần tử chẵn về đầu danh sách liên kết
struct Node* moveEvenToFront(struct Node *head) {
    if (head == NULL || head->next == NULL) {
        return head; // Danh sách không cần thay đổi
    }

    struct Node *evenHead = NULL; // Đầu danh sách chứa các phần tử chẵn
    struct Node *evenTail = NULL; // Đuôi danh sách chứa các phần tử chẵn
    struct Node *current = head;   // Con trỏ duyệt danh sách
    struct Node *prev = NULL;      // Con trỏ trỏ đến nút trước nút đang duyệt

    while (current != NULL) {
        if (current->data % 2 == 0) { // Nếu phần tử là số chẵn
            if (evenHead == NULL) {
                evenHead = evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = current;
            }

            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
        } else {
            prev = current;
        }

        current = current->next;
    }

    if (evenTail != NULL) {
        evenTail->next = head;
        return evenHead;
    }

    return head;
}

// Hàm để hoán đổi nội dung của hai biến
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm để sắp xếp danh sách liên kết theo thứ tự tăng dần bằng thuật toán Bubble Sort
void bubbleSort(struct Node *head) {
    int swapped, i;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Hoán đổi dữ liệu hai nút
                swap(&ptr1->data, &ptr1->next->data);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
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

// // Hàm để tìm vị trí của giá trị x trong danh sách liên kết
// int findPosition(struct Node *head, int x) {
//     struct Node *current = head;
//     int position = 1;

//     while (current != NULL) {
//         if (current->data == x) {
//             return position;
//         }
//         position++;
//         current = current->next;
//     }

//     return -1; // Giá trị x không có trong danh sách
// }

// Hàm để chèn giá trị x vào vị trí tùy ý trong danh sách liên kết
struct Node* insertValueAtPosition(struct Node *head, int x, int position) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = NULL;

    if (position == 1) {
        new_node->next = head;
        head = new_node;
        return head;
    }

    struct Node *current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Vi tri chen khong hop le.\n");
        free(new_node);
        return head;
    }

    new_node->next = current->next;
    current->next = new_node;
    return head;
}


int main() {
    int n;

    printf("- Nhap so luong node: ");
    scanf("%d", &n);

    struct Node *head = createLinkedList(n);

    printf("- Danh sach vua nhap: ");
    printList(head);

    int count = countConditionNodes(head);
    printf("- So luong phan tu: %d\n", n);

    float average = calculateAverage(head);
    printf("- Trung binh cong: %.4f\n", average);


    int maxValue, maxPosition, minValue, minPosition;
    findMaxValue(head, &maxValue, &maxPosition);
    findMinValue(head, &minValue, &minPosition);

    printf("- Gia tri lon nhat la %d nam o vi tri thu %d\n", maxValue, maxPosition);
    printf("- Gia tri nho nhat la %d nam o vi tri thu %d\n", minValue, minPosition);


    head = moveEvenToFront(head);

    printf("- Danh sach sau khi chuyen cac phan tu chan ve dau: ");
    printList(head);

    bubbleSort(head);

    printf("- Danh sach sap xep tang dan: ");
    printList(head);

    struct Node *primeList = NULL;
    struct Node *nonPrimeList = NULL;

    splitLists(head, &primeList, &nonPrimeList);

    printf("- Danh sach so nguyen to: ");
    printList(primeList);

    printf("- Danh sach khong phai so nguyen to: ");
    printList(nonPrimeList);

    // int x;
    // printf("- Nhap gia tri x can tim: ");
    // scanf("%d", &x);

    // int position = findPosition(head, x);

    // if (position != -1) {
    //     printf("  + Gia tri %d nam o vi tri %d.\n", x, position + 1);
    // } else {
    //     printf("  + Gia tri %d khong ton tai.\n", x);
    // }

    int x, position;
    printf("- Nhap gia tri x can chen: ");
    scanf("%d", &x);
    printf("  + Vi tri so %d can chen: ", x);

    
    scanf("%d", &position);

    head = insertValueAtPosition(head, x, position);

    printf("  => Danh sach sau khi chen gia tri %d vao vi tri %d: ", x, position);
    printList(head);

    return 0;
}
