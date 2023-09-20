#include <stdio.h>
#include <string.h>
#include <math.h>

// sắp xếp mảng tăng / giảm dần
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
// với trường hợp giảm dần arr[j] < key
        while (j >= 0 && arr[j] > key) {  
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Hàm kiểm tra số chính phương
int isPerfectSquare(int n) {
    int sqrtn = sqrt(n);
    return (sqrtn * sqrtn == n);
}

// Hàm kiểm tra số nguyên tố
int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int arr[100]; // Giả sử mảng có tối đa 100 phần tử
    int size = 0; // Kích thước thực tế của mảng
    char input[100]; // Chuỗi để nhập từ bàn phím
    
    // hiện thị mảng
    printf("\n- Nhap mang: ");
    fgets(input, sizeof(input), stdin);
    char *token = strtok(input, " "); // Tách chuỗi thành các phần tử cách nhau bởi khoảng trắng
    while (token != NULL) {
        sscanf(token, "%d", &arr[size]);
        size++;
        token = strtok(NULL, " ");
    }
    
    insertionSort(arr, size);
    printf("\n- Mang sap xep tang dan: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // tính tổng các phần tử trong mảng
    printf("\n- Tong cac phan tu trong mang la: %d", size);

    int sum = 0; 
    int max = arr[0];
    int min = arr[0];
    int scp = 0;
    int snt = 0;

    // Lặp qua dãy số để tính tổng, tìm giá trị lớn nhất, giá trị nhỏ nhất, số chính phương và số nguyên tố
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        if (arr[i] > max) { max = arr[i]; }
        if (arr[i] < min) { min = arr[i]; }
        if (isPerfectSquare(arr[i])) { scp++; }
        if (isPrime(arr[i])) { snt++; }
    }
    // In ra kết quả
    printf("\n- Tong cua day so: %d\n", sum);
    printf("- Gia tri trung binh: %.2f\n", (float) sum / size);
    printf("- Gia tri lon nhat: %d\n", max);
    printf("- Gia tri nho nhat: %d\n", min);

    // tìm số chính phương 
    printf("- Day so chinh phuong: ");
    for (int i = 0; i < size; i++) {
        if (isPerfectSquare(arr[i])) {
            printf("%d ", arr[i]);
        }
    }

    // tìm số nguyên tố
    printf("\n- Day so nguyen to: ");
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    
    // tìm vị trí của số nguyên bất kì có thể tồn tại trong mảng 
    int target;
    printf("\n- Nhap vao phan tu can tim: ");
    scanf("%d", &target);
    int found = 0; // Biến để kiểm tra xem phần tử có được tìm thấy hay không
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            found = 1;
            printf("  + Phan tu %d duoc tim thay tai vi tri so %d trong mang.\n", target, i + 1);
        }
    }
    if (found != 1) {
        printf("  + Khong tim thay phan tu %d trong mang.\n", target);
    }

    return 0;
}
