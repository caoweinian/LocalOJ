#include "program.h"
#include "prelude.h"

using namespace std;

namespace oj
{
    Result<program> program::from(int argc, const char **argv)
    {
        auto parsed = cmdarg::from(argc, argv);
        if(parsed.is_err())
            return Result<program>::err(
                std::move(
                    static_cast<error_type>(parsed.get_error())
                    ));
        auto dm_tasks = task_group::from_cmdarg(std::move(parsed.unwrap()));
        return Result<program>::ok(program{std::move(dm_tasks)});
    }

    Result<bool> program::run() const 
    {
        if(i32 result = this->dm_task_group.run_all(); result == 0)
            return Result<bool>::ok(true);
        else
            return Result<bool>::err(static_cast<error_type>(result));
    }

    program::program(task_group processes)
    : dm_task_group{std::move(processes)}
    {
    }
}