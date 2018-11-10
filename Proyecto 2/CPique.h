//
// Created by Carlos Reátegui on 11/10/18.
//

#ifndef PY01_CPIQUE_H
#define PY01_CPIQUE_H


class CPique{
private:
    unsigned int cantidad;
    float kgPrenda;
public:
    CPique(unsigned int, float);
    ~CPique();

    void setCantidad(unsigned int);
    void setKgPrenda(float);

    unsigned int getCantidad();
    float getKgPrenda();
};

#endif //PY01_CPIQUE_H
