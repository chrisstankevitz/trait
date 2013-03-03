#pragma once

#include <boost/function.hpp>
#include <iostream>
#include <sstream>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TCIoTraitsEncoder
{
  public:

    TCIoTraitsEncoder(std::ostream& Stream)
    : mStringStream(),
      mStream(Stream)
    {
    }

    TCIoTraitsEncoder()
    : mStringStream(),
      mStream(mStringStream)
    {
    }

    std::string GetBytes() const
    {
      return mStringStream.str();
    }

    template <class TATraits, class TAObject>
    void operator()(
      const TATraits& Traits,
      const TAObject& Object,
      const boost::function<const typename TATraits::TDType&(const TAObject&)>& Get,
      const boost::function<void (TAObject&, const typename TATraits::TDType&)>& Set)
    {
      Traits.Write(Get(Object), mStream);
    }

    std::ostringstream mStringStream;

    std::ostream& mStream;
};
