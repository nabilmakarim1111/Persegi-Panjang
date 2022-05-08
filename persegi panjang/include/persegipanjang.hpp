#ifndef _PERSEGI_PANJANG_HPP_
#define _PERSEGI_PANJANG_HPP_

class PersegiPanjang
{
private:
    float xmin, xmax, ymin, ymax;

public:
    PersegiPanjang(int xpusat, int ypusat, int panjang, int lebar);
    PersegiPanjang(float x_min, float x_max, float y_min, float y_max)
    {
        xmax = x_max;
        xmin = x_min;
        ymax = y_max;
        ymin = y_min;
    }
    void SetXmax(float value) { xmax = value; }
    void SetXmin(float value) { xmin = value; }
    void SetYmax(float value) { ymax = value; }
    void SetYmin(float value) { ymin = value; }
    float GetXmax() { return xmax; }
    float GetXmin() { return xmin; }
    float GetYmax() { return ymax; }
    float GetYmin() { return ymin; }    

    int GetPanjang() { return xmax - xmin; }
    int GetLebar() { return ymax - ymin; }
    int GetPusatX() { return xmin + (GetPanjang() / 2.f); }
    int GetPusatY() { return ymin + (GetLebar() / 2.f); }

    bool operator==(PersegiPanjang &pp);
    PersegiPanjang operator+(PersegiPanjang &pp);
    PersegiPanjang operator-(PersegiPanjang &pp);
    PersegiPanjang operator++();
    PersegiPanjang operator++(int);
    PersegiPanjang operator--();
    PersegiPanjang operator--(int);
    float operator[](int index);
};

#endif