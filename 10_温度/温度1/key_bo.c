void key_8()
{
//�رվ���
		delay10ms();//����
		if(key8!=0) return;		
		inf_vo=(inf_vo+1)%2;
		light1_red=0;light2_red=0;//������� ��ʾδ�ڼ��״̬
		if(inf_vo==0){temper_alarm(1);temper_alarm(1);}
		if(inf_vo==1)	{light1_red=0;light2_red=0;temper_alarm(7);	}
		delay300ms();
}


void key_board()
{
    key_8();
}
