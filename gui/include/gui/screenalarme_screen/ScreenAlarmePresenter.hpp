#ifndef SCREENALARME_PRESENTER_HPP
#define SCREENALARME_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScreenAlarmeView;

class ScreenAlarmePresenter : public Presenter, public ModelListener
{
public:
    ScreenAlarmePresenter(ScreenAlarmeView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();
    virtual void Capteur1Changed();
    virtual void Capteur2Changed();
    virtual void Capteur3Changed();
    virtual ~ScreenAlarmePresenter() {};

private:
    ScreenAlarmePresenter();

    ScreenAlarmeView& view;
};


#endif // SCREENALARME_PRESENTER_HPP
