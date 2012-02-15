#ifndef _BAREBONESDOUBLYLINKEDLIST_H_
#define _BAREBONESDOUBLYLINKEDLIST_H_


template < typename itemType > class doublyLinkedList;
template < typename itemType > class doublyLinkedListNode;


template < typename itemType >
class doublyLinkedList {

    private:

        doublyLinkedListNode< itemType > * myHeadPointer;

        virtual doublyLinkedListNode< itemType > * const & headPointerConstReference() const;

        doublyLinkedList(doublyLinkedListNode< itemType > * nodePointer);

    public:

        doublyLinkedList();
        virtual ~doublyLinkedList();

        virtual bool isNull() const;

        virtual itemType const & headConstReference() const;
        virtual itemType & headReference();
        virtual void setHead(itemType const & i);

        virtual doublyLinkedList< itemType > const & suffixConstReference() const;
        virtual doublyLinkedList< itemType > & suffixReference ();
        virtual void setSuffix(doublyLinkedList< itemType > const & dll);

        virtual doublyLinkedList< itemType > const & prefixConstReference() const;
        virtual doublyLinkedList< itemType > & prefixReference ();
        virtual void setPrefix(doublyLinkedList< itemType > const & dll);

        virtual void insertAfterFirst(itemType const & i);
        virtual void removeAfterFirst();

        virtual void insertFirst(itemType const & i);
        virtual void removeFirst();

        virtual bool isIdentical(doublyLinkedList< itemType > dll) const;

        virtual void duplicate(
            doublyLinkedList< itemType > & headerOfDuplicate,
            doublyLinkedList< itemType > & trailerOfDuplicate
            ) const;

        virtual void destroy();

    };


template <class itemType>
class doublyLinkedListNode {

    private:

        itemType myCurrentItem;
        doublyLinkedList< itemType > mySuffixList;
        doublyLinkedList< itemType > myPrefixList;

    public:

        doublyLinkedListNode();
        virtual ~doublyLinkedListNode();

        virtual itemType const & currentConstReference() const;
        virtual itemType & currentReference();
        virtual void setCurrent(itemType const & i);

        virtual doublyLinkedList< itemType > const & suffixConstReference() const;
        virtual doublyLinkedList< itemType > & suffixReference();
        virtual void setSuffix(doublyLinkedList< itemType > const & dll);

        virtual doublyLinkedList< itemType > const & prefixConstReference() const;
        virtual doublyLinkedList< itemType > & prefixReference();
        virtual void setPrefix(doublyLinkedList< itemType > const & dll);

    };


#include <cstddef>


using namespace std;


//
// Class doublyLinkedList
//


//
// Private members
//


template < typename itemType >
doublyLinkedListNode< itemType > * const & doublyLinkedList< itemType >::headPointerConstReference() const {

    return myHeadPointer;

    }


template < typename itemType >
doublyLinkedList< itemType >::doublyLinkedList(
        doublyLinkedListNode< itemType > * nodePointer
        )
        : myHeadPointer(nodePointer)
        {

    }


//
// Public members
//


template < typename itemType >
doublyLinkedList< itemType >::doublyLinkedList()
        : myHeadPointer(NULL)
        {

    }


template < typename itemType >
doublyLinkedList< itemType >::~doublyLinkedList() {

    }


template < typename itemType >
bool doublyLinkedList< itemType >::isNull() const {

    return headPointerConstReference() == NULL;

    }


template < typename itemType >
itemType const & doublyLinkedList< itemType >::headConstReference() const {

    return headPointerConstReference() -> currentConstReference();

    }


template < typename itemType >
itemType & doublyLinkedList< itemType >::headReference() {

    return headPointerConstReference() -> currentReference();

    }


template < typename itemType >
void doublyLinkedList< itemType >::setHead(itemType const & i) {

    headPointerConstReference() -> setCurrent(i);

    }


template < typename itemType >
doublyLinkedList< itemType > const & doublyLinkedList< itemType >::suffixConstReference() const {

    return headPointerConstReference() -> suffixConstReference();

    }


template < typename itemType >
doublyLinkedList< itemType > & doublyLinkedList< itemType >::suffixReference() {

    return headPointerConstReference() -> suffixReference();

    }


template < typename itemType >
void doublyLinkedList< itemType >::setSuffix(doublyLinkedList< itemType > const & dll) {

    headPointerConstReference() -> setSuffix(dll);

    }


template < typename itemType >
doublyLinkedList< itemType > const & doublyLinkedList< itemType >::prefixConstReference() const {

    return headPointerConstReference() -> prefixConstReference();

    }


template < typename itemType >
doublyLinkedList< itemType > & doublyLinkedList< itemType >::prefixReference() {

    return headPointerConstReference() -> prefixReference();

    }


template < typename itemType >
void doublyLinkedList< itemType >::setPrefix(doublyLinkedList< itemType > const & dll) {

    headPointerConstReference() -> setPrefix(dll);

    }


template < typename itemType >
void doublyLinkedList< itemType >::insertAfterFirst(itemType const & i) {

    doublyLinkedList< itemType > ptrToNewNode(new doublyLinkedListNode< itemType >);

    ptrToNewNode.setHead(i);
    ptrToNewNode.setSuffix(suffixConstReference());
    ptrToNewNode.setPrefix(headPointerConstReference());
    if (! suffixConstReference().isNull())
        suffixReference().setPrefix(ptrToNewNode);
    setSuffix(ptrToNewNode);

    }


template < typename itemType >
void doublyLinkedList< itemType >::removeAfterFirst() {

    doublyLinkedList< itemType > ptrToOldNode = suffixConstReference();

    if (! suffixConstReference().suffixConstReference().isNull())
        suffixReference().suffixReference().setPrefix(headPointerConstReference());
    setSuffix(suffixConstReference().suffixConstReference());
    delete ptrToOldNode.headPointerConstReference();

    }


template < typename itemType >
void doublyLinkedList< itemType >::insertFirst(itemType const & i) {

    doublyLinkedList< itemType > ptrToNewNode(new doublyLinkedListNode< itemType >);

    ptrToNewNode.setHead(i);
    if (! isNull()) {
        ptrToNewNode.setSuffix(headPointerConstReference());
        ptrToNewNode.setPrefix(prefixConstReference());
        setPrefix(ptrToNewNode);
        if (! ptrToNewNode.prefixConstReference().isNull())
            ptrToNewNode.prefixReference().setSuffix(ptrToNewNode);
        }
    * this = ptrToNewNode;

    }


template < typename itemType >
void doublyLinkedList< itemType >::removeFirst() {

    doublyLinkedList< itemType > ptrToOldNode = * this;

    if (! suffixConstReference().isNull())
        suffixReference().setPrefix(prefixConstReference());
    if (! prefixConstReference().isNull())
        prefixReference().setSuffix(suffixConstReference());
    if (! suffixConstReference().isNull())
        * this = suffixConstReference();
    else
        * this = prefixConstReference();
    delete ptrToOldNode.headPointerConstReference();

    }


template < typename itemType >
bool doublyLinkedList< itemType >::isIdentical(doublyLinkedList< itemType > dll) const {

    return headPointerConstReference() == dll.headPointerConstReference();

    }


template < typename itemType >
void doublyLinkedList< itemType >::duplicate(
        doublyLinkedList< itemType > & headerOfDuplicate,
        doublyLinkedList< itemType > & trailerOfDuplicate
        ) const {

    doublyLinkedList< itemType > thisCurrent;

    headerOfDuplicate = doublyLinkedList< itemType >();
    trailerOfDuplicate = headerOfDuplicate;

    if (! isNull()) {
        headerOfDuplicate.insertFirst(headConstReference());
        for (trailerOfDuplicate = headerOfDuplicate,
                    thisCurrent = suffixConstReference();
                ! thisCurrent.isNull();
                trailerOfDuplicate = trailerOfDuplicate.suffixConstReference(),
                    thisCurrent = thisCurrent.suffixConstReference())
            trailerOfDuplicate.insertAfterFirst(thisCurrent.headConstReference());
        }

    }


template < typename itemType >
void doublyLinkedList< itemType >::destroy() {

    while (! isNull())
        removeFirst();

    }


//
// Class doublyLinkedListNode
//


//
// Public members
//


template < typename itemType >
doublyLinkedListNode< itemType >::doublyLinkedListNode()
        : myCurrentItem(),
          mySuffixList(),
          myPrefixList()
        {

    }


template < typename itemType >
doublyLinkedListNode< itemType >::~doublyLinkedListNode() {

    }


template < typename itemType >
itemType & doublyLinkedListNode< itemType >::currentReference() {

    return myCurrentItem;

    }


template < typename itemType >
itemType const & doublyLinkedListNode< itemType >::currentConstReference() const {

    return myCurrentItem;

    }


template < typename itemType >
void doublyLinkedListNode< itemType >::setCurrent(itemType const & i) {

    myCurrentItem = i;

    }


template < typename itemType >
doublyLinkedList< itemType > const & doublyLinkedListNode< itemType >::suffixConstReference() const {

    return mySuffixList;

    }


template < typename itemType >
doublyLinkedList< itemType > & doublyLinkedListNode< itemType >::suffixReference() {

    return mySuffixList;

    }


template < typename itemType >
void doublyLinkedListNode< itemType >::setSuffix(doublyLinkedList< itemType > const & dll) {

    mySuffixList = dll;

    }


template < typename itemType >
doublyLinkedList< itemType > const & doublyLinkedListNode< itemType >::prefixConstReference() const {

    return myPrefixList;

    }


template < typename itemType >
doublyLinkedList< itemType > & doublyLinkedListNode< itemType >::prefixReference() {

    return myPrefixList;

    }


template < typename itemType >
void doublyLinkedListNode< itemType >::setPrefix(doublyLinkedList< itemType > const & dll) {

    myPrefixList = dll;

    }


#endif
