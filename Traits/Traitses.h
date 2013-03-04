#pragma once

#include "Utility/WrappingVariantMaker.h"
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/variant.hpp>
#include <utility>
#include <vector>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <class TAObject, class ... TAAllowableTraits>
class TCTraitses
{
  public:

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    template<class TAUniversalVisitor, class TAUniversalObject>
    void Visit(
      TAUniversalVisitor&& UniversalVisitor,
      TAUniversalObject&&  UniversalObject)
    {
      TCVisitor<TAUniversalVisitor, TAUniversalObject> Visitor(
        std::forward<TAUniversalVisitor>(UniversalVisitor),
        std::forward<TAUniversalObject>(UniversalObject));

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
    template<class TAUniversalVisitor, class TAUniversalObject>
    class TCVisitor : public boost::static_visitor<void>
    {
      public:

      TCVisitor(
        TAUniversalVisitor&& Visitor,
        TAUniversalObject&& Object)
          : mVisitor(std::forward<TAUniversalVisitor>(Visitor)),
            mObject(std::forward<TAUniversalObject>(Object))
        {
        }

        //---------------------------------------------------------------------
        //---------------------------------------------------------------------
        template<
          class TAReadX,
          class TAVisitorX,
          class TATraitsX,
          class TAObjectX,
          class TAGetX,
          class TASetX>
        static typename boost::enable_if<TAReadX>::type VisitReadWrite(
          TAVisitorX&& Visitor,
          TATraitsX&& Traits,
          TAObjectX&& Object,
          TAGetX&& Get,
          TASetX&& Set)
        {
          Visitor(Traits, Get(Object));
        }

        //---------------------------------------------------------------------
        //---------------------------------------------------------------------
        template<
          class TAReadX,
          class TAVisitorX,
          class TATraitsX,
          class TAObjectX,
          class TAGetX,
          class TASetX>
        static typename boost::disable_if<TAReadX>::type VisitReadWrite(
          TAVisitorX&& Visitor,
          TATraitsX&& Traits,
          TAObjectX&& Object,
          TAGetX&& Get,
          TASetX&& Set)
        {
          Set(Object, Visitor(Traits));
        }

        template <class TATraits>
        void operator()(const TSItem<TATraits>& Item) const
        {
          typedef typename std::decay<TAUniversalVisitor>::type
            TDDecayedVisitor;

          typedef typename TDDecayedVisitor::TDRead TDMplBoolType;

          VisitReadWrite<TDMplBoolType>(
            mVisitor,
            *Item.mpTraits,
            mObject,
            Item.mGet,
            Item.mSet);

          //mVisitor(*Item.mpTraits, mObject, Item.mGet, Item.mSet);
        }

      private:

        TAUniversalVisitor&& mVisitor;

        TAUniversalObject&& mObject;
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
