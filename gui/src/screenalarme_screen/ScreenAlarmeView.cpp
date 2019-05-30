#include <gui/screenalarme_screen/ScreenAlarmeView.hpp>

ScreenAlarmeView::ScreenAlarmeView() : Capteur1(false), Capteur2(false), Capteur3(false), StatutGlobal(false)
{

}

void ScreenAlarmeView::setupScreen()
{
    ScreenAlarmeViewBase::setupScreen();
}

void ScreenAlarmeView::tearDownScreen()
{
    ScreenAlarmeViewBase::tearDownScreen();
}
char ScreenAlarmeView::getCapteur1()
{
  return Capteur1;
}
char ScreenAlarmeView::getCapteur2()
{
  return Capteur2;
}
char ScreenAlarmeView::getCapteur3()
{
  return Capteur3;
}
void ScreenAlarmeView::updateCapteur1()
{
  Capteur1 = toggleButtonCapteur1.getState();
}
void ScreenAlarmeView::updateCapteur2()
{
  Capteur2 = toggleButtonCapteur2.getState();
}
void ScreenAlarmeView::updateCapteur3()
{
  Capteur3 = toggleButtonCapteur3.getState();
}