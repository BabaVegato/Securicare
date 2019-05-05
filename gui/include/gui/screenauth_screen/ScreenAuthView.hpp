#ifndef SCREENAUTH_VIEW_HPP
#define SCREENAUTH_VIEW_HPP

#include <gui_generated/screenauth_screen/ScreenAuthViewBase.hpp>
#include <gui/screenauth_screen/ScreenAuthPresenter.hpp>

class ScreenAuthView : public ScreenAuthViewBase
{
public:
    ScreenAuthView();
    virtual ~ScreenAuthView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void updateTxt(int newValue);
protected:
};

#endif // SCREENAUTH_VIEW_HPP
