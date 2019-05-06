#include <gui/screenauth_screen/ScreenAuthView.hpp>

ScreenAuthView::ScreenAuthView()
{

}

void ScreenAuthView::setupScreen()
{
  ScreenAuthViewBase::setupScreen();
}

void ScreenAuthView::tearDownScreen()
{
    ScreenAuthViewBase::tearDownScreen();
}
void ScreenAuthView::updateBar(int val)
{
 boxProgress_Demande_Code.setValue(val);
}