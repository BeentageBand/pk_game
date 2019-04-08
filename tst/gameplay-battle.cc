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

class GameplayBattle : public ::testing::Test
{
    public:
    ::testing::NiceMock<MockEngine> mock_engine;

    public:
    GameplayBattle(void)
    : mock_engine()
    {}

    pkm::Trainer && build_trainer(std::string const & name, pkm::Pokemon & pokemon)
    {
        pkm::PokemonTeam team = build_pokemon_team(pokemon);
        return pkm::Trainer::builder().with_name(name).with_pokemon_team(team).build();
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

TEST_F(GameplayBattle, play_continues)
{
    pkm::Pokemon pokemon = this->build_pokemon("charizard");
    pkm::Trainer trainer = this->build_trainer("trainer", pokemon);
    pkm::Trainer opponent = this->build_trainer("opponent", pokemon);

    Battle battle(this->mock_engine, trainer, opponent);

    uint8_t evaluates = battle.evaluate();
    ASSERT_EQ(evaluates, Battle::CONTINUES);
}
