#ifndef SCREENCODES_PRESENTER_HPP
#define SCREENCODES_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScreenCodesView;

class ScreenCodesPresenter : public Presenter, public ModelListener
{
public:
    ScreenCodesPresenter(ScreenCodesView& v);

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

    virtual ~ScreenCodesPresenter() {};

private:
    ScreenCodesPresenter();

    ScreenCodesView& view;
};


#endif // SCREENCODES_PRESENTER_HPP
