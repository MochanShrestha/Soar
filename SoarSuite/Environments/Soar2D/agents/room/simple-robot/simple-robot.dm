146
SOAR_ID 0
SOAR_ID 1
SOAR_ID 2
SOAR_ID 3
ENUMERATION 4 1 state
ENUMERATION 5 1 nil
SOAR_ID 6
ENUMERATION 7 3 complete error executing
SOAR_ID 8
ENUMERATION 9 3 backward forward stop
ENUMERATION 10 3 complete error executing
ENUMERATION 11 3 left right stop
SOAR_ID 12
STRING 13
SOAR_ID 14
ENUMERATION 15 1 wander
SOAR_ID 16
ENUMERATION 17 1 state
ENUMERATION 18 1 wander
ENUMERATION 19 2 operator state
ENUMERATION 20 2 multiple none
ENUMERATION 21 2 no-change tie
ENUMERATION 22 1 book
SOAR_ID 23
ENUMERATION 24 1 wait
ENUMERATION 25 1 elaboration
SOAR_ID 26
SOAR_ID 27
FLOAT_RANGE 28 -Infinity Infinity
SOAR_ID 29
SOAR_ID 30
INTEGER_RANGE 31 0 2147483647
SOAR_ID 32
INTEGER_RANGE 33 0 2147483647
INTEGER_RANGE 34 0 2147483647
SOAR_ID 35
INTEGER_RANGE 36 0 2147483647
INTEGER_RANGE 37 0 2147483647
SOAR_ID 38
FLOAT_RANGE 39 0.0 Infinity
FLOAT_RANGE 40 0.0 Infinity
FLOAT_RANGE 41 -Infinity Infinity
ENUMERATION 42 4 east north south west
SOAR_ID 43
SOAR_ID 44
FLOAT_RANGE 45 -Infinity Infinity
FLOAT_RANGE 46 0.0 Infinity
FLOAT_RANGE 47 0.0 Infinity
INTEGER_RANGE 48 0 2147483647
SOAR_ID 49
INTEGER_RANGE 50 0 2147483647
INTEGER_RANGE 51 0 2147483647
SOAR_ID 52
INTEGER_RANGE 53 0 2147483647
INTEGER_RANGE 54 0 2147483647
INTEGER_RANGE 55 0 2147483647
SOAR_ID 56
ENUMERATION 57 2 false true
ENUMERATION 58 2 false true
INTEGER_RANGE 59 0 2147483647
INTEGER_RANGE 60 -2147483648 2147483647
SOAR_ID 61
FLOAT_RANGE 62 0.0 Infinity
FLOAT_RANGE 63 0.0 Infinity
INTEGER_RANGE 64 0 2147483647
INTEGER_RANGE 65 0 2147483647
FLOAT_RANGE 66 0.0 1.0
FLOAT_RANGE 67 0.0 Infinity
SOAR_ID 68
FLOAT_RANGE 69 0.0 Infinity
FLOAT_RANGE 70 -Infinity Infinity
FLOAT_RANGE 71 -Infinity Infinity
SOAR_ID 72
SOAR_ID 73
FLOAT_RANGE 74 -Infinity Infinity
FLOAT_RANGE 75 -Infinity Infinity
ENUMERATION 76 3 complete error executing
ENUMERATION 77 3 complete error executing
ENUMERATION 78 2 complete error
SOAR_ID 79
ENUMERATION 80 1 state
ENUMERATION 81 1 move-to-gateway
ENUMERATION 82 1 rotate
SOAR_ID 83
ENUMERATION 84 1 move
SOAR_ID 85
SOAR_ID 86
ENUMERATION 87 1 state
ENUMERATION 88 1 move-block
ENUMERATION 89 1 get
SOAR_ID 90
ENUMERATION 91 1 blocked
SOAR_ID 92
INTEGER_RANGE 93 -2147483648 2147483647
ENUMERATION 94 4 east north south west
SOAR_ID 95
INTEGER_RANGE 96 -2147483648 2147483647
ENUMERATION 97 1 block
SOAR_ID 98
FLOAT_RANGE 99 -Infinity Infinity
INTEGER_RANGE 100 -2147483648 2147483647
INTEGER_RANGE 101 -2147483648 2147483647
ENUMERATION 102 1 block
SOAR_ID 103
FLOAT_RANGE 104 -Infinity Infinity
ENUMERATION 105 2 no yes
FLOAT_RANGE 106 -Infinity Infinity
FLOAT_RANGE 107 -Infinity Infinity
INTEGER_RANGE 108 -2147483648 2147483647
INTEGER_RANGE 109 -2147483648 2147483647
SOAR_ID 110
ENUMERATION 111 1 move-to-gateway
SOAR_ID 112
ENUMERATION 113 1 move-block
INTEGER_RANGE 114 -2147483648 2147483647
INTEGER_RANGE 115 -2147483648 2147483647
INTEGER_RANGE 116 -2147483648 2147483647
SOAR_ID 117
SOAR_ID 118
SOAR_ID 119
ENUMERATION 120 1 true
ENUMERATION 121 1 true
ENUMERATION 122 1 true
SOAR_ID 123
SOAR_ID 124
ENUMERATION 125 1 stop
INTEGER_RANGE 126 -2147483648 2147483647
INTEGER_RANGE 127 -2147483648 2147483647
SOAR_ID 128
ENUMERATION 129 1 drop
INTEGER_RANGE 130 -2147483648 2147483647
INTEGER_RANGE 131 -2147483648 2147483647
SOAR_ID 132
ENUMERATION 133 1 move
SOAR_ID 134
SOAR_ID 135
ENUMERATION 136 1 rotate
SOAR_ID 137
ENUMERATION 138 1 stop
SOAR_ID 139
SOAR_ID 140
FLOAT_RANGE 141 0.0 Infinity
SOAR_ID 142
SOAR_ID 143
SOAR_ID 144
ENUMERATION 145 1 true
160
0 attribute 19
0 block-id 114
0 choices 20
0 impasse 21
0 io 1
0 name 22
0 operator 14
0 operator 23
0 operator 110
0 operator 112
0 superstate 5
0 top-state 0
0 type 4
1 input-link 2
2 area-description 29
2 continuous 145
2 object 98
2 self 26
3 move 6
3 rotate 8
3 rotate-absolute 72
3 rotate-relative 73
3 stop-sim 12
6 direction 9
6 status 7
8 direction 11
8 status 10
12 status 78
12 true 13
14 actions 3
14 name 15
16 io 1
16 name 18
16 operator 132
16 operator 135
16 operator 137
16 superstate 0
16 top-state 0
16 type 17
23 name 24
23 random 25
26 angle 27
26 area 93
26 carry 95
26 collision 56
26 cycle 59
26 position 61
26 random 66
26 score 60
26 time 67
26 velocity 68
27 output-link 3
27 yaw 28
29 gateway 43
29 wall 30
30 center 38
30 direction 42
30 id 31
30 left 32
30 right 35
32 col 33
32 row 34
35 col 37
35 row 36
38 angle-off 143
38 x 39
38 y 40
43 center 44
43 direction 94
43 id 48
43 left 49
43 right 52
43 to 55
44 angle-off 142
44 range 141
44 x 46
44 y 47
49 col 50
49 row 51
52 col 53
52 row 54
56 x 58
56 y 57
61 col 65
61 row 64
61 x 62
61 y 63
68 speed 69
68 x 70
68 y 71
72 status 76
72 yaw 74
73 status 77
73 yaw 75
79 gateway 43
79 io 1
79 moving 121
79 name 81
79 need-to-turn 120
79 operator 83
79 operator 85
79 operator 92
79 rotating 122
79 superstate 0
79 top-state 0
79 type 80
83 actions 124
83 name 82
85 actions 123
85 name 84
86 block-id 126
86 io 1
86 name 88
86 operator 90
86 operator 128
86 superstate 0
86 top-state 0
86 type 87
90 actions 117
90 name 89
92 block-id 131
92 name 91
95 id 96
95 type 97
98 angle-off 144
98 area 100
98 id 101
98 position 103
98 range 104
98 type 102
98 visible 105
103 col 109
103 row 108
103 x 106
103 y 107
110 gateway 116
110 name 111
112 block-id 115
112 name 113
117 get 118
117 move 119
117 rotate-relative 73
118 id 127
119 direction 125
123 move 6
124 rotate-relative 73
128 block-id 130
128 name 129
132 actions 134
132 name 133
134 move 6
135 actions 140
135 name 136
137 actions 139
137 name 138
139 move 6
140 rotate 8
142 yaw 45
143 yaw 41
144 yaw 99
