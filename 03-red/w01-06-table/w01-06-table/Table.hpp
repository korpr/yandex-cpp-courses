//
//  Table.hpp
//  w01-06-table
//
//  Created by Sergey Gordeev on 16.03.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef Table_hpp
#define Table_hpp

#include <stdio.h>

#include "Table.hpp"
#include <vector>

template <typename T>
class Table{
public:
    Table(const size_t rowsCount, const size_t columnsCount):size(rowsCount,columnsCount),rows(rowsCount, std::vector<T>(columnsCount)){}
    std::vector<T>& operator [](size_t idx) {
        return rows[idx];
    };
   const std::vector<T> operator [](size_t idx) const {
        return rows[idx];
    };
    void Resize(const size_t rowsCount, const size_t columnsCount){
        size = std::make_pair(rowsCount,columnsCount);
        rows.resize(rowsCount);
        for(auto& r:rows){
            r.resize(columnsCount);
        }
    }
    std::pair<size_t, size_t> Size() const{
        return size;
    }
private:
    
    std::pair<size_t,size_t> size;
    std::vector<std::vector<T>> rows;
};


#endif /* Table_hpp */
