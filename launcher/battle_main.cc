#include <vector>
#include "pkm/trainer.hpp"
#include "gameplay/battle.hpp"
#include "gameplay/fight_options.hpp"
#include "pkm/pokemon.hpp"

using namespace std;
using namespace pkm;

int main(void)
{
//  vector<Pokemon> pokemon_rental;
//
//  Pokemon::Builder pokemon_builder = Pokemon::builder();
//  Attributes::Builder attributes_builder = Attributes::builder();
//  Stats::Builder stats_builder = Stats::builder();
//  Metadata::Builder metadata_builder = Metadata::builder();
//
//  vector<string> moveset {"tackle", "growl"};
//
//  attributes_builder.with_nickname("pikachu");
//  attributes_builder.with_level(250);
//  attributes_builder.with_moveset(moveset);
//  
//  pokemon_builder.with_attributes(pokemon_attributes);
//  pokemon_builder.with_stats(pokemon_stats);
//  pokemon_builder.with_metadata(pokemon_metadata);
//
//  pokemon_rental.push_back(pokemon_builder.build());
//
//  std::vector<pkm::Trainer> trainers;
//
//  {
//    uint8_t i = 2;
//    while(i--)
//    {
//      Trainer trainer = Trainer::builder().with_name("Trainer" + i).build();
//
//      trainer.get_pokemon_team().push_pokemon(pokemon_rental[0+i]);
//      trainer.get_pokemon_team().push_pokemon(pokemon_rental[1+i]);
//      trainer.get_pokemon_team().push_pokemon(pokemon_rental[2+i]);
//      trainers.push_back(trainer);
//    }
//  }
//
//  gameplay::FightOptions figh_options;
//  gameplay::Battle battle(fight_options, trainers[0], trainers[1]);
//  battle.play();
  return 0;
}

