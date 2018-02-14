#
# comment
# another one
# another one
#

.name "zork"
.comment "justabasiclivingprog"

l2:
sti r1,%:live,%1
and r1,%0,r1
live: live%1
zjmp %:live
