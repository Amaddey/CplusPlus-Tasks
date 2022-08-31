#include<iostream>
//#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;

struct Point
{
    int x,y;
};

struct Rectangle
{
    int a, b;
    Point point;
};

Rectangle Init(){
    Rectangle rec;
    cout << "Enter an a :" << endl;
    cin >> rec.a;
    cout << "Enter an b :" << endl;
    cin >> rec.b;
    cout << "Enter an position x :" << endl;
    cin >> rec.point.x;
    cout << "Enter an position y : " << endl;
    cin >> rec.point.y;

    return rec;
}


void ShowR(Rectangle rec) {
    for (int i = 0; i < rec.a; i++)
    {
        for (int i = 0; i < rec.b; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}

//void MoveRec(Rectangle &rec) {
//    cin >> rec.point.x;
//    cin >> rec.point.y;
//    COORD coord_pos;
//    HANDLE headle_pos = GetStdHandle(STD_OUTPUT_HANDLE);
//    coord_pos.X = point.x;
//    coord_pos.Y = rec.point.y;
//    SetConsoleCursorPosition(headle_pos, coord_pos);
//}




int main()
{
    setlocale(LC_ALL,"Russian");
    srand((time(0)));

    double Res(Point p1, Point p2) {
        return (sqrt(pow(p2.x - p1.y, 2) + pow(p2.y - p1.y, 2)));
    }

    Rectangle R = Init();
    /*MoveRec(R);*/
    ShowR(R);
   
    
    Point p1{ 1,1 };
    Point p2{ 2,2 };
    cout << Res(p1, p2);
   
    
    return 0;
}


