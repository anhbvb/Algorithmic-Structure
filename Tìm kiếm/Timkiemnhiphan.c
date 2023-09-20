#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        // Tìm giá trị giữa của phần mảng được xét
        int mid = left + (right - left) / 2;
        // Kiểm tra xem phần tử giữa có phải là giá trị cần tìm không
        if (arr[mid] == target){
            return mid;
        }
        // Nếu giá trị cần tìm nhỏ hơn phần tử giữa, tiến hành tìm ở nửa bên trái
        else if (arr[mid] > target){
            right = mid - 1;
        // Nếu giá trị cần tìm lớn hơn phần tử giữa, tiến hành tìm ở nửa bên phải
        }else{
            left = mid + 1;
        }
    }
    // Nếu không tìm thấy giá trị trong mảng, trả về -1
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Nhap gia tri can tim: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result == -1){
        printf("Khong tim thay %d trong mang.\n", target);
    }else{
        printf("%d duoc tim thay tai vi tri %d trong mang.\n", target, result + 1);
    }
    return 0;
}