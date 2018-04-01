.name		"the knock puncher"
.comment	"il va vous les briser"

		st	r1,9
		fork	%:roulo
		live	%42
		fork	%:live
		fork	%:back_wall
debut:		fork	%:attaque
		fork	%:live1
		fork	%:back_wall1
		zjmp	%:debut

attaque:	fork	%:first_atk
		fork	%:second_atk
		fork	%:live1
		zjmp	%:attaque

live:		st	r1, 6
live1:		live	%42
		fork	%:live2
		st	r1,24
		st	r1,18
		st	r1,12
		st	r1,6
         	live	%42
		live	%42
		live	%42
		live	%42
		zjmp	%-20

live2:		fork	%:live3
		st	r1,24
		st	r1,18
		st	r1,12
		st	r1,6
         	live	%42
		live	%42
		live	%42
		live	%42
		zjmp	%-20

live3:		fork	%:live4
		st	r1,24
		st	r1,18
		st	r1,12
		st	r1,6
         	live	%42
		live	%42
		live	%42
		live	%42
		zjmp	%-20

live4:		fork	%:live1
		st	r1,24
		st	r1,18
		st	r1,12
		st	r1,6
         	live	%42
		live	%42
		live	%42
		live	%42
		zjmp	%-20

back_wall:	ld	%:jump, r6
		fork	%:back_wall1
		fork	%:live
		zjmp	%-6

back_wall1:	st	r6,-400
		st	r6,-401
		st	r6,-402
		st	r6,-403
		st	r6,-404
		st	r6,-405
		st	r6,-406
		st	r6,-407
		st	r6,-408
		st	r6,-409
		st	r6,-410
		st	r6,-411
		st	r6,-412
		st	r6,-413
		st	r6,-414
		st	r6,-415
		st	r6,-416
		st	r6,-417
		st	r6,-418
		st	r6,-419
		st	r6,-420
		st	r6,-421
		st	r6,-422
		st	r6,-423
		st	r6,-424
		st	r6,-425
		zjmp	%:back_wall1

first_atk:	lfork	%-2024
		lfork	%-3024
		lfork	%-4024
		lfork	%5500
		zjmp	%:first_atk

second_atk:	lfork	%-2024
		lfork	%-3024
		lfork	%-4024
		lfork	%5500
		zjmp	%:second_atk

jump:		zjmp	%:live1

roulo:		ld	%0,r15
		sti	r1, %28, %1
		sti	r1, %349, %1
		sti	r1, %178, %1
		st	r1, r10
		fork	%:label_203
		live	%42
		fork	%:label_125
		ld	%655339, r7
		ld	%655329, r8
		ld	%655319, r9
		ld	%655309, r10
		ld	%655299, r11
		ld	%40, r1
		ld	%45, r2
		ld	%50, r3
		ld	%55, r4
		ld	%55, r5
		xor	r16, r16, r16
		zjmp	%:label_367

label_125:	ld	%655289, r7
		ld	%655279, r8
		ld	%655269, r9
		ld	%84476042, r10
		ld	%1409748737, r11
		ld	%90, r1
		ld	%95, r2
		ld	%100, r3
		ld	%14, r4
		ld	%144, r5
		xor	r16, r16, r16
		zjmp	%:label_367

label_203:	live	%42
		fork	%:label_289
		ld	%190056463, r7
		ld	%251857748, r8
		ld	%168756225, r9
		ld	%42, r11
		ld	%151000843, r11
		ld	%5, r1
		ld	%8, r2
		ld	%7, r3
		ld	%6, r4
		ld	%140, r5
		xor	r16, r16, r16
		zjmp	%:label_367

label_289:	ld	%34296841, r7
		ld	%655259, r8
		ld	%655249, r9
		ld	%190057231, r10
		ld	%167770889, r11
		ld	%9, r1
		ld	%115, r2
		ld	%120, r3
		ld	%10, r4
		ld	%0, r5
		xor	r16, r16, r16
		zjmp	%:label_367

label_367:	live	%42
		fork	%:label_367
		zjmp	%:label_378

label_378:	sti	r10, r15, r4
		live	%42
		sti	r11, r15, r5
zjmp %138
