/*���ڽṹ�����鸳ֵ������ο�https://blog.csdn.net/ginwafts/article/details/80858232*/ 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
struct grade
{
	char subject[10];
	int score;
	
};
struct studentsym 
{
	int num;
	char name[4];
	char sex;
	struct grade s[3];
	

}; 
int main(void)
{
	//struct studentsym test={000,"zyf",'n',{"english"}}; 
	struct studentsym test[20]; 
	test[0].num=000;
	strcpy(test[0].name, "zyf");
	test[0].sex='n';
	strcpy(test[0].s[0].subject,"english");
	test[0].s[0].score=90;
	printf("%sѧ���ǣ�%d,�Ա���%c,��Ŀ�ǣ�%s�÷��ǣ�%d",test[0].name,test[0].num,test[0].sex,test[0].s[0].subject,test[0].s[0].score);
} 


