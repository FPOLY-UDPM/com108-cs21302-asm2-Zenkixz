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
#include <math.h>
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
// Gọi hàm void để xử lý chức năng tính tiền cho quán Karaoke
    void chucNangTinhTienquanKaraoke() { 
    int gioBatDau, gioKetThuc;
    float tienThanhToan;
    int tongsogio;
        printf("Nhap gio bat dau (12-23): ");
    scanf("%d", &gioBatDau);
    printf("Nhap gio ket thuc (12-23): ");
    scanf("%d", &gioKetThuc);
    // Kiểm tra hợp lệ
    if (gioBatDau < 12 || gioBatDau > 23 || gioKetThuc < 12 || gioKetThuc > 23 || gioKetThuc <= gioBatDau) {
        printf("Thoi gian khong hop le!\n");
        return;
    }

    tongsogio = gioKetThuc - gioBatDau;

    // Tính tiền
    if (tongsogio <= 3) {
        tienThanhToan = tongsogio * 150000;
    } else {
        tienThanhToan = 3 * 150000 + (tongsogio - 3) * 150000 * 0.7; // giảm 30% từ giờ thứ 4
    }

    // Giảm thêm 10% nếu giờ bắt đầu trong khoảng 14-17
    if (gioBatDau >= 14 && gioBatDau <= 17) {
        tienThanhToan = tienThanhToan * 0.9;
    }

    printf("Tong so gio: %d\n", tongsogio);
    printf("So tien can thanh toan: %.0f VND\n", tienThanhToan);
}   
void chucNangTinhTienDien() {
    // Khai báo biến
    int kWh;

    // Nhập dữ liệu
    printf("Nhap so dien tieu thu hang thang: ");
    scanf("%d", &kWh);      
     if (kWh <= 50) {
        float tien = kWh * 1.678;
        printf("So tien phai dong: %.2f VND\n", tien);
    } else if (kWh <= 100) {
        float tien = 50 * 1.678 + (kWh - 50) * 1.734;
        printf("So tien phai dong: %.2f VND\n", tien);
    } else if (kWh > 100) {
        float tien = 50 * 1.678 + 50 * 1.734 + (kWh - 100) * 2.014;
        printf("So tien phai dong: %.2f VND\n", tien);
    } else if (kWh > 200) {
        float tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + (kWh - 200) * 2.536;
        printf("So tien phai dong: %.2f VND\n", tien);
    } else if (kWh > 300) {
        float tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + (kWh - 300) * 2.834;
        printf("So tien phai dong: %.2f VND\n", tien);
    } else if (kWh > 400) {
        float tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + 100 * 2.834 + (kWh - 400) * 2.927;
        printf("So tien phai dong: %.2f VND\n", tien);
    } else {
        printf("So dien tieu thu khong hop le.\n");
    }       

    // Xử lý, tính toán VÀ Hiển thị kết quả           
}   
void chucnangdoitien(int money) {
    int nhungmenhgia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int n = sizeof(nhungmenhgia) / sizeof(nhungmenhgia[0]);
printf("Nhap so tien can doi: "); 
scanf("%d", &money);
    printf("Ket qua doi tien cho so tien %d:\n", money);
    for (int i = 0; i < n; i++) {
        int count = money / nhungmenhgia[i];
        if (count > 0) {
            printf("%d to %d\n", count, nhungmenhgia[i]);
            money %= nhungmenhgia[i];
        }
    }
}

void chucnangtinhlaisuatvaynganhangvaytragop(int tienVay) {
    int tienVay;
    printf("Nhap so tien muon vay: ");
    scanf("%d", &tienVay);

    chucnangtinhlaisuatvaynganhangvaytragop(tienVay);
    
    float laiSuat = 0.05; // 5%/tháng
    int kyHan = 12;       // 12 tháng
    int gocPhaiTra = tienVay / kyHan;
    int soTienConLai = tienVay;

    printf("Bang tinh lai suat vay ngan hang tra gop:\n");
    printf("Ky han | Lai phai tra | Goc phai tra | So tien phai tra | So tien con lai\n");
    printf("--------------------------------------------------------------------------\n");

    for (int thang = 1; thang <= kyHan; thang++) {
        int laiPhaiTra = (int)(soTienConLai * laiSuat);
        int soTienPhaiTra = gocPhaiTra + laiPhaiTra;
        soTienConLai -= gocPhaiTra;

        printf("%2d     | %10d   | %11d   | %15d   | %14d\n",
               thang, laiPhaiTra, gocPhaiTra, soTienPhaiTra, soTienConLai);
    }
}

void chucnangvaytienmuaxe(int phanTramVay) {
     int phanTramVay;
    printf("Nhap phan tram vay toi da (vd: 80): ");
    scanf("%d", &phanTramVay);
    chucnangvaytienmuaxe(phanTramVay);
    float giaXe = 500000000.0f; // 500 triệu
    int thoiHanNam = 24;
    int thoiHanThang = thoiHanNam * 12;
    float laiSuatNam = 0.072f;
    float laiSuatThang = laiSuatNam / 12;

    // Tính số tiền vay và trả trước
    float soTienVay = giaXe * phanTramVay / 100.0f;
    float traTruoc = giaXe - soTienVay;

    // Công thức tính trả góp hàng tháng (annuity formula)
    float tienTraHangThang = soTienVay * laiSuatThang / (1 - powf(1 + laiSuatThang, -thoiHanThang));

    printf("Gia xe: %.0f VND\n", giaXe);
    printf("Tra truoc: %.0f VND\n", traTruoc);
    printf("So tien vay: %.0f VND\n", soTienVay);
    printf("Thoi han vay: %d nam (%d thang)\n", thoiHanNam, thoiHanThang);
    printf("Lai suat co dinh: %.2f%%/nam\n", laiSuatNam * 100);
    printf("So tien phai tra hang thang: %.0f VND\n", tienTraHangThang);
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