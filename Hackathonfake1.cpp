#include <stdio.h>

int main() {
    int i, n = 0, c, max, kiemtra = 0;
    int array[1000];
    int key, found, pos;  

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In ra cac gia tri cua phan tu vua nhap\n");
        printf("3. In ra gia tri lon nhat cua mang\n");
        printf("4. In ra cac phan tu la so nguyen to trong mang\n");
        printf("5. Them mot phan tu vao trong mang\n");
        printf("6. Xoa mot phan tu trong mang\n");
        printf("7. Sap xep mang theo thu tu tang dan\n");
        printf("8. Tim kiem phan tu va in ra index cua phan tu do\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Nhap so phan tu cua mang: ");
                scanf("%d", &n);
                if (n < 1 || n > 1000) { 
                    printf("So phan tu khong hop le.\n");
                    break;
                }
                printf("Nhap gia tri cac phan tu cua mang:\n");
                for (i = 0; i < n; i++) {
                    printf("Phan tu thu %d: ", i + 1);
                    scanf("%d", &array[i]);
                }
                break;

            case 2:
                printf("Cac phan tu cua mang la:\n");
                for (i = 0; i < n; i++) {
                    printf("Phan tu thu %d: %d\n", i + 1, array[i]);
                }
                break;

            case 3:
                if (n == 0) {
                    printf("Mang trong.\n");
                    break;
                }
                max = array[0];
                for (i = 1; i < n; i++) {
                    if (array[i] > max) {
                        max = array[i];
                    }
                }
                printf("Gia tri lon nhat cua mang la: %d\n", max);
                break;

            case 4:
                printf("Cac phan tu la so nguyen to trong mang:\n");
                for (i = 0; i < n; i++) {
                    kiemtra = 0;
                    if (array[i] <= 1) {
                        kiemtra = 1;
                    } else {
                        for (int j = 2; j * j <= array[i]; j++) {
                            if (array[i] % j == 0) {
                                kiemtra = 1;
                                break;
                            }
                        }
                    }

                    if (kiemtra == 0) {
                        printf("%d ", array[i]);
                    }
                }
                printf("\n");
                break;

            case 5:
                if (n >= 1000) {
                    printf("Khong the them phan tu vi mang da day.\n");
                    break;
                }
                printf("Nhap gia tri phan tu moi: ");
                scanf("%d", &array[n]);
                n++;
                printf("Phan tu da duoc them thanh cong.\n");
                break;

            case 6:
                printf("Nhap vi tri cua phan tu muon xoa (1-%d): ", n);
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }
                for (i = pos - 1; i < n - 1; i++) {
                    array[i] = array[i + 1];
                }
                n--;
                printf("Phan tu da duoc xoa thanh cong.\n");
                break;

            case 7:
                for (i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (array[i] > array[j]) {
                            int temp = array[i];
                            array[i] = array[j];
                            array[j] = temp;
                        }
                    }
                }
                printf("Mang sau khi sap xep tang dan:\n");
                for (i = 0; i < n; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;

            case 8:
                printf("Nhap gia tri phan tu muon tim: ");
                scanf("%d", &key);
                found = 0; 

                for (i = 0; i < n; i++) {
                    if (array[i] == key) {
                        printf("Phan tu %d duoc tim thay tai vi tri index %d.\n", key, i);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Phan tu %d khong ton tai trong mang\n", key);
                }
                break;

            case 9:
                printf("Thoat chuong trinh.\n");
                return 0;

            default:
                printf("Yeu cau ban nhap khong hop le.\n");
                break;
        }
    }

    return 0;
}

