#pragma once

#include "Utility/WrappingVariantMaker.h"
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/variant.hpp>
#include <vector>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <class TAObject, class ... TAAllowableTraits>
class TCTraitses
{
  public:

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    template<class TAMutableOrConstVisitor, class TAMutableOrConstObject>
    void Visit(
      TAMutableOrConstVisitor& MutableorConstVisitor,
      TAMutableOrConstObject& MutableorConstObject)
    {
      TCVisitor<TAMutableOrConstVisitor, TAMutableOrConstObject> Visitor(
        MutableorConstVisitor,
        MutableorConstObject);

      for (const auto& Item : mItems)
      {
        boost::apply_visitor(Visitor, Item);
      }
    }

  protected:

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    template <class TATraits>
    struct TSItem
    {
      typedef boost::function<
        const typename TATraits::TDType&(const TAObject&)> TDGet;

      typedef boost::function<
        void (TAObject&, const typename TATraits::TDType&)> TDSet;

      TSItem(
        const TATraits* pTraits,
        const TDGet& Get,
        const TDSet& Set)
        : mpTraits(pTraits),
          mGet(Get),
          mSet(Set)
      {
      }

      const TATraits* mpTraits;

      TDGet mGet;

      TDSet mSet;
    };

    typedef typename
      TSWrappingVariantMaker<TSItem, TAAllowableTraits ...>::TDResult TDItem;

    typedef std::vector<TDItem> TDItems;

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    template<class TAMutableOrConstVisitor, class TAMutableOrConstObject>
    class TCVisitor : public boost::static_visitor<void>
    {
      public:

      TCVisitor(
        TAMutableOrConstVisitor& Visitor,
        TAMutableOrConstObject& Object)
          : mVisitor(Visitor),
            mObject(Object)
        {
        }

        template <class TATraits>
        void operator()(const TSItem<TATraits>& Item) const
        {
          mVisitor(*Item.mpTraits, mObject, Item.mGet, Item.mSet);
        }

      private:

        TAMutableOrConstVisitor& mVisitor;

        TAMutableOrConstObject& mObject;
    };

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    TCTraitses(const std::vector<TDItem>& Items)
      : mItems(Items)
    {
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    template <class TAMember, class TAType>
    static void DoSet(TAMember Member, TAObject& Object, const TAType& Type)
    {
      boost::bind<TAType&>(Member, &Object)() = Type;
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    template <class TATraits, class TAMember>
    static TDItem Make(const TATraits& Traits, const TAMember& Member)
    {
      typedef typename TATraits::TDType TDType;

      return TSItem<TATraits>(
        &Traits,
        boost::bind<const TDType&>(Member, _1),
        boost::bind(DoSet<TAMember, TDType>, Member, _1, _2));
    }

  private:

    const TDItems mItems;

};
