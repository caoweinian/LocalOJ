#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "batchpcs.h"
#include <unistd.h>
#include <sys/types.h>

using namespace std;

namespace oj
{
    pcs::pcs(): dm_apkg{}
    {
    }

    pcs::pcs(string cmd_pkg): dm_apkg{}
    {
        istringstream iss(std::move(cmd_pkg));
        string temp;
        while(iss >> temp)
            this->dm_apkg.push_back(std::move(temp));
    }

    pcs& pcs::then(string cmd)
    {
        this->dm_apkg.push_back(std::move(cmd));
    }

    i32 pcs::run() const
    {
        vector<const char*> argv;
        argv.reserve(size(this->dm_apkg));
        transform(
            next(begin(this->dm_apkg)),
            end(this->dm_apkg),
            back_inserter(argv),
            [](const string& s){return s.c_str();}
        );
        argv.push_back(nullptr);
        i32 result = execv(
            argv[0], 
            const_cast<char *const*>(argv.data()) + 1
        );
        return WEXITSTATUS(result);
    }
}