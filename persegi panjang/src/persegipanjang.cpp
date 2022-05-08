#include "include/persegipanjang.hpp"

PersegiPanjang::PersegiPanjang(int xpusat, int ypusat, int panjang, int lebar)
{
    xmax = xpusat + (panjang / 2.f);
    xmin = xpusat - (panjang / 2.f);
    ymax = ypusat + (lebar / 2.f);
    ymin = ypusat - (lebar / 2.f);
}

PersegiPanjang PersegiPanjang::operator+(PersegiPanjang &pp)
{
    if (!(*this == pp))
        throw;

    float new_xmin, new_xmax, new_ymin, new_ymax;

    if (this->GetXmin() < pp.GetXmin()) new_xmin = this->GetXmin();
    else new_xmin = pp.GetXmin();
    if (this->GetXmax() > pp.GetXmax()) new_xmax = this->GetXmax();
    else new_xmax = pp.GetXmax();
    if (this->GetYmin() < pp.GetYmin()) new_ymin = this->GetYmin();
    else new_ymin = pp.GetYmin();
    if (this->GetYmax() > pp.GetYmax()) new_ymax = this->GetYmax();
    else new_ymax = pp.GetYmax();
    PersegiPanjang result(new_xmin, new_xmax, new_ymin, new_ymax);

    return result;
}

PersegiPanjang PersegiPanjang::operator-(PersegiPanjang &pp)
{
    if (!(*this == pp))
        throw;
    float new_xmin, new_xmax, new_ymin, new_ymax;

    if (this->GetXmin() > pp.GetXmin()) new_xmin = this->GetXmin();
    else new_xmin = pp.GetXmin();
    if (this->GetXmax() < pp.GetXmax()) new_xmax = this->GetXmax();
    else new_xmax = pp.GetXmax();
    if (this->GetYmin() > pp.GetYmin()) new_ymin = this->GetYmin();
    else new_ymin = pp.GetYmin();
    if (this->GetYmax() < pp.GetYmax()) new_ymax = this->GetYmax();
    else new_ymax = pp.GetYmax();
    PersegiPanjang result(new_xmin, new_xmax, new_ymin, new_ymax);

    return result;
}

PersegiPanjang PersegiPanjang::operator--()
{
    int panjang, lebar;

    panjang = xmax - xmin;
    lebar = ymax - ymin;

    xmax -= panjang / 4.f;
    xmin += panjang / 4.f;
    ymax -= lebar / 4.f;
    ymin += lebar / 4.f;   

    return *this;
}

PersegiPanjang PersegiPanjang::operator--(int)
{
    PersegiPanjang old = *this;
    operator--();
    return old;
}
PersegiPanjang PersegiPanjang::operator++()
{
    int panjang, lebar;

    panjang = xmax - xmin;
    lebar = ymax - ymin;

    xmax += panjang / 2.f;
    xmin -= panjang / 2.f;
    ymax += lebar / 2.f;
    ymin -= lebar / 2.f;    

    return *this;
}

PersegiPanjang PersegiPanjang::operator++(int)
{
    PersegiPanjang old = *this;
    operator++();
    return old;
}

bool PersegiPanjang::operator==(PersegiPanjang &pp)
{
    bool xIrisan = (this->GetXmin() < pp.GetXmax()) && (pp.GetXmin() < this->GetXmax());
    bool yIrisan = (this->GetYmin() < pp.GetYmax()) && (pp.GetYmin() < this->GetYmax());
    return xIrisan && yIrisan;
}

float PersegiPanjang::operator[](int index)
{
    if (index % 4 == 0) return xmin;
    if (index % 4 == 1) return xmax;
    if (index % 4 == 2) return ymin;
    if (index % 4 == 3) return ymax;
}