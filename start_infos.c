#include "ft_printf.h"

void start_infos(t_infos *infos)
{
        infos -> width = 0;
        infos -> dash = 0;
        infos -> zero = 0;
        infos -> dot = 0;
        infos -> square = 0;
        infos -> space = 0;
        infos -> plus = 0;
}
