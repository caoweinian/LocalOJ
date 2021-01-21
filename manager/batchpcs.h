// a way to run serveral processes continuously

#include <vector>
#include <string>
#include "primitive.h"

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

        // add a command to the tail
        Self& then(std::string cmd);

        // run the process based on commands passed
        i32 run() const;

        // the big-five
        pcs(const Self&) = default;
        pcs(Self&&) = default;
        pcs& operator=(const Self&) = default;
        pcs& operator=(Self&&) = default;
        ~pcs() = default;
         
    private:
        std::vector<std::string> dm_apkg;
    };

    class task_group
    {
    public:
        
    private:

    };
}