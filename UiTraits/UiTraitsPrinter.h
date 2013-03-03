#pragma once

#include <boost/function.hpp>
#include <iostream>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TCUiTraitsPrinter
{
  public:

    template <class TATraits, class TAObject>
    void operator()(
      const TATraits& Traits,
      const TAObject& Object,
      const boost::function<const typename TATraits::TDType&(const TAObject&)>& Get,
      const boost::function<void (TAObject&, const typename TATraits::TDType&)>& Set) const
    {
      std::cout << Traits.GetString(Get(Object)) << '\n';
    }
};
