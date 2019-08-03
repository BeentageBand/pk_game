#pragma once
#include "pkm/trainer.hpp"

namespace gameplay {
    class Decider 
    {
        public:
        virtual ~Decider(void) {}
        virtual bool evaluate(pkm::Trainer & trainer) = 0;
    };
}
