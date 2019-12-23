/*c语言图形编程练习 
 


*/
#include<stdio.h>
#include <windows.h> 
#include <conio.h>
int color(int c);
void getxy(int x,int y);
void textbackground(int color); 
int main(void)
{
	
   int i;
   for(i=0;i<=15;i++){
   	color(i);
   	
   	getxy(40,i);
	printf("%d是什么颜色的代码\n",i);
   }
   return 0;
}
int color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
	return 0;
}
void getxy(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
