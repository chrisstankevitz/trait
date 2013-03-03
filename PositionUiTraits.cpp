#include "PositionUiTraits.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
static const double Pi = 3.14159265358979;

const TCUiTraitsDouble TCPositionUiTraits::sLatitudeTraits(
  "Latitude",
  "deg",
  5,
  180/Pi);

const TCUiTraitsDouble TCPositionUiTraits::sAltitudeTraits(
  "Altitude",
  "m MSL");

const TCUiTraitsUnsigned TCPositionUiTraits::sStepsTraits("Steps");

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
TCPositionUiTraits::TCPositionUiTraits()
  : TCTraitses<TCPosition, TCUiTraitsDouble, TCUiTraitsUnsigned>
({
  Make(sLatitudeTraits, &TCPosition::mLatitude),
  Make(sAltitudeTraits, &TCPosition::mAltitude),
  Make(sStepsTraits, &TCPosition::mSteps)
})
{
}
