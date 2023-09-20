#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node để biểu diễn các nút trong danh sách liên kết đơn
struct Node
{
    int data;          // Dữ liệu của nút
    struct Node *next; // Con trỏ đến nút kế tiếp trong danh sách
};

typedef struct Node Node; // Định nghĩa kiểu dữ liệu mới là Node để sử dụng dễ dàng hơn

// Hàm tạo một nút mới với dữ liệu truyền vào và trả về con trỏ tới nút mới này
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // Cấp phát bộ nhớ cho nút mới
    newNode->data = data;                         // Gán giá trị data cho nút mới
    newNode->next = NULL;                         // Khởi tạo con trỏ next của nút mới là NULL
    return newNode;                               // Trả về con trỏ đến nút mới đã tạo
}

// Hàm chèn một nút mới có dữ liệu vào cuối danh sách liên kết
void insert(Node **head, int data)
{
    Node *newNode = createNode(data); // Tạo nút mới với dữ liệu truyền vào
    if (*head == NULL)
    {                    // Nếu danh sách rỗng
        *head = newNode; // Thay đổi con trỏ đầu danh sách để trỏ tới nút mới
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next; // Di chuyển đến nút cuối cùng trong danh sách
        }
        current->next = newNode; // Chèn nút mới vào cuối danh sách
    }
}

// Hàm hiển thị các phần tử trong danh sách liên kết đơn
void display(Node *head)
{
    Node *current = head; // Bắt đầu từ đầu danh sách
    while (current != NULL)
    {
        printf("%d -> ", current->data); // In ra giá trị của nút hiện tại
        current = current->next;         // Di chuyển đến nút kế tiếp
    }
    printf("NULL\n"); // In ra NULL để kết thúc danh sách
}

int main()
{
    Node *linkedList = NULL; // Khởi tạo danh sách liên kết ban đầu là rỗng

    // Chèn các phần tử vào danh sách liên kết
    insert(&linkedList, 3);
    insert(&linkedList, 4);
    insert(&linkedList, 5);
    insert(&linkedList, 6);
    insert(&linkedList, 7);

    // Hiển thị danh sách liên kết
    display(linkedList);

    return 0;
}
