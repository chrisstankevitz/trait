#pragma once

#include <boost/function.hpp>
#include <iostream>
#include <sstream>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TCIoTraitsDecoder
{
  public:

    TCIoTraitsDecoder(std::istream& Stream)
    : mStringStream(),
      mStream(Stream)
    {
    }

    TCIoTraitsDecoder(const std::string& Bytes)
    : mStringStream(Bytes),
      mStream(mStringStream)
    {
    }

    template <class TATraits, class TAObject>
    void operator()(
      const TATraits& Traits,
      TAObject& Object,
      const boost::function<const typename TATraits::TDType&(const TAObject&)>& Get,
      const boost::function<void (TAObject&, const typename TATraits::TDType&)>& Set)
    {
      typename TATraits::TDType Value;

      Traits.Read(Value, mStream);

      Set(Object, Value);
    }

    std::istringstream mStringStream;

    std::istream& mStream;
};
