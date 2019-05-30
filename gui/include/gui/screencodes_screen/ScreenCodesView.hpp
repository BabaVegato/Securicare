#ifndef SCREENCODES_VIEW_HPP
#define SCREENCODES_VIEW_HPP

#include <gui_generated/screencodes_screen/ScreenCodesViewBase.hpp>
#include <gui/screencodes_screen/ScreenCodesPresenter.hpp>

class ScreenCodesView : public ScreenCodesViewBase
{
public:
    ScreenCodesView();
    virtual ~ScreenCodesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREENCODES_VIEW_HPP
