#include <stdio.h>

int main() {
    int arr[100], n = 0, choice;

    do {
        printf("\n\tMENU\n");
        printf("1. Nhap so luong va gia tri cho cac phan tu\n");
        printf("2. In mang\n");
        printf("3. Dem so luong so hoan hao\n");
        printf("4. Dem so luong so nguyen to\n");
        printf("5. Tim gia tri lon thu 2\n");
        printf("6. Tim gia tri nho thu 2\n");
        printf("7. Them phan tu tai vi tri\n");
        printf("8. Xoa phan tu tai vi tri\n");
        printf("9. Sap xep mang tang dan(insertion sort)\n");
        printf("10. Sap xep mang giam dan(insertion sort)\n");
        printf("11. Tim kiem phan tu (tim kiem nhi phan)\n");
        printf("12. Xoa phan tu trung lap va in ra phan tu doc nhat\n");
        printf("13. Sap xep va hien thi so chan dung truoc so le dung sau \n");
        printf("14. Dao nguoc mang\n");
        printf("15. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Nhap so luong phan tu: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap phan tu arr[%d]: ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            }
            case 2: {
                printf("Mang: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 3: {
                int count = 0;
                for (int i = 0; i < n; i++) {
                    int sum = 0;
                    for (int j = 1; j < arr[i]; j++) {
                        if (arr[i] % j == 0) {
                            sum += j;
                        }
                    }
                    if (sum == arr[i]) {
                        count++;
                    }
                }
                printf("So luong so hoan hao: %d\n", count);
                break;
            }
            case 4: {
                int count = 0;
                for (int i = 0; i < n; i++) {
                    int isPrime = 1;
                    if (arr[i] <= 1) isPrime = 0;
                    for (int j = 2; j * j <= arr[i]; j++) {
                        if (arr[i] % j == 0) {
                            isPrime = 0;
                            break;
                        }
                    }
                    if (isPrime) count++;
                }
                printf("So luong so nguyen to: %d\n", count);
                break;
            }
            case 5: {
                if (n < 2) {
                    printf("Khong du phan tu de tim gia tri lon thu 2.\n");
                    break;
                }
                int max = arr[0], secondMax = -1;
                for (int i = 1; i < n; i++) {
                    if (arr[i] > max) {
                        secondMax = max;
                        max = arr[i];
                    } else if (arr[i] > secondMax && arr[i] != max) {
                        secondMax = arr[i];
                    }
                }
                printf("Gia tri lon thu 2: %d\n", secondMax);
                break;
            }
            case 6: {
                if (n < 2) {
                    printf("Khong du phan tu de tim gia tri nho thu 2.\n");
                    break;
                }
                int min = arr[0], secondMin = 99999999; 
                for (int i = 1; i < n; i++) {
                    if (arr[i] < min) {
                        secondMin = min;
                        min = arr[i];
                    } else if (arr[i] < secondMin && arr[i] != min) {
                        secondMin = arr[i];
                    }
                }
                printf("Gia tri nho thu 2: %d\n", secondMin);
                break;
            }
            case 7: {
                int viTri, giaTri;
                printf("Nhap vi tri can them: ");
                scanf("%d", &viTri);
                printf("Nhap gia tri can them: ");
                scanf("%d", &giaTri);
                if (viTri < 0 || viTri > n) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }
                for (int i = n; i > viTri; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[viTri] = giaTri;
                n++;
                break;
            }
            case 8: {
                int viTri;
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &viTri);
                if (viTri < 0 || viTri >= n) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }
                for (int i = viTri; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                break;
            }
            case 9: {
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (arr[i] > arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("Mang da sap xep tang dan.\n");
                break;
            }
            case 10: {
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (arr[i] < arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("Mang da sap xep giam dan.\n");
                break;
            }
            case 11: {
                int x;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);
                int left = 0, right = n - 1, found = -1;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (arr[mid] == x) {
                        found = mid;
                        break;
                    } else if (arr[mid] < x) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if (found != -1)
                    printf("Tim thay %d tai vi tri %d.\n", x, found);
                else
                    printf("Khong tim thay %d trong mang.\n", x);
                break;
            }
            case 12: {
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; ) {
                        if (arr[i] == arr[j]) {
                            for (int k = j; k < n - 1; k++) {
                                arr[k] = arr[k + 1];
                            }
                            n--;
                        } else {
                            j++;
                        }
                    }
                }
                printf("Mang da xoa cac phan tu trung lap.\n");
                break;
            }
            case 13: {
                int evenIndex = 0, oddIndex = n - 1;
                int temp[100];
                for (int i = 0; i < n; i++) {
                    if (arr[i] % 2 == 0)
                        temp[evenIndex++] = arr[i];
                    else
                        temp[oddIndex--] = arr[i];
                }
                for (int i = 0; i < n; i++) {
                    arr[i] = temp[i];
                }
                printf("Mang sau khi sap xep so chan truoc, so le sau.\n");
                break;
            }
            case 14: {
                for (int i = 0; i < n / 2; i++) {
                    int temp = arr[i];
                    arr[i] = arr[n - 1 - i];
                    arr[n - 1 - i] = temp;
                }
                printf("Mang da dao nguoc.\n");
                break;
            }
            case 15:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 15);

    return 0;
}

