// File Chua cac ham dung chung cho nhieu doi tuong trong chuong trinh
#pragma once
#include <string>
#include <Windows.h>

using namespace std;

//tao gia tri ngau nhien trong mot khoang cho truoc
//Tham so start : gia tri khoi dau
//Tham so end : gia tri ket thuc
// return : gia tri ngau nhien duoc tao
int randomRange(int start, int end);


//Chuyen mot chuoi sang mot so
//Tham so line : chuoi can chuyen sang so nguyen
// return : so duoc chuyen
//Neu chuyen that bai se tra ve 0
int tryParseInt(string line);


//dua con tro ghi toi vi tri (x,y)
void gotoXY(int x, int y, HANDLE& h);