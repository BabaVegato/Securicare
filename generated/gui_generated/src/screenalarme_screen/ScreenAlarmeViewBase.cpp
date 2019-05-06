/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screenalarme_screen/ScreenAlarmeViewBase.hpp>
#include "BitmapDatabase.hpp"

ScreenAlarmeViewBase::ScreenAlarmeViewBase() :
    buttonCallback(this, &ScreenAlarmeViewBase::buttonCallbackHandler)
{
    TILEDIMG_Background_Alarme.setBitmap(Bitmap(BITMAP_BLUE_TEXTURES_MOCHAGRUNGE_ID));
    TILEDIMG_Background_Alarme.setPosition(0, 0, 240, 320);
    TILEDIMG_Background_Alarme.setOffset(0, 0);

    BUTTON_retour_Screen1.setXY(5, 254);
    BUTTON_retour_Screen1.setBitmaps(Bitmap(BITMAP_DARK_BUTTONS_ROUND_ICON_BUTTON_ID), Bitmap(BITMAP_DARK_BUTTONS_ROUND_ICON_BUTTON_PRESSED_ID));
    BUTTON_retour_Screen1.setAction(buttonCallback);

    IMG_Back.setXY(17, 261);
    IMG_Back.setBitmap(Bitmap(BITMAP_DARK_ICONS_BACK_ARROW_48_ID));

    swipeContainer_Capteurs.setXY(0, 105);

    Capteur3.setPosition(0, 0, 241, 128);


    swipeContainer_Capteurs.add(Capteur3);

    Capteur2.setPosition(0, 0, 241, 128);


    swipeContainer_Capteurs.add(Capteur2);

    Capteur1.setPosition(0, 0, 241, 128);


    swipeContainer_Capteurs.add(Capteur1);

    swipeContainer_Capteurs.setPageIndicatorBitmaps(Bitmap(BITMAP_DARK_PAGEINDICATOR_DOT_INDICATOR_SMALL_NORMAL_ID), Bitmap(BITMAP_DARK_PAGEINDICATOR_DOT_INDICATOR_SMALL_HIGHLIGHT_ID));
    swipeContainer_Capteurs.setPageIndicatorXY(0, 0);
    swipeContainer_Capteurs.setSwipeCutoff(50);
    swipeContainer_Capteurs.setEndSwipeElasticWidth(50);
    swipeContainer_Capteurs.setSelectedPage(0);

    add(TILEDIMG_Background_Alarme);
    add(BUTTON_retour_Screen1);
    add(IMG_Back);
    add(swipeContainer_Capteurs);
}

void ScreenAlarmeViewBase::setupScreen()
{

}

void ScreenAlarmeViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &BUTTON_retour_Screen1)
    {
        //Go_To_SCREEN1
        //When BUTTON_retour_Screen1 clicked change screen to Screen1
        //Go to Screen1 with screen transition towards West
        application().gotoScreen1ScreenCoverTransitionWest();
    }
}
