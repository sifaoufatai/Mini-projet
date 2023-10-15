  #ifndef BORD_H
#define BORD_H
  #include<iostream>
  #include <stdio.h>
  #include <vector>
  #include "Piece.h"
    using namespace std ;


class Bord { 
public:
    int row , col;
    vector <Piece> listPieces;
    Piece ** bord ;
    

  //  Bord(){}
       
    Bord( const char * filname);
    bool isposible(Piece **bord, int x, int y, int position);
    bool sequentielle(int x, int y);
   void display(Piece** bord);
  

   // bool sequentielle(){}
};
#endif