//
//  main.cpp
//  w05-26-figures
//
//  Created by Sergey Gordeev on 05.02.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include "test_runner.hpp"
#include "assertation_tools.hpp"

using namespace std;

class Figure{
public:
    virtual string Name() const = 0;
    virtual float Perimeter() = 0;
    virtual float Area() = 0;
private:
    const string name;
protected:
    float perimeter = numeric_limits<int>::min();
    float area = numeric_limits<int>::min();
};

class Rect:public Figure{
public:
    Rect(float aHeight, float aWeight):height(aHeight), weight(aWeight){}
    virtual string Name() const override{
        return "RECT";
    }
    virtual float Perimeter() override{
        if (perimeter < 0){
            perimeter = 2 * (height + weight);
        }
        return perimeter;
    }
    virtual float Area() override{
        if (area < 0){
            area = height * weight;
        }
        return area;
    }
private:
    float height;
    float weight;
    
};

class Triangle:public Figure{
public:
    Triangle(float anA, float aB, float aC): a(anA), b(aB), c(aC){}
    virtual string Name() const override{
        return "TRIANGLE";
    }
    virtual float Perimeter() override{
        if (perimeter < 0){
            perimeter = a + b + c;
        }
        return perimeter;
    }
    virtual float Area() override{
        if (area < 0){
            area = a * b * c;
        }
        return area;
    }
private:
    float a;
    float b;
    float c;
};

class Circle:public Figure{
public:
    Circle(float aR):r(aR){}
    virtual string Name() const override{
        return "CIRCLE";
    }
    virtual float Perimeter() override{
        if (perimeter < 0){
            perimeter = 2 * Pi * r;
        }
        return perimeter;
    }
    virtual float Area() override{
        if (area < 0){
            area = Pi * pow(r,2);
        }
        return area;
    }
private:
    float r;
    const float Pi = 3.14;
    
};

shared_ptr<Figure> CreateFigure(istringstream& is){
    string name;
    is >> name;
    if (name == "TRIANGLE"){
        float a,b,c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a,b,c);
    } else
        if (name == "CIRCLE"){
            float r;
            is >> r;
            return make_shared<Circle>(r);
        }
    
    if (name == "RECT"){
        float h,w;
        is >> h >> w;
        return make_shared<Rect>(h,w);
    }
    throw domain_error("figure is unknowen");
}
void CircleTest(){
    istringstream is("CIRCLE 1.23");
    auto f = CreateFigure(is);
    stringstream s;
    s << fixed << setprecision(3)<< f->Name() << " " << f->Perimeter()<<" "<< f->Area();
    AssertEq("CIRCLE 7.724 4.751", s.str(),"circle name");
}
void RectTest(){
    istringstream is("RECT 1.23 1.23");
    auto f = CreateFigure(is);
    stringstream s;
    s << fixed << setprecision(3)<< f->Name() << " " << f->Perimeter()<<" "<< f->Area();
    AssertEq("RECT 4.920 1.513", s.str(),"rect");
}

void TriangleTest(){
    istringstream is("TRIANGLE 1.23 1.23 1.23");
    auto f = CreateFigure(is);
    stringstream s;
    s << fixed << setprecision(3)<< f->Name() << " " << f->Perimeter()<<" "<< f->Area();
    AssertEq("TRIANGLE 3.690 1.861", s.str(), "triangle");
}
int main() {
    {
        TestRunner r;
        r.RunTest(CircleTest, "CircleTest");
        r.RunTest(RectTest, "RectTest");
        r.RunTest(TriangleTest, "TriangleTest");
    }
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);
        
        string command;
        is >> command;
        if (command == "ADD") {
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                << current_figure->Name() << " "
                << current_figure->Perimeter() << " "
                << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}
