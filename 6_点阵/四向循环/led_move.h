
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
	for(k=15;k>=0;k--)//移屏
	{
	  n=3;
	  if(w==0&&k==0 ) n=10;
	  
	  while(n--)//反复 刷几次，就可以减慢速度
	  {
       for(i=0;i<16;i++)//刷屏
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
	for(k=0;k<16;k++)//移屏
	{
	  n=3;
	  if(w==1&&k==15) n=10;
	  while(n--)//反复 刷几次，就可以减慢速度
	  {
       for(i=0;i<16;i++)//刷屏
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
 while(w<=1)//会从第二个字加到第三个字
 {
   
	for(k=0;k<16;k++)//移屏
	{
	n=3;
	 if(k==15&&w==1) n=10;
	  
	  while(n--)//反复 刷几次，就可以减慢速度
	  {
	   
       for(i=0;i<16;i++)//刷屏
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
  while(w>=0)//会从第二个字加到第三个字
  {
	for(k=15;k>=0;k--)//移屏
	{
	  n=3;
	  if(k==0&&w==0) n=10;
	  
	  while(n--)//反复 刷几次，就可以减慢速度
	  {
       for(i=0;i<16;i++)//刷屏
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
  sck=1;//上升沿 移位
  lck=1;//上升沿 输出
  //第一段数据
  for(i=0;i<8;i++)
  {
    sck=0;
	sdi=dat0&0x01;
	dat0>>=1;
	
	sck=1; 	
  
  }
 
  //第二段数据
  for(i=0;i<8;i++)
  {
    sck=0;
	sdi=dat1&0x01;
	dat1>>=1;
	 
	sck=1;	

  }
   
   //第三段数据
  for(i=0;i<8;i++)
  { 
    sck=0;
    sdi=dat2&0x01;
	dat2>>=1;
   
	sck=1;	

  }
     
   //第四段数据
  for(i=0;i<8;i++)
  {
    sck=0;
	sdi=dat3&0x01;
	dat3>>=1;
	
	sck=1;	
  }

  //并口输出
   lck=0;
   lck=1;
    

}




