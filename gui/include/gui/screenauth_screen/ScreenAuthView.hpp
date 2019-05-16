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
    virtual void updateBar(int);
    virtual void updateWildcardCode(char, int);
    virtual void updateAlphaTXT(int);
    virtual void updateColorBar(uint8_t, uint8_t, uint8_t);
protected:
};

#endif // SCREENAUTH_VIEW_HPP
