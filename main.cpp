/* #include <stdio.h>
#include <omp.h>

int calculate()
{
	int i , sum = 0;
	int thread_sum[4];
	
	omp_set_num_threads(4);
	
	#pragma omp parallel
	{
		int ID = omp_get_thread_num();
		thread_sum[ID] = 0;
		#pragma omp for
		for(i=0; i<100000; i++)
		{
			thread_sum[ID] += i;
		}
	}
	
	for(i=0; i<4; i++)
	{
		sum = sum + thread_sum[i];
	}
	
	return sum;
}

int main()
{
	long start_time = omp_get_wtime();
	int sum = calculate();
	printf("sum = %d\n",sum);
	long end_time = omp_get_wtime();
	
	long elapsed_time = end_time - start_time;
	printf("Total time = %d",elapsed_time); 
} */

/* #include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define size 10

int main()
{
	int i;	
	int max;
	int a[size];
	
	for(i=0; i<size; i++)
	{
		a[i] = rand();
		printf("%d\n",a[i]);
	}
	
	max = a[0];
	#pragma omp parallel for num_threads(4)
		for(i=0; i<size; i++)
		{
			if(a[i]>max)
			{
				#pragma omp critical
				{
					if(a[i]>max)
					{
						max = a[i];
					}
				}
			}
		}
	
	printf("max = %d",max);
}*/

/* #include <iostream>
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define size 10

int main()
{
	int i;
	int max;
	int a[size];
	
	for(i=0; i<size; i++)
	{
		a[i] = rand();
		printf("%d\n",a[i]);
	}
	
	max = a[0];
	#pragma omp parallel for num_threads(4)
	for(i=0; i<size; i++)
	{
		if(a[i]>max)
		{
			#pragma omp critical
			if(a[i]>max)
			{
				max = a[i];
			}
		}
	}
	printf("max = %d\n",max);
} */

/* #include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define max 10

int main()
{
	int count = 0;
	
	#pragma omp parallel num_threads(max)
	{
		#pragma omp atomic update
		count++;
	}
	printf("count = %d\n",count);
} */

/*#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define size 10

int main()
{
	int i;
	int max;
	int a[size];
	
	for(i=0; i<size; i++)
	{
		a[i] = rand();
		printf("%d\n",a[i]);
	}
	
	max = a[0];
	#pragma omp parallel num_threads(4)
	for(i=0; i<size; i++)
	{
		if(a[i]>max)
		{
			#pragma omp critical
			if(a[i]>max)
			{
				max = a[i];
			}
		}
	}
	
	printf("max = %d",max);
}*/

/* #include <iostream>
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define max 10 

int main()
{
	int count = 0;
	#pragma omp parallel num_threads(max)
	{
		#pragma omp atomic update
		count++;
	}
	printf("count = %d\n",count);
} */


