#ifndef STM32F4XX_HAL_DRIVER_INC_LED_DRIVER_H_
#define STM32F4XX_HAL_DRIVER_INC_LED_DRIVER_H_

/***********************************************************************************************\
 * ------->In this section, a standard for communication has been established.<------------
 * ------>The first byte of the incoming data determines the function to be used.<----------
\************************************************************************************************/

#define LED_ON_COMMUNICATION_PROTOCOL            '1'
#define LED_AMBULANCE_COMMUNICATION_PROTOCOL     '2'
#define LED_BLINK_COMMUNICATION_PROTOCOL 		'3'
#define LED_OFF_COMMUNICATION_PROTOCOL 			'4'


/****************************************************************\
 * ------>This part defines data for communication<-------------*
\****************************************************************/

#define LED_ON_DATA				'A'
#define LED_AMBULANCE_DATA		'B'
#define LED_BLINK_DATA			'C'
#define LED_OFF_DATA			'D'



void LED_Apps(uint8_t*data);
void LED_On(uint8_t*data1);
void LED_Ambulance(uint8_t*data1);
void LED_Party(uint8_t*data1);
void LED_Off(uint8_t*data1);

#endif /* STM32F4XX_HAL_DRIVER_INC_LED_DRIVER_H_ */
