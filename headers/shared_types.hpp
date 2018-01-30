namespace shared_types
{
using Arg_count =
    Strong_type<int, struct Raw_arg_count_>;

using Args =
    Strong_type<const char**, struct Raw_args_>;
}