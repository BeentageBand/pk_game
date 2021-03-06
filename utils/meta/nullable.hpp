#pragma once

namespace meta
{
  template<typename T>
  class Nullable
  {
    T * pointer;
    private:
    Nullable(T & pointer)
      : pointer(&pointer)
    {}

    Nullable(T * const pointer)
      : pointer(pointer)
    {}

    public:
    Nullable(void)
    : pointer(nullptr)
    {}

    virtual ~Nullable(void){}

    static Nullable empty(void) { return Nullable();}
;
    static Nullable of(T & data) { return Nullable(data);}

    static Nullable of_nullable(T * const data) { return Nullable(data);}

    inline T & get(void) const { return *this->pointer;}
    inline T * get_pointer(void) const {return this->pointer;}
    inline void set_pointer(T * const pointer) {this->pointer = pointer;}

    inline T & or_else(T & else_pointer)
    {
      return (this->is_present())? *this->pointer : else_pointer ;
    }

    inline T or_else(T && else_pointer)
    {
      return (this->is_present())? *this->pointer : else_pointer ;
    }

    inline bool is_present(void) const { return nullptr != this->pointer;}

    template<typename F>
    inline void if_present(F functor)
    {
      if(this->is_present())
        functor(this->get());
    }

    Nullable & operator=(Nullable const & rval)
    {
      if(this != &rval)
      {
        this->set_pointer(rval.get_pointer());
      }
      return *this;
    }
  };
}
