/******************************************************************************
 * Họ và tên: [NGUYỄN HUỲNH ANH QUÂN]
 * MSSV:      [PS48285]
 * Lớp:       [CS21301]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c


// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>
void chucNNangTimSoNguyen() {
    float so;
    printf("Nhap mot so: ");    
    scanf("%f", &so);
    if (so == (int)so) {
        printf("%.2f la so nguyen.\n", so);
    } else {
        printf("%.2f khong phai la so nguyen.\n", so);
    }
}
void chucNangTimUocSoChungVaBoiSoChung() {
    int a, b;
    printf("Nhap hai so nguyen a va b: ");
    scanf("%d %d", &a, &b);

    // Tim Uoc so chung lon nhat (USCLN)
    int uscln = 1;
    for (int i = 1; i <= (a < b ? a : b); i++) {
        if (a % i == 0 && b % i == 0) {
            uscln = i;
        }
    }
    // Tim Boi so chung nho nhat (BSCNN)
    int bscnn = (a * b) / uscln;
    printf("Uoc so chung lon nhat cua %d va %d la: %d\n", a, b, uscln);
    printf("Boi so chung nho nhat cua %d va %d la: %d\n", a, b, bscnn);
}
    void chucNangTinhTienquanKaraoke() { 
    int gioBatDau, gioKetThuc;
    printf("Nhap gio bat dau (0-23): ");
    scanf("%d", &gioBatDau);    
    printf("Nhap gio ket thuc (0-23): ");
    scanf("%d", &gioKetThuc);
    if (gioKetThuc < gioBatDau || gioBatDau < 0 || gioBatDau > 23 || gioKetThuc < 0 || gioKetThuc > 23) {
        printf("Gio khong hop le.\n");
        return;
    } 
    int tongGio = gioKetThuc - gioBatDau;
    int tienThanhToan = 0;
    if (tongGio <= 2) {
        tienThanhToan = tongGio * 20000;
    } else {
        tienThanhToan = 2 * 20000 + (tongGio - 2) * 15000;
    }
    printf("Tong tien phai thanh toan: %d VND\n", tienThanhToan);
}
void chucNangTinhTienDien() {
    int soDien;
    printf("Nhap so dien tieu thu: ");
    scanf("%d", &soDien);
    int tienDien = 0;
    if (soDien <= 50) {
        tienDien = soDien * 1000;
    } else if (soDien <= 100) {
        tienDien = 50 * 1000 + (soDien - 50) * 1200;
    } else {
        tienDien = 50 * 1000 + 50 * 1200 + (soDien - 100) * 1500;
    }           
    printf("Tien dien phai tra: %d VND\n", tienDien);   
}
void chucNangDoiTien() {
    int soTien;
    printf("Nhap so tien can doi: ");
    scanf("%d", &soTien);
    int soTienDoiDuoc = soTien / 23000; // Gia tien USD/VND
    printf("So tien doi duoc: %d USD\n", soTienDoiDuoc);
}   
void chucNangTinhLaiSuatVayNganHangVayTraGop() {
    float soTienVay, laiSuat, thoiGianVay;  
    printf("Nhap so tien vay: ");   
    scanf("%f", &soTienVay);    
    printf("Nhap lai suat nam (%%): "); 
    scanf("%f", &laiSuat);
    printf("Nhap thoi gian vay (nam): ");   
    scanf("%f", &thoiGianVay);  
    float tongTienTra = soTienVay * (1 + (laiSuat / 100) * thoiGianVay);    
    printf("Tong tien phai tra sau %.2f nam: %.2f VND\n", thoiGianVay, tongTienTra);    
}
void chucNangSapXepThongTinSinhVien() {
    // Chức năng này sẽ được hoàn thiện sau
}   
void chucNangGameFPOLYLOTT() {
    // Chức năng này sẽ được hoàn thiện sau
}
void chucNangTinhToanPhanSo() {
    // Chức năng này sẽ được hoàn thiện sau
}
void chucNangThoat() {
        printf("Cam on ban da su dung chuong trinh. Hen gap lai!\n");
}
int main() {
    int chonChucNang;

    do {
        printf("Chon chuc nang:\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim Uoc so chung va boi so chung cua 2 so\n");
        printf("3. Tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay ngan hang vay tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chonChucNang);

         

        switch (chonChucNang) {
            case 1:
                // Gọi hàm kiểm tra số nguyên
                printf("DA CHON CHUC NANG 1: KIEM TRA SO NGUYEN\n");
                chucNNangTimSoNguyen(); 
                break;
            case 2:
                // Gọi hàm tìm Ước số chung và bội số chung
                printf("DA CHON CHUC NANG 2: TIM UOC SO CHUNG VA BOI SO CHUNG CUA 2 SO\n");
                chucNangTimUocSoChungVaBoiSoChung();
                break;
            case 3:
                // Gọi hàm tính tiền cho quán Karaoke
                printf("DA CHON CHUC NANG 3: TINH TIEN CHO QUAN KARAOKE\n");
                chucNangTinhTienquanKaraoke();
                break;
            case 4:
                // Gọi hàm tính tiền điện
                printf("DA CHON CHUC NANG 4: TINH TIEN DIEN\n");
                chucNangTinhTienDien();
                break;
            case 5:
                // Gọi hàm đổi tiền
                printf("DA CHON CHUC NANG 5: DOI TIEN\n");
                chucNangDoiTien();
                break;
            case 6:
                // Gọi hàm tính lãi suất vay ngân hàng
                printf("DA CHON CHUC NANG 6: TINH LAI SUAT VAY NGAN HANG VAY TRA GOP\n");
                chucNangTinhLaiSuatVayNganHangVayTraGop();
                break;
            case 7:
                // Gọi hàm vay tiền mua xe
                printf("DA CHON CHUC NANG 7: VAY TIEN MUA XE\n");
                break;
            case 8:
                // Gọi hàm sắp xếp thông tin sinh viên
                printf("DA CHON CHUC NANG 8: SAP XEP THONG TIN SINH VIEN\n");
                chucNangSapXepThongTinSinhVien();
                break;
            case 9:
                // Gọi hàm game FPOLY-LOTT
                printf("DA CHON CHUC NANG 9: GAME FPOLY-LOTT\n");
                chucNangGameFPOLYLOTT();
                break;
            case 10:
                // Gọi hàm tính toán phân số
                printf("DA CHON CHUC NANG 10: TINH TOAN PHAN SO\n");
                chucNangTinhToanPhanSo();
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                chucNangThoat();    
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (chonChucNang != 0);

    return 0;
}