#include "PositionUiTraits.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
static const double Pi = 3.14159265358979;

const TCTraitsDouble TCPositionUiTraits::sLatitudeTraits(
  "Latitude",
  "deg",
  5,
  180/Pi);

const TCTraitsDouble TCPositionUiTraits::sAltitudeTraits(
  "Altitude",
  "m MSL");

const TCTraitsUnsigned TCPositionUiTraits::sStepsTraits("Steps");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
TCPositionUiTraits::TCPositionUiTraits()
  : TCTraitses<TCPosition>({
  Make(sLatitudeTraits, &TCPosition::mLatitude),
  Make(sAltitudeTraits, &TCPosition::mAltitude),
  Make(sStepsTraits, &TCPosition::mSteps)
  })
{
}
