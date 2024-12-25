#include <stdio.h>
#include <stdlib.h>

#define MAX 100
//menu 2
int displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    return 0; 
}


//menu3
int isPerfectNumber(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n ? 1 : 0;
}
//menu 4
int findSecondLargest(int arr[], int n) {
    int max = -1, secondMax = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            secondMax = max;
            max = arr[i];
        } else if (arr[i] > secondMax && arr[i] < max) {
            secondMax = arr[i];
        }
    }
    return secondMax;
}
//menu7
int insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return 0; 
}
//menu 8
int binarySearch(int arr[], int n, int value) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) return 1;
        else if (arr[mid] < value) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}

//menu 9
int sortEvenOdd(int arr[], int n) {
    int temp[MAX], index = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) temp[index++] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) temp[index++] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
    return 0; 
}

//menu 10
int reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    return 0; 
}

int main() {
    int arr[MAX], n, choice;

    while (1) {
        printf("\n==================MENU==================\n");
        printf("1. Nhap so phan tu va gia tri cho mang.\n");
        printf("2. In ra cac gia tri phan tu trong mang.\n");
        printf("3. Đếm số lượng số hoàn hảo trong mảng.\n");
        printf("4. Tim gia tri lon thu 2 trong mang.\n");
        printf("5. them mot phan tu tai mot vi tri ngau nhien.\n");
        printf("6. Xoa phan tu tai mot vi tri cu the.\n");
        printf("7. Sap xep mang theo theo thu tu tang dan.\n");
        printf("8. Tim kiem phan tu.\n");
        printf("9. Sắp xếp lai mang.\n");
        printf("10. Đao nguoc mang.\n");
        printf("0. Thoát\n");
        printf("Nhập lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhập số phần tử: ");
                scanf("%d", &n);
                printf("Nhap cac phan tu trong mang:\n");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = ", i);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                displayArray(arr, n);
                break;

            case 3: {
                int count = 0;
                for (int i = 0; i < n; i++) {
                    if (isPerfectNumber(arr[i])) count++;
                }
                printf("Số lượng số hoàn hảo trong mảng: %d\n", count);
                break;
            }

            case 4:
                printf("Giá trị lớn thứ hai trong mảng: %d\n", findSecondLargest(arr, n));
                break;

            case 5: {
                int value, pos;
                printf("Nhập giá trị cần thêm: ");
                scanf("%d", &value);
                pos = rand() % n;
                for (int i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = value;
                n++;
                printf("Đã thêm phần tử tại vị trí %d\n", pos);
                break;
            }

            case 6: {
                int pos;
                printf("Nhập vị trí cần xóa: ");
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Vị trí không hợp lệ!\n");
                } else {
                    for (int i = pos; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Đã xóa phần tử tại vị trí %d\n", pos);
                }
                break;
            }

            case 7:
                insertionSort(arr, n);
                printf("Mảng sau khi sắp xếp tăng dần:\n");
                displayArray(arr, n);
                break;

            case 8: {
                int value;
                printf("Nhập giá trị cần tìm: ");
                scanf("%d", &value);
                if (binarySearch(arr, n, value)) {
                    printf("Phần tử %d tồn tại trong mảng.\n", value);
                } else {
                    printf("Phần tử %d không tồn tại trong mảng.\n", value);
                }
                break;
            }

            case 9:
                sortEvenOdd(arr, n);
                printf("Mảng sau khi sắp xếp chẵn trước, lẻ sau:\n");
                displayArray(arr, n);
                break;

            case 10:
                reverseArray(arr, n);
                printf("Mảng sau khi đảo ngược:\n");
                displayArray(arr, n);
                break;

            case 0:
                exit(0);

            default:
                printf("Lựa chọn không hợp lệ!\n");
        }
    }

    return 0;
}
