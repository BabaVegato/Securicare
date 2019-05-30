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

char ScreenAlarmeView::getCapteur1(){return Capteur1;}
char ScreenAlarmeView::getCapteur2(){return Capteur2;}
char ScreenAlarmeView::getCapteur3(){return Capteur3;}

void ScreenAlarmeView::updateCapteur1(){Capteur1 = toggleButtonCapteur1.getState();}
void ScreenAlarmeView::updateCapteur2(){Capteur2 = toggleButtonCapteur2.getState();}
void ScreenAlarmeView::updateCapteur3(){Capteur3 = toggleButtonCapteur3.getState();}

void ScreenAlarmeView::setCapteur1(bool s){Capteur1 = s;}
void ScreenAlarmeView::setCapteur2(bool s){Capteur2 = s;}
void ScreenAlarmeView::setCapteur3(bool s){Capteur3 = s;}

void ScreenAlarmeView::forceBTNStatut(bool s){toggleButtonToutEteindre.forceState(s);}

void ScreenAlarmeView::forceCapteur1(bool state){toggleButtonCapteur1.forceState(state);}
void ScreenAlarmeView::forceCapteur2(bool state){toggleButtonCapteur2.forceState(state);}
void ScreenAlarmeView::forceCapteur3(bool state){toggleButtonCapteur3.forceState(state);}