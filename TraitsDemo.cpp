#include "TraitsPrinter.h"
#include "Traitses.h"
#include "Position.h"
#include "PositionUiTraits.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main()
{
  TCPosition Position;

  Position.mLatitude = 0.2;

  Position.mAltitude = 321;

  Position.mSteps = 4;

  static TCPositionUiTraits PositionUiTraits;

  PositionUiTraits.Visit(TCTraitsPrinter(), Position);

  return 0;
}

