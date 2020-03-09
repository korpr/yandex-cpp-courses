//
//  node.hpp
//  w06-28-capstone
//
//  Created by Sergey Gordeev on 10.02.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#ifndef node_hpp
#define node_hpp

#include <string>
#include "date.h"

enum Comparison{
    Less,LessOrEqual,Greater,GreaterOrEqual,Equal,NotEqual
};
enum LogicalOperation{
    And, Or
};
using namespace std;
class Node{
public:
    virtual bool Evaluate(const Date& date, const string& condition) const = 0;
};
class EmptyNode: public Node{
public:
     virtual bool Evaluate(const Date& date, const string& condition) const override;
};
class ComparisonNode : public Node{
public:
    ComparisonNode(const Comparison aComparison);
    virtual bool Evaluate(const Date& date, const string& condition) const override;
protected:
    const Comparison comparison;
};
class DateComparisonNode: public ComparisonNode{
public:
    DateComparisonNode(const Comparison comparison, const Date date);
    virtual bool Evaluate(const Date& date, const string& condition) const override;
private:
    const Date value;
};
class EventComparisonNode: public ComparisonNode{
public:
    EventComparisonNode(const Comparison comparison, const string event);
    virtual bool Evaluate(const Date& date, const string& condition) const override;
private:
    const string value;
};
class LogicalOperationNode: public Node{
public:
    LogicalOperationNode(const LogicalOperation anOperation,const int aValue,const shared_ptr<Node> aLeft, const shared_ptr<Node> anRight);
    LogicalOperationNode(const LogicalOperation anOperation,const int aValue);
    LogicalOperationNode(const LogicalOperation anOperation,const shared_ptr<Node> aLeft, const shared_ptr<Node> anRight);
    virtual bool Evaluate(const Date& date, const string& condition)  const override;
private:
    const LogicalOperation operation;
    const int value;
    const shared_ptr<Node> left;
    const shared_ptr<Node> right;
   
};



#endif /* node_hpp */
