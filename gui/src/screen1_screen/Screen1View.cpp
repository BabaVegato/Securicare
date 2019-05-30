#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/hal/GPIO.hpp>
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>

Screen1View::Screen1View()
{
	
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
    //Screen1View::updateWildcard(3);
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}
void Screen1View::updateWildcard(int val)
{
	Unicode::snprintf(TXT_Nb_VoleursBuffer,5,"%d",val);
 	TXT_Nb_Voleurs.invalidate();
}
void Screen1View::updateWildStatus(int State)
{
	if(State == 0){
		Unicode::snprintf(TXTStatutBuffer,10,"%c", 'I');
 		TXTStatut.invalidate();
	}
	if(State == 1){
		Unicode::snprintf(TXTStatutBuffer,10,"%c", 'A');
 		TXTStatut.invalidate();
	}
	if(State == 2){
		Unicode::snprintf(TXTStatutBuffer,10,"%c",'M');
 		TXTStatut.invalidate();
	}
}

