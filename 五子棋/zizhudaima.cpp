#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#define N 20
char flag='O'; 
char qipan [N][N];//���ڴ������� 
int x,y;//�������̵�����
void initqipan();//���̵ĳ�ʼ��
void printqipan();//��ӡ����
void pos (int x, int y);//���ù��λ��
void startgame();//��Ϸ��ʼ
int panduan(int x,int y);//�ж���Ϸ�Ƿ��������Ӧ�Ľ��
int showwhowin();//���˭Ӯ��
void whiteplay();//�׷����� 
void balackplay();//�ڷ�����
void printzuobiao();//��ӡ��������
void color(int c);//���������������ɫ 
 
 void color(int c) //���������������ɫ 
{
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);//attribute �������ÿ��ƴ�����������ɫ 

}
void pos (int x, int y)
{
	COORD pos;//��ʾһ���ַ��ڿ���̨��Ļ�ϵ����꣬���Ͻ�����(0,0)
	HANDLE h;
	pos.X=x;
	pos.Y=y;
	h=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
} 
void printshuzi()
{
	int i;
	pos(6,0);
	for(i=0;i<N;i++) //��ӡ�������� 
	{
		printf("%2d",i);
	}
	for(i=0;i<N;i++)// ��ӡ��������
	{
		pos(4,i+1);//�������޸�֮������ѭ���У�ʵ���Զ����� 
		printf("%2d",i);
		
	} 
}
void initqipan()
{
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            qipan[i][j]='+';
}
void printqipan()
{
	 int i,j;
    printshuzi();
    for(i=0;i<N;i++)
    {
        pos(6,1+i);//�Զ����е�����Ĺ��ܣ�����printf("\n");
        for(j=0;j<N;j++)
            printf(" %c",qipan[i][j]);
    }	
} 
int panduan (int x,int y)
{

	int j,k,n1,n2;
	while(1)
	{
		//���Ϸ�
		printf("��б��"); 
		n1=n2=0;
		for(j=x,k=y;j>=0&&k>=0;j--,k--)//����һֱ�������ƶ�1λ; 
		{
			if(qipan[j][k]==flag)
			{
				n1++; 
			}
			else
				break;
		}
		//���·�	
		for(j=x,k=y;j<N&&k<N;j++,k++)//����һֱ�������ƶ�1λ; 
		{
			if(qipan[j][k]==flag)
			{
				n2++; 
			}
			else
				break;
		}
		if(n1+n2-1>=5)
		{
			printf("%d",n1+n2);
			return 1;
		}
		//���Ϸ�
		printf("��б��");
		n1=n2=0;
		for(j=x,k=y;j<N&&k>=0;j++,k--)//����һֱ���ұ����ƶ�1λ; 
		{
			if(qipan[j][k]==flag)
			{
				n1++; 
			}
			else
				break;
		}
		//���·�	
		for(j=x,k=y;j>N&&k<N;j--,k++)//����һֱ�������ƶ�1λ; 
		{
			if(qipan[j][k]==flag)
			{
				n2++; 
			}
			else
				break;
		}
		if(n1+n2-1>=5)
		{
			printf("%d",n1+n2);
			return 1;
		}
		//��
		printf("ˮƽ");
		n1=n2=0;
		for(j=x,k=y;j>=0;j--)//
		{
			if(qipan[j][k]==flag)
			{
				n1++; 
			}
			else
				break;
		}
		//��
		for(j=x,k=y;j<N;j++)//����һֱ�������ƶ�1λ; 
		{
			if(qipan[j][k]==flag)
			{
				n2++; 
			}
			else
				break;
		}
		if(n1+n2-1>=5)
		{
			printf("%d",n1+n2);
			return 1;
		}
	
		//��
		printf("��ֱ");
		n1=n2=0;
		for(j=x,k=y;k>=0;k--)//����һֱ�������ƶ�1λ; 
		{
			if(qipan[j][k]==flag)
			{
				n1++; 
			}
			else
				break;
		}
		//��	
		for(j=x,k=y;k<N;k++)//����һֱ�������ƶ�1λ; 
		{
			if(qipan[j][k]==flag)
			{
				n2++; 
			}
			else
				break;
		}
		if(n1+n2-1>=5)
		{
			printf("%d",n1+n2);
			return 1;
		}
			
			
	return 0; 
}
}
int showwhowin()
{

    int overLeap=0;//1�������
    int leap;//��������˭Ӯ��
    leap=panduan(x,y);
    if(leap==1)
    {
    	if(flag=='O')
		{
		
        	overLeap=1;
        	system("cls");
        	printqipan();
        	printf("\n�׷�ʤ��\n");
        	system("pause");
        }
    
    	else if(flag=='@')
	{
        overLeap=1;
        system("cls");
        printqipan();
        printf("\n�ڷ�ʤ��\n");
        system("pause");
    	}
	}
    return overLeap;
}
void whiteplay()
{
	flag='O';
    printf("\n��׷����ӣ����������е�����:");
    scanf("%d%d",&x,&y);//�����ֵ
    while(1)//���һֱ�´��ӵ�����
    {
        if(qipan[x][y]=='+')//���ӵĵط�û��������
        {
        	
            qipan[x][y]='O';
            pos(x,y);
            color(9); 
             //���while(1)
             break;
        }
        else
        {
            printf("�����Ӵ���\n");
            printf("��׷����ӣ����������е�����:");
            scanf("%d%d",&x,&y);//�����ֵ
        }

    }
    printqipan();

}
void blackplay()
{
	flag='@';
    printqipan();
    printf("\n��ڷ����ӣ����������е�����:");
    scanf("%d%d",&x,&y);//�����ֵ
        while(1)//���һֱ�´��ӵ�����
    {
        if(qipan[x][y]=='+')//���ӵĵط�û��������
        {
        	color(12);
             qipan[x][y]='@';
             //���while(1)
             break;
        }
        else
        {
            printf("�����Ӵ���\n");
            printf("��ڷ����ӣ����������е�����:");
        }
        scanf("%d%d",&x,&y);//�����ֵ

    }
    printqipan();

}
    void startgame()
{
	initqipan();
    printqipan();
    while(1)
    {
        whiteplay();
        if(showwhowin()==1)//system("pause");
             break;
        system("cls");//������Ļ,����Ļ�ϵ��ֲ��ظ�
        blackplay();
        if(showwhowin()==1)//system("pause");
             break;
        system("cls");
        printqipan();
    }
    printf("���Ƿ�������Ϸ:y  or n");
    if(getch()=='n')
    {
        system("cls");
        printf("��Ϸ����\n");
        exit(0);//��Ϊ������ֹ
    }
    if(getch()=='y')
    {
        system("cls");
        startgame();
    }

}
int main(void)
{
	startgame();

   return 0;
}

