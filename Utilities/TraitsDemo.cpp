#include "UiTraits/UiTraitsPrinter.h"
#include "Position/Position.h"
#include "Position/PositionUiTraits.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main()
{
  TCPosition Position;

  Position.mLatitude = 0.2;

  Position.mAltitude = 321;

  Position.mSteps = 4;

  static TCPositionUiTraits PositionUiTraits;

  PositionUiTraits.Visit(TCUiTraitsPrinter(), Position);

  return 0;
}

