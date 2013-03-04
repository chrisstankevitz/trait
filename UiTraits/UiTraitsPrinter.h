#pragma once

#include <boost/mpl/bool.hpp>
#include <iostream>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TCUiTraitsPrinter
{
  public:

    typedef boost::mpl::bool_<true> TDRead;

    template <class TATraits>
    void operator()(
      const TATraits& Traits,
      const typename TATraits::TDType& Value)
    {
      std::cout << Traits.GetString(Value) << '\n';
    }
};
