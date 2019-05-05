#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/hal/GPIO.hpp>
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>

Screen1View::Screen1View()
{
	
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}
void Screen1View::updateLEDState(bool state)
{
	presenter->updateLEDState(toggleButton1.getState());
}

