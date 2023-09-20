#include <stdio.h>
#include <stdlib.h> // Để sử dụng hàm malloc

int main() {
    int original_array[] = {1, 2, 3, 4, 5};
    int original_size = sizeof(original_array) / sizeof(original_array[0]);
    
    int delete_element;

    printf("Nhap gia tri cua phan tu muon xoa: ");
    scanf("%d", &delete_element);

    int found = 0;
    int new_size = original_size - 1;
    int *new_array = (int *)malloc(new_size * sizeof(int));

    // Sao chep cac phan tu tu mang ban dau sang mang moi, loai bo phan tu muon xoa
    for (int i = 0, j = 0; i < original_size; i++) {
        if (original_array[i] == delete_element) {
            found = 1;
        } else {
            new_array[j++] = original_array[i];
        }
    }

    if (!found) {
        printf("Khong tim thay phan tu de xoa. ");
        printf("Mang ban dau: ");
        for (int i = 0; i < original_size; i++) {
            printf("%d ", original_array[i]);
        }
    } else {
        // In mang moi sau khi xoa phan tu
        printf("Mang moi sau khi xoa phan tu: ");
        for (int i = 0; i < new_size; i++) {
            printf("%d ", new_array[i]);
        }
    }

    // Giai phong bo nho da cap phat cho mang moi
    free(new_array);

    return 0;
}
