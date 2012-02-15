#ifndef _ABSTRACTLIST_H_
#define _ABSTRACTLIST_H_


template < typename itemType > class abstractListPosition;
template < typename itemType > class abstractConstListPosition;
template < typename itemType > class abstractList;


template < typename itemType >
class abstractListPosition {

    public:

        virtual ~abstractListPosition();

        virtual bool error() const = 0;
        virtual bool success() const = 0;

        virtual void advance() = 0;

        virtual void retreat() = 0;

        virtual itemType & reference() = 0;

        virtual void insert(itemType const & i) = 0;
        virtual void remove() = 0;

        virtual bool isFirst() const = 0;
        virtual bool isEnd() const = 0;

    };


template < typename itemType >
class abstractConstListPosition {

    public:

        virtual ~abstractConstListPosition();

        virtual bool error() const = 0;
        virtual bool success() const = 0;

        virtual void advance() = 0;

        virtual void retreat() = 0;

        virtual itemType const & constReference() = 0;

        virtual bool isFirst() const = 0;
        virtual bool isEnd() const = 0;

    };


template < typename itemType >
class abstractList {

    public:

        virtual ~abstractList();

        virtual bool isEmpty() const = 0;

    };


template < typename itemType >
abstractListPosition< itemType >::~abstractListPosition()
{

    }


template < typename itemType >
abstractConstListPosition< itemType >::~abstractConstListPosition()
{

    }


template < typename itemType >
abstractList< itemType >::~abstractList()
{

    }


#endif
