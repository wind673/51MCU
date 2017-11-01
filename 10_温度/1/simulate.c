//Ä£ÄâÎÂ¶ÈÊä³ö

void temper_simu()
{
  temper1_l++;
	temper2_l++;
  temper1_0l=(temper1_0l*temper1_h+temper1_l)%9;
  temper1_0h=(temper1_0l*temper1_h)%8;
  temper1_l=(temper1_0l+temper1_l)%7;
  temper1_h=(temper1_0l*temper1_h+temper1_l)%4;
	
	temper2_0l=(temper2_0l*temper2_h+temper2_l)%8;
  temper2_0h=(temper2_0l+temper2_l)%7;
  temper2_l=(temper2_0l*temper2_h)%6+3;
  temper2_h=(temper2_h+temper2_l)%4;
  
}