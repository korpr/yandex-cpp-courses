//
//  permutator.cpp
//  w04-17-all-variants
//
//  Created by Sergey Gordeev on 19/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include "permutator.hpp"


std::vector<int> GenerateVector( int n){
    std::vector<int> result(n);
    int i  = n;
    std::generate(result.begin(), result.end(), [i]()mutable{
        return i--;
    });
    return result;
}

std::vector<std::vector<int>> AllPermutations(const int& n){
    std::vector<int> base = GenerateVector(n);
    std::vector<std::vector<int>> result;
    do{
        result.push_back(base);
    }while(std::prev_permutation(base.begin(),base.end()));
    return result;
}
