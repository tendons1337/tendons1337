#include "pch.h"
#include "gapo.h"

GAPO::GAPO(void)
{
}

GAPO::~GAPO(void)
{
}

void GAPO::Eval(stockIndicator* pGAPO, CArray<stockDailys*, stockDailys*>* aryDailys)
{
   double gapo = 0, high = 0, open = 0;
   for (int i = 0; i < aryDailys->GetCount(); i++)
   {
      if (i > 0)
      {
         open = aryDailys->GetAt(i)->Open;
         high = aryDailys->GetAt(i)->High; 

         gapo = ((high - open) / open);   // Values are -1 to 1
         if (isnan(gapo) || isinf(gapo))
            gapo = 0;

         CString sDate(aryDailys->GetAt(i)->Date);
         pGAP->Code = aryDailys->GetAt(i)->Code;
         pGAP->Date.Add(sDate);
         pGAP->values.Add(gapo);
         pGAP->map.SetAt(sDate, pGAP->values.GetCount());


      }
   }
}