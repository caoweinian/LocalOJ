// java/C#-like class that holds program entrance

#ifndef PROGRAM_H
#define PROGRAM_H

#include "prelude.h"

namespace oj
{
    class program
    {
    private:
        using Self = program;
    public:
        static Result<Self> from(int argc, const char **argv);

        Result<bool> run() const;
    private:
        program(task_group processes);
    private:
        task_group dm_task_group;
    };
}

#endif