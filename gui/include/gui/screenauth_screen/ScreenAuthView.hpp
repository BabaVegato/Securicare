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
    virtual void bouton1appuye(){
		updateBTN('1');
    }
    virtual void bouton2appuye(){
		updateBTN('2');
    }
    virtual void bouton3appuye(){
		updateBTN('3');
    }
    virtual void bouton4appuye(){
		updateBTN('4');
    }
    virtual void bouton5appuye(){
		updateBTN('5');
    }
    virtual void bouton6appuye(){
		updateBTN('6');
    }
    virtual void bouton7appuye(){
		updateBTN('7');
    }
    virtual void bouton8appuye(){
		updateBTN('8');
    }
    virtual void bouton9appuye(){
		updateBTN('9');
    }
    virtual void boutonAappuye(){
		updateBTN('A');
    }
    virtual void boutonBappuye(){
		updateBTN('B');
    }
    virtual void boutonCappuye(){
		updateBTN('C');
    }
    virtual void boutonDappuye(){
		updateBTN('D');
    }
    virtual void boutonEappuye(){
		updateBTN('E');
    }
    virtual void boutonFappuye(){
		updateBTN('F');
    }
    virtual void bouton0appuye(){
		updateBTN('0');
    }

    virtual char getBTN();
    virtual void updateBTN(char);
protected:
	char BTN;
};

#endif // SCREENAUTH_VIEW_HPP
