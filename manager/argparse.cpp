#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>
#include <type_traits>
#include "argparse.h"
#include "result.hpp"
using namespace std;


namespace oj
{
    /* check if the arguments are legal. If not, exit with code error_type::ARGPARSE_FAILED */
    bool check_args(const string& command, const string& properties,
        const unordered_map<string, vector<string>>& kvp);

    bool starts_with_only_one_hyphen(const string& s);
    bool starts_with_two_hyphen(const string& s);
    vector<string> argv2vs(int argc, const char **argv);

    cmdarg::cmdarg(string command, string properties,
    unordered_map<string, vector<string>> kvp)
    :dm_command{std::move(command)},
    dm_properties{std::move(properties)},
    dm_kvp{std::move(kvp)}
    {
    }

    Result<cmdarg> cmdarg::from(int argc, const char **argv)
    {
        #define PARSE_ERROR (Result<cmdarg>::err(error_type::ARGPARSE_FAILED))
        if(argc == 1)
            report_and_exit(error_type::ARGPARSE_FAILED);
        const auto argvv = argv2vs(argc, argv);
        const auto sz = size(argvv);
        string command = argvv[0];
        string properties;
        unordered_map<string, vector<string>> kvp;

        for(remove_const_t<decltype(sz)> cur = 1; cur < sz; ++cur)
        {
            if(starts_with_only_one_hyphen(argvv[cur]))
            {
                copy(
                    next(begin(argvv[cur])), 
                    end(argvv[cur]),
                    back_inserter(properties)
                    );
            }
            else if(starts_with_two_hyphen(argvv[cur]))
            {
                auto pos = argvv[cur].find('=', 2);
                if(pos == string::npos)
                    kvp[argvv[cur].substr(2)];
                else
                {
                    string k = argvv[cur].substr(2, pos - 2);
                    string v = argvv[cur].substr(pos + 1);
                    kvp[k].push_back(std::move(v));
                }
            }
            else // the error that can be tested earlier should get reported in advance
                return PARSE_ERROR;
        }
        if(!check_args(command, properties, kvp))
            return PARSE_ERROR;
        #undef PARSE_ERROR
        return Result<cmdarg>::ok(cmdarg{
            std::move(command), 
            std::move(properties), 
            std::move(kvp)
        });
    }

    bool check_args(const string& command, const string& properties,
    const unordered_map<string, vector<string>>& kvp)
    {
        return false;
        // static_assert(false, "oj::check_args not implemented");
    }

    bool starts_with_only_one_hyphen(const string& s)
    {
        auto sz = s.size();
        if(sz > 1)
            return s[0] == '-' && s[1] != '-';
        else if(sz == 1)
            return s[0] == '-';
        return false;
    }

    bool starts_with_two_hyphen(const string& s)
    {
        auto sz = s.size();
        if(sz > 2)
            return s[0] == '-' && s[1] == '-' && s[2] != '-';
        else if(sz == 2)
            return s == "--";
        return false;
    }

    vector<string> argv2vs(int argc, const char **argv)
    {
        vector<string> ret;
        for(int i = 1; i != argc; ++i)
            ret.push_back(argv[i]);
        return /* std::move( */ ret /* ) */;
    }

}