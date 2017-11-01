//温度功能








void temper_compare()
{
	int temp1,temp2,temp_max,temp_min;
	temp1=hundred1*10000+temper1_h*1000+temper1_l*100+temper1_0h*10+temper1_0l;
	temp2=hundred2*10000+temper2_h*1000+temper2_l*100+temper2_0h*10+temper2_0l;
	temp_max=temper_limit[0][0]*1000+temper_limit[0][1]*100+temper_limit[0][2]*10+temper_limit[0][3];
	temp_min=temper_limit[1][0]*1000+temper_limit[1][1]*100+temper_limit[1][2]*10+temper_limit[1][3];
	if(temp1>=temp_max||temp1<=temp_min) {warn_sw1=1;light1_gre=1;}
	if(temp2>=temp_max||temp2<=temp_min) {warn_sw2=1;light2_gre=1;}
	if(temp1<temp_max&&temp1>temp_min) {warn_sw1=0;light1_gre=0;}
	if(temp2<temp_max&&temp2>temp_min) {warn_sw2=0;light2_gre=0;}
	
}


	
void temper_alarm(uchar h)
{
 int mu,del;
 
  if(inf_vo==0)
 { 
	if(warn_sw1==1)light1_red=0;
  if(warn_sw2==1)light2_red=0;//警告时制造出闪烁的红灯状态
 }
   
 
 for(mu=0;mu<150;mu++)
 {
  del=45*h;
  while(del--);
  voice=0;
  del=5*h;
  while(del--);
  voice=1;
 } 
 

 if(inf_vo==1)
 {
  if(warn_sw1==1)light1_red=1;
  if(warn_sw2==1)light2_red=1;//警告时制造出闪烁的红灯状态
 
 }
   
   
}
   

void light()
{

	if(inf_vo==0){ light1_red=1;light2_red=1;}
	if(inf_vo==1){ light1_red=0;light2_red=0;}//若关闭自动模式则亮红灯警告
  
	

}









void temper_warn()
{
	temper_compare();
	if(warn_sw1==0&&warn_sw2==0) return;
	if(warn_sw1==1){temper_alarm(2);}
	if(warn_sw2==1){temper_alarm(4);}
	
}







