#ft_printf

100/100

Time invested: around 5 hours

Tested with francinette, everything OK.

Cases like printf(0) or the string passed as parameter ended with a single % (e.g. printf(" %d %c %i %", 1, 'a', 10))) should not be taken into consideration since they would be treated as error if compiled with flags -Wall -Wextra -Werror. (If compiled without flags, the two previous examples would be treated as warning and the original printf() will return -1. But it's not something that should be considered in this projet.)

ALl of these to say, if you pass francinette, you should be able to pass moulinette.
