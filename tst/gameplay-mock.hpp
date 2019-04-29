#pragma once
#include <vector>
#include "gameplay/command.hpp"
#include "gameplay/decider.hpp"
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
    MOCK_METHOD0(build_decider, gameplay::Decider && ());
};

class MockOption : public gameplay::Option
{
    public:
    MockOption(void)
    : Option("option")
    {}
    MOCK_METHOD1(build, gameplay::Command && (pkm::Trainer & trainer));
};

class DeciderStub : public gameplay::Decider
{
    std::vector<bool> status;
    public:
    DeciderStub(void)
        : status()
    {}

    void add_evaluate_status(bool const status) { this->status.push_back(status); };

    bool evaluate(pkm::Trainer & trainer) 
    {
        bool evaluate_status = this->status.back();
        this->status.pop_back();
        return evaluate_status;
    }
};
