//
//  rectangle.hpp
//  w03-11-class-def
//
//  Created by Sergey Gordeev on 15/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef rectangle_hpp
#define rectangle_hpp

#include <stdio.h>
class Rectangle {
public:
    Rectangle(int width, int height);
    
    int GetArea() const;
    int GetPerimeter() const;
    
    int GetWidth() const;
    int GetHeight() const;
    
private:
    int width_, height_;
};
#endif /* rectangle_hpp */
