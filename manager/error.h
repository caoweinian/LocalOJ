// report error if something unexpected occurs

#ifndef ERROR_H
#define ERROR_H

#include "primitive.h"

namespace oj
{
    enum class error_type: i32
    {
        /* invoke result::unwrap_or_report but don't call std::exit voluntarily */
        NOT_EXIT_IN_UNWRAP_OR_REPORT = 1,
        /* the arguments passed to program have invalid format */
        ARGPARSE_FAILED,
        /* run a child process but have a zon-zero value returned */
        TASK_RETURN_NONZERO,
    };

    void report_and_exit(error_type t);
}

#endif