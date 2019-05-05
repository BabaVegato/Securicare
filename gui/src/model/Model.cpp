#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <touchgfx/hal/GPIO.hpp>
#include <gui/model/stm32f429i_discovery.h>


Model::Model() : modelListener(0)
{
	//BSP_LED_Init(LED3);
	//BSP_LED_ON(LED3);
	RCC->AHB1ENR |= (1 << 2) | (1 << 6);
	
	GPIOC->MODER &= ~(0x3 << 26); //Pour activer PC 13 On force bit 26&27 de GPIOG MODER à être '00'
	GPIOC->MODER &= ~(0x3 << 24); // PC12
	//GPIOC->MODER &= ~(0x3 << 30); // PC15

	GPIOG->MODER &= ~(0x3 << 26); //LED VERTE
	GPIOG->MODER |= (1 << 26);

}

void Model::tick()
{

//updateLEDState(1);

#ifndef SIMULATOR

 // use filter variable to make sure we only trigger this once per input change.
 // Sample pin B12
GPIOG->ODR |= (1 << 13);
 if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)){
 		updateLEDVERTEState(1);
 }
 else{
 	updateLEDVERTEState(0);
 }


#endif 
}

void Model::updateLEDROUGEState(bool state){
	/*if (state == 1){
		GPIOG->ODR |= (1 << 14);
	}
	else{
		GPIOG->ODR &= ~(1 << 14);
	}*/

}
void Model::updateLEDVERTEState(bool state){
	/*if (state == 1){
		GPIOG->ODR |= (1 << 13);
	}
	else{
		GPIOG->ODR &= ~(1 << 13);
	}*/

}
void Model::updateLEDState(bool state){

}

/*void Model::toggleButton1(){
	modelListener->toggleButton1();
}*/