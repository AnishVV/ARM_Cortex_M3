




const unsigned char Shoot[] = 
{7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,8,7,7,7,7,7,7,7,7,7,7,7,8,7,6,8,8,7,7,7,7,7,7,7,7,7,8,7,7,8,7,8,6,7,6,7,8,5,7,11,9,5,6,10,9,7,8,9,10,7,2,8,8,9,9,8,11,11,10,5,10,8,3,4,4,6,10,5,5,7,4,7,
10,6,8,12,10,6,6,11,11,10,6,10,12,7,10,13,12,13,12,12,9,5,5,5,6,8,7,9,6,10,12,8,7,10,11,8,5,8,12,8,6,7,11,12,10,8,10,11,9,13,12,13,10,12,10,6,8,7,9,5,5,9,10,8,4,3,3,6,4,3,3,3,3,4,6,4,3,6,6,5,10,6,8,8,4,5,6,5,5,6,6,5,6,5,2,3,2,3,2,3,4,3,3,2,5,5,3,4,3,5,6,4,4,5,9,9,10,10,9,7,7,7,7,6,6,6,6,7,7,5,7,6,6,8,8,6,7,6,6,5,5,4,6,10,8,4,5,7,6
,6,4,6,7,5,6,6,7,8,8,6,7,8,8,5,9,10,9,10,11,11,11,10,8,8,5,7,6,5,6,10,7,5,6,9,7,5,8,8,10,10,10,9,8,9,8,6,5,5,7,8,6,5,6,8,9,9,6,8,11,11,12,10,11,11,11,11,9,8,10,11,10,10,10,9,6,7,8,6,7,7,6,5,5,7,5,8,8,8,9,9,10,10,10,10,8,6,7,7,6,7,7,5,5,7,5,5,6,7,9,8,7,8,9,10,8,7,8,10,11,9,10,11,11,11,10,11,11,11,10,10,11,10,9,9,10,9,10,9,8,9,11,10
,9,10,10,10,9,9,8,9,9,8,10,9,8,8,8,9,7,7,8,8,8,7,8,8,7,9,8,7,9,10,9,8,9,9,9,8,8,9,9,9,10,10,10,10,10,10,10,9,10,11,10,10,9,9,9,9,8,9,8,9,9,8,8,8,9,9,8,8,8,9,9,8,9,9,8,8,9,9,8,9,9,9,10,9,9,10,8,8,10,9,9,10,9,9,9,8,8,9,9,8,10,9,9,10,10,10,10,9,9,10,9,9,10,9,8,10,9,8,10,9,9,9,8,8,9,9,8,8,9,8,8,9,8,8,9,8,9,8,9,8,7,8,9,9,9,8,9,9,9,9,8,
8,9,9,9,9,9,9,8,9,9,9,9,9,8,9,9,9,9,9,9,8,9,9,9,9,9,9,10,9,9,9,9,9,9,9,9,9,9,8,8,8,8,9,9,8,8,8,8,9,9,9,9,8,9,9,9,9,9,9,9,9,9,9,9,8,8,8,9,8,8,8,8,9,8,8,9,8,8,8,9,9,8,9,9,8,8,8,8,8,9,9,9,8,9,8,8,9,9,9,8,8,8,8,8,8,8,9,9,8,8,8,9,8,8,9,9,8,9,9,8,9,9,8,8,8,8,8,9,7,8,9,8,8,8,8,9,8,8,8,8,8,8,8,9,8,8,8,8,8,8,8,8,8,8,7,8,8,8,8,8,8,8,9,8,8,8
,8,8,8,8,8,8,8,8,8,9,8,8,8,8,8,8,8,8,8,7,8,9,8,8,8,8,8,8,8,8,7,8,8,7,8,7,8,8,7,8,7,7,8,8,8,8,7,8,8,7,8,8,7,8,8,8,7,8,7,8,8,7,8,8,8,8,8,8,8,8,9,8,7,8,9,8,8,8,8,8,8,8,8,9,8,7,8,6,8,8,7,7,8,8,7,8,8,8,8,7,7,7,8,8,7,8,8,8,7,8,7,7,8,7,8,7,8,8,7,7,7,8,8,7,7,7,7,7,7,9,7,7,7,7,6,8,10,10,8,4,2,2,3,6,9,9,5,4,7,9,8,7,7,6,3,4,7,6,9,10,10,10,9
,7,5,7,6,3,6,6,8,10,10,8,6,7,5,7,7,5,5,5,7,6,8,10,8,7,7,8,7,7,7,7,9,6,7,9,9,8,6,6,6,7,7,9,8,8,5,3,5,7,7,9,10,7,6,7,8,8,9,10,6,5,6,6,6,7,7,8,7,8,8,6,7,7,8,7,5,5,5,7,7,7,8,8,6,7,7,6,7,7,7,6,6,6,6,7,6,8,7,8,7,5,7,7,5,7,7,7,7,8,8,7,6,8,8,6,7,9,9,6,10,7,3,3,3,3,6,9,8,10,11,8,6,5,9,11,9,9,10,7,9,9,6,9,9,7,7,4,3,3,3,5,6,5,7,5,5,7,8,10,9
,9,9,9,6,3,4,6,8,8,9,6,6,8,7,6,6,5,5,5,5,5,4,6,5,6,8,8,7,6,7,7,6,5,6,7,8,8,8,6,7,7,6,8,9,7,6,6,6,7,7,6,6,7,7,7,6,5,5,6,7,7,7,6,6,7,6,7,7,5,7,6,7,7,7,7,6,7,7,7,6,5,6,6,4,5,7,8,7,7,5,8,8,5,7,6,5,6,7,8,7,7,8,6,7,7,6,5,6,6,6,7,6,6,6,6,6,7,7,7,6,6,6,5,4,6,6,5,7,8,8,6,7,9,6,7,7,7,7,6,6,7,7,7,8,7,7,7,6,5,4,6,6,7,6,5,5,6,7,6,7,7,8,8,7,6,
6,6,6,7,6,6,7,8,8,6,6,7,7,6,5,5,6,7,7,7,6,7,7,7,7,6,6,5,4,5,5,5,7,6,7,7,6,8,7,6,7,7,7,6,6,6,6,7,7,6,5,6,7,6,6,7,6,7,7,5,5,6,7,7,6,7,6,6,7,7,6,7,6,6,5,6,7,6,7,7,6,6,7,7,5,6,7,6,6,6,6,6,5,7,7,6,6,6,6,7,7,6,5,6,7,7,6,7,5,5,6,6,6,6,6,7,7,6,6,5,6,6,6,6,7,6,6,7,7,7,6,8,9,7,7,8,7,6,8,11,11,7,3,4,6,5,3,4,4,5,9,12,10,11,13,12,12,11,8,9,10,
9,7,5,4,6,6,5,4,2,2,2,4,3,4,5,6,8,8,8,9,10,9,8,7,8,9,7,6,7,6,5,4,3,3,4,6,7,9,8,8,9,9,10,9,7,8,8,8,7,5,5,6,6,5,5,6,8,7,5,3,3,5,6,6,7,8,8,6,6,7,9,8,7,8,7,7,9,8,7,5,6,6,5,6,6,6,6,6,5,6,7,7,8,7,6,6,7,6,6,6,6,7,7,6,7,6,7,7,6,7,7,7,6,6,6,6,7,7,7,6,7,7,7,6,6,7,6,7,7,6,6,7,7,7,7,7,7,6,6,7,7,7,7,7,7,8,7,6,6,6,6,6,6,6,6,7,7,7,6,6,6,8,8,6,7,
7,7,7,7,7,8,7,7,6,7,7,7,6,7,8,7,7,7,7,6,6,6,6,6,7,7,6,6,7,7,6,7,7,6,6,7,8,7,7,8,8,7,7,7,7,7,7,7,7,6,7,6,6,6,6,7,7,7,6,6,7,7,7,7,6,6,7,6,6,6,7,7,7,7,8,7,7,8,8,7,6,7,7,7,7,7,7,7,7,6,6,6,6,6,7,7,7,7,6,6,7,7,8,8,7,7,7,7,6,6,7,7,7,7,7,7,7,7,6,7,9,11,9,5,3,3,4,7,8,9,7,8,11,9,6,5,6,8,9,8,8,7,7,7,7,6,5,5,5,6,7,6,6,6,7,7,8,9,8,7,7,6,6,6,7
,7,7,7,7,6,6,6,6,6,7,8,7,7,8,7,7,7,8,8,7,7,8,8,7,6,7,8,7,6,6,7,6,5,5,5,6,7,8,7,8,8,7,7,7,8,7,7,7,8,7,7,7,7,7,6,7,8,8,8,8,7,6,6,6,6,6,7,7,7,6,7,8,10,12,6,4,5,4,5,3,3,4,9,13,13,12,10,9,8,7,8,6,3,3,6,9,9,9,10,9,7,6,5,4,4,6,6,7,10,9,10,9,6,5,6,7,7,7,6,5,6,7,7,8,8,9,9,7,7,6,7,6,6,7,7,6,6,8,8,7,11,11,7,5,4,5,7,4,3,7,9,12,12,9,9,8,7,7,6
,5,7,9,9,8,9,11,10,7,7,7,6,6,6,6,4,5,6,6,6,6,7,8,7,7,9,10,9,8,9,8,7,5,5,7,7,6,8,9,10,9,7,6,6,6,6,4,4,9,5,3,7,7,7,7,9,7,5,5,7,9,12,12,12,11,7,6,5,5,5,6,7,7,7,7,11,12,8,4,4,5,4,5,6,7,6,6,6,7,6,7,9,9,9,10,10,6,5,6,6,7,8,8,7,7,7,8,8,8,8,11,12,7,2,5,4,3,3,5,7,7,6,8,12,8,5,9,12,11,12,12,9,7,8,8,8,9,8,9,10,8,6,5,5,4,3,4,6,6,5,5,7,8,7,8,
8,8,8,9,7,6,6,9,10,9,11,10,9,7,7,8,9,10,8,6,5,8,9,8,7,6,7,8,6,6,5,3,5,6,5,6,8,9,10,9,10,10,8,9,8,6,6,6,8,9,9,6,8,8,7,7,8,9,8,6,7,8,7,6,5,7,12,9,4,4,4,4,4,5,5,4,7,11,10,9,8,10,13,13,12,10,8,7,6,7,8,6,7,7,5,6,6,5,6,6,5,6,7,7,8,9,9,9,9,9,7,7,8,8,9,9,8,7,7,8,9,10,9,7,6,7,7,7,7,6,6,9,11,9,5,5,5,5,6,6,6,6,6,9,10,8,7,9,11,10,8,9,9,8,9,8
,7,7,8,7,7,7,7,8,7,6,5,5,6,5,5,5,7,9,10,9,7,7,8,9,10,10,9,7,5,4,6,7,8,8,8,8,9,9,9,8,6,6,8,8,8,9,9,8,9,8,8,8,7,7,7,8,7,7,6,5,6,8,8,8,8,8,7,6,6,6,8,9,9,8,7,7,8,9,9,8,6,7,9,9,7,4,6,8,10,9,9,9,7,6,7,7,7,7,7,8,8,9,8,7,6,8,8,6,7,7,7,8,8,8,7,8,8,9,9,6,5,6,7,7,8,8,7,7,8,8,9,9,9,10,8,8,8,8,8,7,7,7,6,8,7,7,8,8,8,8,7,7,7,8,8,7,8,8,8,7,6,8,9,
7,7,7,7,7,7,7,7,7,8,9,8,8,10,11,9,7,6,5,7,9,8,8,8,8,9,9,9,7,6,6,6,7,7,6,6,7,8,8,9,9,9,7,7,9,8,7,7,8,8,8,7,8,9,9,7,7,7,7,6,6,7,7,8,9,8,10,9,8,8,9,8,6,6,6,6,7,7,8,8,8,8,8,8,7,7,9,9,9,9,8,7,8,8,8,9,8,7,6,6,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,7,8,9,7,6,6,7,6,4,6,11,12,9,8,8,9,9,8,9,7,6,7,6,6,8,6,6,8,7,9,10,8,8,7,7,8,9,9,9,9,8,8,8,8,8,8,10
,9,7,6,5,6,6,6,8,6,6,8,7,7,8,7,8,9,8,9,9,8,7,8,9,8,8,8,9,8,7,7,8,7,7,7,7,7,6,7,8,7,7,7,8,8,8,8,8,8,8,9,7,6,8,7,7,8,8,8,9,8,7,8,8,8,8,8,9,9,7,6,7,6,5,5,7,7,5,5,6,7,8,8,10,9,8,9,11,11,10,9,8,9,10,9,8,7,6,6,6,6,6,6,7,7,7,8,7,7,7,8,9,9,8,8,7,6,7,7,7,8,8,8,9,8,9,8,7,8,8,7,7,8,9,8,7,8,9,8,8,8,9,7,7,8,8,8,7,8,8,8,8,8,8,8,8,8,8,8,6,6,7,7
,8,8,7,8,8,8,8,9,8,8,8,9,9,8,7,7,7,7,7,8,8,8,7,7,10,9,6,7,8,7,7,7,9,8,7,7,7,7,8,8,9,8,8,8,8,7,7,10,10,8,7,8,9,9,8,7,6,7,9,8,6,6,8,8,7,7,7,7,7,8,9,9,9,8,9,7,8,9,8,8,8,8,8,8,7,6,7,8,7,7,7,6,5,7,8,8,7,7,8,9,9,9,9,10,8,8,8,8,9,9,7,7,5,6,8,8,8,9,8,6,7,9,7,7,7,7,8,9,10,11,9,8,7,6,6,7,6,7,8,8,8,8,7,8,8,6,6,7,8,9,7,6,7,9,10,11,11,9,8,8,8,
9,8,7,7,7,7,7,9,8,7,7,8,7,6,6,5,5,7,9,8,8,9,8,8,9,8,7,8,8,7,7,7,8,8,8,10,11,9,8,8,7,6,6,7,8,7,7,7,8,8,7,8,8,8,8,7,7,7,6,7,9,8,8,8,9,9,9,9,8,8,7,8,8,8,8,7,8,7,7,7,6,7,7,8,8,9,9,10,9,8,8,9,10,10,9,9,8,8,8,8,6,6,7,8,9,9,8,7,7,7,7,9,9,8,7,7,8,8,8,8,7,7,8,9,9,9,9,8,8,9,9,9,9,7,6,7,8,8,7,8,8,8,8,8,8,6,7,8,9,9,8,9,9,8,7,6,7,7,7,9,8,8,9,9
,8,8,8,8,8,6,6,6,6,7,8,8,7,7,7,8,10,9,9,9,9,8,6,7,8,7,7,7,7,8,7,6,6,6,6,8,8,8,8,9,8,9,9,10,9,8,8,7,8,8,8,8,7,8,8,8,8,7,6,6,8,7,6,7,7,8,8,9,9,9,9,10,10,9,6,7,8,7,7,5,7,8,8,8,8,8,8,10,11,10,9,6,6,7,9,9,8,8,10,10,9,9,8,7,7,7,8,9,8,6,6,6,6,7,6,6,7,8,10,10,10,10,11,10,11,11,10,9,7,6,6,8,8,7,7,6,7,7,8,8,7,7,6,6,6,7,8,8,9,9,9,9,9,9,8,9,
9,7,8,8,8,8,9,9,8,8,8,8,7,7,7,8,7,7,8,8,7,8,10,10,8,5,6,6,6,6,6,6,8,9,8,8,9,8,8,8,6,6,9,9,11,12,11,9,7,7,8,8,8,8,8,7,7,8,9,7,5,5,6,6,6,5,6,8,9,10,10,9,7,8,8,9,10,10,10,10,10,10,8,7,6,5,6,8,9,7,6,7,9,11,9,7,8,8,10,8,4,5,6,7,8,7,7,7,7,6,7,9,8,9,10,10,9,9,9,8,8,7,7,8,6,7,8,9,8,9,9,8,7,6,8,8,7,6,7,8,8,8,10,10,10,9,7,7,8,8,8,8,7,6,7,9
,10,10,10,8,7,7,7,7,7,7,8,8,8,8,8,8,8,8,9,9,8,8,8,8,9,10,9,6,6,7,8,7,8,8,7,6,8,8,7,7,7,6,7,10,9,7,8,8,8,9,9,9,8,8,9,8,8,7,7,7,6,6,7,8,8,8,8,8,7,6,6,8,9,8,6,8,8,6,6,7,8,10,10,9,9,8,8,7,7,9,10,9,9,10,8,7,7,7,8,9,9,8,7,6,6,5,7,9,8,6,5,5,6,7,6,7,10,10,11,12,11,10,9,8,9,8,8,8,8,8,8,7,7,7,7,7,8,8,7,6,6,6,6,5,6,6,6,8,9,11,11,11,10,8,8,9
,9,9,8,7,7,7,7,8,8,9,9,9,7,5,6,6,7,8,8,8,6,6,7,8,7,7,9,10,10,9,8,6,5,5,5,4,8,11,11,11,10,9,9,10,9,7,7,9,8,7,6,6,6,7,7,7,5,4,5,7,9,10,9,8,10,12,12,10,8,7,7,8,9,11,9,8,7,6,6,7,7,7,6,6,7,7,7,7,7,8,8,8,10,11,11,10,9,9,7,6,6,7,7,8,8,8,8,7,7,7,8,9,9,8,8,7,7,7,7,8,9,9,9,9,7,6,6,7,8,7,8,9,9,9,9,10,11,9,8,8,7,7,7,8,7,8,8,8,8,7,7,8,7,7,8,8
,9,9,9,9,8,8,8,8,7,7,7,6,6,7,7,7,8,10,9,7,7,8,9,7,9,9,8,7,8,7,7,7,7,9,8,7,7,7,8,9,10,9,8,7,6,8,10,9,8,8,8,7,7,6,5,6,7,6,6,8,9,10,10,9,8,8,9,7,7,7,9,9,7,7,7,7,7,6,6,6,7,8,9,10,9,7,9,10,9,9,8,7,8,7,8,8,8,7,7,6,5,5,5,4,6,7,8,8,8,9,10,9,9,10,10,10,10,9,9,9,8,7,8,7,7,7,6,5,5,5,7,8,8,10,10,8,9,9,8,8,9,9,9,8,7,7,7,6,5,5,7,8,8,9,8,9,9,9,9
,9,9,7,7,7,8,7,7,7,7,8,8,9,8,7,7,8,8,8,7,8,8,8,8,8,9,10,8,7,8,9,9,8,7,7,8,7,6,8,9,7,7,7,7,7,6,6,7,7,7,7,8,9,8,8,9,10,9,8,8,7,7,6,7,9,10,7,6,6,6,7,6,5,5,5,5,7,10,11,11,11,11,10,10,9,8,8,8,8,7,7,6,6,7,7,7,6,5,6,7,7,7,6,6,7,7,8,9,9,9,10,10,10,10,10,9,8,8,8,8,8,7,7,6,8,7,7,7,7,7,8,8,8,9,10,9,8,7,6,7,7,7,7,8,8,8,7,7,7,8,7,7,8,8,10,9,8,
8,8,7,6,7,9,8,8,8,8,8,7,7,8,8,6,7,8,10,9,7,8,9,9,7,7,7,6,6,5,6,7,8,9,9,8,7,8,9,10,9,8,9,9,8,9,9,8,7,6,7,7,8,9,8,6,7,8,7,5,5,6,7,7,7,8,10,11,9,8,7,6,8,9,8,9,8,7,7,7,8,8,8,8,7,6,7,8,7,6,6,7,7,7,8,9,9,8,9,9,8,8,8,9,8,8,8,7,7,6,6,7,9,8,7,7,8,8,8,9,10,9,8,8,8,8,7,7,7,7,7,6,7,7,8,9,8,8,8,8,7,7,7,6,6,6,7,8,8,8,8,8,9,9,8,8,7,8,9,10,10,8,
6,6,7,7,7,7,7,8,9,8,8,8,7,6,6,8,8,8,7,8,7,7,7,7,8,9,9,9,8,9,8,7,7,6,6,7,8,9,9,8,6,7,7,7,7,7,8,8,8,9,9,9,8,8,8,8,9,9,8,8,9,10,10,6,6,6,6,6,6,6,7,7,9,10,9,9,8,8,7,6,6,6,6,6,8,9,8,8,8,9,8,7,6,5,6,7,8,9,9,11,10,9,9,10,11,10,8,7,7,7,6,7,6,5,5,6,8,9,10,9,7,7,6,6,6,7,8,8,7,9,9,9,9,8,7,7,7,8,7,7,7,8,9,9,7,8,10,11,10,9,9,8,6,5,5,7,7,7,7,7
,7,7,8,9,8,8,7,7,7,7,7,7,7,7,8,8,9,9,9,8,7,7,8,9,8,8,8,9,8,8,8,7,7,7,8,8,8,8,8,8,7,7,8,9,9,9,9,7,7,6,6,7,7,7,7,7,8,7,8,9,8,7,8,8,8,9,8,8,8,9,8,9,9,9,9,8,7,6,7,6,6,7,7,6,5,6,8,8,9,8,7,7,8,9,8,9,9,9,9,9,8,7,7,6,7,7,7,7,8,9,9,8,8,8,7,6,5,6,7,8,7,7,7,7,8,9,10,10,9,8,8,7,7,8,8,7,7,7,8,8,8,8,7,7,7,8,8,8,8,7,9,9,9,9,9,8,7,8,8,6,6,6,7,7,
7,8,9,9,8,6,7,7,7,7,8,9,10,9,9,9,10,9,7,7,7,6,7,7,7,8,7,7,7,8,8,8,8,6,6,7,8,7,6,6,8,10,9,9,9,11,10,8,7,6,5,5,6,8,8,7,7,7,8,8,7,7,8,9,8,8,9,9,9,8,8,6,5,6,6,7,7,8,8,7,6,6,6,7,8,9,9,8,9,9,9,8,7,7,7,8,7,7,7,8,8,8,8,7,7,8,8,8,8,8,7,6,6,7,8,7,7,8,8,8,8,7,7,8,8,7,8,8,8,8,7,7,7,7,8,8,9,10,9,8,7,7,8,7,7,7,7,7,8,8,8,7,7,8,8,8,8,8,8,7,7,8,9,
9,8,8,8,8,8,7,6,7,7,8,8,8,8,9,9,9,8,9,9,8,7,8,10,9,8,7,7,7,7,7,7,7,7,7,8,8,7,6,6,7,8,8,9,10,10,9,10,10,9,8,7,7,7,7,7,7,7,8,9,9,10,10,9,8,7,7,7,8,8,8,8,8,8,8,7,6,5,5,4,5,6,7,8,10,11,11,10,10,9,8,7,7,8,9,9,8,8,7,7,7,6,5,5,7,7,8,7,6,7,6,6,6,7,8,8,9,8,9,9,9,9,7,7,7,7,6,6,5,6,8,8,8,8,8,8,8,9,9,7,6,6,6,6,7,8,8,8,8,7,7,7,7,7,7,7,7,7,8,8
,7,7,8,7,8,8,8,8,8,7,8,9,9,8,8,8,9,9,9,9,9,9,9,8,7,7,6,6,6,6,7,8,8,7,7,6,7,8,7,7,8,8,8,8,8,9,9,9,8,7,8,9,9,8,9,9,8,8,7,6,6,7,7,8,8,8,9,8,7,6,7,6,6,8,9,8,9,10,9,9,8,7,7,7,7,7,8,8,7,7,8,7,7,7,8,9,10,9,8,7,6,6,7,7,7,6,6,7,7,6,7,7,8,9,8,8,9,9,8,9,9,8,8,8,6,6,7,8,8,7,7,7,6,6,6,7,7,7,7,8,8,8,7,6,6,6,7,8,9,9,8,8,9,10,8,8,7,8,8,9,9,8,6,8
,9,9,8,8,10,9,8,7,7,7,6,6,8,8,7,6,6,6,7,7,7,8,8,8,8,8,9,8,9,9,9,8,9,9,9,9,9,8,8,9,9,8,7,7,6,5,5,5,6,6,7,8,8,8,8,9,7,7,8,8,8,8,8,7,8,8,7,7,7,8,9,10,10,9,8,6,6,6,6,6,6,7,7,7,8,8,8,8,9,9,8,7,6,6,7,8,8,9,9,9,9,8,7,8,8,7,6,6,7,6,6,7,9,9,8,7,5,6,6,7,8,8,8,8,9,8,8,7,6,6,7,8,8,9,10,9,8,7,7,7,7,7,6,6,7,8,8,7,7,8,10,9,8,8,8,8,8,8,7,7,7,7,7
,8,8,9,8,7,8,9,9,10,9,8,8,9,10,9,7,7,7,9,9,9,8,8,7,6,6,6,6,5,6,8,9,10,9,9,9,8,8,8,7,6,6,7,8,7,8,9,9,9,8,8,8,8,7,6,6,7,7,7,7,7,8,8,7,7,7,7,6,5,6,7,7,7,8,9,9,9,9,8,7,7,8,9,9,9,8,6,5,6,8,8,8,8,8,8,8,7,7,6,5,5,6,6,6,6,8,8,7,8,8,7,7,7,9,8,7,8,10,9,9,8,9,9,8,8,9,9,9,8,7,6,6,6,5,5,5,5,6,8,10,11,10,8,7,8,9,10,9,8,6,6,7,8,8,7,8,9,10,10,9,
8,9,10,8,7,7,6,6,7,8,7,6,6,6,6,7,7,6,7,7,7,9,11,11,10,10,9,9,9,8,7,7,6,7,7,7,7,6,5,6,8,8,8,9,9,9,9,8,8,7,7,7,7,6,6,5,6,6,6,6,6,6,7,6,7,7,8,8,8,9,10,11,10,8,7,6,6,7,8,8,7,7,7,7,7,6,7,7,7,6,6,7,7,7,8,8,8,8,8,8,8,9,9,10,10,9,8,8,9,9,8,8,7,7,8,7,7,7,6,7,7,7,7,8,7,7,7,8,8,8,9,9,9,9,9,9,8,8,8,9,10,10,7,5,5,6,6,6,7,8,8,8,7,7,9,8,6,7,8,
7,8,9,8,8,8,9,8,8,9,10,10,9,8,9,10,9,7,7,7,8,10,10,8,6,7,7,6,7,8,8,8,8,8,7,6,6,7,7,6,6,7,8,9,8,9,9,8,7,7,7,7,7,7,7,7,7,7,8,7,6,6,6,6,7,7,7,7,7,7,8,9,8,8,9,8,7,7,7,8,8,8,8,7,7,6,6,6,6,6,7,7,7,6,6,5,5,6,6,7,7,7,7,7,9,10,10,9,8,7,7,8,8,7,7,8,8,8,8,6,6,6,6,7,8,8,7,7,6,7,8,8,8,8,8,8,8,8,9,9,8,8,7,7,7,6,6,6,5,5,6,7,8,8,7,8,8,9,9,9,9,9,
9,9,9,9,7,7,7,8,8,8,7,7,7,7,8,8,9,9,9,9,9,8,8,8,9,8,8,8,8,7,7,9,9,8,8,9,9,8,7,6,5,5,6,7,8,8,8,9,9,9,9,9,10,9,9,9,8,8,8,8,8,8,8,8,7,6,5,5,4,5,6,8,9,9,9,8,7,7,6,6,6,6,7,7,8,9,9,8,7,6,6,6,7,8,8,8,9,9,8,8,9,8,7,8,7,7,7,6,5,5,5,5,5,4,6,6,5,6,7,7,7,8,10,10,9,9,8,8,8,8,8,8,8,7,7,8,8,8,8,7,6,6,6,6,6,8,8,7,7,7,7,8,7,7,7,7,7,8,8,9,9,9,8,8,
8,8,8,7,6,6,7,7,7,7,7,8,9,9,9,9,8,8,8,8,8,8,7,7,7,8,8,8,8,7,7,7,7,7,7,7,7,8,8,8,8,8,9,9,8,8,8,7,7,7,8,8,7,7,8,9,9,7,6,6,6,7,7,7,8,9,9,9,8,7,7,8,9,9,9,8,7,6,6,6,6,6,7,8,8,8,8,8,9,10,10,10,9,8,8,7,7,8,8,8,7,7,7,8,8,8,7,7,6,6,6,7,7,7,7,7,8,9,9,9,8,8,8,8,8,7,7,7,7,7,7,7,6,7,7,7,7,7,7,8,8,7,7,7,7,7,7,7,7,7,7,6,6,6,6,6,6,6,7,8,9,8,8,8,
8,9,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,9,10,10,10,8,8,7,7,7,8,8,7,6,6,7,7,7,7,7,6,7,7,7,7,8,8,8,8,8,8,9,9,9,8,9,8,7,7,7,7,7,7,6,6,7,7,7,7,7,7,8,8,8,8,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,7,7,7,8,9,9,8,8,7,7,7,7,7,6,6,7,7,7,8,7,7,8,8,7,7,8,8,8,9,9,9,8,8,7,8,9,8,8,8,9,8,8,7,6,7,8,7,7,8,7,7,7,6,6,6,7,7,7,7,7,8,8,8,8,8,8,8,8,8,7,7,7,8,
8,9,9,9,8,8,7,7,7,8,8,7,7,7,7,7,7,7,7,7,7,7,8,8,8,7,7,7,7,7,7,7,8,8,7,7,7,7,8,8,9,9,8,8,8,7,7,7,7,7,7,8,7,7,6,6,7,7,7,7,7,7,7,8,9,9,8,8,7,6,7,6,6,6,6,6,7,8,8,8,8,8,9,8,8,7,7,8,8,7,7,8,7,7,7,7,7,8,8,9,9,9,8,8,8,8,9,8,8,8,8,8,8,8,8,9,9,9,8,7,7,7,6,6,6,7,7,7,7,8,10,9,9,9,9,9,9,8,7,8,9,9,9,9,10,9,8,7,6,6,6,6,6,7,7,8,9,9,9,9,9,9,9,8,
7,7,7,7,6,7,7,8,8,7,7,7,7,7,7,7,8,8,8,8,9,9,8,8,8,7,7,6,6,6,5,5,6,6,6,7,8,8,8,7,7,7,8,7,7,8,6,5,6,6,6,6,6,6,6,7,7,7,7,7,8,9,8,7,7,7,8,8,9,10,10,9,8,7,7,7,7,7,6,7,7,7,7,6,6,6,7,8,7,7,6,6,6,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,9,10,9,9,9,9,8,8,7,7,7,7,7,7,7,7,7,6,6,6,6,7,8,8,8,7,7,7,7,8,8,8,8,7,8,8,9,9,8,7,7,7,7,7,8,8,9,9,8,8,8,7,7,7,7,8
,8,8,8,8,7,6,6,6,7,6,6,6,7,8,8,9,9,8,7,7,7,8,8,8,7,6,6,7,8,8,8,9,9,8,8,7,7,7,8,9,9,7,7,7,7,7,7,7,8,8,8,8,7,7,8,8,8,7,6,6,6,6,7,7,8,8,8,9,9,10,9,8,7,7,7,7,7,7,7,7,6,6,7,7,7,7,7,8,8,9,9,9,9,9,9,9,8,8,8,8,8,7,6,7,7,7,6,6,7,7,7,6,6,6,6,6,7,7,7,7,9,10,10,9,9,9,9,9,10,10,9,8,7,7,5,5,5,6,7,8,8,7,6,7,7,7,7,7,7,8,9,8,8,8,8,9,8,7,7,7,7,7,
7,7,7,7,7,7,8,8,8,8,8,9,8,7,7,6,7,7,7,7,8,9,8,8,7,6,7,8,8,9,8,9,9,9,9,9,9,9,9,9,8,8,7,6,6,6,6,6,6,6,6,7,8,8,9,9,8,8,7,7,7,7,8,9,9,9,8,8,7,7,7,8,8,7,7,8,8,7,6,6,6,6,6,7,8,8,8,7,7,7,7,7,6,6,7,8,8,8,8,8,8,8,8,7,7,7,7,6,6,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,7,7,7,6,7,7,7,7,8,8,7,7,8,8,8,8,8,8,8,7,6,7,7,8,7,8,8,7,7,7,7,8,7,6,6,6,7,7,7,7,8,
8,9,9,8,8,8,9,8,8,7,7,7,7,7,8,8,8,8,7,7,6,7,7,8,8,7,7,7,8,8,8,8,8,8,8,8,8,7,7,7,7,8,8,8,7,8,8,9,9,8,9,9,9,9,8,6,6,6,7,8,8,8,7,7,7,7,8,9,9,9,9,9,8,7,7,7,6,6,6,7,7,7,6,6,5,6,7,8,9,9,9,9,9,7,6,6,6,7,8,9,9,8,8,8,9,9,8,7,6,6,6,7,7,7,6,5,5,6,7,7,6,6,5,6,7,7,6,6,6,8,9,9,9,9,9,9,9,8,7,7,8,8,9,9,9,8,6,5,5,6,6,6,7,8,7,7,7,7,8,8,9,10,10,8,8
,8,7,7,8,8,8,8,7,7,7,7,7,7,8,7,6,7,9,9,9,9,9,10,9,8,8,7,7,7,7,7,7,8,8,8,8,8,7,7,7,7,7,7,7,6,6,6,7,7,8,8,8,8,8,8,7,7,7,7,7,7,7,7,8,8,9,8,8,7,7,7,7,7,7,6,7,8,7,7,6,7,7,8,8,8,7,7,8,9,9,8,8,8,8,9,8,7,7,8,8,7,7,7,7,6,6,6,6,7,6,6,7,7,7,8,8,9,9,8,6,7,7,8,9,10,9,8,7,7,8,8,8,6,6,6,6,6,5,6,7,7,7,8,8,8,7,7,7,8,8,8,8,8,9,9,8,7,8,8,7,7,8,8,8,7
,8,8,8,9,9,8,8,8,7,6,6,6,6,6,6,6,7,7,8,8,8,8,8,8,7,7,8,8,9,8,9,9,9,9,9,10,9,8,8,7,7,7,6,6,6,7,7,7,7,7,6,6,7,7,7,7,8,8,8,8,8,8,8,8,9,9,9,8,7,7,7,8,8,7,6,6,6,7,7,7,7,6,6,7,7,6,6,6,6,7,7,8,8,8,8,8,7,7,6,7,7,8,8,8,8,8,7,8,8,8,8,8,7,7,8,8,8,7,7,6,6,7,7,7,8,7,7,7,6,6,6,7,8,9,9,9,9,8,8,8,8,8,9,8,8,8,8,8,7,8,8,8,8,8,7,7,7,7,8,8,7,6,6,7,8
,8,9,8,8,7,7,8,9,9,8,8,7,7,7,7,8,8,9,9,9,8,7,6,7,7,8,9,10,10,10,9,7,6,6,6,5,6,7,8,8,7,6,6,6,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,7,7,6,6,7,7,8,8,8,7,7,7,7,7,7,7,7,7,7,6,6,6,7,7,7,7,7,7,8,8,8,8,8,7,7,8,8,8,8,8,8,8,8,8,8,9,8,7,6,6,7,7,7,8,9,9,9,9,9,9,9,9,8,8,8,7,7,7,6,6,6,6,6,6,6,6,6,7,8,8,9,9,9,9,9,9,9,8,8,9,8,8,8,7,7,8,8,7,6,6,7,7,6,
6,6,6,6,5,6,6,7,7,8,8,8,8,8,8,7,8,8,8,8,8,8,8,7,7,7,7,6,6,7,7,6,6,7,7,7,7,7,7,7,8,8,8,8,8,8,9,9,9,8,8,8,8,8,8,8,7,7,7,7,7,7,7,8,7,7,7,7,7,7,7,8,8,8,8,8,7,7,8,8,8,8,8,8,8,7,7,7,7,6,7,7,7,7,8,8,8,8,8,8,8,8,8,8,7,7,8,8,8,8,8,7,7,7,8,8,9,8,8,8,8,7,7,6,6,6,6,7,8,8,8,9,9,9,9,9,9,8,8,8,8,7,7,8,8,7,8,8,8,8,7,7,7,7,7,8,8,8,7,8,7,7,8,9,9,8
,8,7,7,7,7,7,8,8,7,6,6,6,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,6,6,6,6,6,7,7,7,8,8,8,8,8,8,8,8,8,8,7,7,6,6,6,6,6,6,6,6,7,7,8,8,8,8,8,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,7,7,6,7,7,8,8,8,8,9,9,9,9,9,8,7,8,8,7,7,6,6,6,7,7,7,7,6,6,6,7,7,8,8,9,9,9,9,8,8,8,8,8,7,6,6,7,7,7,7,7,7,7,7,7,7,7,6,6,6,7,7,7,7,8,8,7,7,7,7,7,7,7,7,7,7,8,8,8,8,
7,8,8,8,8,8,7,7,8,8,9,9,8,7,7,7,7,7,7,8,8,8,8,8,9,9,8,8,7,7,7,8,8,9,10,10,9,9,8,9,9,8,8,7,7,7,7,8,7,6,6,6,7,6,6,6,7,7,8,8,8,8,8,9,9,10,10,9,8,8,8,7,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6,6,6,6,7,8,8,8,8,8,8,7,7,6,7,7,7,8,8,8,7,6,6,7,7,6,6,7,7,7,8,8,8,8,8,8,9,8,7,7,7,7,7,7,7,7,7,6,6,7,7,7,7,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7
,8,8,8,7,7,7,7,6,7,7,8,8,8,8,9,9,8,8,8,7,7,7,7,7,7,7,7,7,6,6,5,6,6,6,6,7,7,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,8,8,8,8,8,7,7,7,6,5,5,6,6,6,6,6,7,7,7,8,8,9,9,9,9,9,8,7,7,7,7,7,7,8,8,8,9,9,9,9,8,8,8,8,8,9,9,9,9,9,9,10,9,9,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,8,8,8,8,8,7,7,8,8,9,9,9,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,6,6,6,6,6,7,7,7,7,7,7,7,7
,7,7,7,7,7,7,8,8,7,7,7,7,7,6,6,6,6,6,6,7,7,7,6,6,6,6,7,7,7,7,7,7,7,8,8,8,8,9,9,8,8,7,7,7,6,7,7,7,7,7,8,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6,6,6,6,7,7,7,7,7,8,8,9,9,9,8,8,8,8,8,8,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,8,8,8,8,
8,8,8,8,7,7,7,7,7,7,7,7,8,8,8,8,7,7,7,8,8,8,8,8,8,8,8,8,8,8,7,8,7,7,8,8,7,7,7,6,6,6,7,7,8,8,8,8,7,7,7,7,7,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,8,8,8,8,9,9,8,8,7,7,7,7,7,7,7,7,7,8,8,8,8,8,7,7,7,7,7,8,8,8,8,8,8,8,7,7,7,7,8,8,8,8,8,8,8,8,8,7,7,7,8,8,8,8,8,8,8,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8
,8,8,8,8,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,8,7,8,7,7,7,7,7,7,7,7,7,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,7,7,7,8,8,8,8,8,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,8,8,8,8,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,6,7,7,6,6,6,6,7,7,7,7,7,7,7,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,7,7,7,7,8,8,8,8,8,8,8,8,7,7,8,8,9,9,9,9,9,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,8,8,8,8,8,8,8,8,8,7,8,8,8,8,8,8,7,7,7,7,8,8,7,7,8,8,7,7,6,6,7,7,7,7,7,6,6,7,7,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,8,8,8,8,9,9,9,9,8,8,8,8,8,8,8,8,8,7,7,6,6,7,7,7,7,7,7,7,8,8,8,8,8
,8,8,8,8,8,8,9,9,9,8,7,7,7,7,7,7,6,6,6,6,7,7,7,7,8,8,8,8,8,7,8,8,8,8,9,9,8,8,7,7,7,7,7,7,7,7,7,7,6,7,7,7,8,8,8,8,8,8,8,8,8,7,8,8,8,8,8,7,7,7,6,6,6,6,6,7,7,8,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,7,7,6,7,7,7,8,8,8,8,7,7,7,7,7,6,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,9,9,9,9,9,8,8,8,7,7,7,7,7,
8,8,7,7,7,6,7,7,7,7,7,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,8,8,8,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,7,7,6,6,6,7,7,7,7,8,7,7,7,8,8,8,7,7,7,7,7,8,8,8,8,7,7,7,7,7,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,7,7,7,7,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,7,7,8,8,8,8,8,8,8,8,8,7,7,8,8,8,8,8,8,8,7,7,7,7,7
,7,8,8,8,8,8,8,7,7,8,8,8,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,8,8,8,8,8,8,8,8,8,7,7,7,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,6,6,6,7,7,7,7,7,7,7,8,8,8,8,8,7,7,7,7,7,7,7,7,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,7,7,7,7,7,7,7,7,7,7,8,8,8,8,7,7,7,6,6,7,
7,7,7,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,7,7,8,8,8,7,7,7,7,7,7,7,7,6,6,6,7,7,8,8,8,8,8,8,8,7,7,7,7,7,7,7,8,8,8,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,9,9,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,7,7
,7,7,7,7,7,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,7,7,7,7,7,8,8,8,9,9,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,9,9,9,9,9,8,8,8
,8,8,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,7,7,7,7,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8
,8,8,8,8,8,7,8,8,8,8,7,8,8,8,8,7,7,7,7,8,8,8,8,8,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,8,7,7,7,7,7,7,8,8,8,8,8,7,7,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,8,8,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,8,8,8,7,7,8,8,8,7,7,7,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8
,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,8,8,8,8,7,8,8,8,8,8,7,7,7,7,8,8,8,8,8,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,8,7,7,7,7,7,7,7,7,8,8,8,8,7,7,7,7,7,7,7,8,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8
,8,8,8,8,8,8,8,8,7,7,7,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,8,8,8,8,8,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,7,7,7,7,8,8,8,7,7,7,7,7,7,7,7,7,8,8,8,8,7,7,7,7,7,7,7,7,7
,8,8,8,8,8,7,7,7,7,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7
,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,7,7,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,7,7,7,7,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,8,8,7,7,7,7,7,7,7,8,8,8,8,8,8,7,7,7,8,8,8,8,8,8,8,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,8,8,8,8,7,7,7,8,8,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,8,8,8,8,8,8,8,8,8,7,7,7,8,8,8,8,8,8,8,8,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,8,8,7,7,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,7,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,8,8,7,7,7,7,7,7,7,7,7,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,7,7,8,8,8,8,7,7,8,8,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,8,8,8,8,8,8,8,8,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,8,8,8,8,8,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,7,7,7,7,7,7,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,7,7,8,8,8,8,7,7,7,7,7,7,
7,7,8,8,8,8,8,8,8,8,8,7,7,7,7,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,7,7,7,7,7,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,8,8,
8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,8,8,8,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,7,7,7,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,7,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,8,8,8,8,8,8,8,
8,8,8,7,7,7,7,7,8,8,7,7,7,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,7,7,7,7,7,7,7,7,7,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,8,8,8,8,8,8,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,8,8,8,8,8,7,7,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,7,7,7,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7

};

