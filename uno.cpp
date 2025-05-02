#include <iostream>
#include <vector>
#include "card.h"
#include "uno.h"
#include "parser.h"
#include "player.h"

uno::uno() {}


void uno::readCards(std::istream& is, Parser& p){
    p.parse(is, drawPile);
} 

void uno::dealCards(Player& p1, Player& p2){
    for(int i=0; i < 7; i++){
        Card* card = drawPile.back(); 
        p1.hand_.push_back(card);
        drawPile.pop_back(); 

         card = drawPile.back(); 
        p2.hand_.push_back(card);
        drawPile.pop_back(); 
    }
}

Card* uno::getDrawTop(){
    Card* topCard = drawPile.back();
    drawPile.pop_back(); 
    return topCard; 
}

Card* uno::getTopCard(){
    if(drawPile.empty()){
        std::cout << "draw pile is empty" << std::endl;
        return NULL;
    }
    
    Card* topCard = drawPile.back();
    drawPile.pop_back(); 
    
    return topCard;
}

std::vector<Card*>&  uno::getDrawPile (){
    return drawPile; 
}

std::vector<Card*>&  uno::getDiscardPile(){
    return discardPile; 
}
