#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "primitive.h"
namespace oj
{
    void report_and_exit(error_type t)
    {
        i32 code = static_cast<i32>(t);

        if(t == error_type::ARGPARSE_FAILED)
            fprintf(stderr, "arguments parsing failed\n");
        else if(t == error_type::NOT_EXIT_IN_UNWRAP_OR_REPORT)
            fprintf(stderr, "internal error\n");
        else if(t == error_type::TASK_RETURN_NONZERO)
            fprintf(stderr, "child process exit with an error\n");
        
        exit(code);
    }
}