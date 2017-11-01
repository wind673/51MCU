//红外线控制

uchar inf_dat[4]={0};
uchar inf_sure=0;
uchar fcmode=1;
uchar fcmove=1;
uchar fcvol=0;
uchar fcstar=0;
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
   delay500ms();
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
   if(inf_sw==1){fcmode++;}
   if(inf_sw==2){fcmode++;inf_sw=1;}
   delay200ms();
   if(fcmode==3) fcmode=1;
}

void inf_start()
{
    
   if(inf_sure==0x22&&inf_t>2)//防止多次重写，每两次屏蔽一次
   {
   if(inf_sw==0) inf_sw=2;
   if(inf_sw==1) inf_sw=0;
   inf_t=0;
   }
   inf_t++;
   if(inf_sw==0) {fcstar=1;}
   if(inf_sw==2){ fcstar=0;inf_sw=1;}
   delay500ms();
  
}



void inf_left()
{
    
   if(inf_sure==0x02&&inf_t>1)//防止多次重写，每两次屏蔽一次
   {
   if(inf_sw==0) inf_sw=2;
   if(inf_sw==1) inf_sw=0;
   inf_t=0;
   }
   inf_t++;
   if(inf_sw==0) {fcmove--;}
   if(inf_sw==2) {fcmove--;inf_sw=1;}
   delay500ms();
   if(fcmove==0) fcmove=16;
   
}

void inf_right()
{
    
   if(inf_sure==0x52&&inf_t>1)//防止多次重写，每两次屏蔽一次
   {
   if(inf_sw==0) inf_sw=2;
   if(inf_sw==1) inf_sw=0;
   inf_t=0;
   }
   inf_t++;
   if(inf_sw==0) {fcmove++;}
   if(inf_sw==2){ fcmove++;inf_sw=1;}
   delay500ms();
   if(fcmove==17) fcmove=1;
}

void inf_vol0()
{
    
   if(inf_sure==0xd0&&inf_t>1)//防止多次重写，每两次屏蔽一次
   {
   if(inf_sw==0) inf_sw=2;
   if(inf_sw==1) inf_sw=0;
   inf_t=0;
   }
   inf_t++;
   if(inf_sw==0) {fcvol--;}
   if(inf_sw==2){fcvol--;inf_sw=1;}
   delay500ms();
}


void inf_vol1()
{
    
   if(inf_sure==0xd0&&inf_t>1)//防止多次重写，每两次屏蔽一次
   {
   if(inf_sw==0) inf_sw=2;
   if(inf_sw==1) inf_sw=0;
   inf_t=0;
   }
   inf_t++;
   if(inf_sw==0) {fcvol++;}
   if(inf_sw==2){fcvol++;inf_sw=1;}
   delay500ms();
}




void inf_voice()
{
    
   if(inf_sure==0xe2&&inf_t>1)//防止多次重写，每两次屏蔽一次
   {
   if(inf_sw==0) inf_sw=2;
   if(inf_sw==1) inf_sw=0;
   inf_t=0;
   }
   inf_t++;
   if(inf_sw==0) {;}
   if(inf_sw==2){ ;inf_sw=1;}
   delay200ms();
}


