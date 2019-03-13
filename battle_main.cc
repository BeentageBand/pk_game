#include <vector>
#include "pkm/trainer.hpp"
#include "gameplay/battle.hpp"
#include "gameplay/fight_options.hpp"
#include "pkm/pokemon.hpp"

using namespace std;
using namespace pkm;

int main(void)
{

  vector<Pokemon> pokemon_rental;

  pokemon_rental.push_back();

  std::vector<pkm::Trainer> trainers;

  {
    uint8_t i = 2;
    while(i--)
    {
      Trainer trainer = Trainer::builder().with_name("Trainer" + i).build();

      trainer.get_pokemon_team().push_pokemon(pokemon_rental[0+i]);
      trainer.get_pokemon_team().push_pokemon(pokemon_rental[1+i]);
      trainer.get_pokemon_team().push_pokemon(pokemon_rental[2+i]);
      trainers.push_back(trainer);
    }
  }

  gameplay::FightOptions figh_options;
  battle::Battle battle(fight_options, trainers[0], trainers[1]);
  battle.play();
  return 0;
}
