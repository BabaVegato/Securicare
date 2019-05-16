#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <touchgfx/hal/GPIO.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/hal/Types.hpp>
#include <gui/model/stm32f429i_discovery.h>


Model::Model() : modelListener(0), nbVoleurs(0), AlphaTXT(0), compteur(0), auth(0), codeTape(false), codeEntre('0'), codeEntreTotal{'2', '2', '2', '2'}, codeAdmin{'1', '2', '2', '2'}, ColorBarR(0), ColorBarG(0), ColorBarB(0), ilFautRestart(false), Gagne(false)
{
	RCC->AHB1ENR |= (1 << 2) | (1 << 6) | (1 << 3);
	
	GPIOC->MODER &= ~(0x3 << 26); //Pour activer PC 13 On force bit 26&27 de GPIOG MODER à être '00' 
	GPIOC->MODER &= ~(0x3 << 24); // PC12
	GPIOG->MODER &= ~(0x3 << 6); // PG3 ToucheTapee
	GPIOG->MODER &= ~(0x3 << 4); // PG2 Bit 1
	GPIOD->MODER &= ~(0x3 << 8); // PD4, Bit 2

	//GPIOC->MODER &= ~(0x3 << 11); // PC11, Bit 1
	//GPIOD->MODER &= ~(0x3 << 14); // PD7, Bit 4
	//GPIOD->MODER &= ~(0x3 << 10); // PD5, Bit 4
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

//IOCODETAPE
if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3)){
 	updateLEDVERTEState(1);
	codeTape = true;
}
else{
	updateLEDVERTEState(0);
}

/////

if(compteur>30 && codeTape){

	//IOVoleurs
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)){
		 	updateLEDVERTEState(1);
 			nbVoleurs++;
 			modelListener->nbVoleursChanged();
	}
	else{
 		updateLEDVERTEState(0);
 	}
 	/////

	//PROCESS TOUCHE
	if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2)){
 		codeEntre = '1';
 	}
 	if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_4)){
 		codeEntre = '2';
 	}
 	if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_4)){
 		codeEntre = '3';
 	}
 	if (!HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && !HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_4)){
 		codeEntre = '0';
 	}
 	modelListener->CodeEntreChanged();
 	/////
 	if(auth != 4){
 		codeEntreTotal[auth] = codeEntre;
 	}

	auth++;
	modelListener->authChanged();

	if(ilFautRestart == true){
		Restart();
		ilFautRestart = false;
	}

	if (auth==4){
		BonpasBon();
	}
	else{
		Bleutermediaire();
	}
	compteur = 0;
	codeTape = false;
}

#endif
}


void Model::BonpasBon(){
	if(codeEntreTotal != codeAdmin){
		if(Gagne==false){
			ColorBarR = 0;
			ColorBarG = 150;
			ColorBarB = 0;
			AlphaTXT = 255;
			modelListener->AlphaTXTChanged();
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
	for(int i=0; i<4; i++){
		codeEntreTotal[i] = '0';
	}
	
}

/*#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <touchgfx/hal/GPIO.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/hal/Types.hpp>
#include <gui/model/stm32f429i_discovery.h>


Model::Model() : modelListener(0), nbVoleurs(0), compteur(0), pret(true), avancementCodeAuth(0), codeAdmin(2222), CodeEntreTotal(0), CodeEntre(0), codeEstTape(false), ColorBarR(0), ColorBarG(0), ColorBarB(0), AlphaTXT(0), fini(false), lecodeestbon(false), lecodeestmauvais(false), compteurCodeBonMauvais(0)
{ // avancementCodeAuth est le nombre de chiffres tapés,   codeAdmin est le code qu'il faut taper,   inputDigi est le chiffre tapé sur le digicode
	RCC->AHB1ENR |= (1 << 2) | (1 << 6) | (1 << 3);
	
	GPIOC->MODER &= ~(0x3 << 26); //Pour activer PC 13 On force bit 26&27 de GPIOG MODER à être '00' 
	GPIOC->MODER &= ~(0x3 << 24); // PC12
	GPIOG->MODER &= ~(0x3 << 6); // PG3 ToucheTapee
	GPIOG->MODER &= ~(0x3 << 4); // PG2 Bit 1
	GPIOD->MODER &= ~(0x3 << 8); // PD4, Bit 2

	//GPIOC->MODER &= ~(0x3 << 11); // PC11, Bit 1
	//GPIOD->MODER &= ~(0x3 << 14); // PD7, Bit 4
	//GPIOD->MODER &= ~(0x3 << 10); // PD5, Bit 4
	//GPIOD->MODER &= ~(0x3 << 24); // PD12, Bit 2
	//GPIOD->MODER &= ~(0x3 << 28); // PD14, Bit 3
	//GPIOD->MODER &= ~(0x3 << 20); // PD10, crée des problèmes d'écran...
	//GPIOD->MODER &= ~(0x3 << 6); // PE3 , crée des problèmes d'écran...

	//GPIOC->MODER &= ~(0x3 << 30); // PC15

	GPIOG->MODER &= ~(0x3 << 26); //LED VERTE
	GPIOG->MODER |= (1 << 26);

	ColorBarR = 0;
	ColorBarG = 0;
	ColorBarB = 120;

}

void Model::tick()
{

//updateLEDState(1);

#ifndef SIMULATOR
compteur++;
codeEstTape = false;

//signal nbVoleurs
 if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) && pret == true){
 	compteur = 0;
 	nbVoleurs++;
 	updateLEDVERTEState(1);
 	modelListener->nbVoleursChanged();
 	pret = false;
 }
 else{
 	updateLEDVERTEState(0);
 }

//signal CodeEstTape sur PG3
 if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3) && pret == true && !fini){
 	updateLEDVERTEState(1);
 	compteur = 0;
 	avancementCodeAuth++;
 	modelListener->avancementCodeAuthChanged();
 	codeEstTape = true;
 	pret = false;
 }
 if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && codeEstTape == true){
 	CodeEntre = 1;
 	pret = false;
 }
 if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_4) && codeEstTape == true){
 	CodeEntre = 2;
 	pret = false;
 }
 if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_4) && codeEstTape == true){
 	CodeEntre = 3;
 	pret = false;
 }
 if (!HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2) && !HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_4) && codeEstTape == true){
 	CodeEntre = 0;
 	pret = false;
 }
 modelListener->CodeEntreChanged();


 if (compteur == 30){
 	compteur = 0;
 	pret = true;

 }
 if(codeEstTape){
 	EntreeCode(CodeEntre);
 }
 if (avancementCodeAuth == 4){
 	avancementCodeAuth = 0;
 }
 if(lecodeestmauvais){
		if(compteurCodeBonMauvais>5){
			compteurCodeBonMauvais = 0;
			lecodeestmauvais = false;
		}
		else{
			Recommencer();
			compteurCodeBonMauvais++;
		}
	}
if(lecodeestbon){
	if(compteurCodeBonMauvais>5){
		compteurCodeBonMauvais = 0;
		lecodeestbon = false;
	}
	else{
		Victoire();
		compteurCodeBonMauvais++;
	}
}
if(!lecodeestbon && !lecodeestmauvais){
	ColorBarR = 0;
	ColorBarG = 0;
	ColorBarB = 120;
	modelListener->ColorBarChanged();
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
void Model::EntreeCode(int nb){
	if(avancementCodeAuth==0){
		CodeEntreTotal += CodeEntre;
	}
	if(avancementCodeAuth==1){
		CodeEntreTotal += CodeEntre*10;
	}
	if(avancementCodeAuth==2){
		CodeEntreTotal += CodeEntre*100;
	}
	if(avancementCodeAuth==4){
		CodeEntreTotal += CodeEntre*1000;
		if(CodeEntreTotal == codeAdmin){
			fini = true;
			lecodeestbon = true;
		}
		if(CodeEntreTotal != codeAdmin){
			fini = true;
			lecodeestmauvais = true;
		}
	}
}

void Model::Recommencer(){
	ColorBarR = 255;
	ColorBarG = 0;
	ColorBarB = 0;
	CodeEntreTotal = 0;
	avancementCodeAuth = 0;
	modelListener->ColorBarChanged();
}
void Model::Victoire(){
	ColorBarR = 0;
	ColorBarG = 255;
	ColorBarB = 0;
	CodeEntreTotal = 0;
	avancementCodeAuth = 0;
	AlphaTXT = 255;
	modelListener->AlphaTXTChanged();
	modelListener->ColorBarChanged();
}*/