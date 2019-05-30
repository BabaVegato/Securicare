#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <touchgfx/hal/GPIO.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/hal/Types.hpp>
#include <gui/model/stm32f429i_discovery.h>


Model::Model() : modelListener(0), nbVoleurs(0), AlphaTXT(0), compteur(0), auth(0), codeTape(false), codeEntre('X'), codeEntre1('X'), codeEntre2('X'), codeEntre3('X'), codeEntre4('X'), codeAdmin1('A'), codeAdmin2('1'), codeAdmin3('B'), codeAdmin4('2'), ColorBarR(0), ColorBarG(0), ColorBarB(0), ilFautRestart(false), Gagne(false), Capteur1(false), Capteur2(false), Capteur3(false), BTN('X'), State(0), Teleco(false)
{
	RCC->AHB1ENR |= (1 << 2) | (1 << 6) | (1 << 3);
	
	GPIOC->MODER &= ~(0x3 << 26); //Pour activer PC 13 On force bit 26&27 de GPIOG MODER à être '00' 
	GPIOC->MODER &= ~(0x3 << 24); // PC12
	GPIOG->MODER &= ~(0x3 << 4); // PG2 Bit 1
	GPIOG->MODER &= ~(0x3 << 6); // PG3 Bit 2
	GPIOG->MODER &= ~(0x3 << 18);// PG9 Bit 3
	GPIOD->MODER &= ~(0x3 << 10); // PD5 Bit 4
	GPIOD->MODER &= ~(0x3 << 8); // PD4, ToucheTapee
	GPIOD->MODER &= ~(0x3 << 14); // PD7, Teleco

	//GPIOC->MODER &= ~(0x3 << 11); // PC11, Bit 1
	//GPIOD->MODER &= ~(0x3 << 14); // PD7, Bit 4
	//GPIOD->MODER &= ~(0x3 << 24); // PD12, Bit 2
	//GPIOD->MODER &= ~(0x3 << 28); // PD14, Bit 3
	//GPIOD->MODER &= ~(0x3 << 20); // PD10, crée des problèmes d'écran...
	//GPIOD->MODER &= ~(0x3 << 6); // PE3 , crée des problèmes d'écran...

	//GPIOC->MODER &= ~(0x3 << 30); // PC15

	GPIOG->MODER &= ~(0x3 << 26); //LED VERTE
	GPIOG->MODER |= (1 << 26);
}

void Model::tick()
{

#ifndef SIMULATOR

compteur++;

if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_7) && !Teleco){
 	State = 0;
 	updateLEDVERTEState(1);
 	compteur = 0;
 	Teleco = true;
 	modelListener->StateChanged();
}

//IOCODETAPE
if(compteur>25){
	if(ilFautRestart == true){
		Restart();
		ilFautRestart = false;
	}
}
if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_4) && compteur>25){
	codeTape = true;
}

/////
modelListener->BTNChanged();
modelListener->Capteur1Changed();
modelListener->Capteur2Changed();
modelListener->Capteur3Changed();

if(!Capteur1 && !Capteur2 && !Capteur3){
	State = 0; //Tout éteint
}
if(Capteur1 && Capteur2 && Capteur3){
	State = 1; //Tout allumé
}
if(!(!Capteur1 && !Capteur2 && !Capteur3) && !(Capteur1 && Capteur2 && Capteur3)){
	State = 2; //Mixed
}

modelListener->StateChanged();

//codeTape = false;
//
if(BTN != 'X'){
	if(ilFautRestart == true){
		Restart();
		ilFautRestart = false;
	}
	codeTape = true;
}
//
if(compteur>25 && codeTape && !Gagne){

	//IOVoleurs
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)){
 		nbVoleurs++;
		modelListener->nbVoleursChanged();
	}
 	/////


	//PROCESS TOUCHE ////// BIT 1 = PG2 ; BIT 2 = PG3 ; BIT 3 = PG9 ; BIT 4 = PD5
	if (!HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && !HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3) && !HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_9) && !HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5)){
 		codeEntre = '0';
 	}
 	if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && !HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3) && !HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_9) && !HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5)){
 		codeEntre = '1';
 	}
 	if (!HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3) && !HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_9) && !HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5)){
 		codeEntre = '2';
 	}
 	if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3) && !HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_9) && !HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5)){
 		codeEntre = '3';
 	}
 	if (!HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && !HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3) && HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_9) && !HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5)){
 		codeEntre = '4';
 	}
 	if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && !HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3) && HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_9) && !HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5)){
 		codeEntre = '5';
 	}
 	if (!HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3) && HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_9) && !HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5)){
 		codeEntre = '6';
 	}
 	if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3) && HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_9) && !HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5)){
 		codeEntre = '7';
 	}
 	if (!HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && !HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3) && !HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_9) && HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5)){
 		codeEntre = '8';
 	}
 	if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && !HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3) && !HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_9) && HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5)){
 		codeEntre = '9';
 	}
 	if (!HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3) && !HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_9) && HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5)){
 		codeEntre = 'A';
 	}
 	if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3) && !HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_9) && HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5)){
 		codeEntre = 'B';
 	}
 	if (!HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && !HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3) && HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_9) && HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5)){
 		codeEntre = 'C';
 	}
 	if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && !HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3) && HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_9) && HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5)){
 		codeEntre = 'D';
 	}
 	if (!HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3) && HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_9) && HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5)){
 		codeEntre = 'E';
 	}
 	if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3) && HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_9) && HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5)){
 		codeEntre = 'F';
 	}

 	if(BTN != 'X'){
 		codeEntre = BTN;
 		BTN = 'X';
 		modelListener->BTNXauthview();
	}

 	modelListener->CodeEntreChanged();
 	/////

 	if(auth == 0){
 		codeEntre1 = codeEntre;
 	}
 	if(auth == 1){
 		codeEntre2 = codeEntre;
 	}
 	if(auth == 2){
 		codeEntre3 = codeEntre;
 	}
 	if(auth == 3){
 		codeEntre4 = codeEntre;
 	}

	auth++;
	modelListener->authChanged();

	if (auth==4){
		BonpasBon();
	}
	else{
		Bleutermediaire();
	}
	compteur = 0;
	codeTape = false;
}

if(compteur>25 && Gagne){
	Restart();
	modelListener->GoToCodes();
}



#endif
}


void Model::BonpasBon(){
	if(codeEntre1 == codeAdmin1 && codeEntre2 == codeAdmin2 && codeEntre3 == codeAdmin3 && codeEntre4 == codeAdmin4){
		if(!Gagne){
			ColorBarR = 0;
			ColorBarG = 150;
			ColorBarB = 0;
			modelListener->ColorBarChanged();
			Gagne = true;
		}
	}
	else{
		ColorBarR = 150;
		ColorBarG = 0;
		ColorBarB = 0;
		modelListener->ColorBarChanged();
		ilFautRestart = true;
	}
}
void Model::Bleutermediaire(){
	ColorBarR = 0;
	ColorBarG = 0;
	ColorBarB = 150;
	modelListener->ColorBarChanged();
}

void Model::updateLEDVERTEState(bool state){
	if (state == 1){
		GPIOG->ODR |= (1 << 13);
	}
	else{
		GPIOG->ODR &= ~(1 << 13);
	}

}
void Model::Restart(){
	ColorBarR = 150;
	ColorBarG = 0;
	ColorBarB = 0;
	modelListener->ColorBarChanged();
	auth = 0;
	modelListener->authChanged();
	codeEntre1='X';
	codeEntre2='X';
	codeEntre3='X';
	codeEntre4='X';
	Gagne = false;
	compteur = 0;
}