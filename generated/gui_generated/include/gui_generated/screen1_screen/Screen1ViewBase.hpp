/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN1_VIEW_BASE_HPP
#define SCREEN1_VIEW_BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <touchgfx/widgets/TiledImage.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/EasingEquations.hpp>
#include <touchgfx/mixins/FadeAnimator.hpp>

class Screen1ViewBase : public touchgfx::View<Screen1Presenter>
{
public:
    Screen1ViewBase();
    virtual ~Screen1ViewBase() {}

    virtual void setupScreen();
    virtual void afterTransition();

    /*
     * Custom Action Handlers
     */
    virtual void updateLEDState()
    {
        // Override and implement this function in Screen1View
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::TiledImage TILEDIMG_BG_Screen1;
    touchgfx::ToggleButton toggleButton1;
    touchgfx::Button BTN_Go_Screen_Auth;
    touchgfx::TextArea TXT_Bonjour;
    touchgfx::Image image1;
    touchgfx::FadeAnimator< touchgfx::TextAreaWithOneWildcard > TXT_Nb_Voleurs;
    touchgfx::Button BTN_Go_Screen_Alarmes;
    touchgfx::Image image2;
    touchgfx::TextAreaWithOneWildcard TXTStatut;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TXT_NB_VOLEURS_SIZE = 5;
    touchgfx::Unicode::UnicodeChar TXT_Nb_VoleursBuffer[TXT_NB_VOLEURS_SIZE];
    static const uint16_t TXTSTATUT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar TXTStatutBuffer[TXTSTATUT_SIZE];

private:

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Screen1ViewBase, const touchgfx::AbstractButton&> buttonCallback;

};

#endif // SCREEN1_VIEW_BASE_HPP
