#include "binaryoperator.h"

std::string BinaryOperator::toString() {
    std::string res = this->left->toString() + " " + this->name + " " + this->right->toString();
    return res;
}

BinaryOperator::~BinaryOperator() {
    delete(this->left);
    delete(this->right);
}

void BinaryOperator::setRight(SubExpression *right) {
    this->right = right;
}
