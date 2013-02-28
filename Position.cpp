#include "Position.h"
#include "Traitses.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
static const double Pi = 3.14159265358979;

const TCTraitsDouble TCPosition::sLatitudeTraits(
  "Latitude",
  "deg",
  5,
  180/Pi);

const TCTraitsDouble TCPosition::sAltitudeTraits(
  "Altitude",
  "m MSL");

const TCTraitsUnsigned TCPosition::sStepsTraits("Steps");

template <>
const TCTraitses<TCPosition>::TDItems TCTraitses<TCPosition>::mItems =
{
  MakeItem<TCPosition>(TCPosition::sLatitudeTraits, &TCPosition::mLatitude),
  MakeItem<TCPosition>(TCPosition::sAltitudeTraits, &TCPosition::mAltitude),
  MakeItem<TCPosition>(TCPosition::sStepsTraits, &TCPosition::mSteps)
};
