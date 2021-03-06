#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "batchpcs.h"
#include "primitive.h"
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
        return *this;
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

    task_group::task_group(): dm_group{}
    {
    }

    task_group& task_group::add(pcs&& process)
    {
        this->dm_group.push_back(std::move(process));
        return *this;
    }

    i32 task_group::run_all() const
    {
        for(const pcs& p: this->dm_group)
            if(auto ret = p.run(); ret != 0)
                return ret;
        return 0;
    }

    task_group task_group::from_cmdarg(cmdarg args)
    {
        return {};
        // static_assert(false, "unimplemented");
    }
}