//
//  animals.hpp
//  w05-24-inheritance
//
//  Created by Sergey Gordeev on 28.01.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef animals_hpp
#define animals_hpp

#include <iostream>
#include <string>

class Animal {
public:
    // ваш код
    Animal(std::string name):Name(name){};
    const std::string Name;
};


class Dog: public Animal {
public:
    // ваш код
    Dog(std::string name):Animal(name){}
    void Bark() {
        std::cout << Name << " barks: woof!" << std::endl;
    }
};

#endif /* animals_hpp */
