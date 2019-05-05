#include <gui/screenauth_screen/ScreenAuthView.hpp>

ScreenAuthView::ScreenAuthView()
{

}

void ScreenAuthView::setupScreen()
{
  ScreenAuthViewBase::setupScreen();
  /*txt.setTypedText(TypedText(1));
  txt.setXY(10, 20); 
  txt.setColor(Color::getColorFrom24BitRGB(0xFF, 0xFF, 0xFF))
  txt.setWildcard(txtBuffer);
  add(txt);

  updateTxt(5);*/
}

void ScreenAuthView::tearDownScreen()
{
    ScreenAuthViewBase::tearDownScreen();
}

void ScreenAuthView::updateTxt(int newValue)
{
  /*Unicode::snprintf(txtBuffer, 10, "%d", newValue);
  txt.invalidate();*/ 
}