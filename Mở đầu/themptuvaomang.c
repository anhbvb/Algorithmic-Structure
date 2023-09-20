#include <stdio.h>
#include <stdlib.h> // De su dung ham malloc

int main() {
    int original_array[] = {1, 2, 4, 5};
    int original_size = sizeof(original_array) / sizeof(original_array[0]);
    
    int new_element;
    int insert_index;

    printf("\nMang: ");
    for( int i = 0; i < original_size; i++){
        printf("%d ", original_array[i]);
    }

    printf("\nNhap phan tu moi: ");
    scanf("%d", &new_element);

    printf("Nhap vi tri de chen phan tu moi: ");
    scanf("%d", &insert_index);

    if (insert_index < 0 || insert_index > original_size) {
        printf("Vi tri chen khong hop le.\n");
        return 1;
    }

    // Tao mang moi voi kich thuoc lon hon mot don vi so voi mang ban dau
    int new_size = original_size + 1;
    int *new_array = (int *)malloc(new_size * sizeof(int));

    // Sao chep cac phan tu tu mang ban dau den vi tri truoc vi tri chen
    for (int i = 0; i < insert_index; i++) {
        new_array[i] = original_array[i];
    }

    // Gan phan tu moi vao vi tri chen
    new_array[insert_index] = new_element;

    // Sao chep cac phan tu con lai tu mang ban dau
    for (int i = insert_index + 1; i < new_size; i++) {
        new_array[i] = original_array[i - 1];
    }

    // In mang moi
    printf("Mang moi sau khi them phan tu: ");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", new_array[i]);
    }

    // Giai phong bo nho da cap phat cho mang moi
    free(new_array);

    return 0;
}
