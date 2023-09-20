#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc nút trong DSLK cấp 2 (sub)
struct SubNode {
    int data;
    struct SubNode *next;
};

// Định nghĩa cấu trúc nút trong DSLK chính (main)
struct MainNode {
    struct SubNode *pHead;
    struct SubNode *pTail;
    struct MainNode *next;
};

// Hàm để tạo nút con mới
struct SubNode* createSubNode(int data) {
    struct SubNode *new_node = (struct SubNode *)malloc(sizeof(struct SubNode));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Hàm để thêm phần tử vào DSLK con
void insertSubNode(struct SubNode **pHead, int data) {
    struct SubNode *new_node = createSubNode(data);

    if (*pHead == NULL || data < (*pHead)->data) {
        new_node->next = *pHead;
        *pHead = new_node;
    } else {
        struct SubNode *current = *pHead;
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Hàm để in DSLK chính kèm các DSLK con
void printMainList(struct MainNode *mainNode) {
    while (mainNode != NULL) {
        struct SubNode *currentSubNode = mainNode->pHead;
        printf("DSLK con: ");
        while (currentSubNode != NULL) {
            printf("%d ", currentSubNode->data);
            currentSubNode = currentSubNode->next;
        }
        printf("\n");
        mainNode = mainNode->next;
    }
}

int main() {
    struct MainNode *mainHead = NULL;

    for (int i = 0; i <= 999; i++) {
        int subListIndex = i / 1000;
        struct MainNode *currentMainNode = mainHead;

        // Tìm hoặc tạo DSLK con tương ứng với giá trị i
        while (subListIndex > 0 && currentMainNode != NULL) {
            currentMainNode = currentMainNode->next;
            subListIndex--;
        }

        if (currentMainNode == NULL) {
            currentMainNode = (struct MainNode *)malloc(sizeof(struct MainNode));
            currentMainNode->pHead = currentMainNode->pTail = NULL;
            currentMainNode->next = NULL;

            if (mainHead == NULL) {
                mainHead = currentMainNode;
            } else {
                struct MainNode *temp = mainHead;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = currentMainNode;
            }
        }

        int data;
        printf("Nhap gia tri cho DSLK con %d: ", i);
        scanf("%d", &data);
        insertSubNode(&(currentMainNode->pHead), data);
    }

    printf("Danh sach:\n");
    printMainList(mainHead);

    return 0;
}
