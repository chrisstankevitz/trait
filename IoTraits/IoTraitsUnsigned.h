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
      unsigned Scale = 1,
      unsigned Translate = 0);

    TEEncoding mEncoding;

    unsigned mScale;

    unsigned mTranslate;

    void Write(unsigned Value, std::ostream& Stream) const;
};
