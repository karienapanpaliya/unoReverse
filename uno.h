#ifndef UNO_H
#define UNO_H
#include <iostream>
#include <stdexcept>
#include <vector>
#include "card.h"
#include "parser.h"
#include "player.h"


class uno
{
public:
    uno(); //default ctor 
    void shuffle(std::vector<Card*>& v); //shuffles deck 
    void dealCards(Player& p1, Player& p2);
    void readCards(std::istream& is, Parser& p);
    Card* getTopCard();
    std::vector<Card*>& getDrawPile ();
    std::vector<Card*>& getDiscardPile();
    Card* getDrawTop(); 


protected:
    std::vector<Card*> drawPile;
    std::vector<Card*> discardPile;

private:
    //player p0;
    //player p1; 
    //bool winner;
    //int whoseTurn; 
};

#endif 
