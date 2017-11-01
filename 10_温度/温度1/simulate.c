//Ä£ÄâÎÂ¶ÈÊä³ö

//////////////////////////////////////////////////////////////////




void temper_simu()
{
  
	
	
 /*
  temper1_0l++;temper2_0l++;
  if(temper1_0l==6)
  {temper1_0l+=3;}
  if(temper1_0l>8) temper1_0l=9;
  if(temper1_0l==9)
  {temper1_0h++;temper1_0l=0;}
	if(temper1_0h==9)
  {temper1_l++;temper1_0h=0;}
  if(temper1_l==9)
  {temper1_h++;temper1_l=0;}
*/
  if(temper2_0l==4)
  {temper2_0l+=1;}
  if(temper2_0l>8) temper2_0l=9;
 
  if(temper2_0l==9)
  {temper2_0h++;temper2_0l=0;}
	if(temper2_0h==9)
  {temper2_l++;temper2_0h=0;}
  if(temper2_l==9)
  {temper2_h++;temper2_l=0;}
 
	if(temper1_h==4||temper2_h==4)
  {temper1_h=3;temper2_h=2;}
	

}