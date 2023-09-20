#include <stdio.h>

int linearSearch( int a[], int n, int x){
    for (int i = 0; i < n; i++ ){
        if( a[i] == x ){
            return i + 1;
        }
    }
    return -1;
}
int main(){
    int a[]= { 5, 7, 4 , 3 ,9 };
    int n = sizeof(a)/sizeof(a[0]);
    int x;

    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);
    
    int m = linearSearch ( a, n, x);
    
    
    if ( m != -1 ){
        printf("phan tu %d duoc tim tai vi tri %d \n", x, m );
    }else{
        printf("phan tu %d k ton tai trong mang \n", x);
    }
    return 0;
}

// Dưới đây là các bước giải thuật của thuật toán tìm kiếm tuyến tính trong một mảng:

// **Đầu vào:** Mảng các số nguyên `arr`, kích thước của mảng `size`, và phần tử cần tìm kiếm `target`.

// 1. **Khởi tạo vòng lặp:** Bắt đầu từ `index = 0`, duyệt qua từng phần tử trong mảng.

// 2. **Kiểm tra phần tử:** Tại mỗi vòng lặp, kiểm tra nếu `arr[index]` bằng `target`.

//     - Nếu bằng, tức là chúng ta đã tìm thấy phần tử cần. Trả về giá trị `index`.
//     - Nếu không bằng, tiếp tục tới phần tử tiếp theo trong mảng.

// 3. **Kết thúc vòng lặp:** Sau khi duyệt qua toàn bộ mảng mà không tìm thấy phần tử cần, thoát khỏi vòng lặp.

// 4. **Trả về kết quả:** Nếu vòng lặp kết thúc mà không tìm thấy phần tử, trả về giá trị -1 để thể hiện rằng phần tử không tồn tại trong mảng.

// Các bước này thể hiện cách thuật toán tìm kiếm tuyến tính hoạt động. Nó sẽ duyệt qua từng phần tử trong mảng cho đến khi tìm thấy phần tử cần hoặc duyệt qua toàn bộ mảng. Đây là một phương pháp đơn giản và tương đối hiệu quả đối với các danh sách nhỏ, nhưng có thể trở nên chậm chạp với các danh sách lớn.







