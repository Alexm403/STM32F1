void init_SysTick(void){
SysTick->LOAD=72000000/(1000-1);
SysTick->VAL=72000000/(1000-1);
SysTick->CTRL=	SysTick_CTRL_CLKSOURCE_Msk |
                SysTick_CTRL_TICKINT_Msk   |
                SysTick_CTRL_ENABLE_Msk;;
}


int main (void)
{
	init_SysTick();
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

	GPIOC->CRH &= ~GPIO_CRH_CNF13;
	GPIOC->CRH |= GPIO_CRH_MODE13_0;

GPIO_InitTypeDef port;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

GPIO_StructInit(&port);
    port.GPIO_Mode = GPIO_Mode_Out_PP;
    port.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_12;
    port.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &port); 
	
	
	while(1)
	{
	delay_ms(1);
	}
  
}

//SysTick Interrupt
void SysTick_Handler(void)
{
static uint16_t tick;
tick++;

if (tick==190){GPIOB->BSRR = GPIO_BSRR_BS13;}	
if (tick==200){GPIOB->BSRR = GPIO_BSRR_BR13;tick=0;}	

}
