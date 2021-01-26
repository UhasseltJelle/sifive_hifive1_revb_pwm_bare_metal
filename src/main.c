#include "PWM.h"

int main() {

    init_PWM();
    int strenght = 0;
	while(1)
	{
		if(strenght >= (1<<16)) strenght = 0;
		set_PWM_1(PWM_LED_R,strenght);
		set_PWM_1(PWM_LED_G,strenght);
		set_PWM_1(PWM_LED_B,strenght);
		strenght++;
		for(int i=0;i<100;i++);
	}
	return 0;
}

