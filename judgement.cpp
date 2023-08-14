#include<iostream>
#include<fstream>

using namespace std;

void mul(long *l1,long *l2,long *l3,int s1,int s2)
{
    int i1,i2;
    for(i1=0;i1<s1;i1++)
    {
	for(i2=0;i2<s2;i2++)
	{
	    *(l3+i1+i2)+=*(l1+i1)*(*(l2+i2))%10000;
	    *(l3+i1+i2+1)+=*(l1+i1)*(*(l2+i2))/10000;
	}
	for(i2=0;i2<s1+s2;i2++)
	{
	    *(l3+i2+1)+=*(l3+i2)/10000;
	    *(l3+i2)%=10000;
	}
    }
}

int main(int argc,char *argv[])
{
    if(argc==2)
    {
	long s1;
	long l1[2542490],l2[1571346],l3[971146];
	char tmp[2];
	for(s1=0;s1<8;s1++)
	{
	    l1[s1]=*(argv[1]+2*s1)*100+*(argv[1]+2*s1+1)-3232;
	}
        for(s1=7;s1>0;s1--)
	{
	    if(l1[s1]<0)
	    {
		l1[s1-1]-=1;
		l1[s1]+=10000;
	    }
	}
	long *p1=&l1[0],*p2=&l2[0],*p3=&l3[0];
	mul(p1,p1,p2,8,8);//2,16
	mul(p1,p2,p3,8,16);//3,24
	mul(p2,p3,p1,16,24);//5,40
	mul(p1,p3,p2,24,40);//8,64
	mul(p3,p2,p1,40,64);//13,104
	mul(p2,p1,p3,64,104);//21,168
	mul(p1,p3,p2,104,168);//34,272
	mul(p3,p2,p1,168,272);//55,440
	mul(p2,p1,p3,272,440);//89,712
	mul(p1,p3,p2,440,712);//144,1152
	mul(p3,p2,p1,712,1152);//233,1864
	mul(p2,p1,p3,1152,1864);//377,3016
	mul(p1,p3,p2,1864,3016);//610,4880
	mul(p3,p2,p1,3016,4880);//987,7896
	mul(p2,p1,p3,4880,7896);//1597,12776
	mul(p1,p3,p2,7896,12776);//2584,20672
	mul(p3,p2,p1,12776,20672);//4181,33448
	mul(p2,p1,p3,20672,33448);//6765,54120
	mul(p1,p3,p2,33448,54120);//10946,87568
	mul(p3,p2,p1,54120,87568);//17711,141688
	mul(p2,p1,p3,87568,141688);//28657,229256
	mul(p1,p3,p2,141688,229256);//46368,370944
	mul(p3,p2,p1,229256,370944);//75025,600200
	mul(p2,p1,p3,370944,600200);//121393,971144
	mul(p1,p3,p2,600200,971144);//196418,1571344
	mul(p3,p2,p1,971144,1571344);//317811,2542488
	long results[1271240]={};
	ifstream f1;
	f1.open("./Railgun_tools/data.t",ios::in|ios::binary);
	for(s1=0;s1<1271240;s1++)
	{
	    f1.seekg(2*s1,ios::beg);
	    f1.read(tmp,2);
	    results[s1]=tmp[0]*100+tmp[1];
	}
	f1.close();
	bool result=true;
	for(s1=0;s1<1271240;s1++)
	{
	    if(results[s1]!=l1[4+s1*2])
	    {
		result=false;
	    }
	}
	ofstream f2;
	f2.open("./Railgun_tools/tmp.t",ios::ate);
	if(result)
	{
	    f2<<"1";
	}
	else
	{
	    f2<<"0";
	}
	f2.close();
    }
}
