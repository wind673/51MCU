//红外线控制头文件





void inf_function()
{
	if(inf_sure==0xa2) inf_switch();
    if(inf_sure==0x62) inf_mode();
	if(inf_sure==0xe2) inf_voice();
	if(inf_sure==0x22) inf_start();
	if(inf_sure==0x02) inf_left();
	if(inf_sure==0x52) inf_right();
	if(inf_sure==0xd0) inf_eq();

}
