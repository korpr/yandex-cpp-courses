//
//  node.cpp
//  w06-28-capstone
//
//  Created by Sergey Gordeev on 10.02.2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include "node.h"

ComparisonNode::ComparisonNode(const Comparison aComparison)
:comparison(aComparison){};
DateComparisonNode::DateComparisonNode(const Comparison comparison, const Date aDate):ComparisonNode(comparison),value(aDate){};

EventComparisonNode::EventComparisonNode(const Comparison comparison,const string event):ComparisonNode(comparison), value(event){};

LogicalOperationNode::LogicalOperationNode(
                                           const LogicalOperation anOperation,
                                           const int aValue,
                                           const shared_ptr<Node> aLeft = nullptr,
                                           const shared_ptr<Node> anRight = nullptr)
:operation(anOperation),value(aValue),right(anRight),left(aLeft){};

LogicalOperationNode::LogicalOperationNode(const LogicalOperation anOperation,const int aValue):LogicalOperationNode(anOperation, aValue,nullptr,nullptr){};

LogicalOperationNode::LogicalOperationNode(const LogicalOperation anOperation,
                                           const shared_ptr<Node> aLeft,
                                           const shared_ptr<Node> anExpression
                                           
                                           ):LogicalOperationNode(anOperation,0,aLeft,anExpression){};
bool ComparisonNode::Evaluate(const Date& date, const string& condition) const {
    return false;
};
bool DateComparisonNode::Evaluate(const Date& date, const string& condition) const {
    switch (comparison) {
        case Equal:
            return date.asTuple() == value.asTuple();
        case NotEqual:
            return date.asTuple() != value.asTuple() ;
        case Less:
            return date.asTuple() < value.asTuple();
        case LessOrEqual:
            return date.asTuple() <= value.asTuple();
        case Greater:
            return  date.asTuple() > value.asTuple();
        case GreaterOrEqual:
            return date.asTuple() >= value.asTuple() ;
        default:
            throw domain_error("operation is unknown");
    }
};
bool EventComparisonNode::Evaluate(const Date& date, const string& condition) const{
    switch (comparison) {
        case Equal:
            return condition == value;
        case NotEqual:
            return condition != value;
        case Less:
            return condition < value;
        case LessOrEqual:
            return  condition <= value;
        case Greater:
            return condition > value;
        case GreaterOrEqual:
            return condition >= value;
        default:
            throw domain_error("operation is unknown");
    }
};
bool LogicalOperationNode::Evaluate(const Date& date, const string& condition) const{
    switch (operation) {
        case And:
            return left->Evaluate(date, condition) && right->Evaluate(date, condition);
        case Or:
            return left->Evaluate(date, condition) || right->Evaluate(date, condition);
        default:
            throw domain_error("operation is unknown");
    }
};
bool EmptyNode::Evaluate(const Date&, const string&) const{
    return true;
};
