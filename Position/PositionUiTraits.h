#pragma once

#include "Position.h"
#include "Traits/Traitses.h"
#include "UiTraits/UiTraitsDouble.h"
#include "UiTraits/UiTraitsUnsigned.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TCPositionUiTraits
: public TCTraitses<TCPosition, TCUiTraitsDouble, TCUiTraitsUnsigned>
{
  public:

    static const TCUiTraitsDouble sLatitudeTraits;

    static const TCUiTraitsDouble sAltitudeTraits;

    static const TCUiTraitsUnsigned sStepsTraits;

    TCPositionUiTraits();
};
