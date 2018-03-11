.name "test"
.comment "test"

l2:
ld %42,r5
and r5,%55,r7
aff r7
ld %66,r5
or r5,%12,r7
aff r7
ld %12,r5
xor r5,%76,r7
aff r7
ldi %1, %2, r3
