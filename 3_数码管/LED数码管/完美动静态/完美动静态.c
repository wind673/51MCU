#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char
unsigned char code nnum[10]={0x3f,0x06,0x5b,0x4f,0x66,
                             0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char code pnum[10]={0xc0,0xf9,0xa4,0xb0,0x99,
                             0x92,0x82,0xf8,0x80,0x90};
sbit voice=P1^4;
sbit LSA=P1^5;
sbit LSB=P1^6;
sbit LSC=P1^7;
sbit key1=P2^1;
sbit key2=P2^0;
sbit key8=P2^2;
sbit spot=P0^7;
void music(unsigned char h);
void ddisplay(unsigned int ddi,unsigned int i);
void sdisplay(unsigned int sdi);
void key();
char sw=0;
char reset=0;

void main()
{

    uint tms=0,ts=0,tm=0,th=0,td=0;//�˴�tmsΪ100ms
	uint dtms=0,dts1=0,dtm1=0,dth1=0,dtd1=0;//��λ
	uint dts2=0,dtm2=0,dth2=0,dtd2=0;//��λ
	uint di[8],i;
while(1)
{
     
	 key();
	 if(reset==1)//��λ
	 {
	 reset=0;
	 tms=0,ts=0,tm=0,th=0,td=0;//��λʱ��
	 di[1]=0;di[0]=0;//��λ��ʾ
	 di[3]=0;di[2]=0;
	 di[5]=0;di[4]=0;
	 di[7]=0;di[6]=0;dtms=0;
	 }
	 //ʱ��ģ��
	 if(sw==1)
	 {
	 tms++;
	 if(tms==40) ts++,tms=0;
	 if(ts==60) tm++,ts=0;
	 if(tm==60) th++,tm=0;
	 if(th==24) td++,th=0;
	 }
	 //���ݴ���
	 /*��λ����*/
	 dts1=ts%10;
	 dtm1=tm%10;
	 dth1=th%10;
	 dtd1=td%10;
	 /*��λ����*/
	 dts2=ts/10;
	 dtm2=tm/10;
	 dth2=th/10;
	 dtd2=td/10;
	 dtms=tms/20;
	//���ݴ��� 
	 di[1]=dtd1;di[0]=dtd2;
	 di[3]=dth1;di[2]=dth2;
	 di[5]=dtm1;di[4]=dtm2;
	 di[7]=dts1;di[6]=dts2;	 
	//��ʾ���
	for(i=0;i<8;i++)//��̬	
	ddisplay(di[i],i);
   
	 
}
    
}
void ddisplay(unsigned int ddi,unsigned int i)//��̬��ʾdynamic
{

	unsigned int j;
	
	
		switch(i)	 //λѡ��ѡ�����������ܣ�
		{
			case(0):
				LSA=0;LSB=0;LSC=0; break;//��ʾ��0λ
			case(1):
				LSA=1;LSB=0;LSC=0; break;//��ʾ��1λ
			case(2):
				LSA=0;LSB=1;LSC=0; break;//��ʾ��2λ
			case(3):
				LSA=1;LSB=1;LSC=0; break;//��ʾ��3λ
			case(4):
				LSA=0;LSB=0;LSC=1; break;//��ʾ��4λ
			case(5):
				LSA=1;LSB=0;LSC=1; break;//��ʾ��5λ
			case(6):
				LSA=0;LSB=1;LSC=1; break;//��ʾ��6λ
			case(7):
				LSA=1;LSB=1;LSC=1; break;//��ʾ��7λ	
		}
	
		if((i==1||i==3||i==5||i==7)||(ddi!=0))
		{
		 P0=nnum[ddi];//���Ͷ���
		}
		if(i==1||i==3||i==5||i==7)
		spot=1;
		j=100;						 //ɨ����ʱ���趨
		while(j--);	
		P0=0x00;//����
	

}
void key()//����
{
   uint re,mu,mus;
//��λ
   if(key8==0)
   {
   re=10000;
   while(re--);
    if(key8==0)
    {
	sw=0;
    reset=1;
	for(mus=0;mus<2;mus++)
	for(mu=7+mus;mu<9+mus;mu++)	
	music(mu); 

    }
  
   }
//��ʼ 
   if(sw==0)
   if(key1==0)
   {  
       re=10000;
       while(re--);
	   
       if(key1==0)
	   {
	   music(4);
	   music(5);
	   sw=1;
	    
	   }
   }
 
//����
   if(sw==1)
   if(key2==0)
   {  
       re=10000;
       while(re--);
       if(key2==0)
	   {
	   sw=0;
	   music(6);
	   music(7);
	   music(6);
	  
	   }
   }
   
   
   
}
	


void music(unsigned char h)
 {
 int mu,del;
 for(mu=0;mu<80;mu++)
   {
   del=45*h;
    while(del--);
   voice=0;
    del=5*h;
    while(del--);
   voice=1; 
   }  
 }

