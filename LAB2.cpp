#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;
    const int minute_rate_7to17 = 400;
    const int minute_rate_17to24 = 350;
    const int minute_rate_0to7 = 300;

    const int discount_threshold_6h = 6 * 60;
    const int discount_threshold_4h = 4 * 60;
    const int discount_threshold_7h = 7 * 60;
// kiểm tra SNT
bool isPrime(int number) {
    if (number <= 1)
        return false;
    if (number <= 3)
        return true;

    if (number % 2 == 0 || number % 3 == 0)
        return false;

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0)
            return false;
    }

    return true;
}

int reverseDigits(int n) {
    int reversed = 0;
    
    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    
    return reversed;
}

// ------- Tính tiền phòng --------------------
long tinhTienPhong(int &ngay, char loaiPhong)
{
    long tongTienPhong, giamGia;
    const double giaA = 250000;
    const double giaB = 200000;
    const double giaC = 150000;

    if (loaiPhong == 'A')
    {
        if (ngay > 12)
        {
            tongTienPhong = giaA * ngay;
            giamGia = tongTienPhong * 0.1;
            tongTienPhong = tongTienPhong - giamGia;
        }
        else
        {
            tongTienPhong = giaA * ngay;
        }
    }
    if (loaiPhong == 'B')
    {
        if (ngay > 12)
        {
            tongTienPhong = giaB * ngay;
            giamGia = tongTienPhong * 0.08;
            tongTienPhong = tongTienPhong - giamGia;
        }
        else
        {
            tongTienPhong = giaB * ngay;
        }
    }
    if (loaiPhong == 'C')
    {
        if (ngay > 12)
        {
            tongTienPhong = giaC * ngay;
            giamGia = tongTienPhong * 0.08;
            tongTienPhong = tongTienPhong - giamGia;
        }
        else
        {
            tongTienPhong = giaC * ngay;
        }
    }
    return tongTienPhong;
}
// =======================================



// ------- Kiểm tra năm nhuận--------------
bool mamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int soNgayCuaThang(int thang, int nam) {
    if (thang == 2) {
        return mamNhuan(nam) ? 29 : 28;
    } else if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
        return 30;
    } else {
        return 31;
    }
} //=======================================




int main() {

    // -- CƠ BẢN -- //
    int choice, n;
    double sum = 0.0;
    
    do {
        cout << "Lựa chọn yêu cầu" << endl;
        cout << "1. Kiểm tra số nguyên thỏa mãn 'Tích 2 số bằng 2 lần tổng 2 số ( 10 ~ 99 )'" << endl;
        cout << "2. Các số nguyên tố nhỏ hơn N" << endl;
        cout << "3. Xuất ra bảng mã ASCII" << endl;
        cout << "4. Số đảo ngược" << endl;
        cout << "5. Tổng các chữ số của số nguyên N" << endl;
        cout << "6. Tính cước truy cập" << endl;
        cout << "7. Tính tiền thuê phòng" << endl;
        cout << "8. Kiểm tra ngày/tháng/năm" << endl;
        cout << "9. Tính tiền Taxi" << endl;
        cout << "10. Xếp loại học sinh" << endl;
        cout << "0. Thoát." << endl;
        cout << "Chọn yêu cầu: ";
        cin >> choice;

        switch (choice) {
            case 1:
            {
               cout << "Cac so nguyen thoa man dieu kien tu 10 den 99: ";
                for (int num = 10; num <= 99; num++) {
                    int tens_digit = num / 10;
                    int ones_digit = num % 10;
                    int product = tens_digit * ones_digit;
                    int sum = tens_digit + ones_digit;

                    if (product == 2 * sum) {
                        cout << num << " ";
                    }
                }
                cout << endl;
                break;
            }
            case 2:
            {
                 int n;
                cout << "Nhap vao so n: ";
                cin >> n;

                cout << "Cac so nguyen to nho hon " << n << " la: ";
                for (int i = 2; i < n; i++) {
                    if (isPrime(i)) {
                        cout << i << " ";
                    }
                }
                cout << endl;
                break;
               
            }
            case 3:
            {
               const int rows_per_page = 20; 
            char start_char = ' '; 
            char end_char = '~'; 

             int current_char = static_cast<int>(start_char); 
            while (true) {
        
                 cout << "BANG MA ASCII" << endl;
                 cout << "Ky tu | Ma ASCII" << endl;
                 cout << "-------+---------" << endl;

       
                 for (int i = 0; i < rows_per_page && current_char <= static_cast<int>(end_char); i++) {
                  cout << "   " << static_cast<char>(current_char) << "   |   " << current_char << endl;
                 current_char++;
                }

             char choice;
            cout << "Nhan 'Q' hoac 'q' de thoat, hoac phim bat ky de xem trang tiep theo: ";
            cin >> choice;

                if (choice == 'Q' || choice == 'q') {
             break; 
            }
             }

             return 0;
                break;
                }
            case 4:
            {
                int n;
                cout << "Nhap mot so nguyen duong n: ";
                cin >> n;

                int reversedNumber = reverseDigits(n);

                 cout << "Chu so dao nguoc cua " << n << " la: " << reversedNumber << endl;

                     return 0;
                break;
            }
            case 5:
            {
                int n;
               cout << "Nhap mot so nguyen duong n: ";
              cin >> n;

            // Đếm số lượng chữ số và tính tổng các chữ số
          int countDigits = 0;
          int sumDigits = 0;
          int number = n;

        while (number > 0) {
            int digit = number % 10;
         countDigits++;
            sumDigits += digit;
            number /= 10;
             }

             cout << "So luong chu so cua " << n << " la: " << countDigits << endl;
            cout << "Tong cac chu so cua " << n << " la: " << sumDigits << endl;

                return 0;
                break;
            }
            case 6:
            {
               int start_hour, start_minute, end_hour, end_minute;

                    // Nhập giờ bắt đầu và kết thúc truy cập
                    cout << "Nhap gio bat dau truy cap (0 - 23): ";
                    cin >> start_hour;
                    cout << "Nhap phut bat dau truy cap (0 - 59): ";
                    cin >> start_minute;
                    cout << "Nhap gio ket thuc truy cap (0 - 23): ";
                    cin >> end_hour;
                    cout << "Nhap phut ket thuc truy cap (0 - 59): ";
                    cin >> end_minute;

                    // Chuyển đổi thời gian truy cập thành phút
                    int total_minutes = (end_hour * 60 + end_minute) - (start_hour * 60 + start_minute);

                    // Xác định giá cước dựa trên khoảng thời gian
                    int minute_rate;
                    
                    if (start_hour >= 7 && end_hour < 17) {
                        minute_rate = minute_rate_7to17;
                        if (total_minutes > discount_threshold_6h) {
                            minute_rate -= minute_rate * 0.10;
                        }
                    } else if (start_hour >= 17 || end_hour < 7) {
                        minute_rate = minute_rate_17to24;
                        if (total_minutes > discount_threshold_4h) {
                            minute_rate -= minute_rate * 0.12;
                        }
                    } else {
                        minute_rate = minute_rate_0to7;
                        if (total_minutes > discount_threshold_7h) {
                            minute_rate -= minute_rate * 0.15;
                        }
                    }

            // Tính cước truy cập
            double total_cost = total_minutes * minute_rate / 60.0;

            // Hiển thị kết quả
            cout << "Tong so phut truy cap: " << total_minutes << " phut" << endl;
            cout << "Cuuoc truy cap: " << total_cost << " dong" << endl;

                 return 0;

                break;
            }
            case 7:
            {                  
                int ngaythue;
                char loaiphong;
                long tongtienphong;
                cout << "Nhap ngay thue" << endl;
                cin >> ngaythue;
                cout << "chon loai phong A B C" << endl;
                cin >> loaiphong;
                tongtienphong = tinhTienPhong(ngaythue, loaiphong);
                cout << "Tong tien phong:" << tongtienphong << endl;
                break;
            }
            case 8:
            {
                int ngay, thang, nam;
                bool hopLe = false;

                do {
                    cout << "Nhập ngày: ";
                    cin >> ngay;
                    cout << "Nhập tháng: ";
                    cin >> thang;
                    cout << "Nhập năm: ";
                    cin >> nam;

                    if (ngay >= 1 && ngay <= 31 && thang >= 1 && thang <= 12) {
                        hopLe = true;
                    } else {
                        cout << "Nhập lại ngày, tháng, năm!" << endl;
                    }                  
                } while (!hopLe);
                
                if (ngay < 1){
                        --thang;
                        cout << "Ngày hôm qua là ngày: " << ngay <<endl;
                        if (thang < 12){
                            --nam;

                        }
                }
                int ngayTrongThang = soNgayCuaThang(thang, nam);
                cout << "Hôm nay là ngày : "<< ngay << endl;
                cout << "Tháng " << thang << " năm " << nam << " có " << ngayTrongThang << " ngày" << endl;
                break;
            }
            case 9:
            {
                const double gia1km = 15000; //Km đầu tiên
                const double gia2_5km = 13500; //Km thứ 2 đến 5
                const double giaTren6km = 11000; //Km thứ 6
                const double giamGiaTren120km = 0.1; //Trên 120Km

                double soKm;
                cout << "Nhập số km: ";
                cin >> soKm;

                double tongTien = 0;
                
                if (soKm <= 0) {
                    cout << "Nhập lại km" << endl;
                    return 0;
                }
                else if (soKm <= 1) {
                    tongTien = gia1km * soKm;
                }
                else if (soKm <= 5) {
                    tongTien = gia1km + gia2_5km * (soKm - 1);
                }
                else if (soKm <= 120) {
                    tongTien = gia1km + gia2_5km * 4 + giaTren6km * (soKm - 5);
                }
                else {
                    double giamGia = gia1km + gia2_5km * 4 + giaTren6km * 115;
                    tongTien = giamGia + (soKm - 120) * giaTren6km * (1 - giamGiaTren120km);
                }

                cout << "Tông tiền là: " << tongTien << " VND" << endl;
                break;
            }
            case 10:
            {
                double diemTB, diemT, diemL, diemH;
                cout << "Nhâp điểm Toán: ";
                cin >> diemT;
                cout << "Nhâp điểm Lý: ";
                cin >> diemL;
                cout << "Nhâp điểm Hóa: ";
                cin >> diemH;
                diemTB = (diemT+diemL+diemH)/3;
                cout << "Điểm TB của bạn là: " << diemTB << endl;

                int hocLuc;
                
                if (diemTB >= 9.0) {
                    hocLuc = 1; 
                } else if (diemTB >= 8.0) {
                    hocLuc = 2; 
                } else if (diemTB >= 6.5) {
                    hocLuc = 3; 
                } else if (diemTB > 5.0) {
                    hocLuc = 4; 
                } else if(diemTB <= 3.0){
                    hocLuc = 5; 
                }

                switch (hocLuc) {
                    case 1:
                        cout << "Học lực giỏi" << endl;
                        break;
                    case 2:
                        cout << "Hoc lực khá" << endl;
                        break;
                    case 3:
                        cout << "Học lực trung bình" << endl;
                        break;
                    case 4:
                        cout << "Học lực yếu" << endl;
                        break;
                    case 5:
                        cout << "Học lực kém" << endl;
                        break;
                    default:
                        cout << "Học lực yếu" << endl;
                        break;
                }
                break;
            }
            case 0:
                cout << "Thoát" << endl;
                break;
            default:
                cout << "Vui lòng chọn lại" << endl;
        }
    } while (choice != 0);

    return 0;
}
