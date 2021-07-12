//
// Created by juv on 12/07/2021.
//

#ifndef HUMANGL_MEMBRE_H
#define HUMANGL_MEMBRE_H

#include "../../hdr/HumanGL.hpp"

class Membre {
public:
    Matrix  scaleMat;
    Matrix  currentMat;
    Membre  *parent;
    std::vector<Membre *>children;
    void    addChild(Membre *child);
    void    setParent(Membre *parent);

private:

};


#endif //HUMANGL_MEMBRE_H
