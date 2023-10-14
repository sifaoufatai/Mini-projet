#include <iostream>
#include "Piece.h"


    
        Piece::Piece() : top(0), right(0), bot(0), left(0) {}
    

            
         Piece::  Piece(char left, char top, char right , char bot ) : left(left),  top(top),  right(right) , bot (bot)
         {
                used = false ;
            
         }
    

