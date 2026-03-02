#include "STM32F401_GPIO.h"
int main(void)
{
	uint8_t cnt=0;
	GPIO_Handle_t GPIOLED,GPIOBTN;
	GPIOLED.pGPIOx=GPIOB;
	GPIOLED.GPIO_config.GPIO_PinMode=GPIO_MODE_OUT;
	GPIOLED.GPIO_config.GPIO_PinSpeed=2;
	GPIOLED.GPIO_config.GPIO_PinOptype=GPIO_OP_TYPE_PP;
	GPIOLED.GPIO_config.GPIO_Pinpupdcontrol=GPIO_NO_PUPD;
	GPIO_PLLCLK_Init(GPIOB,ENABLE);
	for(uint8_t i=0;i<8;i++)
	{
		GPIOLED.GPIO_config.GPIO_PinNumber=i;
		GPIO_Init(&GPIOLED);
	}
	GPIOBTN.pGPIOx=GPIOA;
	GPIOBTN.GPIO_config.GPIO_PinMode=GPIO_MODE_IN;
	GPIOBTN.GPIO_config.GPIO_PinSpeed=2;
	GPIOBTN.GPIO_config.GPIO_PinNumber=GPIO_PIN_0;
	GPIOBTN.GPIO_config.GPIO_Pinpupdcontrol=GPIO_PIN_PU;
	GPIO_PLLCLK_Init(GPIOA,ENABLE);
	GPIO_Init(&GPIOBTN);
	while(1)
	{
		if(GPIO_Read_Pin(GPIOA,GPIO_PIN_0))
		{
			cnt++;
			GPIO_Write_Port(GPIOB,cnt);
			for(uint32_t i=0;i<5000000;i++);
			while(GPIO_Read_Pin(GPIOA,GPIO_PIN_0));
		}
	}
}
