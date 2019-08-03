#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include "commands/command.hpp"
#include "pkm/trainer.hpp"

namespace gameplay 
{
    class Option
    {
        std::string const name;
        public:
        explicit Option(std::string const & name)
            : name(name)
        {}
        virtual ~Option(void){}
        inline std::string const & get_name(void) {return this->name;}
        virtual Command && build(pkm::Trainer & trainer) = 0;
    };

    class Options : public Option
    {
        std::map<std::string, Option *> options;
        public:
        explicit Options(std::string const & name)
            : Option(name)
        {}

        virtual ~Options(void){}

        void insert(std::string const & key, Option & option)
        {
            this->options.insert(std::pair<std::string, Option *>(key, &option));
        }

        void display(pkm::Trainer & trainer) 
        {
            std::cout << trainer.get_name() << " - Options: " << std::endl;
            for(auto & each : this->options)
            {
                std::cout << "\t" << each.second->get_name() << std::endl;
            }
        }

        virtual Command && build(pkm::Trainer & trainer)
        {
            this->display(trainer);
            std::string key_input;

            do
            {
                std::cin >> key_input;

                if(this->options.empty()) return std::move(Command());

                auto found_option = this->options.find(key_input);
                if(found_option != this->options.end())
                {
                    return found_option->second->build(trainer);
                }
                std::cout << "invalid option!!";
            }while(true);
        }
    };
} // namespace gameplay
