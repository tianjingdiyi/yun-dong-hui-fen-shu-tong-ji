#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
using namespace std;
struct Athlete
{
	int school;    //学校编号
	int item;      //项目编号
	int rank;      //名次 
	int score;     //成绩
	char name[22]; //姓名
	char sex;      //性别
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
	cout<<"(编号为奇数的项目取前五名，得分顺序为7,5,3,2,1;编号为偶数的项目取前三名,得分顺序为5,3,2)"<<endl;
	cout<<"请输入项目，运动员姓名，性别（w/m），学校，名次"<<endl; 
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
    cout<<"打印成绩单和成绩报表："<<endl; 
    for(j=1;j<=n;j++)           //学校数目 
    {  
        ws=0;ms=0;s=0;
        cout<<"*******************************"<<endl; 
        cout<<"学校 姓名 性别 项目 名次 分数"<<endl;
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
        cout<<j<<"学校的团体总分是："<<s<<endl; 
        cout<<j<<"号学校的女子团体总分是："<<ws<<endl; 
        cout<<j<<"号学校的男子团体总分是："<<ms<<endl; 
        cout<<endl; 
    }
} 
int main() 
{ 
    Seqlist L;  
    int n,m,w;
    cout<<"请输入学校个数，男子项目以及女子项目的个数："<<endl; 
    cin>>n>>m>>w; 
    enter(&L,m,w);      //赋值操作 
    display(&L,n); 
    system("pause"); 
    return 0; 
}

