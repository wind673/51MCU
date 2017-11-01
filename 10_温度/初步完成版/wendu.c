
void zhaochi_main()		 
{	
	EA=1;
	ET0=1;
	ET1=1;
	TMOD=0X11;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	TH1=(65536-5)/256;
	TL1=(65536-5)%256;
	 
	
}
void time0() interrupt 1		 
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	hold++;
}
void time1() interrupt 3		
{
	TH1=(65536-5)/256;
	TL1=(65536-5)%256;
	ma++;
}