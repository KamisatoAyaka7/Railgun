#include<iostream>
#include<fstream>

using namespace std;

struct informtion
{
    char p1[16]="",p2[16]="";
    char p3[16]="",p4[16]="";
    char filename[512]="./Railgun_files/";
}gcc;

ifstream f1;
ofstream f2;

void dishoot(char* p)
{
    char b1[16] = "", b2[16] = "";

    b1[0] = ~(*p); p += 4;
    b1[1] = ~(*p); p += 4;
    b1[2] = ~(*p); p += 4;
    b1[3] = ~(*p); p -= 11;
    b1[4] = ~(*p); p += 4;
    b1[5] = ~(*p); p += 4;
    b1[6] = ~(*p); p += 4;
    b1[7] = ~(*p); p -= 11;
    b1[8] = ~(*p); p += 4;
    b1[9] = ~(*p); p += 4;
    b1[10] = ~(*p); p += 4;
    b1[11] = ~(*p); p -= 11;
    b1[12] = ~(*p); p += 4;
    b1[13] = ~(*p); p += 4;
    b1[14] = ~(*p); p += 4;
    b1[15] = ~(*p);

    b2[15] = b1[0] ^ gcc.p4[0];
    b2[11] = b1[1] ^ gcc.p4[1];
    b2[7] = b1[2] ^ gcc.p4[2];
    b2[3] = b1[3] ^ gcc.p4[3];
    b2[14] = b1[4] ^ gcc.p4[4];
    b2[10] = b1[5] ^ gcc.p4[5];
    b2[6] = b1[6] ^ gcc.p4[6];
    b2[2] = b1[7] ^ gcc.p4[7];
    b2[13] = b1[8] ^ gcc.p4[8];
    b2[9] = b1[9] ^ gcc.p4[9];
    b2[5] = b1[10] ^ gcc.p4[10];
    b2[1] = b1[11] ^ gcc.p4[11];
    b2[12] = b1[12] ^ gcc.p4[12];
    b2[8] = b1[13] ^ gcc.p4[13];
    b2[4] = b1[14] ^ gcc.p4[14];
    b2[0] = b1[15] ^ gcc.p4[15];

    b1[10] = b2[0] ^ gcc.p3[0];
    b1[11] = b2[1] ^ gcc.p3[1];
    b1[8] = b2[2] ^ gcc.p3[2];
    b1[9] = b2[3] ^ gcc.p3[3];
    b1[14] = b2[4] ^ gcc.p3[4];
    b1[15] = b2[5] ^ gcc.p3[5];
    b1[12] = b2[6] ^ gcc.p3[6];
    b1[13] = b2[7] ^ gcc.p3[7];
    b1[2] = b2[8] ^ gcc.p3[8];
    b1[3] = b2[9] ^ gcc.p3[9];
    b1[0] = b2[10] ^ gcc.p3[10];
    b1[1] = b2[11] ^ gcc.p3[11];
    b1[6] = b2[12] ^ gcc.p3[12];
    b1[7] = b2[13] ^ gcc.p3[13];
    b1[4] = b2[14] ^ gcc.p3[14];
    b1[5] = b2[15] ^ gcc.p3[15];

    b2[1] = ~b1[0];
    b2[2] = ~b1[1];
    b2[3] = ~b1[2];
    b2[0] = ~b1[3];
    b2[5] = ~b1[4];
    b2[6] = ~b1[5];
    b2[7] = ~b1[6];
    b2[4] = ~b1[7];
    b2[9] = ~b1[8];
    b2[10] = ~b1[9];
    b2[11] = ~b1[10];
    b2[8] = ~b1[11];
    b2[13] = ~b1[12];
    b2[14] = ~b1[13];
    b2[15] = ~b1[14];
    b2[12] = ~b1[15];

    b1[4] = b2[0] ^ gcc.p2[0];
    b1[5] = b2[1] ^ gcc.p2[1];
    b1[6] = b2[2] ^ gcc.p2[2];
    b1[7] = b2[3] ^ gcc.p2[3];
    b1[8] = b2[4] ^ gcc.p2[4];
    b1[9] = b2[5] ^ gcc.p2[5];
    b1[10] = b2[6] ^ gcc.p2[6];
    b1[11] = b2[7] ^ gcc.p2[7];
    b1[12] = b2[8] ^ gcc.p2[8];
    b1[13] = b2[9] ^ gcc.p2[9];
    b1[14] = b2[10] ^ gcc.p2[10];
    b1[15] = b2[11] ^ gcc.p2[11];
    b1[0] = b2[12] ^ gcc.p2[12];
    b1[1] = b2[13] ^ gcc.p2[13];
    b1[2] = b2[14] ^ gcc.p2[14];
    b1[3] = b2[15] ^ gcc.p2[15];

    b2[2] = b1[0] ^ gcc.p1[0];
    b2[3] = b1[1] ^ gcc.p1[1];
    b2[0] = b1[2] ^ gcc.p1[2];
    b2[1] = b1[3] ^ gcc.p1[3];
    b2[6] = b1[4] ^ gcc.p1[4];
    b2[7] = b1[5] ^ gcc.p1[5];
    b2[4] = b1[6] ^ gcc.p1[6];
    b2[5] = b1[7] ^ gcc.p1[7];
    b2[10] = b1[8] ^ gcc.p1[8];
    b2[11] = b1[9] ^ gcc.p1[9];
    b2[8] = b1[10] ^ gcc.p1[10];
    b2[9] = b1[11] ^ gcc.p1[11];
    b2[14] = b1[12] ^ gcc.p1[12];
    b2[15] = b1[13] ^ gcc.p1[13];
    b2[12] = b1[14] ^ gcc.p1[14];
    b2[13] = b1[15] ^ gcc.p1[15];

    p -= 7;
    *p = ~b2[0]; p += 1;
    *p = ~b2[1]; p += 1;
    *p = ~b2[2]; p += 1;
    *p = ~b2[3]; p+=1;
    *p = ~b2[4]; p += 1;
    *p = ~b2[5]; p += 1;
    *p = ~b2[6]; p += 1;
    *p = ~b2[7]; p -=15;
    *p = ~b2[8]; p += 1;
    *p = ~b2[9]; p += 1;
    *p = ~b2[10]; p += 1;
    *p = ~b2[11]; p += 1;
    *p = ~b2[12]; p += 1;
    *p = ~b2[13]; p += 1;
    *p = ~b2[14]; p += 1;
    *p = ~b2[15]; p += 1;
}

void short_to_char(short s1,char *p)
{
    *p=s1/100+48;p++;
    *p=(s1%100)/10+48;p++;
    *p=s1%10+48;p++;
}

void init(char *p)
{
    for(short s1=0;s1<16;s1++)
    {
	gcc.p1[s1]=~(*p^gcc.p1[s1]);
	gcc.p2[s1]=~(*p^gcc.p2[s1]);
	gcc.p3[s1]=~(*p^gcc.p3[s1]);
	gcc.p4[s1]=~(*p^gcc.p4[s1]);p++;
    }
}

int main(int argc,char *argv[])
{
    char tmp[16]="";
    long s1=0;
    if(argc==3)
    {
	init(argv[1]);
        char *p=argv[2];
	for(;*p!='\0';p++)
	{
	    short_to_char(~*p,tmp);
	    for(;gcc.filename[s1]!='\0';s1++){}
	    gcc.filename[s1]=tmp[0];
	    gcc.filename[s1+1]=tmp[1];
	    gcc.filename[s1+2]=tmp[2];
	    gcc.filename[s1+3]='\0';
	}
	f1.open(gcc.filename,ios::in|ios::binary);
	f2.open(argv[2],ios::app|ios::binary);
	f1.seekg(0,ios::end);
	long size=f1.tellg();
	cout<<"file name: "<<argv[2]<<endl;
        cout<<"file size: "<<size<<endl;
        cout<<"releasing..."<<endl;
	for(s1=0;s1<size-16;s1+=16)
	{
	    f1.seekg(s1,ios::beg);
	    f1.read(tmp,16);
	    dishoot(tmp);
	    f2.write(tmp,16);
	}
	for(s1+=1;s1<size;s1++)
	{
	    f1.seekg(s1,ios::beg);
	    f1.read(tmp,1);
	    tmp[0]=~(*argv[1]^tmp[0]);
	    f2.write(tmp,1);
	}
        cout<<"released this file successfully."<<endl;
	f1.close();
	f2.close();
    }
    return 0;
}
