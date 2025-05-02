#ifndef CARD_H
#define CARD_H
#include <vector>
#include <string>
#include <iostream>

class Card {
public:
    Card(int type);
    virtual std::string getColor() const { return "none"; } // returns none if its not a number card 
    virtual int getAction() const { return -1; } // returns -1 if its not a special card 
    virtual int getNumber() const { return -1; } // same here 
    virtual ~Card();
    virtual void printCard() = 0;
    int getType(); 
    private: 
    int type_; 
};


class numCard: public Card {
    public: 
    numCard(int type, int number, std::string color);
    ~numCard();
    void printCard();
    std::string getColor() const;
    int getNumber() const;  
    private: 
     //enum colors{0=red, 1=yellow, 2=green, 3=blue, 4=black}; 
     std::string color_;
     int number_; 
     //int type_; 
}; 

class specialCard: public Card{
    public: 
    specialCard(int type, std::string color, int action);
    ~specialCard();
    std::string getColor() const;
    int getAction() const;  
    void printCard(); 
    private: 
    //enum type{0=add2, 1=blockTurn, 2= reverse};
    std::string color_;
    int action_;
    //int type_;
}; 

class wildCard: public Card{
    public: 
    wildCard(int type, int action);
    ~wildCard();
    void printCard();
    private: 
    //enum type(0=changeColor, 1=take4);
    int action_;
    //int type_; 
}; 

#endif


