#include <stdio.h>

void interchangeSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                // Hoán đổi phần tử arr[i] và arr[j]
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n]; // Tạo mảng với kích thước n

    // Nhập các phần tử của mảng từ người dùng
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Sắp xếp mảng bằng thuật toán Interchange Sort
    interchangeSort(arr, n);

    // In mảng sau khi sắp xếp
    printf("Mang sau khi sap xep:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
