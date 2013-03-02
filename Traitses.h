#pragma once

#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <string>
#include <vector>

//-----------------------------------------------------------------------------
// This class holds all the traits ("traitses") for any object.  If you use it
// be sure to create a specialization of TCTraitses::mItems for your particular
// object, in the order you like.
//-----------------------------------------------------------------------------
template <class TAObject>
class TCTraitses
{
  public:

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    struct TSItem
    {
      virtual ~TSItem() {}

      virtual void PrintValue(const TAObject* pObject) const = 0;
    };

    typedef boost::shared_ptr<const TSItem> TDItem;

    typedef std::vector<TDItem> TDItems;

    void PrintValues(const TAObject* pObject)
    {
      for (const auto& pItem : mItems)
      {
        pItem->PrintValue(pObject);
      }
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    TCTraitses(const std::vector<TDItem>& Items)
      : mItems(Items)
    {
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    template <typename TAType, class TATypeTraits>
    struct TSItemType : public TSItem
    {
      TSItemType(
        const TATypeTraits* pTypeTraits,
        boost::function<const TAType&(const TAObject*)> GetType)
        : mpTypeTraits(pTypeTraits),
          mGetType(GetType)
      {
      }

      void PrintValue(const TAObject* pObject) const
      {
        std::cout
          << mpTypeTraits->GetString(mGetType(pObject))
          << std::endl;
      }

      const TATypeTraits* mpTypeTraits;

      boost::function<const TAType&(const TAObject*)> mGetType;
    };

    template <class TATraits, class TAMember>
    static TDItem Make(const TATraits& Traits, TAMember Member)
    {
      typedef typename TATraits::TDType TDType;

      return boost::make_shared<TSItemType<TDType, TATraits>>(
        &Traits,
        boost::bind<const TDType&>(Member, _1));
    }

  private:

    const TDItems mItems;

};
