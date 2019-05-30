#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{
}

void Screen1Presenter::activate()
{
	view.updateWildcard(model->getnbVoleurs()); //ptet que cette ligne est de trop ?
}

void Screen1Presenter::deactivate()
{

}
void Screen1Presenter::nbVoleursChanged(){
	view.updateWildcard(model->getnbVoleurs());
}
void Screen1Presenter::StateChanged(){
	view.updateWildStatus(model->getState());
}