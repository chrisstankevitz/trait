#pragma once

#include <iostream>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TCUiTraitsPrinter
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
