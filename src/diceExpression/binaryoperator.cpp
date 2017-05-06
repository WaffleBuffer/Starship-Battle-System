#include "binaryoperator.h"

string BinaryOperator::getName() {
    return this->name;
}

BinaryOperator::~BinaryOperator() {
    delete(this->left);
    delete(this->right);
}

void BinaryOperator::setRight(SubExpression *right) {
    this->right = right;
}
