/*
 * PWM.c
 *
 *  Created on: Jan 26, 2021
 *
 */


#include "PWM.h"

/**
 * inits the PWM for the RGB led on the hifive1 revb board
 */
void init_PWM()
{
	IOF_EN |=(1<<19)|(1<<21)|(1<<22); //we only enable the RGB LED pins
									  //PIN 20 can also be enabled for PWM
	IOF_SEL |= (1<<19)|(1<<21)|(1<<22);
	PWM_1_COUNT = (1<<16)-1; //the max value the PWM will count to
							 //max 30 bits long
	PWM_1_CONFIG =	(1<<9)| //reset to zero after match
					(1<<12); // PWM always on
}

/**
 * set the PWM value for a selected PWM output
 * @select_output: the output you which the change the PWM value of
 * @value: the requested output value between 0 and 2^16-1 (65535)
 */
void set_PWM_1(int select_output,int value)
{
	switch(select_output)
	{
	case 0:
		PWM_1_COMP_0 = value;
		break;
	case 1:
		PWM_1_COMP_1 = value;
		break;
	case 2:
		PWM_1_COMP_2 = value;
		break;
	case 3:
		PWM_1_COMP_3 = value;
		break;
	default:
		break;
	}

}
