#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int   Menu(void)//�����Ͳ˵�
{
    int i;
    system("title ѧ���ɼ�����ϵͳV1.0  Create By zyf");
    printf("\n\n");
    printf("             ѧ���ɼ�����ϵͳ(V1.0�汾)\n");
    printf("*******************************************************************************************\n");
    printf("1.  ¼��һ����ͬѧ����Ϣ                                                                  *\n");
    printf("2.  �޸�ĳ��ѧ���Ļ�����Ϣ                                                                *\n"); 
    printf("3.  ��ѧ��ɾ��ѧ����Ϣ                                                                    *\n");
    printf("4.  ��ѧ����Ϣд���ļ�                                                                    *\n");
    printf("5.  ���ļ���ȡѧ����Ϣ                                                                    *\n");
    printf("6.  ��ѧ��ɾ��ѧ����Ϣ                                                                    *\n");
	printf("0.  �˳�����                                                                              *\n");
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
