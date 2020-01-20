//
//  merge-sort.hpp
//  w04-19-merge-sort
//
//  Created by Sergey Gordeev on 20/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef merge_sort_hpp
#define merge_sort_hpp

#include <vector>
#include <algorithm>


template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    size_t size = range_end - range_begin;
    if (size < 2){
        return;
    }
    std::vector<typename RandomIt::value_type> elements(range_begin, range_end);
    if (size % 2 == 0){
        auto middle =  begin(elements) + size / 2;
        
        MergeSort(begin(elements), middle);
        MergeSort(middle, end(elements));
        
        std::merge(begin(elements), middle, middle, end(elements), range_begin);
    }else if (size % 3 == 0){
        size_t part_size = size / 3;
       
        auto second_part = begin(elements) + part_size;
        auto third_part = second_part + part_size;
        
        MergeSort(begin(elements),second_part);
        MergeSort(second_part, third_part);
        MergeSort(third_part, end(elements));
        
        std::vector<typename RandomIt::value_type> temp;
        std::merge(begin(elements), second_part, second_part, third_part, back_inserter(temp));
        std::merge(begin(temp), end(temp), third_part, end(elements), range_begin);
    }
    
    
}
#endif /* merge_sort_hpp */
