#include <string>
#include <unordered_map>
#include <vector>
#include "console/option_parser.hpp"

int main(int argc, char ** argv)
{
    std::vector<std::string> args;
    OptionParser option_parser;
    std::unordered_map<std::string, std::string> const & options = option_parser.parse(argv, argc);

    auto found_option = options.find(argv);
    if (options.end() == found_option)
    {
        console::Builder builder(options);

        console::Command commands = builder.build();
        commands.exec();
    }
    return 0;
}
