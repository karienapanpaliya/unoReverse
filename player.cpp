#include "card.h"
#include "player.h"
#include <iostream>
#include <iomanip>

Player::Player() {}
Player::~Player() {}

bool Player::play(Card* top, std::vector <Card*>& drawPile, std::vector<Card*>& discardPile){
    std::cout << drawPile.size() << std::endl;
    std::cout << discardPile.size() << std::endl;
    for(size_t i =0; i < hand_.size(); i++){
        std::cout << hand_[i]->getColor() << " "; 
        if(hand_[i]->getNumber() != -1 ){
            std::cout << hand_[i]->getNumber() << " "; 
        }
        else{
            std::cout << "special " << std::endl;
        }
    }

    // check if card is wild / + 2 / block / reverse
    if( top->getType() == 2){
        std::cout << "+4!" << std::endl;
        for(int i=0; i < 4 && !drawPile.empty(); i++){
            Card* card = drawPile.back(); 
            hand_.push_back(card); 
            drawPile.pop_back(); 
        }
        return false; 
    }
    
    if(top->getType() == 1){
        if(top->getAction() == 0){
            // add 2
            if(!drawPile.empty()){
            Card* card = drawPile.back();
            hand_.push_back(card);}
           if(!drawPile.empty()){
            Card* card = drawPile.back();
            hand_.push_back(card);}
        }
    
        else if(top->getAction() == 1){
            // next player's turn
            std::cout << "Turn blocked!" << std::endl;
        }

        else if(top->getAction() == 2){
            // no implementation right now 
            std::cout << "reverse order" << std::endl;
        }
        return false;
        
    }


    // check if player has a +4 card or normal card
  
    for(size_t i=0; i < hand_.size(); i++){
        Card* curr = hand_[i]; 
        if(curr->getType() == 2){
            discardPile.push_back(curr); 
            //top = hand_[i]; 
            hand_.erase(hand_.begin()+ i); 
            return true;
        } 
    
                    // look for the same color
        if(hand_[i]->getColor() == top->getColor()){
            //top = hand_[i]; 
            discardPile.push_back(curr); 
            hand_.erase(hand_.begin()+ i); 
            return true; 
            }

        if(hand_[i]->getNumber() == top->getNumber()){
            //top = hand_[i]; 
            discardPile.push_back(curr); 
            hand_.erase(hand_.begin()+ i); 
            return true; 
            }


        
        }
         return false; 
    }

void Player::printHand(){
    for(size_t i = 0; i < hand_.size(); i++){
        hand_[i]->printCard();
        std::cout << " ";
    }
}
