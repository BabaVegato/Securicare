#include <gui/screenauth_screen/ScreenAuthView.hpp>
#include <gui/screenauth_screen/ScreenAuthPresenter.hpp>

ScreenAuthPresenter::ScreenAuthPresenter(ScreenAuthView& v)
    : view(v)
{
}

void ScreenAuthPresenter::activate()
{
	//view.updateBar(model->getAvancementCodeAuth());
}

void ScreenAuthPresenter::deactivate()
{

}
void ScreenAuthPresenter::authChanged(){
	view.updateBar(model->getAuth());
}
void ScreenAuthPresenter::CodeEntreChanged(){
	view.updateWildcardCode(model->getCodeEntre(), model->getAuth());
}
void ScreenAuthPresenter::nbVoleursChanged(){
}
void ScreenAuthPresenter::ColorBarChanged(){
	view.updateColorBar(model->getColorBarR(), model->getColorBarG(), model->getColorBarB());
}
void ScreenAuthPresenter::AlphaTXTChanged(){
	view.updateAlphaTXT(model->getAlphaTXT());
}