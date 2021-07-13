//
// Created by juv on 12/07/2021.
//

#ifndef HUMANGL_MATRIX_HPP
#define HUMANGL_MATRIX_HPP

#include "../../hdr/HumanGL.hpp"

class Matrix {
public:
    float   matrix[16];
    Matrix(void);
    ~Matrix(void);
    void    translate(float x, float y, float y);
    void    translate(float xyz);
    void    scale(float x, float y, float y);
    void    scale(float xyz);
    void    rotate(float angle, e_axis axis);

    void    multiply(Matrix mat);
    void    multiply(Vector3f vec);
    void    add(Matrix mat);
    void    sub(Matrix mat);
};


#endif //HUMANGL_MATRIX_HPP
