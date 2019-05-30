#include <gui/screenalarme_screen/ScreenAlarmeView.hpp>
#include <gui/screenalarme_screen/ScreenAlarmePresenter.hpp>

ScreenAlarmePresenter::ScreenAlarmePresenter(ScreenAlarmeView& v)
    : view(v)
{
}

void ScreenAlarmePresenter::activate()
{

}

void ScreenAlarmePresenter::deactivate()
{

}
void ScreenAlarmePresenter::Capteur1Changed(){
	model->setCapteur1(view.getCapteur1());
}
void ScreenAlarmePresenter::Capteur2Changed(){
	model->setCapteur2(view.getCapteur2());
}
void ScreenAlarmePresenter::Capteur3Changed(){
	model->setCapteur3(view.getCapteur3());
}
