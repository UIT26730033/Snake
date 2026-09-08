#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
using namespace std;

#define MINX 2
#define MINY 2
#define MAXX 35
#define MAXY 20

void gotoxy( int column, int line );
struct Point{
    int x,y;
};
class CONRAN{
public:
    struct Point A[100];
    int DoDai;
    CONRAN(){
        DoDai = 3;
        A[0].x = 10; A[0].y = 10;
        A[1].x = 11; A[1].y = 10;
        A[2].x = 12; A[2].y = 10;
    }
    void Ve(Point Qua){
        for (int i = 0; i < DoDai; i++){
            gotoxy(A[i].x,A[i].y);
            cout<<"X";
        }
        gotoxy(Qua.x,Qua.y);
        cout<<"*";
    }
    void DiChuyen(int Huong, Point& Qua){
        for (int i = DoDai-1; i>0;i--)
            A[i] = A[i-1];
        if (Huong==0) A[0].x = A[0].x + 1;
        if (Huong==1) A[0].y = A[0].y + 1;
        if (Huong==2) A[0].x = A[0].x - 1;
        if (Huong==3) A[0].y = A[0].y - 1;

        if(A[0].x == Qua.x && A[0].y == Qua.y){
            DoDai++;
            Qua.x = rand()%(MAXX - MINX) + MINX;
            Qua.y = rand()%(MAXY - MINY) + MINY;
        }
    }

     bool KiemTraThua(){
        if (A[0].x <= MINX || A[0].x >= MAXX || A[0].y <= MINY || A[0].y >= MAXY)
            return true;
        for (int i = 1; i < DoDai; i++)
            if (A[0].x == A[i].x && A[0].y == A[i].y)
                return true;
        return false;
    }
};


void VeKhung(){
    for (int i = MINX ; i<=MAXX ; i++)
        for (int j = MINY ; j<=MAXY ; j++)
            if ((i==MINX) || (i==MAXX) || (j==MINY) || (j==MAXY)){
                gotoxy(i,j);
                printf("+");
            }
}

int main()
{
    CONRAN r;
    Point Qua;
    srand((int)time(0));
    Qua.x = rand()%(MAXX - MINX) + MINX;
    Qua.y = rand()%(MAXY - MINY) + MINY;    
    int Huong = 0;
    char t;

    while (1){
        if (kbhit()){
            t = getch();
            if (t=='a') Huong = 2;
            if (t=='w') Huong = 3;
            if (t=='d') Huong = 0;
            if (t=='x') Huong = 1;
        }
        system("cls");
        VeKhung();
        r.Ve(Qua);
        r.DiChuyen(Huong, Qua);   
        
         if (r.KiemTraThua()){
            gotoxy(MINX + 8, (MINY + MAXY) / 2);
            cout << "GAME OVER!";
            gotoxy(MINX + 2, (MINY + MAXY) / 2 + 1);
            cout << "Bam phim bat ky de thoat...";
            getch();
            break;
        }
        
        Sleep(300);
    }

    return 0;
}


void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }
