#include "card.h"
#include <iostream>
#include <iomanip>

using namespace std;

Card::Card(int type) : type_(type) {}

int Card::getType(){
    return type_;
}
 

Card::~Card(){}

numCard::~numCard(){}

specialCard::~specialCard(){}

wildCard::~wildCard(){}

numCard::numCard(int type, int number, std::string color) : Card(type), color_(color), number_(number){}

specialCard::specialCard(int type, std::string color, int action) : Card(type), color_(color), action_(action){}

wildCard::wildCard(int type, int action) : Card(type), action_(action) {}

void numCard::printCard(){
    cout << color_ << " " << number_ << endl; 
}

void specialCard::printCard(){
    string action[3] = {"Add 2", "Block Turn", "Reverse"};
    if(action_ >= 0 && action_ <= 3) 
   { cout << color_ << " " << action[action_] << endl; }
   else{
    cout << color_ << "unknown action" << endl;
   }
}

void wildCard::printCard(){
    cout << "Plus 4" << endl; 
}

std::string numCard::getColor() const {
    return color_;
}

std::string specialCard::getColor() const {
    return color_;
}

int specialCard::getAction() const{
    return action_; 
} 

int numCard::getNumber() const{
    return number_; 
}
