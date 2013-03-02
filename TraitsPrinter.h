#pragma once
#include "TraitsDouble.h"
#include <iostream>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TCTraitsPrinter
{
  public:

    template <typename TATraits>
    void operator()(
      const TATraits& Traits,
      const typename TATraits::TDType& Value) const
    {
      std::cout << Traits.GetString(Value) << '\n';
    }
};
