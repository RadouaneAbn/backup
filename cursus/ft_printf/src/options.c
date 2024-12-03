#include "../ft_printf.h"

void	init_options(t_opt *opt)
{
	opt->leading_space_sign = 0;
	opt->pad = 0;
	opt->width = 0;
	opt->alt = 0;
	opt->precision[0] = 0;
	opt->precision[1] = 0;
	opt->fill = ' ';
}