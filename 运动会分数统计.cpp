#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
using namespace std;
struct Athlete
{
	int school;    //ѧУ���
	int item;      //��Ŀ���
	int rank;      //���� 
	int score;     //�ɼ�
	char name[22]; //����
	char sex;      //�Ա�
};
struct Seqlist
{
	Athlete elem[MAXSIZE];
	int last;
};
int sum(int m,int w)
{
	int Sum=0;
	for(int i=1;i<=(m+w);i++)
	{
		if(i%2==1)	Sum=Sum+5;
		if(i%2==0)	Sum=Sum+3;
	}
	return Sum;
}
void change(Athlete* e)
{
	if(e->item%2==0)
	{
		switch(e->rank)
		{
			case 1:
				e->score=5;
				break; 
			case 2:
				e->score=3;
				break;
			case 3:
				e->score=2;
				break;
		}
	}
	if(e->item%2==1) 
	{
		switch(e->rank)
		{
			case 1:
				e->score=7;
				break;
			case 2:
				e->score=5;
				break;
			case 3:
				e->score=3;
				break;
			case 4:
				e->score=2;
				break;
			case 5:
				e->score=1;
				break;
		}
	}
}
void enter( Seqlist* L,int m,int w) 
{
	int i=1;  
	L->last=sum(m,w); 
	cout<<"(���Ϊ��������Ŀȡǰ�������÷�˳��Ϊ7,5,3,2,1;���Ϊż������Ŀȡǰ����,�÷�˳��Ϊ5,3,2)"<<endl;
	cout<<"��������Ŀ���˶�Ա�������Ա�w/m����ѧУ������"<<endl; 
	for(int i=1;i<=L->last;i++)  
	{  
		cin>>L->elem[i].item>>L->elem[i].name>>L->elem[i].sex >>L->elem[i].school>>L->elem[i].rank; 
		change(& L->elem[i]);
	}  
}  
void display(Seqlist* L,int n) 
{ 
    int j,i;  
    int s=0,ms=0,ws=0;
    cout<<"��ӡ�ɼ����ͳɼ�����"<<endl; 
    for(j=1;j<=n;j++)           //ѧУ��Ŀ 
    {  
        ws=0;ms=0;s=0;
        cout<<"*******************************"<<endl; 
        cout<<"ѧУ ���� �Ա� ��Ŀ ���� ����"<<endl;
        for(i=1;i<=L->last;i++)
            if(L->elem[i].school==j) 
            {  
                cout<<"  "<<L->elem[i].school<<"    "<<L->elem[i].name<<"    "<<L->elem[i].sex<<"    "<<L->elem[i].item<<"    "<<L->elem[i].rank<<"    "<<L->elem[i].score<<endl;
                if(L->elem[i].sex=='w') 
                    ws+=L->elem[i].score; 
                if(L->elem[i].sex=='m')  
                    ms+=L->elem[i].score; 
                s=ws+ms; 
            } 
        cout<<j<<"ѧУ�������ܷ��ǣ�"<<s<<endl; 
        cout<<j<<"��ѧУ��Ů�������ܷ��ǣ�"<<ws<<endl; 
        cout<<j<<"��ѧУ�����������ܷ��ǣ�"<<ms<<endl; 
        cout<<endl; 
    }
} 
int main() 
{ 
    Seqlist L;  
    int n,m,w;
    cout<<"������ѧУ������������Ŀ�Լ�Ů����Ŀ�ĸ�����"<<endl; 
    cin>>n>>m>>w; 
    enter(&L,m,w);      //��ֵ���� 
    display(&L,n); 
    system("pause"); 
    return 0; 
}

