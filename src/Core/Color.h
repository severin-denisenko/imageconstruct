//
// Created by Severin on 06.12.2022.
//

#ifndef IMAGECONSTRUCT_COLOR_H
#define IMAGECONSTRUCT_COLOR_H

#include "types.h"
#include <iostream>
#include <fstream>

template<typename T>
class Color {
public:
    Color();
    virtual ~Color();
    explicit Color(T r);
    explicit Color(T r, T g);
    explicit Color(T r, T g, T b);
    explicit Color(T r, T g, T b, T a);

    virtual Color<T> operator+ (const Color<T> & first) const;
    virtual Color<T> operator- (const Color<T> & first) const;
    virtual Color<T> operator* (const T& first) const;
    virtual Color<T> operator/ (const T& first) const;

    T r;
    T g;
    T b;
    T a;

    size_type depth;
};

template<typename T>
Color<T>::Color() : r(0), g(0), b(0), a(0), depth(0) {

}

template<typename T>
Color<T>::Color(T r) : r(r), g(0), b(0), a(0), depth(1) {

}

template<typename T>
Color<T>::Color(T r, T g) : r(r), g(g), b(0), a(0), depth(2) {

}

template<typename T>
Color<T>::Color(T r, T g, T b) : r(r), g(g), b(b), a(0), depth(3) {

}

template<typename T>
Color<T>::Color(T r, T g, T b, T a) : r(r), g(g), b(b), a(a), depth(4) {

}

template<typename T>
Color<T> Color<T>::operator+(const Color<T> &first) const {
    Color<T> res = Color<T>();
    res.depth = this->depth;

    res.r = this->r + first.r;
    res.g = this->g + first.g;
    res.b = this->b + first.b;
    res.a = this->a + first.a;

    return res;
}

template<typename T>
Color<T> Color<T>::operator-(const Color<T> &first) const {
    Color<T> res = Color<T>();
    res.depth = this->depth;

    res.r = this->r - first.r;
    res.g = this->g - first.g;
    res.b = this->b - first.b;
    res.a = this->a - first.a;

    return res;
}

template<typename T>
Color<T> Color<T>::operator*(const T &first) const {
    Color<T> res = Color<T>();
    res.depth = this->depth;

    res.r = this->r * first;
    res.g = this->g * first;
    res.b = this->b * first;
    res.a = this->a * first;

    return res;
}

template<typename T>
Color<T> Color<T>::operator/(const T &first) const {
    Color<T> res = Color<T>();
    res.depth = this->depth;

    res.r = this->r / first;
    res.g = this->g / first;
    res.b = this->b / first;
    res.a = this->a / first;

    return res;
}

template<typename T>
Color<T>::~Color() = default;

template<typename U, typename T>
U& operator<< (U& out, const Color<T> &color) {

    switch (color.depth) {
        case 0:
            break;
        case 1:
            out << +color.r << std::endl;
            break;
        case 2:
            out << +color.r << " " << +color.g << std::endl;
            break;
        case 3:
            out << +color.r << " " << +color.g << " " << +color.b << std::endl;
            break;
        case 4:
            out << +color.r << " " << +color.g << " " << +color.b << " " << +color.a << std::endl;
            break;
        default:
            std::cerr << "Invalid color depth: " << color.depth << std::endl;
    }

    return out;
}

template<typename U, typename T>
U& operator>> (U& in, Color<T> &color) {

    size_type r = 0;
    size_type g = 0;
    size_type b = 0;
    size_type a = 0;

    switch (color.depth) {
        case 0:
            break;
        case 1:
            in >> r;
            break;
        case 2:
            in >> r;
            in >> g;
            break;
        case 3:
            in >> r;
            in >> g;
            in >> b;
            break;
        case 4:
            in >> r;
            in >> g;
            in >> b;
            in >> a;
            break;
        default:
            std::cerr << "Invalid color depth: " << color.depth << std::endl;
    }

    color.r = (T) r;
    color.g = (T) g;
    color.b = (T) b;
    color.a = (T) a;

    return in;
}

#endif //IMAGECONSTRUCT_COLOR_H