#
# zork.s for corewar
#
# Bob Bylan
#
# Sat Nov 10 03:24;30 2081
#
.name "zork"
.comment "just a basic living prog"

l2:
and r1,r2,r3
ld %2,r2
lfork %2
aff r2
