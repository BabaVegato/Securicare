#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/hal/GPIO.hpp>
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>

Screen1View::Screen1View()
{
	
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
    Screen1View::updateWildcard(3);
    
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}
void Screen1View::updateLEDState(bool state)
{
	presenter->updateLEDState(toggleButton1.getState());
}
void Screen1View::updateWildcard(int val)
{
 Unicode::snprintf(TXT_Nb_VoleursBuffer,5,"%d",val);
 TXT_Nb_Voleurs.invalidate();
}
