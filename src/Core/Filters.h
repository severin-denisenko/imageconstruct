//
// Created by Severin on 07.12.2022.
//

#ifndef IMAGECONSTRUCT_FILTERS_H
#define IMAGECONSTRUCT_FILTERS_H

#include "Map.h"
#include "Kernel.h"
#include "Operators.h"
#include "TiledMap.h"
#include "KernelCollection.h"


template<typename T>
class Filters {
public:
    Filters() = delete;

    static void GaussBlur(Map<T> &map, size_type size, double sigma);
    static void GaussBlur(TiledMap<T> &map, size_type size, double sigma);
};

template<typename T>
void Filters<T>::GaussBlur(Map<T> &map, size_type size, double sigma) {
    Kernel<double> kernel = KernelCollection<double>::GaussBlur(size, sigma);

    Operators<T>::Convolution(map, kernel);
}

template<typename T>
void Filters<T>::GaussBlur(TiledMap<T> &map, size_type size, double sigma) {
    Kernel<double> kernel = KernelCollection<double>::GaussBlur(size, sigma);

    Operators<T>::Convolution(map, kernel);
}

#endif //IMAGECONSTRUCT_FILTERS_H
