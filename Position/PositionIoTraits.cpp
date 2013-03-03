#include "PositionIoTraits.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
static const double Pi = 3.14159265358979;

const TCIoTraitsDouble TCPositionIoTraits::sLatitudeTraits(
  TCIoTraitsDouble::eFloat64BigEndian);

const TCIoTraitsDouble TCPositionIoTraits::sAltitudeTraits(
  TCIoTraitsDouble::eFloat64BigEndian);

const TCIoTraitsUnsigned TCPositionIoTraits::sStepsTraits(
  TCIoTraitsUnsigned::eUint32BigEndian);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
TCPositionIoTraits::TCPositionIoTraits()
  : TCTraitses<TCPosition, TCIoTraitsDouble, TCIoTraitsUnsigned>
({
  Make(sLatitudeTraits, &TCPosition::mLatitude),
  Make(sAltitudeTraits, &TCPosition::mAltitude),
  Make(sStepsTraits, &TCPosition::mSteps)
})
{
}
