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
  TCTraitses<TCPosition>::MakeItem(
    TCPosition::sLatitudeTraits,
    &TCPosition::mLatitude),

  TCTraitses<TCPosition>::MakeItem(
    TCPosition::sAltitudeTraits,
    &TCPosition::mAltitude),

  TCTraitses<TCPosition>::MakeItem(
    TCPosition::sStepsTraits,
    &TCPosition::mSteps)

  //MakeItem<TCPosition>(TCPosition::sLatitudeTraits, &TCPosition::mLatitude)

};
