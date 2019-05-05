#ifndef SCREENALARME_VIEW_HPP
#define SCREENALARME_VIEW_HPP

#include <gui_generated/screenalarme_screen/ScreenAlarmeViewBase.hpp>
#include <gui/screenalarme_screen/ScreenAlarmePresenter.hpp>

class ScreenAlarmeView : public ScreenAlarmeViewBase
{
public:
    ScreenAlarmeView();
    virtual ~ScreenAlarmeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREENALARME_VIEW_HPP
