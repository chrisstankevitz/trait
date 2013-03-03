#include "IoTraits/IoTraitsEncoder.h"
#include "UiTraits/UiTraitsPrinter.h"
#include "Position/Position.h"
#include "Position/PositionIoTraits.h"
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

  static TCPositionIoTraits PositionIoTraits;

  TCIoTraitsEncoder IoTraitsEncoder;

  PositionIoTraits.Visit(IoTraitsEncoder, Position);

  std::cout
    << "Encoded position byte count: "
    << IoTraitsEncoder.mStream.str().size()
    << std::endl;

  return 0;
}

