#pragma once
#include <string>

namespace battle {
  
  class MoveAttributes
  {
  };

  class Move
  {
    public:
    class Builder
    {
      std::string name;
      std::string description;
      std::string type; //pokemon type
      uint8_t move_type; //physical special
      MoveAttributes const * attributes;

      public:
      Builder(void){}
      inline Builder & with_name(std::string const & name) { this->name = name; return *this;}
      inline Builder & with_description(std::string const & description) { this->description = description; return *this;}
      inline Builder & with_type(std::string const & type) { this->type = type; return *this;}
      inline Builder & with_move_type(uint8_t const & move_type) { this->move_type = move_type; return *this;}
      inline Builder & with_move_attributes(MoveAttributes const & attributes) { this->attributes = &attributes; return *this;}
      inline Move build(void) {return Move(this->name, this->description, this->type, this->move_type, *this->attributes);}
    };

    std::string const name;
    std::string const description;
    std::string const type; //pokemon type
    uint8_t const move_type; //physical special
    MoveAttributes attributes;
    
    public:
    static Builder & builder(void)
    {
      static Builder builder;
      return builder;
    }

    Move(std::string const & name, std::string const & description, std::string const type, uint8_t const move_type, MoveAttributes const & attributes)
      : name(name), description(description), type(type), move_type(move_type), attributes(attributes)
    {}
  };
} // namespace battle
