//
// Created by Carlos Reátegui on 11/10/18.
//

#ifndef PY01_CFRANELA_H
#define PY01_CFRANELA_H


class CFranela
{
private:
    unsigned int cantidad;
    float kgPrenda;
public:
    CFranela(unsigned int, float);
    ~CFranela();

    void setCantidad(unsigned int);
    void setKgPrenda(float);

    unsigned int getCantidad();
    float getKgPrenda();
};

#endif //PY01_CFRANELA_H
