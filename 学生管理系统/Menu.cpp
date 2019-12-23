#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int   Menu(void)//兼容型菜单
{
    int i;
    system("title 学生成绩管理系统V1.0  Create By zyf");
    printf("\n\n");
    printf("             学生成绩管理系统(V1.0版本)\n");
    printf("*******************************************************************************************\n");
    printf("1.  录入一个新同学的信息                                                                  *\n");
    printf("2.  修改某个学生的基本信息                                                                *\n"); 
    printf("3.  按学号删除学生信息                                                                    *\n");
    printf("4.  将学生信息写入文件                                                                    *\n");
    printf("5.  从文件读取学生信息                                                                    *\n");
    printf("6.  按学号删除学生信息                                                                    *\n");
	printf("0.  退出程序                                                                              *\n");
    printf("*******************************************************************************************\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("*****************Please Input your choice:");
    scanf("%d", &i);
    return i;

}
int main()
{
	int i;
	i=Menu();
	printf("%d",i);
	return 0;
}
