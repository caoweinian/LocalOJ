// a way to run serveral processes continuously

#include <vector>
#include <string>
#include "primitive.h"
#include "argparse.h"

namespace oj
{
    // one process
    class pcs
    {
    private:
        using Self = pcs;
    public:
        pcs();
        pcs(std::string cmd_pkg);

        /* the big-five */
        pcs(const Self&) = default;
        pcs(Self&&) = default;
        pcs& operator=(const Self&) = default;
        pcs& operator=(Self&&) = default;
        ~pcs() = default;

        /* add a command to the tail */
        Self& then(std::string cmd);

        /* run the process based on commands passed */
        i32 run() const;
    private:
        std::vector<std::string> dm_apkg;
    };

    class task_group
    {
    private:
        using Self = task_group;
    public:
        task_group();

        // build Self using right cmdarg
        static Self from_cmdarg(cmdarg args);

        /* the big-five */
        task_group(const Self&) = default;
        task_group(Self&&) = default;
        task_group& operator=(const task_group&) = default;
        task_group& operator=(task_group&&) = default;
        ~task_group() = default;

        Self& add(pcs&& process);

        /* run all the processes stored before sequentially. Return 0 if every process returns 0.
         If any of the processes return k where k is not 0, return the first k, ant the subsequent
         tasks-- if exists-- will not be run. */
        i32 run_all() const;
    private:
        std::vector<pcs> dm_group;
    };
}