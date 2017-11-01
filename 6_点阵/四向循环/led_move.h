
sbit sck=P3^6;
sbit lck=P3^5;
sbit sdi=P3^4;
void leftch();
void rightch();
void upch();
void downch();
void send(int dat0,int dat1,int dat2,int dat3);




void rightch()
{
  char i,k,n,w=1;
  while(w>=0)
  {
	for(k=15;k>=0;k--)//����
	{
	  n=3;
	  if(w==0&&k==0 ) n=10;
	  
	  while(n--)//���� ˢ���Σ��Ϳ��Լ����ٶ�
	  {
       for(i=0;i<16;i++)//ˢ��
	   {
	    send(~hang[i][1],~hang[i][0],landst[w][(i+k)*2+1],landst[w][(i+k)*2]);
	   }
	  }
	} 
   w--;
  }

}

void leftch()
{
  char i,k,n,w=0;
  while(w<=1)
  {
	for(k=0;k<16;k++)//����
	{
	  n=3;
	  if(w==1&&k==15) n=10;
	  while(n--)//���� ˢ���Σ��Ϳ��Լ����ٶ�
	  {
       for(i=0;i<16;i++)//ˢ��
	   {
	    send(~hang[i][1],~hang[i][0],landst[w][(i+k)*2+1],landst[w][(i+k)*2]);
	   }
	  }
	} 
   w++;
  }

}


void upch()
{

    char i,k,n,w=0;
 while(w<=1)//��ӵڶ����ּӵ���������
 {
   
	for(k=0;k<16;k++)//����
	{
	n=3;
	 if(k==15&&w==1) n=10;
	  
	  while(n--)//���� ˢ���Σ��Ϳ��Լ����ٶ�
	  {
	   
       for(i=0;i<16;i++)//ˢ��
	   {
	    send(~portst[w][(i+k)*2+1],~portst[w][(i+k)*2],hang[i][1],hang[i][0]);
	   }
	  }
	} 
	 w++;
 }
}


void downch()
{

   char i,k,n,w=1;
  while(w>=0)//��ӵڶ����ּӵ���������
  {
	for(k=15;k>=0;k--)//����
	{
	  n=3;
	  if(k==0&&w==0) n=10;
	  
	  while(n--)//���� ˢ���Σ��Ϳ��Լ����ٶ�
	  {
       for(i=0;i<16;i++)//ˢ��
	   {
	    send(~portst[w][(i+k)*2+1],~portst[w][(i+k)*2],hang[i][1],hang[i][0]);
	   }
	  }
	} 
   w--;
  }
}





void send(int dat0,int dat1,int dat2,int dat3)
{

  unsigned char i;
  sck=1;//������ ��λ
  lck=1;//������ ���
  //��һ������
  for(i=0;i<8;i++)
  {
    sck=0;
	sdi=dat0&0x01;
	dat0>>=1;
	
	sck=1; 	
  
  }
 
  //�ڶ�������
  for(i=0;i<8;i++)
  {
    sck=0;
	sdi=dat1&0x01;
	dat1>>=1;
	 
	sck=1;	

  }
   
   //����������
  for(i=0;i<8;i++)
  { 
    sck=0;
    sdi=dat2&0x01;
	dat2>>=1;
   
	sck=1;	

  }
     
   //���Ķ�����
  for(i=0;i<8;i++)
  {
    sck=0;
	sdi=dat3&0x01;
	dat3>>=1;
	
	sck=1;	
  }

  //�������
   lck=0;
   lck=1;
    

}




