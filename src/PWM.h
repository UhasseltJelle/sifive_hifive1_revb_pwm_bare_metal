/*
 * PWM.h
 *
 *  Created on: Jan 26, 2021
 *
 */

#ifndef PWM_H_
#define PWM_H_

#define PWM_0_BASE_ADDRESS 0x10015000
#define PWM_1_BASE_ADDRESS 0x10025000
#define PWM_2_BASE_ADDRESS 0x10035000

#define PWM_1_CONFIG_ADDRESS PWM_1_BASE_ADDRESS
#define PWM_1_CONFIG *(int*)PWM_1_CONFIG_ADDRESS

#define PWM_1_COUNT_ADDRESS (PWM_1_BASE_ADDRESS + 0x08)
#define PWM_1_COUNT *(int*)PWM_1_COUNT_ADDRESS

#define PWM_1_SCALED_ADDRESS (PWM_1_BASE_ADDRESS + 0x10)
#define PWM_1_SCALED *(int*)PWM_1_SCALED_ADDRESS

#define PWM_1_COMP_0_ADDRESS (PWM_1_BASE_ADDRESS + 0x20)
#define PWM_1_COMP_0 *(int*)PWM_1_COMP_0_ADDRESS

#define PWM_1_COMP_1_ADDRESS (PWM_1_BASE_ADDRESS + 0x24)
#define PWM_1_COMP_1 *(int*)PWM_1_COMP_1_ADDRESS

#define PWM_1_COMP_2_ADDRESS (PWM_1_BASE_ADDRESS + 0x28)
#define PWM_1_COMP_2 *(int*)PWM_1_COMP_2_ADDRESS

#define PWM_1_COMP_3_ADDRESS (PWM_1_BASE_ADDRESS + 0x2c)
#define PWM_1_COMP_3 *(int*)PWM_1_COMP_3_ADDRESS

#define PWM_LED_G 1
#define PWM_LED_B 2
#define PWM_LED_R 3

#define baseAdressGPIO 0x10012000

#define PinModeIOF 0x38
#define PinModeSEL 0x3C

#define IOF_EN       *(int*)(baseAdressGPIO+PinModeIOF)
#define IOF_SEL		 *(int*)(baseAdressGPIO+PinModeSEL)

/**
 * inits the PWM for the RGB led on the hifive1 revb board
 */
void init_PWM();
/**
 * set the PWM value for a selected PWM output
 * @select_output: the output you which the change the PWM value of
 * @value: the requested output value between 0 and 2^16-1 (65535)
 */
void set_PWM_1(int select_output,int value);

#endif /* PWM_H_ */
