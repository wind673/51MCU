//红外遥控
uchar inf_dat[4]={0};
uchar inf_sure=0;
uchar fcmode=0;
uchar inf_sw=1; 
uchar inf_t=1;



void inf_switch()
{
    
   if(inf_sure==0xa2&&inf_t>1)//防止多次重写，每两次屏蔽一次
   {
   if(inf_sw==0) inf_sw=2;
   if(inf_sw==1) inf_sw=0;
   inf_t=0;
   }
   //功能区
   inf_t++;
   if(inf_sw==0) {wdir(0x08);}
   if(inf_sw==2){ wdir(0x0c); inf_sw=1;}
   delay300ms();delay300ms();
}

void inf_mode()
{
    
   if(inf_sure==0x62&&inf_t>1)//防止多次重写，每两次屏蔽一次
   {
   if(inf_sw==0) inf_sw=2;
   if(inf_sw==1) inf_sw=0;
   inf_t=0;
   }
   inf_t++;
   //功能区,以后会有更多的模式
   if(inf_sw==1){fcmode=1;}
   if(inf_sw==2){fcmode=0;inf_sw=1;}
   delay300ms();
   
}

void inf_function()
{
	if(inf_sure==0xa2) inf_switch();
    if(inf_sure==0x62) inf_mode();
	

}
