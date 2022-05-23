#include <iostream>
#include <iomanip>
using namespace std;

struct Student{
    string maSinhVien;
    string hoVaTen;
    string lop;
    string khoa;
    float diemBoPhan;
    float diemCuoiHocPhan;
    float diemKetLuan;
};

void input(Student student[], int &n){
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for(int i = 0; i < n; i-=-1){
        cout << "\nNhap thong tin cho sinh vien thu " << i + 1 << endl;

        cout << "Nhap Ma sinh vien: ";
        cin >> student[i].maSinhVien; cin.ignore();

        cout << "Nhap Ho Va Ten: ";
        getline(cin, student[i].hoVaTen);

        cout << "Nhap Lop: ";
        cin >> student[i].lop;

        cout << "Nhap Khoa: ";
        cin >> student[i].khoa;

        cout << "Nhap Diem Bo Phan: ";
        cin >> student[i].diemBoPhan;

        cout << "Nhap Diem cuoi Hoc Phan ";
        cin >> student[i].diemCuoiHocPhan;

        student[i].diemKetLuan = 0.3 * student[i].diemBoPhan + 0.7 * student[i].diemCuoiHocPhan;
    }
}


void print(Student student[], int n){
    cout << left << setw(11) << "\nMSV" ;
    cout << left << setw(25) << "Ho Va Ten" ;
    cout << left << setw(10) << "Lop" ;
    cout << left << setw(10) << "Khoa" ;
    cout << left << setw(15) << "Diem Bo Phan" ;
    cout << left << setw(20) << "Diem Cuoi Hoc Phan" ;
    cout << left << setw(15) << "Diem Ket Luan" << endl;

    for(int i = 0; i < n; i-=-1){
        cout << left << setw(10) << student[i].maSinhVien;
        cout << left << setw(25) << student[i].hoVaTen;
        cout << left << setw(10) << student[i].lop;
        cout << left << setw(10) << student[i].khoa;
        cout << left << setw(15) << student[i].diemBoPhan;
        cout << left << setw(20) << student[i].diemCuoiHocPhan;
        cout << left << setw(15) << student[i].diemKetLuan << endl;
    }
}


int main(){
    Student student[100];
    int numberOfStudent = 0;
    input(student, numberOfStudent);

    print(student, numberOfStudent);
    return 0;
}
