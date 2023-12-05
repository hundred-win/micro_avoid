#include "stm32f10x.h"
#include "microsonic.h"
#include "pwm.h"
#include "Delay.h"
#include "turn.h"
//���ε�˵����Ҫ�ǣ�����������ʱ��ʵ�ֵ���ת�Ƕ�ͳһ����
int main()
{
	int Q_temp,L_temp,R_temp;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	microsonic_init();
	pwm_init();
	turn_init();
	while(1)
	{
		Q_temp = front_detection();
		if(Q_temp>0 && Q_temp<200)
		{
			car_back(60);
			delay_ms(500);
			car_brake();
			
			L_temp = left_detection();
			delay_ms(250);		//����ط�����ʱ�ǵȳ�����ģ���յ��ز������ʱ���ת�򣬶Բ���кܴ�Ӱ��
			R_temp = right_detection();
			delay_ms(250);
			if(L_temp<200 && R_temp<200)//ǰ��ȫ���ϰ�������һ��תһ������,ʵ������Ҫ�ﵽ��ͷ������
			{
				car_spin_left(100);		//ʵ������Ҫ��ͷ����˼
				delay_ms(400);
			}
			else if(L_temp>R_temp)
			{
				car_spin_left(100);
				delay_ms(300);
			}
			else
			{
				car_spin_right(100);
				delay_ms(300);
			}
		}	
		else
		{
			car_run(60);//10.25.22:07  yuan
			delay_ms(10);
		}
	}
}



