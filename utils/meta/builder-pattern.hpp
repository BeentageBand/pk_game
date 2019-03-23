#pragma once
//USE THIS PATTERN as in: 
//EG_BUILD_PATTERN(BUILDER_PROP) 
//   BUILDER_PROP(int, number, 0)
#define BUILDER_PROP(type, obj, def) 

#define BUILDER_MEMBERS(type, obj, def) type obj;
#define BUILDER_MEMBERS_DEF(type, obj, def) type obj = def;
#define BUILDER_SETTERS(type, obj, def) \
  inline Builder & set_##obj(type & obj) { this->obj = obj; return *this;}
#define BUILDER_PARAMS(type, obj, def) \
  ,this->obj

#define BUILDER_CONSTRUCTOR(parent, ...) parent(__VA_ARGS__)

#define BUILDER_PATTERN(parent, builder_prop) \
  private:                                    \
  builder_prop(BUILDER_MEMBERS)               \
  public:                                     \
  class Builder                               \
  {                                           \
    builder_prop(BUILDER_MEMBERS_DEF)         \
    builder_prop(BUILDER_SETTERS)             \
    parent build(void)                        \
    {                                         \
      return BUILDER_CONSTRUCTOR(parent      \
          builder_prop(BUILDER_PARAMS))       \
    }                                         \
  };                                          \
  static Builder builder(void)                \
  {                                           \
    static Builder builder;                   \
    return builder;                           \
  }                                           \
  
