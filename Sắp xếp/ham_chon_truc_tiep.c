#include <stdio.h>

void selectionSort(int arr[], int n)
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Hoán đổi phần tử tại vị trí minIndex với phần tử tại vị trí i
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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

    // Sắp xếp mảng bằng thuật toán Selection Sort
    selectionSort(arr, n);

    // In mảng sau khi sắp xếp
    printf("Mang sau khi sap xep:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
