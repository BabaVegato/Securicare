#include <gui/screenalarme_screen/ScreenAlarmeView.hpp>
#include <gui/screenalarme_screen/ScreenAlarmePresenter.hpp>

ScreenAlarmePresenter::ScreenAlarmePresenter(ScreenAlarmeView& v)
    : view(v)
{
}

void ScreenAlarmePresenter::activate()
{
	view.forceCapteur1(model->getCapteur1());
	view.forceCapteur2(model->getCapteur2());
	view.forceCapteur3(model->getCapteur3());

	view.setCapteur1(model->getCapteur1());
	view.setCapteur2(model->getCapteur2());
	view.setCapteur3(model->getCapteur3());

	if(model->getState() == 0){
		view.forceBTNStatut(false);
	}
	if(model->getState() == 1){
		view.forceBTNStatut(true);
	}
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
void ScreenAlarmePresenter::TelecoEteint(){
	view.setCapteur3(false);
	view.setCapteur2(false);
	view.setCapteur1(false);
}
void ScreenAlarmePresenter::TelecoAllume(){
	view.setCapteur3(true);
	view.setCapteur2(true);
	view.setCapteur1(true);
}
