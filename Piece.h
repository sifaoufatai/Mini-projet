#include <iostream>
#ifndef PIECE_H
#define PIECE_H
class Piece{
    public :
                char left;
                char  top;
                char  right; 
                char bot;

   
            bool used; 
            Piece();
                
            
            Piece(char left, char top, char right , char bot ) ;
    

};
#endif