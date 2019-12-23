#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#define N 20
char flag='O'; 
char qipan [N][N];//用于储存棋盘 
int x,y;//代表棋盘的坐标
void initqipan();//棋盘的初始化
void printqipan();//打印棋盘
void pos (int x, int y);//设置光标位置
void startgame();//游戏开始
int panduan(int x,int y);//判断游戏是否产生了相应的结果
int showwhowin();//输出谁赢了
void whiteplay();//白方落子 
void balackplay();//黑方落子
void printzuobiao();//打印数字坐标
void color(int c);//用来设置输出的颜色 
 
 void color(int c) //用于设置输出的颜色 
{
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);//attribute 用来设置控制窗字体的相关颜色 

}
void pos (int x, int y)
{
	COORD pos;//表示一个字符在控制台屏幕上的坐标，左上角坐标(0,0)
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
	for(i=0;i<N;i++) //打印横行坐标 
	{
		printf("%2d",i);
	}
	for(i=0;i<N;i++)// 打印纵行坐标
	{
		pos(4,i+1);//将坐标修改之处放入循环中，实现自动换行 
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
        pos(6,1+i);//自动换行的输出的功能，代替printf("\n");
        for(j=0;j<N;j++)
            printf(" %c",qipan[i][j]);
    }	
} 
int panduan (int x,int y)
{

	int j,k,n1,n2;
	while(1)
	{
		//左上方
		printf("左斜线"); 
		n1=n2=0;
		for(j=x,k=y;j>=0&&k>=0;j--,k--)//坐标一直向左上移动1位; 
		{
			if(qipan[j][k]==flag)
			{
				n1++; 
			}
			else
				break;
		}
		//右下方	
		for(j=x,k=y;j<N&&k<N;j++,k++)//坐标一直向左上移动1位; 
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
		//右上方
		printf("右斜线");
		n1=n2=0;
		for(j=x,k=y;j<N&&k>=0;j++,k--)//坐标一直向右边上移动1位; 
		{
			if(qipan[j][k]==flag)
			{
				n1++; 
			}
			else
				break;
		}
		//左下方	
		for(j=x,k=y;j>N&&k<N;j--,k++)//坐标一直向左上移动1位; 
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
		//左
		printf("水平");
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
		//右
		for(j=x,k=y;j<N;j++)//坐标一直向左上移动1位; 
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
	
		//上
		printf("竖直");
		n1=n2=0;
		for(j=x,k=y;k>=0;k--)//坐标一直向左上移动1位; 
		{
			if(qipan[j][k]==flag)
			{
				n1++; 
			}
			else
				break;
		}
		//下	
		for(j=x,k=y;k<N;k++)//坐标一直向左上移动1位; 
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

    int overLeap=0;//1代表结束
    int leap;//用来接收谁赢了
    leap=panduan(x,y);
    if(leap==1)
    {
    	if(flag=='O')
		{
		
        	overLeap=1;
        	system("cls");
        	printqipan();
        	printf("\n白方胜利\n");
        	system("pause");
        }
    
    	else if(flag=='@')
	{
        overLeap=1;
        system("cls");
        printqipan();
        printf("\n黑方胜利\n");
        system("pause");
    	}
	}
    return overLeap;
}
void whiteplay()
{
	flag='O';
    printf("\n请白方落子，按下行与列的坐标:");
    scanf("%d%d",&x,&y);//坐标的值
    while(1)//解决一直下错子的问题
    {
        if(qipan[x][y]=='+')//下子的地方没有其他子
        {
        	
            qipan[x][y]='O';
            pos(x,y);
            color(9); 
             //解决while(1)
             break;
        }
        else
        {
            printf("您下子错误\n");
            printf("请白方落子，按下行与列的坐标:");
            scanf("%d%d",&x,&y);//坐标的值
        }

    }
    printqipan();

}
void blackplay()
{
	flag='@';
    printqipan();
    printf("\n请黑方落子，按下行与列的坐标:");
    scanf("%d%d",&x,&y);//坐标的值
        while(1)//解决一直下错子的问题
    {
        if(qipan[x][y]=='+')//下子的地方没有其他子
        {
        	color(12);
             qipan[x][y]='@';
             //解决while(1)
             break;
        }
        else
        {
            printf("您下子错误\n");
            printf("请黑方落子，按下行与列的坐标:");
        }
        scanf("%d%d",&x,&y);//坐标的值

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
        system("cls");//清理屏幕,是屏幕上的字不重复
        blackplay();
        if(showwhowin()==1)//system("pause");
             break;
        system("cls");
        printqipan();
    }
    printf("您是否重新游戏:y  or n");
    if(getch()=='n')
    {
        system("cls");
        printf("游戏结束\n");
        exit(0);//因为程序终止
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

