#include "Traitses.h"
#include "Position.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main()
{
  TCPosition Position;

  Position.mLatitude = 0.2;

  Position.mAltitude = 321;

  Position.mSteps = 4;

  TCTraitses<TCPosition>::PrintValues(&Position);

  return 0;
}

