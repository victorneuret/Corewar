#
# zork.s for corewar
#
# Bob Bylan
#
# Sat Nov 10 03:24;30 2081
#
.name "zork"
.comment "just a basic living prog"

0 l2:            # 2 bytes
2 ld %3, r4      # 3 bytes
5 sa:            # 2 bytes
7 ld %400, r5    # 3 bytes
10 live %:l2     # 4 bytes
14 ld %:sa, r2   # 3 bytes
17
