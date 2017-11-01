#include<reg51.h> 
void main()
{
	unsigned char _bit = 1;
	while(1)
	{ 
		_bit <<= 1;
		if(_bit == 0) _bit = 1;   
		P2 = _bit;	 
	}
}






