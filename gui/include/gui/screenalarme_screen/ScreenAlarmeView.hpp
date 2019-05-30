#ifndef SCREENALARME_VIEW_HPP
#define SCREENALARME_VIEW_HPP

#include <gui_generated/screenalarme_screen/ScreenAlarmeViewBase.hpp>
#include <gui/screenalarme_screen/ScreenAlarmePresenter.hpp>

class ScreenAlarmeView : public ScreenAlarmeViewBase
{
public:
    ScreenAlarmeView();
    virtual ~ScreenAlarmeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();


    virtual void Capteur1BTN(){
		updateCapteur1();
    }
    virtual void Capteur2BTN(){
        updateCapteur2();
    }
    virtual void Capteur3BTN(){
        updateCapteur3();
    }
    virtual void ToutEteindre(){
    	if(toggleButtonToutEteindre.getState()){
    		toggleButtonCapteur1.forceState(true);
			toggleButtonCapteur2.forceState(true);
			toggleButtonCapteur3.forceState(true);

			updateCapteur1();
            updateCapteur2();
            updateCapteur3();
    	}
    	else{
    		toggleButtonCapteur1.forceState(false);
			toggleButtonCapteur2.forceState(false);
			toggleButtonCapteur3.forceState(false);

			updateCapteur1();
            updateCapteur2();
            updateCapteur3();
    	}
    }
    virtual char getCapteur1();
    virtual char getCapteur2();
    virtual char getCapteur3();
    virtual void updateCapteur1();
    virtual void updateCapteur2();
    virtual void updateCapteur3();
protected:
	bool Capteur1;
	bool Capteur2;
	bool Capteur3;
	bool StatutGlobal;
};

#endif // SCREENALARME_VIEW_HPP
