#ifndef MODEL_HPP
#define MODEL_HPP

#include <touchgfx/Utils.hpp>

class ModelListener;

/**
 * The Model class defines the data model in the model-view-presenter paradigm.
 * The Model is a singular object used across all presenters. The currently active
 * presenter will have a pointer to the Model through deriving from ModelListener.
 *
 * The Model will typically contain UI state information that must be kept alive
 * through screen transitions. It also usually provides the interface to the rest
 * of the system (the backend). As such, the Model can receive events and data from
 * the backend and inform the current presenter of such events through the modelListener
 * pointer, which is automatically configured to point to the current presenter.
 * Conversely, the current presenter can trigger events in the backend through the Model.
 */
class Model
{
public:
    Model();

    /**
     * Sets the modelListener to point to the currently active presenter. Called automatically
     * when switching screen.
     */
    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    /**
     * This function will be called automatically every frame. Can be used to e.g. sample hardware
     * peripherals or read events from the surrounding system and inject events to the GUI through
     * the ModelListener interface.
     */
    void tick();

    void updateLEDVERTEState(bool);

    int getnbVoleurs() const {return nbVoleurs;}
    int getAuth() const {return auth;}
    int getCodeEntre() const {return codeEntre;}

    int getColorBarR() const {return ColorBarR;}
    int getColorBarG() const {return ColorBarG;}
    int getColorBarB() const {return ColorBarB;}

    bool getCapteur1() const {return Capteur1;}
    bool getCapteur2() const {return Capteur2;}
    bool getCapteur3() const {return Capteur3;}

    int getAlphaTXT() const {return AlphaTXT;}
    int getState() const {return State;}

    void setBTN(char a) {BTN = a;}

    void setCapteur1(bool a){Capteur1 = a;}
    void setCapteur2(bool a){Capteur2 = a;}
    void setCapteur3(bool a){Capteur3 = a;}

    void BonpasBon();
    void Bleutermediaire();
    void Restart();

protected:
    /**
     * Pointer to the currently active presenter.
     */
    ModelListener* modelListener;
private:
    int nbVoleurs;
    int AlphaTXT;
    int compteur;
    int auth;
    bool codeTape;
    char codeEntre;
    char codeEntre1, codeEntre2, codeEntre3, codeEntre4;
    char codeAdmin1, codeAdmin2, codeAdmin3, codeAdmin4;
    int ColorBarR;
    int ColorBarG;
    int ColorBarB;
    bool ilFautRestart;
    bool Gagne;
    bool Capteur1, Capteur2, Capteur3;
    char BTN;
    int State;
    int compteurTeleco;
    bool CaSonne;
    bool CodeBon;

    
};

#endif /* MODEL_HPP */
