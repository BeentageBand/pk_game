#pragma once
#include <cstddef>
#include <unordered_map>
#include "nullable.hpp"

namespace meta
{
  template<typename K, typename T>
  class LRU
  {

    public:
    struct Entry
    {
      T * const obj;
      Entry * next;
      Entry * prev;

      explicit Entry(T & obj)
        : obj(&obj), next(nullptr), prev(nullptr)
      {}
    };

    private:
    size_t const size;
    std::unordered_map<K, Entry> hashmap;
    Entry * head;
    Entry * tail;
    
    public:
    explicit LRU(size_t const size)
      : size(), hashmap(), head(nullptr), tail(nullptr)
    {}

    virtual ~LRU(void) {}

    T & get(K const & key, T & default_obj = T())
    {
      auto found = this->hashmap.find(key);

      if (found != this->hashmap.end())
      {
        this->move_to_front(found.second);
        return found.second->obj;
      }
      return default_obj;
    }

    void put(K const & key, T & obj)
    {
      this->hashmap.insert(std::pair<K, Entry>(key, Entry(obj) ));
      this->move_to_front(this->hashmap[key]);
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

    void pop(void)
    {
      if(nullptr != this->tail)
        this->remove(*this->tail);
    }
  };
}
