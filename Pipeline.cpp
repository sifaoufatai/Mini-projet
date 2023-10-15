#include <fstream>
#include "Bord.h"
#include "Piece.h"
#include <vector>
#include <thread>
#include "Pipeline.h"

Pipeline::Pipeline(Bord &b) : bord(b) {
    
}





Bord &Pipeline::getBord() {
    return bord;
}

   void Pipeline::setBord(Bord &b) {
    bord = b;
}


void  Pipeline::startpipeline() {
    std::vector<std::thread> threads;

    for (int y = 0; y < this->bord.col; y++) {
        thread t(&Pipeline::pipeline, this, 0, y);
        t.join();
    }

}

bool Pipeline::pipeline(int x, int y) {
    if (x== this->bord.col) {
      this->bord.display(this->bord.bord);
        return true;
    }
    else{
    for (int i = 0; i < this->bord.col *this->bord.row; i++) {
        if (this->bord.listPieces[i].used== false) {
            if(this->bord.isposible(this->bord.bord, x , y , i)){
             this->bord.bord[x][y] =this->bord.listPieces[i];
              this->bord.listPieces[i].used = true;
             
           //
          //  cout<< x << ""<<y <<""<<  i <<endl;
          
                   
            if (pipeline(x+1, y)) {
                return true;
            }

           this->bord.listPieces[i].used = false;
        }
    }}
    
    return false;
    }
}

