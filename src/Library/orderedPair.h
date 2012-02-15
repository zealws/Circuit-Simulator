#ifndef _ORDEREDPAIR_H_
#define _ORDEREDPAIR_H_


template < typename firstItemType, typename secondItemType >
class orderedPair {

    private:

        firstItemType myFirstItem;

        secondItemType mySecondItem;

    public:

        orderedPair();
        orderedPair(orderedPair< firstItemType, secondItemType > const & otherPair);
        orderedPair(
            firstItemType const & initialFirstItem,
            secondItemType const & initialSecondItem
            );

        virtual ~orderedPair();

        virtual firstItemType const & firstConstReference() const;
        virtual firstItemType & firstReference();
        virtual void setFirst(firstItemType const & updatedFirst);

        virtual secondItemType const & secondConstReference() const;
        virtual secondItemType & secondReference();
        virtual void setSecond(secondItemType const & updatedSecond);

        orderedPair< firstItemType, secondItemType > & operator =(
            orderedPair< firstItemType, secondItemType > const & otherPair
            );

    };


//
// Public Members
//


template < typename firstItemType, typename secondItemType >
orderedPair< firstItemType, secondItemType >::orderedPair()
        : myFirstItem(),
          mySecondItem()
        {

    }


template < typename firstItemType, typename secondItemType >
orderedPair< firstItemType, secondItemType >::orderedPair(
        orderedPair< firstItemType, secondItemType > const & otherPair
        )
        : myFirstItem(otherPair.firstConstReference()),
          mySecondItem(otherPair.secondConstReference())
        {

    }


template < typename firstItemType, typename secondItemType >
orderedPair< firstItemType, secondItemType >::orderedPair(
        firstItemType const & initialFirstItem, secondItemType const & initialSecondItem
        )
        : myFirstItem(initialFirstItem),
          mySecondItem(initialSecondItem)
        {

    }


template < typename firstItemType, typename secondItemType >
orderedPair< firstItemType, secondItemType >::~orderedPair()
{

    }


template < typename firstItemType, typename secondItemType >
firstItemType const & orderedPair< firstItemType, secondItemType >::firstConstReference() const
{

    return myFirstItem;

    }


template < typename firstItemType, typename secondItemType >
firstItemType & orderedPair< firstItemType, secondItemType >::firstReference()
{

    return myFirstItem;

    }


template < typename firstItemType, typename secondItemType >
void orderedPair< firstItemType, secondItemType >::setFirst(firstItemType const & updatedFirst)
{

    myFirstItem = updatedFirst;

    }


template < typename firstItemType, typename secondItemType >
secondItemType const & orderedPair< firstItemType, secondItemType >::secondConstReference() const
{

    return mySecondItem;

    }


template < typename firstItemType, typename secondItemType >
secondItemType & orderedPair< firstItemType, secondItemType >::secondReference()
{

    return mySecondItem;

    }


template < typename firstItemType, typename secondItemType >
void orderedPair< firstItemType, secondItemType >::setSecond(secondItemType const & updatedSecond)
{

    mySecondItem = updatedSecond;

    }


template < typename firstItemType, typename secondItemType >
orderedPair< firstItemType, secondItemType > & orderedPair< firstItemType, secondItemType >::operator =(
    orderedPair< firstItemType, secondItemType > const & otherPair
    )
{

    if (this != & otherPair) {

        myFirstItem = otherPair.firstConstReference();
        mySecondItem = otherPair.secondConstReference();

        }

    return * this;

    }


#endif
