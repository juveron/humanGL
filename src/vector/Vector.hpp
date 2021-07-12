//
// Created by juv on 12/07/2021.
//

#ifndef HUMANGL_VECTOR_HPP
#define HUMANGL_VECTOR_HPP

#include "../../hdr/HumanGL.hpp"

class Vector3f {
public:
    float       x,y,z;
    float       dotProduct(Vector3f vec);
    Vector3f    crossProduct(Vector3f vec);
    void        normalize(void);
};


#endif //HUMANGL_VECTOR_HPP
