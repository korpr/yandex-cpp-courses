//
//  rectangle.cpp
//  w03-11-class-def
//
//  Created by Sergey Gordeev on 15/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include "rectangle.hpp"
Rectangle::Rectangle(int width, int height) : width_(width), height_(height)
{
}

int Rectangle::GetArea() const {
    return width_ * height_;
}

int Rectangle::GetPerimeter() const {
    return 2 * (width_ + height_);
}

int Rectangle::GetWidth() const { return width_; }
int Rectangle::GetHeight() const { return height_; }
