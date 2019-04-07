#pragma once
#include "gameplay/command.hpp"
#include "gameplay/engine.hpp"
#include "gameplay/option.hpp"

class MockCommand : public gameplay::Command
{
    public:
    MOCK_METHOD1(execute, void (gameplay::Battle & battle));
};

class MockEngine : public gameplay::Engine
{
    public:
    MOCK_METHOD1(build_options, gameplay::Option && (gameplay::Battle & battle));
};

class MockOption : public gameplay::Option
{
    public:
    MockOption(void)
    : Option("option")
    {}
    MOCK_METHOD1(build, gameplay::Command && (pkm::Trainer & trainer));
};


