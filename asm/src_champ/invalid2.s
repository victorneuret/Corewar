#
# zork.s for corewar
#
# Bob Bylan
#
# Sat Nov 10 03:24;30 2081
#
.name "zork" #the name
.comment "just a basic living prog" #the comment

l2:            # 2 bytes 0
ld %3, r4      # 3 bytes 2
qq:            # 2 bytes 5
ld %400, r5    # 3 bytes 7
live %:l2     # 4 bytes 10
ld %:sa, r2   # 3 bytes 14
