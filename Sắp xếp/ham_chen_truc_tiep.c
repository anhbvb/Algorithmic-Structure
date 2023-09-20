#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Di chuyển các phần tử của mảng đã sắp xếp về phía sau
        // để chèn phần tử key vào đúng vị trí
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n;

    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n]; // Tạo mảng với kích thước n

    // Nhập các phần tử của mảng từ người dùng
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Sắp xếp mảng bằng thuật toán Insertion Sort
    insertionSort(arr, n);

    // In mảng sau khi sắp xếp
    printf("Mang sau khi sap xep:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
