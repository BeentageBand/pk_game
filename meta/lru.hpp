#pragma once
#include <cstddef>

namespace meta
{
  template<typename K, typename T>
  class LRU
  {

    public:
    struct Entry
    {
      T * obj;
      K key;
      Entry * next;
      Entry * prev;

      Entry(void)
        : obj(nullptr), key(), next(nullptr), prev(nullptr)
      {}

    };

    private:
    size_t const size;
    Entry * buffer;
    Entry * head;
    Entry * tail;
    
    public:
    explicit LRU(size_t const size)
      : size(), buffer(new Entry[size]), head(nullptr), tail(nullptr)
    {}

    virtual ~LRU(void) { delete this->buff; }

    T * get(K const & key)
    {
      int hashid = 0;
      Entry * found = this->find(key);
      return found->obj;
    }

    void put(K const & key, T & obj)
    {
      Entry * found = this->find(key);
      if(nullptr == found->obj)
      {
        if(nullptr)
        this->found->obj = &obj;
        this->found->key = key;
        this->move_to_front(found);
      }
      else
      {
      }
    }

    private:
    void move_to_front(Entry & entry)
    {
      this->remove(entry);
      this->push(entry);
    }

    void remove(Entry & entry)
    {
      if(nullptr == this->head && nullptr == this->tail) return;

      if(&entry == this->head)
        this->head = entry.next;
      else if(&entry == this->tail)
        this->tail = entry.prev;

      Entry * prev = entry.prev;
      Entry * next = entry.next;

      if(nullptr != prev)
        prev->next = next;
      if(nullptr != next)
        next->prev = prev;
    }

    Entry * find(K const & key)
    {


    }

    int hashcode(K const & key, hashid)
    {
      
    }

    void pop(void)
    {
      if(nullptr != this->tail)
        this->remove(*this->tail);
    }

    void push(Entry & entry)
    {
      if(nullptr == this->head)
        this->head = &entry;
      if(nullptr == this->tail)
        this->tail = &entry;

      Entry * it = this->head;
      this->head = &entry;

      entry->prev = nullptr;
      entry->next = it;
    }
  };
}
