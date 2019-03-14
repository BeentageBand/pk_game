#pragma once
#include <fstream>

namespace utils
{
  class DAL
  {
    std::string path;
    public:
    DAL(std::string const & path)
      : path(path)
    {}

    pkm::Metadata get_metadata_by_name(std::string const & name)
    {
      pkm::Metadata::Builder builder = pkm::Metadata::builder();

      std::ifstream metadata_file;

      std::string full_path;
      full_path.append(this->path);
      full_path.append(name);
      full_path.append(".pkm");

      metadata_file.open(full_path);

      if(metadata_file)
      {
        std::string line
        while(std::get_line(metadata_file, line))
        {
          

        }

      }
      else
      {

      }

      return builder.build();
    }
  };
}
