#include "Bord.h"

class Pipeline
{
private:
    Bord &bord;
public:
    Pipeline(Bord &b );
  
   void  startpipeline();
    bool pipeline(int x, int y);
     Bord &getBord();  // Getter pour l'attribut "bord"
    void setBord(Bord &b);  // Setter pour l'attribut "bord"

};

