#pragma once
#include <iosfwd>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class TCIoTraitsUnsigned
{
  public:

    typedef unsigned TDType;

    enum TEEncoding
    {
      eUint32BigEndian
    };

    TCIoTraitsUnsigned(
      TEEncoding Encoding,
      unsigned ScaleToEncode = 1,
      unsigned TranslateToEncode = 0);

    TEEncoding mEncoding;

    unsigned mScaleToEncode;

    unsigned mTranslateToEncode;

    void Write(unsigned Value, std::ostream& Stream) const;
};
