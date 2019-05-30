/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screenalarme_screen/ScreenAlarmeViewBase.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

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

    swipeContainer_Capteurs.setXY(0, 86);

    Capteur3.setPosition(0, 0, 241, 148);

    toggleButtonCapteur3.setXY(113, 110);
    toggleButtonCapteur3.setBitmaps(Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_LARGE_BUTTON_OFF_ID), Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_LARGE_BUTTON_ON_ID));
    toggleButtonCapteur3.setAction(buttonCallback);
    Capteur3.add(toggleButtonCapteur3);

    TXTCapteur3.setXY(50, 41);
    TXTCapteur3.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    TXTCapteur3.setLinespacing(0);
    TXTCapteur3.setTypedText(TypedText(T_SINGLEUSEID18));
    Capteur3.add(TXTCapteur3);
    swipeContainer_Capteurs.add(Capteur3);

    Capteur2.setPosition(0, 0, 241, 148);

    toggleButtonCapteur2.setXY(113, 110);
    toggleButtonCapteur2.setBitmaps(Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_LARGE_BUTTON_OFF_ID), Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_LARGE_BUTTON_ON_ID));
    toggleButtonCapteur2.setAction(buttonCallback);
    Capteur2.add(toggleButtonCapteur2);

    TXTCapteur2.setXY(50, 41);
    TXTCapteur2.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    TXTCapteur2.setLinespacing(0);
    TXTCapteur2.setTypedText(TypedText(T_SINGLEUSEID17));
    Capteur2.add(TXTCapteur2);
    swipeContainer_Capteurs.add(Capteur2);

    Capteur1.setPosition(0, 0, 241, 148);

    toggleButtonCapteur1.setXY(111, 110);
    toggleButtonCapteur1.setBitmaps(Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_LARGE_BUTTON_OFF_ID), Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_LARGE_BUTTON_ON_ID));
    toggleButtonCapteur1.setAction(buttonCallback);
    Capteur1.add(toggleButtonCapteur1);

    TXTCapteur1.setXY(50, 41);
    TXTCapteur1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    TXTCapteur1.setLinespacing(0);
    TXTCapteur1.setTypedText(TypedText(T_SINGLEUSEID16));
    Capteur1.add(TXTCapteur1);
    swipeContainer_Capteurs.add(Capteur1);

    swipeContainer_Capteurs.setPageIndicatorBitmaps(Bitmap(BITMAP_DARK_PAGEINDICATOR_DOT_INDICATOR_SMALL_NORMAL_ID), Bitmap(BITMAP_DARK_PAGEINDICATOR_DOT_INDICATOR_SMALL_HIGHLIGHT_ID));
    swipeContainer_Capteurs.setPageIndicatorXY(0, 0);
    swipeContainer_Capteurs.setSwipeCutoff(50);
    swipeContainer_Capteurs.setEndSwipeElasticWidth(50);
    swipeContainer_Capteurs.setSelectedPage(2);

    button1.setXY(0, 0);
    button1.setBitmaps(Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    button1.setAction(buttonCallback);
    button1.setAlpha(0);

    toggleButtonToutEteindre.setXY(67, 37);
    toggleButtonToutEteindre.setBitmaps(Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_SMALL_BUTTON_OFF_ID), Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_SMALL_BUTTON_ON_ID));
    toggleButtonToutEteindre.setAction(buttonCallback);

    textArea1.setXY(26, 2);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(TypedText(T_SINGLEUSEID38));

    add(TILEDIMG_Background_Alarme);
    add(BUTTON_retour_Screen1);
    add(IMG_Back);
    add(swipeContainer_Capteurs);
    add(button1);
    add(toggleButtonToutEteindre);
    add(textArea1);
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
    else if (&src == &toggleButtonCapteur3)
    {
        //InterCapteur3
        //When toggleButtonCapteur3 clicked call virtual function
        //Call Capteur3BTN
        Capteur3BTN();
    }
    else if (&src == &toggleButtonCapteur2)
    {
        //InterCapteur2
        //When toggleButtonCapteur2 clicked call virtual function
        //Call Capteur2BTN
        Capteur2BTN();
    }
    else if (&src == &toggleButtonCapteur1)
    {
        //InterCapteur1
        //When toggleButtonCapteur1 clicked call virtual function
        //Call Capteur1BTN
        Capteur1BTN();
    }
    else if (&src == &button1)
    {
        //GoCodes
        //When button1 clicked change screen to ScreenCodes
        //Go to ScreenCodes with screen transition towards East
        application().gotoScreenCodesScreenSlideTransitionEast();
    }
    else if (&src == &toggleButtonToutEteindre)
    {
        //InterToutEteindre
        //When toggleButtonToutEteindre clicked call virtual function
        //Call ToutEteindre
        ToutEteindre();
    }
}
