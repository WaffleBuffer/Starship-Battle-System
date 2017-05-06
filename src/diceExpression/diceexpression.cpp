#include "diceexpression.h"

SubExpression *parseWord(const string & word, istringstream & iss, SubExpression *left) {
    if (word[0] == 'D'){
        string diceNumber = word.substr(1, word.length() - 1);
        if (diceNumber == "6") {
            return new D6();
        }
        else if(diceNumber == "10") {
            return new D10();
        }
        else {
            throw std::invalid_argument( "unsupported dice " + word);
        }
    }
    else if(utils::isUnsigned(word)) {
        unsigned value = utils::stoui(word);
        return new ConstExpression(value);
    }
    else if (word == "+") {
        string right;
        if(!(iss >> right) || left == nullptr) {
            throw std::invalid_argument( "Missing right operand on " + word);
        }
        Sum *sum = new Sum(left, nullptr);
        SubExpression *rightExp = parseWord(right, iss, sum);
        sum->setRight(rightExp);
        return sum;
    }
    else {
        // Exception
        throw std::invalid_argument( "Bad dice expression on" + word);
    }
}

DiceExpression::DiceExpression(const string & expression) throw()
{
    this->expression = expression;

    istringstream iss(expression);
    string word;
    SubExpression *parsed = nullptr;
    while(iss >> word) {
        parsed = parseWord(word, iss, parsed);
        this->parsedExpression = parsed;
    }
}

DiceExpression::~DiceExpression() {
    delete(this->parsedExpression);
}

int DiceExpression::roll() {
    return this->parsedExpression->roll();
}

int DiceExpression::getMaxValue() {
    return this->parsedExpression->getMaxValue();
}
