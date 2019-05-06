#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <touchgfx/hal/GPIO.hpp>
#include <gui/model/stm32f429i_discovery.h>


Model::Model() : modelListener(0), nbVoleurs(0), compteur(0), pret(true), avancementCodeAuth(0), codeAdmin(1234)
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
compteur++;

 if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) && pret == true){
 	updateLEDVERTEState(1);
 	nbVoleurs++;
 	avancementCodeAuth++;
 	modelListener->nbVoleursChanged();
 	pret = false;
 }
 else{
 	updateLEDVERTEState(0);
 }
 if (compteur == 100){
 	compteur = 0;
 	pret = true;
 }


#endif
}

void Model::updateLEDVERTEState(bool state){
	if (state == 1){
		GPIOG->ODR |= (1 << 13);
	}
	else{
		GPIOG->ODR &= ~(1 << 13);
	}

}
void Model::updateLEDState(bool state){

}
void Model::EntreeCode(int nb){

}