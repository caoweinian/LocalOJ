#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <utility>
#include "argparse.h"
#include "result.hpp"
using namespace std;


namespace oj
{
    cmdarg::cmdarg(string command, unordered_set<string> properties,
    unordered_map<string, vector<string>> kvp)
    :dm_command{std::move(command)},
    dm_properties{std::move(properties)},
    dm_kvp{std::move(kvp)}
    {
    }

    Result<cmdarg> cmdarg::from(int argc, const char **argv)
    {
        
    }
}