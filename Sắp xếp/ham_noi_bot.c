#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // Hoán đổi các phần tử nếu chúng không được sắp xếp
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        // Nếu trong vòng lặp này không có hoán đổi nào xảy ra, dừng vòng lặp
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int n;

    printf("- Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n]; // Tạo mảng với kích thước n

    // Nhập các phần tử của mảng từ người dùng
    for (int i = 0; i < n; i++) {
        printf("  + Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Sắp xếp mảng bằng thuật toán Bubble Sort
    bubbleSort(arr, n);

    // In mảng sau khi sắp xếp
    printf("- Mang sau khi sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
