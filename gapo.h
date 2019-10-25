#include "Indicator.h"


#pragma once
class GAPO
{
public:
   GAPO(void);
   ~GAPO(void);

   void Eval(stockIndicator* pGAPO, CArray<stockDailys*, stockDailys*>* aryDailys);

};
#pragma once
