#include <gui/screenauth_screen/ScreenAuthView.hpp>
#include <gui/screenauth_screen/ScreenAuthPresenter.hpp>

ScreenAuthPresenter::ScreenAuthPresenter(ScreenAuthView& v)
    : view(v)
{
}

void ScreenAuthPresenter::activate()
{
	view.updateBar(model->getAvancementCodeAuth());
}

void ScreenAuthPresenter::deactivate()
{

}
void ScreenAuthPresenter::nbVoleursChanged(){
	view.updateBar(model->getAvancementCodeAuth());
}