#include<iostream>
#include <math.h>
#include<vector>
#include"ConsoleOut.h"
#pragma comment (lib, "ConsoleOut.lib")
using namespace std;
#define Size 10000
#define PI 3.1415926
void NUMchucun(double[],int,char[],double[],double[]);//������¼�뺯��������
void KUOjisuan(double[],int,double[],char[],double[],double[]);//��������������������
void shu(int,char[],double[],double[],double[],double[]);//����������ֵĴ洢��������
void cheng(int,double[],char[],double[],double[],int[]);//�����ĳ˷����㺯������
void jiafa(int,double[],char[],double[],double[]);//���ļӼ������㺯������
void graph_welcome(void)
{
	CreateSmWindow(0,0, 75,23, 12, 0, 2, 1, "Super Counter", false);
	MoveCursorTo(2, 1);
	SetTextColor(12, 1);
}
//���������
int main()
{
op:
	int weizi=4;
	graph_welcome();
	char mula[Size];//�û����������ʽ
	cout<<"ʹ��˵��:1.ʽ��ǰ��ӡ�s,c,t������ִ�������������С�";
	MoveCursorTo(2, 2);
	cout<<"	   2.ʽ��ǰ��ӡ���������ִ�п�����";
	MoveCursorTo(2, 3);
	while(cin>>mula)
{
	
	double teshu[1]={0};//ר��������������
	int teshu1[1]={0};//ר�ŵ�������
	double KUOSUM[Size]={0};//ÿ�����ŵ���������������
	double KUONUM[Size]={0};//�����ڵ����е���
	double KUOSEA[Size]={0};//�����ڵĳ˷��ͳ�����������
	double KUO[Size]={0};//�������ַ����ڵ�λ��
	double NUM[Size]={0};//�����ŵ���������
	double SEA[Size]={0};//�����ŵ��������ֵĳ˷��ͳ�����������
	double num[Size]={0};//��char����װ���Ĵ�ŵ�һ�����飬���μ���Ҫ����
	double sum=0,DX=0;
	int n=0,i=0,kuo=0;
	n=strlen(mula);//��������ĳ���
	mula[n]=',';//�����һλ���һ��P
	for(i=1;i<n;i++)//�ж��������ʽ��û�д���
	{
		if(mula[i]<39||mula[i]==44||mula[i]>58)
		{
			MoveCursorTo(2, weizi);cout<<"������ʽ�������������룬�����λ��Ϊ��"<<i<<"���ַ�,����ĵ�һ���ַ�Ϊ"<<"��"<<mula[i]<<"��";//�������
			weizi+=1;goto over;//��ֹ����
		}
	}
	for(i=0;i<=n;i++)//�ҵ����ŵ�λ��
	{
		if(mula[i]=='('||mula[i]==')'){KUO[kuo]=i;kuo++;}
	}
	NUMchucun(KUO,kuo,mula,KUONUM,num);//��ÿ�������ڵ����������洢����
	KUOjisuan(KUONUM,kuo,KUO,mula,KUOSEA,KUOSUM);//�������ڵ����������浽KUOSUM�����������
	shu(n,mula,num,NUM,KUO,KUOSUM);//ɨ��������ڵ����ִ���
	cheng(n,KUO,mula,SEA,NUM, teshu1);//��ʽ�ĳ˷�
	jiafa(n,NUM,mula,SEA,teshu);//��ʽ�ļӼ�
	for(i=0;i<= teshu1[0];i++){teshu[0]+=SEA[i];}//Ϊ�˱��ս���һ���Ӽ�
	MoveCursorTo(2, weizi);
	weizi+=1;
	if(mula[0]==':'){teshu[0]=sqrt(teshu[0]);}//�󿪷�
	if(mula[0]=='s'){teshu[0]=teshu[0]/180*PI;teshu[0]=sin(teshu[0]);}//��sin
	if(mula[0]=='c'){teshu[0]=teshu[0]/180*PI;teshu[0]=cos(teshu[0]);}//��cos
	if(mula[0]=='t'){teshu[0]=teshu[0]/180*PI;teshu[0]=tan(teshu[0]);}//��tan
	cout<<teshu[0]<<endl;//���
over:
	MoveCursorTo(2, weizi);//�ƶ����
	weizi+=1;
	cout<<"------------------------------";
	MoveCursorTo(2, weizi);
	if(weizi==24){goto op;}//���Ʋ�������
	weizi+=1;

}
	return 0;
}


//¼�����ֵ��Ӻ���
void NUMchucun(double*KUO,int kuo,char*mula,double*KUONUM,double*num)
{
	int x=0,in=0,i=0,peak=0,l=0,y=0,g=0,wwe=0,ww=0;
	for(x;x<=kuo/2;x++)
	{
		i=KUO[in]+1;
		for(i;i<=KUO[in+1];i++)
		{
			if(mula[i]=='.')//�ж��Ƿ�Ϊ��С�����
			{
				ww=i;
				for(ww;ww<=KUO[in+1];ww++)//ѭ���洢С�����λ�ĺ���
				{
					if(mula[ww]>47&&mula[ww]<58){num[peak]=mula[ww]-48;peak++;i++;}
					if(mula[ww]=='+'||mula[ww]=='-'||mula[ww]=='*'||mula[ww]=='/'||mula[ww]==','||mula[ww]==')'){goto nike;}
				}
			}
			if(mula[i]>47&&mula[i]<58){num[peak]=mula[i]-48;peak++;l++;}//¼��С����ǰ��λ
			if(mula[i]=='+'||mula[i]=='-'||mula[i]=='*'||mula[i]=='/'||mula[i]==','||mula[i]==')')//��ʼ�ܽ��������
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



//����������������
void KUOjisuan(double*KUONUM,int kuo,double*KUO,char*mula,double*KUOSEA,double*KUOSUM)
{
	int x=0, in=0,q=0,i=0,sea=0,nike=0;
	double DX=0,sum=0;
	DX=KUONUM[0];//�Ƚ�DX����һ�����ŵĵ�һ����
	for(x;x<kuo/2;x++)//���������ڵ�������
	{
		i=KUO[in]+1;
		for(i;i<KUO[in+1];i++)//�˳���������
		{	
			if(mula[i]=='+'||mula[i]=='-'){q++;DX=KUONUM[q];sea++;}
			if(mula[i]=='*'){DX=DX*KUONUM[q+1];KUONUM[q+1]=0;KUONUM[q]=0;q++;KUOSEA[sea]=DX;}
			if(mula[i]=='/'){DX=DX/KUONUM[q+1];KUONUM[q+1]=0;KUONUM[q]=0;q++;KUOSEA[sea]=DX;}
		}
		q=0;sum=KUONUM[0];
		i=KUO[in]+1;
		for(i;i<KUO[in+1];i++)//�Ӽ�
		{
			if(mula[i]=='+'||mula[i]=='*'||mula[i]=='/'){sum+=KUONUM[q+1];q++;}
			if(mula[i]=='-'){sum-=KUONUM[q+1];q++;}
		}
		for(i=0;i<=sea;i++){sum+=KUOSEA[i];}//������
		KUOSUM[x]=sum;//��KUOSUM�������
		in+=2;
		nike+=(KUO[x+1]-KUO[x])/2;
		DX=KUONUM[nike];//�ֽ�DX���ڵڶ��������ڵĵ�һ����
	}
}



//����������ֵĴ洢����
void shu(int n,char*mula,double*num,double*NUM,double*KUO,double*KUOSUM)
{
	int i=0,x=0,l=0,y=0,in=0,yun=0,g=0,ww=0;
	for(i;i<=n;i++)//��ʼɨ����������ڵ���
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
		if(mula[i]=='('){NUM[g]=KUOSUM[yun];i=KUO[in+1];in++;yun++;g++;}//ɨ�赽���ŵ�ʱ��Ͳ���֮ǰ����������������
nike:;
	}
}


//�����ĳ˷����㺯��
void cheng(int n,double*KUO,char*mula,double*SEA,double*NUM,int*teshu1)
{
	int in=0,i=0,q=0;
	teshu1[0]=0;
	double DX=NUM[0];
	for(i=0;i<n;i++)//����������ĵĳ˳�������
	{
		if(mula[i]=='('){i=KUO[in+1];in++;}
		if(mula[i]=='+'||mula[i]=='-'){q++;DX=NUM[q];if(SEA[teshu1[0]]!=0){teshu1[0]+=1;}}//�����һ����û�и�ֵ�Ļ��Ͳ�sea++
		if(mula[i]=='*'){DX=DX*NUM[q+1];NUM[q+1]=0;NUM[q]=0;q++;SEA[teshu1[0]]=DX;}
		if(mula[i]=='/'){DX=DX/NUM[q+1];NUM[q+1]=0;NUM[q]=0;q++;SEA[teshu1[0]]=DX;}
	}
}


//���ļӼ������㺯��
void jiafa(int n,double*NUM,char*mula,double*SEA,double*teshu)//��ʽ�ļӼ�
{
	int q=0,i=0,adidas=0,over=0;
	teshu[0]=NUM[0];
	for(i=0;i<n;i++)//ɨ���ȥ
	{
		if(mula[i]=='+')
		{
			for(adidas=i+1;adidas<=n;adidas++)//Ϊ�˷�ֹһ��bug��PS��2-3*4��������������������Ļ���ִ�м�ȥ������
			{								  //�Ѿ������3�������������ʽ�ӣ�Ȼ��ͻ���
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

		if(mula[i]=='*'||mula[i]=='/'){q++;}//���Ϊ�˷�ֹһ��bug��PS��3*4-5������Ϊǰ��û��+����-��
loop:lop:;									//���Բ���ִ��q++Ȼ���ô�취ִ�е�-5���������ִ��-4��
	}										//����4����ǰһ�����͹����ˣ����Դ���

}