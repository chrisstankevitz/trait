#pragma once
#include <iosfwd>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TCIoTraitsDouble
{
  public:

    typedef double TDType;

    enum TEEncoding
    {
      eFloat64BigEndian,
      eUint32BigEndian
    };

    TCIoTraitsDouble(
      TEEncoding Encoding,
      double Scale = 1,
      double Translate = 0);

    TEEncoding mEncoding;

    double mScale;

    double mTranslate;

    void Write(double Value, std::ostream& Stream) const;
};
