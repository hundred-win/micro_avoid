#include "stm32f10x.h"
#include "microsonic.h"
#include "pwm.h"
#include "Delay.h"
#include "turn.h"
//调参的说法主要是，几个依靠延时来实现的旋转角度统一就行
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
			delay_ms(250);		//这个地方的延时是等超声波模块收到回波，这个时候就转向，对测距有很大影响
			R_temp = right_detection();
			delay_ms(250);
			if(L_temp<200 && R_temp<200)//前面全是障碍，就往一边转一定方向,实际上需要达到掉头的作用
			{
				car_spin_left(100);		//实际上是要掉头的意思
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



