#pragma once

#include <stdio.h>
#include <iostream>

// template <typename C>
// void Dump(const C& c) {
//     for (size_t i = 0; i < c.size(); ++i) {
//         std::cout << c[i] << std::endl;
//     }
// }

template <typename C>
void Dump(const C& c) {
    for (auto v : c) {
        std::cout << v << std::endl;
    }
}
