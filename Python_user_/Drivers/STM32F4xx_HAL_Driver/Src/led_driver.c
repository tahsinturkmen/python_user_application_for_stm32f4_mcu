#include  "stm32f4xx_hal.h"
#include "led_driver.h"


/*******************************************************************************\
 *this part collects all defined functions in a single function and
 *allows us to call it in the part we want
\*******************************************************************************/

void LED_Apps( uint8_t *data)
{
	LED_On(data);
	LED_Ambulance(data);
	LED_Party(data);
	LED_Off(data);
}


/*******************************************************************************\
 *This function receives incoming uint8_t type data and part keeps the leds on
 *defgroup LED_ON_COMMUNICATION_PROTOCOL = '1'
 *defgroup LED_ON_DATA = 'A'
\*******************************************************************************/

void LED_On(uint8_t *data1)
{
   if((data1[0] == LED_ON_COMMUNICATION_PROTOCOL) && (data1[1] == LED_ON_DATA))
	{
	    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 |GPIO_PIN_13 |GPIO_PIN_14 |GPIO_PIN_15 , GPIO_PIN_SET);
	}
}


/*******************************************************************************\
 *This function receives incoming uint8_t type data and
 *This makes the leds blink like an ambulance light.
 *defgroup LED_AMBULANCE_COMMUNICATION_PROTOCOL = '2'
 *defgroup LED_AMBULANCE_DATA = 'B'
\*******************************************************************************/

void LED_Ambulance(uint8_t * data1)
{
   if((data1[0] == LED_AMBULANCE_COMMUNICATION_PROTOCOL) && (data1[1] == LED_AMBULANCE_DATA))
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 |GPIO_PIN_13  , GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
			HAL_Delay(100);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_Delay(100);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_Delay(100);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
			HAL_Delay(100);
		}
}


/*******************************************************************************\
 *This function receives incoming uint8_t type data and makes the led blink.
 *defgroup LED_BLINK_COMMUNICATION_PROTOCOL = '3'
 *defgroup LED_BLINK_DATA = 'C'
\*******************************************************************************/

void LED_Party(uint8_t * data1)
{
   if((data1[0] == LED_BLINK_COMMUNICATION_PROTOCOL ) && (data1[1] == LED_BLINK_DATA))
	 {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 |GPIO_PIN_13 |GPIO_PIN_14 |GPIO_PIN_15 , GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
			HAL_Delay(100);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			HAL_Delay(100);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_Delay(100);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_Delay(100);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
			HAL_Delay(100);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		    HAL_Delay(100);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
		 	 HAL_Delay(100);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
		HAL_Delay(100);
	}
}


/*******************************************************************************\
 * this function takes a data of incoming uint8_t type and turns off the leds
 * @defgroup LED_OFF_COMMUNICATION_PROTOCOL = '4'
 * @defgroup LED_OFF_DATA = 'D'
\*******************************************************************************/

void LED_Off(uint8_t * data1)
{
    if((data1[0] == LED_OFF_COMMUNICATION_PROTOCOL) && (data1[1] == LED_OFF_DATA))
	  {
		 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 |GPIO_PIN_13 |GPIO_PIN_14 |GPIO_PIN_15 , GPIO_PIN_RESET);
	  }
}
