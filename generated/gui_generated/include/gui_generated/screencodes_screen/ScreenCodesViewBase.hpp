/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREENCODES_VIEW_BASE_HPP
#define SCREENCODES_VIEW_BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screencodes_screen/ScreenCodesPresenter.hpp>
#include <touchgfx/widgets/TiledImage.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/Image.hpp>

class ScreenCodesViewBase : public touchgfx::View<ScreenCodesPresenter>
{
public:
    ScreenCodesViewBase();
    virtual ~ScreenCodesViewBase() {}

    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::TiledImage tiledImage1;
    touchgfx::TextArea textArea1;
    touchgfx::Button button1;
    touchgfx::Image image1;

private:

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

    /*
     * Callback Declarations
     */
    touchgfx::Callback<ScreenCodesViewBase, const touchgfx::AbstractButton&> buttonCallback;

};

#endif // SCREENCODES_VIEW_BASE_HPP
