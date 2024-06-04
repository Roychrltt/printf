#ft_printf

100/100

Time invested: around 5 hours

Tested with francinette, everything OK.

Final update: Printf(0) is not an error for `cc -Wall -Wextra -Werror`. So maybe it's better to add this case into your project, even though you could still pass moulinette without it.

Cases like printf(0) or the string passed as parameter ended with a single % (e.g. printf(" %d %c %i %", 1, 'a', 10))) should not be taken into consideration since they would be treated as error if compiled with gcc and flags `gcc -Wall -Wextra -Werror`. (If compiled without flags, the two previous examples would be treated as warning and the original printf() will return -1. But it's not something that should be considered in this projet.)

All of these to say, if you pass francinette, you should be able to pass moulinette. So hope your evaluators will be nice to you.
