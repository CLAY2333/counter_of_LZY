#include<iostream>
#include <math.h>
#include<vector>
#include"ConsoleOut.h"
#pragma comment (lib, "ConsoleOut.lib")
using namespace std;
#define Size 10000
#define PI 3.1415926
void NUMchucun(double[],int,char[],double[],double[]);//括号内录入函数的声明
void KUOjisuan(double[],int,double[],char[],double[],double[]);//括号内运算结果函数声明
void shu(int,char[],double[],double[],double[],double[]);//括号外的数字的存储函数声明
void cheng(int,double[],char[],double[],double[],int[]);//整个的乘法运算函数声明
void jiafa(int,double[],char[],double[],double[]);//最后的加减的运算函数声明
void graph_welcome(void)
{
	CreateSmWindow(0,0, 75,23, 12, 0, 2, 1, "Super Counter", false);
	MoveCursorTo(2, 1);
	SetTextColor(12, 1);
}
//主程序代码
int main()
{
op:
	int weizi=4;
	graph_welcome();
	char mula[Size];//用户输入的运算式
	cout<<"使用说明:1.式子前面加“s,c,t”可以执行正弦余弦正切。";
	MoveCursorTo(2, 2);
	cout<<"	   2.式子前面加“：”可以执行开方。";
	MoveCursorTo(2, 3);
	while(cin>>mula)
{
	
	double teshu[1]={0};//专门用来当特殊数
	int teshu1[1]={0};//专门当特殊数
	double KUOSUM[Size]={0};//每个括号的所有数的运算结果
	double KUONUM[Size]={0};//括号内的所有的数
	double KUOSEA[Size]={0};//括号内的乘法和除法的运算结果
	double KUO[Size]={0};//括号在字符串内的位置
	double NUM[Size]={0};//非括号的其他数字
	double SEA[Size]={0};//非括号的其他数字的乘法和除法的运算结果
	double num[Size]={0};//将char类型装换的存放的一个数组，不参加主要运算
	double sum=0,DX=0;
	int n=0,i=0,kuo=0;
	n=strlen(mula);//计算输入的长度
	mula[n]=',';//在最后一位后加一个P
	for(i=1;i<n;i++)//判断输入的算式有没有错误
	{
		if(mula[i]<39||mula[i]==44||mula[i]>58)
		{
			MoveCursorTo(2, weizi);cout<<"！！算式错误请重新输入，错误的位置为第"<<i<<"个字符,错误的第一个字符为"<<"‘"<<mula[i]<<"’";//输出错误
			weizi+=1;goto over;//终止程序
		}
	}
	for(i=0;i<=n;i++)//找到括号的位置
	{
		if(mula[i]=='('||mula[i]==')'){KUO[kuo]=i;kuo++;}
	}
	NUMchucun(KUO,kuo,mula,KUONUM,num);//将每个括号内的数单独给存储出来
	KUOjisuan(KUONUM,kuo,KUO,mula,KUOSEA,KUOSUM);//将括号内的运算结果储存到KUOSUM这个数组里面
	shu(n,mula,num,NUM,KUO,KUOSUM);//扫描非括号内的数字储存
	cheng(n,KUO,mula,SEA,NUM, teshu1);//算式的乘法
	jiafa(n,NUM,mula,SEA,teshu);//算式的加减
	for(i=0;i<= teshu1[0];i++){teshu[0]+=SEA[i];}//为了保险进行一个加减
	MoveCursorTo(2, weizi);
	weizi+=1;
	if(mula[0]==':'){teshu[0]=sqrt(teshu[0]);}//求开方
	if(mula[0]=='s'){teshu[0]=teshu[0]/180*PI;teshu[0]=sin(teshu[0]);}//求sin
	if(mula[0]=='c'){teshu[0]=teshu[0]/180*PI;teshu[0]=cos(teshu[0]);}//求cos
	if(mula[0]=='t'){teshu[0]=teshu[0]/180*PI;teshu[0]=tan(teshu[0]);}//求tan
	cout<<teshu[0]<<endl;//输出
over:
	MoveCursorTo(2, weizi);//移动光标
	weizi+=1;
	cout<<"------------------------------";
	MoveCursorTo(2, weizi);
	if(weizi==24){goto op;}//限制不出方格
	weizi+=1;

}
	return 0;
}


//录入数字的子函数
void NUMchucun(double*KUO,int kuo,char*mula,double*KUONUM,double*num)
{
	int x=0,in=0,i=0,peak=0,l=0,y=0,g=0,wwe=0,ww=0;
	for(x;x<=kuo/2;x++)
	{
		i=KUO[in]+1;
		for(i;i<=KUO[in+1];i++)
		{
			if(mula[i]=='.')//判断是否为带小数点的
			{
				ww=i;
				for(ww;ww<=KUO[in+1];ww++)//循环存储小数点后几位的函数
				{
					if(mula[ww]>47&&mula[ww]<58){num[peak]=mula[ww]-48;peak++;i++;}
					if(mula[ww]=='+'||mula[ww]=='-'||mula[ww]=='*'||mula[ww]=='/'||mula[ww]==','||mula[ww]==')'){goto nike;}
				}
			}
			if(mula[i]>47&&mula[i]<58){num[peak]=mula[i]-48;peak++;l++;}//录入小数点前几位
			if(mula[i]=='+'||mula[i]=='-'||mula[i]=='*'||mula[i]=='/'||mula[i]==','||mula[i]==')')//开始总结存入数字
			{
				wwe=l;
				for(y=0;y<peak;y++)
					{
						KUONUM[g]=num[y]*pow(10,l-1)+KUONUM[g];
						l--;
					}
				l=0;
				g++;
				peak=0;
			}
nike:;
		}
		in+=2;
	}
}



//括号内运算结果函数
void KUOjisuan(double*KUONUM,int kuo,double*KUO,char*mula,double*KUOSEA,double*KUOSUM)
{
	int x=0, in=0,q=0,i=0,sea=0,nike=0;
	double DX=0,sum=0;
	DX=KUONUM[0];//先将DX赋第一个括号的第一个数
	for(x;x<kuo/2;x++)//计算括号内的运算结果
	{
		i=KUO[in]+1;
		for(i;i<KUO[in+1];i++)//乘除的运算结果
		{	
			if(mula[i]=='+'||mula[i]=='-'){q++;DX=KUONUM[q];sea++;}
			if(mula[i]=='*'){DX=DX*KUONUM[q+1];KUONUM[q+1]=0;KUONUM[q]=0;q++;KUOSEA[sea]=DX;}
			if(mula[i]=='/'){DX=DX/KUONUM[q+1];KUONUM[q+1]=0;KUONUM[q]=0;q++;KUOSEA[sea]=DX;}
		}
		q=0;sum=KUONUM[0];
		i=KUO[in]+1;
		for(i;i<KUO[in+1];i++)//加减
		{
			if(mula[i]=='+'||mula[i]=='*'||mula[i]=='/'){sum+=KUONUM[q+1];q++;}
			if(mula[i]=='-'){sum-=KUONUM[q+1];q++;}
		}
		for(i=0;i<=sea;i++){sum+=KUOSEA[i];}//算出结果
		KUOSUM[x]=sum;//给KUOSUM这个数组
		in+=2;
		nike+=(KUO[x+1]-KUO[x])/2;
		DX=KUONUM[nike];//又将DX赋于第二个括号内的第一个数
	}
}



//括号外的数字的存储函数
void shu(int n,char*mula,double*num,double*NUM,double*KUO,double*KUOSUM)
{
	int i=0,x=0,l=0,y=0,in=0,yun=0,g=0,ww=0;
	for(i;i<=n;i++)//开始扫描出非括号内的数
	{
		if(mula[i]=='.')//
			{
				ww=i;
				for(ww;ww<=n;ww++)
				{
					if(mula[ww]>47&&mula[ww]<58){num[x]=mula[ww]-48;x++;i++;}
					if(mula[ww]=='+'||mula[ww]=='-'||mula[ww]=='*'||mula[ww]=='/'||mula[ww]==','||mula[ww]==')'){goto nike;}
				}
			}
		if(mula[i]>47&&mula[i]<58){num[x]=mula[i]-48;x++;l++;}
		if(mula[i]=='+'||mula[i]=='-'||mula[i]=='*'||mula[i]=='/'||mula[i]==',')
		{
			for(y=0;y<x;y++)
				{
				NUM[g]=num[y]*pow(10,l-1)+NUM[g];
				l--;
				}
			l=0;
			g++;
			x=0;
		}
		if(mula[i]=='('){NUM[g]=KUOSUM[yun];i=KUO[in+1];in++;yun++;g++;}//扫描到括号的时候就插入之前的运算数，并跳过
nike:;
	}
}


//整个的乘法运算函数
void cheng(int n,double*KUO,char*mula,double*SEA,double*NUM,int*teshu1)
{
	int in=0,i=0,q=0;
	teshu1[0]=0;
	double DX=NUM[0];
	for(i=0;i<n;i++)//运算括号外的的乘除运算结果
	{
		if(mula[i]=='('){i=KUO[in+1];in++;}
		if(mula[i]=='+'||mula[i]=='-'){q++;DX=NUM[q];if(SEA[teshu1[0]]!=0){teshu1[0]+=1;}}//如果第一个是没有赋值的话就不sea++
		if(mula[i]=='*'){DX=DX*NUM[q+1];NUM[q+1]=0;NUM[q]=0;q++;SEA[teshu1[0]]=DX;}
		if(mula[i]=='/'){DX=DX/NUM[q+1];NUM[q+1]=0;NUM[q]=0;q++;SEA[teshu1[0]]=DX;}
	}
}


//最后的加减的运算函数
void jiafa(int n,double*NUM,char*mula,double*SEA,double*teshu)//算式的加减
{
	int q=0,i=0,adidas=0,over=0;
	teshu[0]=NUM[0];
	for(i=0;i<n;i++)//扫描过去
	{
		if(mula[i]=='+')
		{
			for(adidas=i+1;adidas<=n;adidas++)//为了防止一个bug（PS：2-3*4）比如括号这个，减法的话会执行减去的是我
			{								  //已经归零的3，而不是这个整式子，然后就会子
				if(mula[adidas]=='*'||mula[adidas]=='/'){teshu[0]+=SEA[over];SEA[over]=0;over++;q++;goto loop;}
				if(mula[adidas]=='+'||mula[adidas]=='-'||mula[adidas]==','){teshu[0]+=NUM[q+1];q++;goto loop;}
			}
		}

		if(mula[i]=='-')
		{
			for(adidas=i+1;adidas<=n;adidas++)
			{
				if(mula[adidas]=='*'||mula[adidas]=='/'){teshu[0]-=SEA[over];SEA[over]=0;over++;q++;goto lop;}
				if(mula[adidas]=='+'||mula[adidas]=='-'||mula[adidas]==','){teshu[0]-=NUM[q+1];q++;goto lop;}
			}
		}

		if(mula[i]=='*'||mula[i]=='/'){q++;}//如果为了防止一个bug（PS：3*4-5），因为前面没有+或者-。
loop:lop:;									//所以不会执行q++然后就么办法执行到-5的命令，而是执行-4，
	}										//但是4在我前一个步就归零了，所以错误

}