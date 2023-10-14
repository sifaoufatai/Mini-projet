#include <iostream>
#include <fstream>
#include "Bord.h"
#include "Piece.h"
#include <vector>
using namespace std;
char bordcolor;
/*important on admet que x reprente les collonne et y les ligne */
Bord::Bord(const char* filename) {
    char top, left, bot, right;
    ifstream file(filename);
    if (file) {
        file >> this->row;
        file >> this->col;

        this->bord = new Piece*[row];
        for (int i = 0; i < row; i++) {
            this->bord[i] = new Piece[this->col];
        }

        for (int k = 0; k < this->row * this->col; k++) {
            file >> left;
            file >> top;
            file >> right;
            file >> bot;
            this->listPieces.push_back(Piece(left, top, right, bot));
            this->listPieces[k].used= false ;
        }
    }
    file.close();
}

bool Bord::isposible(Piece** bord, int x, int y, int position) {
    if (listPieces[position].used== false) {
        if(x==0 && y==0){
            if (listPieces[position].left==listPieces[position].top){
                bordcolor=listPieces[position].left;
                cout<< bordcolor << endl;
                return true;
            }
            return false ;
        }
       else if((x == 0 || listPieces[position].left == bord[x - 1][y].right) &&
            (y == 0 || listPieces[position].top == bord[x][y - 1].bot )) {
    //uniformiser la couleur de bord 
                if(x==0 && y!=col-1 ) return listPieces[position].left==bordcolor ;

                else if(x==col-1 && y !=col-1) return listPieces[position].right==bordcolor ;
                else if(y==0 && x!=col-1) return listPieces[position].top==bordcolor ;
                else if (y==col-1 && x!=col-1) return listPieces[position].bot==bordcolor ;
                    //last angle 
                else if((x==col-1) && (y==col-1)) return (listPieces[position].right==bordcolor && listPieces[position].bot==bordcolor) ;
                    //second angle 
                else   if(x==0 && y==col-1) return (listPieces[position].left==bordcolor && listPieces[position].bot==bordcolor) ;
                    //third one clear
                else  if(y==0 && x==col-1 ) return listPieces[position].top==bordcolor  && listPieces[position].right==bordcolor;
                    else return true;        
                }
        /*    if(x>0)  cout<<  listPieces[position].top << "  haut"<< bord[x - 1][y].bot << " bas " << y << endl;
           if(y>0)   cout <<  listPieces[position].left << " g " <<bord[x][y - 1].right  <<"d   " << x <<endl;
           else if(x==0) cout <<  listPieces[position].left << " g " <<bord[x][y - 1].right  <<"d "<< y <<endl;
           else  cout<<  listPieces[position].top << "  haut"<< bord[x - 1][y].bot << " bas " << x << endl;*/
            
        }
    return false;

    }



bool Bord::sequentielle(int x, int y) {
    if (y== row) {
        display(bord);
        return true;
    }
    else{
    for (int i = 0; i < col * row; i++) {
        if (listPieces[i].used== false) {
            if(isposible(bord , x , y , i)){
            bord[x][y] = listPieces[i];
            listPieces[i].used = true;
             
           //
          //  cout<< x << ""<<y <<""<<  i <<endl;
            int suivantX = (x + 1); 
                    int suivantY = y;
                    
                    if(suivantX == this->col){ //si on arrive à la fin de colonne, on passe à la suivante
                        suivantX = 0;
                        suivantY++;
                    }
            if (sequentielle(suivantX, suivantY)) {
                return true;
            }

            listPieces[i].used = false;
        }
    }}
    
    return false;
    }
}

void Bord::display(Piece** bord) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "   " << bord[j][i].top << "   ";
        }
        cout << endl;
        for (int j = 0; j < col; j++) {
            cout << " " << bord[j][i].left << "   " << bord[j][i].right << " ";
        }
        cout << endl;
        for (int j = 0; j < this->col; j++) {
            cout << "   " << bord[j][i].bot << "   ";
        }
        cout << endl;
        cout << endl;
    }
}

int main() {
    //const char* filena = "Puzzle5*5.txt";
  const char* filena = "Puzzle_6*6.txt";
    Bord b(filena);
    cout << endl;
   cout << b.sequentielle(0, 0) << endl;
    return 0;
}
