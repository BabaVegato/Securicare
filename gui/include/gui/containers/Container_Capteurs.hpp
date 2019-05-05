#ifndef CONTAINER_CAPTEURS_HPP
#define CONTAINER_CAPTEURS_HPP

#include <gui_generated/containers/Container_CapteursBase.hpp>

class Container_Capteurs : public Container_CapteursBase
{
public:
    Container_Capteurs();
    virtual ~Container_Capteurs() {}

    virtual void initialize();
protected:
};

#endif // CONTAINER_CAPTEURS_HPP
