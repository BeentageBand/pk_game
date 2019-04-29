#include "gmock/gmock.h"
#include "gameplay-mock.hpp"
#include "gameplay/battle.hpp"
#include "pkm/attributes.hpp"
#include "pkm/metadata.hpp"
#include "pkm/pokemon.hpp"
#include "pkm/pokemon_team.hpp"
#include "pkm/trainer.hpp"
#include "battle/stats.hpp"

using namespace gameplay;
using namespace ::testing;

class GameplayBattle : public Test
{
    public:
    NiceMock<MockEngine> mock_engine;
    DeciderStub decider_stub;

    public:
    GameplayBattle(void)
    : mock_engine(), decider_stub()
    {}

    pkm::Trainer && build_trainer(std::string const & name, pkm::Pokemon & pokemon)
    {
        pkm::PokemonTeam team = build_pokemon_team(pokemon);
        return std::move(pkm::Trainer::builder().with_name(name).with_pokemon_team(team).build());
    }

    pkm::PokemonTeam build_pokemon_team(pkm::Pokemon & pokemon)
    {
        pkm::PokemonTeam team;
        team.push_pokemon(pokemon);
        return team;
    }

    pkm::Pokemon build_pokemon(std::string const & name)
    {
        battle::Stats stats = battle::Stats::builder().with_atk(100).with_def(100).with_sp_atk(90).with_sp_def(90)
                                                      .with_spd(90).build();
        std::vector<std::string> types {"fire", "flying"};
        pkm::Metadata metadata = pkm::Metadata::builder().with_name(name).with_stats(stats).with_types(types).build();

        std::vector<std::string> moveset {"flamethrower", "sword dance", "aerial ace", "rest"};
        pkm::Attributes attributes = pkm::Attributes::builder().with_nickname(name).with_level(36).with_moveset(moveset).build();
        return pkm::Pokemon::builder().with_attributes(attributes).with_metadata(metadata).with_stats(stats).build();
   }
};

/**
 * Given evaluate
 * when both trainers can continue
 * then return continue
 */
TEST_F(GameplayBattle, evaluate_continues)
{
    pkm::Pokemon pokemon = this->build_pokemon("charizard");
    pkm::Trainer trainer = this->build_trainer("trainer", pokemon);
    pkm::Trainer opponent = this->build_trainer("opponent", pokemon);

    Battle battle(this->mock_engine, trainer, opponent);

    this->decider_stub.add_evaluate_status(true);
    this->decider_stub.add_evaluate_status(true);
    EXPECT_CALL(this->mock_engine, build_decider()).WillOnce(Return(ByMove(std::move(this->decider_stub))));
    ASSERT_EQ(gameplay::Battle::CONTINUES, battle.evaluate());
}

/**
 * Given evaluate
 * when trainer can continue but opponent
 * then return win
 */
TEST_F(GameplayBattle, evaluate_winner)
{
    pkm::Pokemon pokemon = this->build_pokemon("charizard");
    pkm::Trainer trainer = this->build_trainer("trainer", pokemon);
    pkm::Trainer opponent = this->build_trainer("opponent", pokemon);

    Battle battle(this->mock_engine, trainer, opponent);

    this->decider_stub.add_evaluate_status(true);
    this->decider_stub.add_evaluate_status(false);
    EXPECT_CALL(this->mock_engine, build_decider()).WillOnce(Return(ByMove(std::move(this->decider_stub))));

    ASSERT_EQ(gameplay::Battle::WIN, battle.evaluate());
}

/**
 * Given evaluate
 * when opponent can continue but trainer
 * then return lose 
 */
TEST_F(GameplayBattle, evaluate_lose)
{
    pkm::Pokemon pokemon = this->build_pokemon("charizard");
    pkm::Trainer trainer = this->build_trainer("trainer", pokemon);
    pkm::Trainer opponent = this->build_trainer("opponent", pokemon);

    Battle battle(this->mock_engine, trainer, opponent);

    this->decider_stub.add_evaluate_status(false);
    this->decider_stub.add_evaluate_status(true);
    EXPECT_CALL(this->mock_engine, build_decider()).WillOnce(Return(ByMove(std::move(this->decider_stub))));

    ASSERT_EQ(gameplay::Battle::LOSE, battle.evaluate());
}

/**
 * Given evaluate
 * when both trainers cannot continue
 * then return stale 
 */
TEST_F(GameplayBattle, evaluate_stale)
{
    pkm::Pokemon pokemon = this->build_pokemon("charizard");
    pkm::Trainer trainer = this->build_trainer("trainer", pokemon);
    pkm::Trainer opponent = this->build_trainer("opponent", pokemon);

    Battle battle(this->mock_engine, trainer, opponent);

    this->decider_stub.add_evaluate_status(false);
    this->decider_stub.add_evaluate_status(false);
    EXPECT_CALL(this->mock_engine, build_decider()).WillOnce(Return(ByMove(std::move(this->decider_stub))));

    ASSERT_EQ(gameplay::Battle::STALE, battle.evaluate());
}
