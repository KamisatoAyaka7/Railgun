#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<string>

using namespace std;

struct information
{
    char con[2048]="";
}gcc;

void char_to_short(char *p,short *s1)
{
    *s1=*p*100;p++;
    *s1+=*p*10;p++;
    *s1+=*p;
}

void short_to_char(short s1,char *p)
{
    *p=s1/100+48;p++;
    *p=(s1%100)/10+48;p++;
    *p=s1%10+48;
}

void ls()
{
    char tmp[2];
    ifstream f1;
    f1.open("./Raigun_files/in.t",ios::in|ios::binary);
    f1.seekg(0,ios::end);
    long size=f1.tellg();
    for(long s1=0;s1<size;s1++)
    {
	f1.seekg(s1,ios::beg);
        f1.read(tmp,1);
	if(tmp[0]==0)
	{
	    cout<<'\n';
	}
	else
	{
	    tmp[0]=~tmp[0];
	    cout<<tmp[0];
	}
    }
}

void rm()
{
    short s2=0;
    char tmp1[4]="1",tmp2[512]="rm ./Railgun_files/";
    char tmp[256];
    ifstream f1;
    f1.open("./Railgun_files/in.t",ios::in|ios::binary);
    ofstream f2;
    f2.open("./Railgun_files/in1.t",ios::app|ios::binary);
    f1.seekg(0,ios::end);
    long size=f1.tellg();
    bool b=false;
    for(long l1=0;l1<size;l1++)
    {
	f1.seekg(l1,ios::beg);
	if(l1!=0)
	{
	    f1.seekg(-1,ios::cur);
	    f1.read(tmp1,1);
	    f1.seekg(1,ios::cur);
	}
	if(l1==0||tmp1[0]==0)
	{
	    f1.read(tmp,256);
	    if(0==strcmp(tmp,gcc.con))
	    {
		b=true;
		short s3=0;
                for(;tmp[s3]!='\0';s3++){}
		l1+=s3;
	    }
	}
	f1.read(tmp,1);
        f2.write(tmp,1);
    }
    f1.close();
    f2.close();
    system("rm ./Railgun_files/in.t");
    system("rename n1 n ./Railgun_files/in1.t");
    if(!b)
    {
	cout<<gcc.con<<" not found"<<endl;
	return;
    }
    for(short s1=0;gcc.con[s1]!='\0';s1++)
    {
	for(;tmp2[s2]!='\0';s2++){}
	short_to_char(~gcc.con[s1],tmp1);
	tmp2[s2]=tmp1[0];
	tmp2[s2+1]=tmp1[1];
	tmp2[s2+2]=tmp1[2];
	tmp2[s2+3]='\0';
    }
    system(tmp2);

}

void collect()
{
    char tmp[2148]="./Railgun_tools/collect ";
    short s1=0,s2=0;
    for(;tmp[s1]!='\0';s1++){}
    for(;gcc.con[s2]!='\0';s2++)
    {
	tmp[s1+s2]=gcc.con[s2];
    }
    tmp[s1+s2]='\0';
    system(tmp);
}

void release()
{
    char tmp[522]="./Railgun_tools/release ";
    short s1=0,s2=0;
    for(;tmp[s1]!='\0';s1++){}
    for(;gcc.con[s2]!='\0';s2++)
    {
	tmp[s1+s2]=gcc.con[s2];
    }
    tmp[s1+s2]='\0';
    system(tmp);
}

int main(int argc,char *argv[])
{
    char tmp[64]="./Railgun_tools/judgement ";
    if(argc==1)
    {
	cout<<"password: ";
	cin>>gcc.con;
	short s1=0,s2=0;
	for(;tmp[s1]!='\0';s1++){}
	for(;gcc.con[s2]!='\0';s2++)
	{
	    tmp[s1+s2]=gcc.con[s2];
	}
	tmp[s1+s2]='\0';
    }
    else if(argc==2)
    {
	char *p=argv[1];
	short s1=0,s2=0;
	for(;tmp[s1]!='\0';s1++){}
	for(;*(p+s2)!='\0';s2++)
	{
	    tmp[s1+s2]=*(p+s2);
	}
	tmp[s1+s2]='\0';
    }
    else
    {
	return 0;
    }
    system(tmp);
    ifstream f1;
    f1.open("./Railgun_files/tmp.t",ios::in);
    while(!f1)
    {
	usleep(10);
    }
    f1>>tmp;
    f1.close();
    if(0==strcmp(tmp,"1"))
    {
	cout<<'\n';
	while(true)
	{
	    cout<<">>> ";
	    cin>>gcc.con;
	    if(0==strcmp(gcc.con,"ls"))
	    {
		ls();
	    }
	    else if(0==strcmp(gcc.con,"rm"))
	    {
		cin>>gcc.con;
		rm();
	    }
	    else if(0==strcmp(gcc.con,"clt"))
	    {
		cin>>gcc.con;
		collect();
	    }
	    else if(0==strcmp(gcc.con,"rls"))
	    {
		cin>>gcc.con;
		release();
	    }
	    else if(0==strcmp(gcc.con,"ext"))
	    {
		return 1;
	    }
	    else
	    {
		cout<<gcc.con<<" not found"<<endl;
	    }
	}
    }
    else
    {
	return 0;
    }
    return 0;
}

