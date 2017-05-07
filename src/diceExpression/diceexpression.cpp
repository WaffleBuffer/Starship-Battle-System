#include "diceexpression.h"

SubExpression *parseWord(const string & word, istringstream & iss, SubExpression *left) {
    size_t dPos = word.find('D');
    if (dPos != std::string::npos){

        string diceNumberStr = word.substr(0, dPos);
        unsigned diceNumber = 0;

        if(!diceNumberStr.empty()) {
            if(utils::isUnsigned(diceNumberStr)) {
                diceNumber = utils::stoui(word);
            }
            else {
                throw std::invalid_argument("Bad dice name on " + word);
            }
        }

        string diceMaxValue = word.substr(dPos + 1, word.length() - dPos);
        unsigned maxValue = 0;

        if(utils::isUnsigned(diceMaxValue)) {
            maxValue = utils::stoui(diceMaxValue);
        }
        else {
            throw std::invalid_argument("Bad dice name on " + word);
        }

        Dice *dice = new Dice(word, maxValue);
        if (diceNumber > 0) {
            dice->setDiceNumer(diceNumber);
        }

        return dice;
    }
    else if(utils::isUnsigned(word)) {
        unsigned value = utils::stoui(word);
        return new ConstExpression(value, word);
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

string DiceExpression::toString()
{
    return this->parsedExpression->toString();
}
