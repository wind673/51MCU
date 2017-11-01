#include"com.h"
//红外线
uchar word[]="Input zhe buttons"; 
uchar word1[]="The dir";


void main()
{ 
  uchar wor=0;

  inter_init();
  lcd_init();
  inf_dat[2]=0;
  while(word[wor])
  {
  wdat(word[wor]);
  wor++;
  }
  
  posi(2,1); wor=0;
   while(word1[wor])
  {
  wdat(word1[wor]);
  wor++;
  }
   
   
  while(1)
  {		
   delay200ms();
   posi(2,9);
   wdat(inf_sure);
   //用来调试找错
   /* 
   posi(2,10);
   wdat(0x30+sure);
   posi(2,13);
   for(i=0;i<3;i++)
   wdat(0x30+ero[i]);
   */
   }
}
  			


