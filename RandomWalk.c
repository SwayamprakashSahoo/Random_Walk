#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


double random(int N);

void main()
{
	FILE* fptr;
	fptr = fopen("C:/Users/sahoo/Desktop/RandomWalk/RMSdata.txt", "w");
	printf("Problem involving random walk:");

	printf("For 250 steps:\n");
	double Rms = random(250);
	fprintf(fptr, "%lf\t%lf\n", sqrt(250), Rms);

	printf("For 300 steps:\n");
	Rms = random(300);
	fprintf(fptr, "%lf\t%lf\n", sqrt(300), Rms);

	printf("For 350 steps:\n");
	Rms = random(350);
	fprintf(fptr, "%lf\t%lf\n", sqrt(350), Rms);

	printf("For 400 steps:\n");
	Rms = random(400);
	fprintf(fptr, "%lf\t%lf\n", sqrt(400), Rms);

	printf("For 450 steps:\n");
	Rms = random(450);
	fprintf(fptr, "%lf\t%lf\n", sqrt(450), Rms);
}

double random(int N)
{
	//creating files for data storage
	FILE* fptr1 = NULL;
	FILE* fptr2 = NULL;
	FILE* fptr3 = NULL;
	FILE* fptr4 = NULL;
	FILE* fptr5 = NULL;

	if (N == 250)
	{
		fptr1 = fopen("C:/Users/sahoo/Desktop/RandomWalk/250 steps/walk1.txt", "w");
		fptr2 = fopen("C:/Users/sahoo/Desktop/RandomWalk/250 steps/walk2.txt", "w");
		fptr3 = fopen("C:/Users/sahoo/Desktop/RandomWalk/250 steps/walk3.txt", "w");
		fptr4 = fopen("C:/Users/sahoo/Desktop/RandomWalk/250 steps/walk4.txt", "w");
		fptr5 = fopen("C:/Users/sahoo/Desktop/RandomWalk/250 steps/walk5.txt", "w");
	}
	if (N == 300)
	{
		fptr1 = fopen("C:/Users/sahoo/Desktop/RandomWalk/300 steps/walk1.txt", "w");
		fptr2 = fopen("C:/Users/sahoo/Desktop/RandomWalk/300 steps/walk2.txt", "w");
		fptr3 = fopen("C:/Users/sahoo/Desktop/RandomWalk/300 steps/walk3.txt", "w");
		fptr4 = fopen("C:/Users/sahoo/Desktop/RandomWalk/300 steps/walk4.txt", "w");
		fptr5 = fopen("C:/Users/sahoo/Desktop/RandomWalk/300 steps/walk5.txt", "w");
	}

	if (N == 350)
	{
		fptr1 = fopen("C:/Users/sahoo/Desktop/RandomWalk/350 steps/walk1.txt", "w");
		fptr2 = fopen("C:/Users/sahoo/Desktop/RandomWalk/350 steps/walk2.txt", "w");
		fptr3 = fopen("C:/Users/sahoo/Desktop/RandomWalk/350 steps/walk3.txt", "w");
		fptr4 = fopen("C:/Users/sahoo/Desktop/RandomWalk/350 steps/walk4.txt", "w");
		fptr5 = fopen("C:/Users/sahoo/Desktop/RandomWalk/350 steps/walk5.txt", "w");
	}

	if (N == 400)
	{
		fptr1 = fopen("C:/Users/sahoo/Desktop/RandomWalk/400 steps/walk1.txt", "w");
		fptr2 = fopen("C:/Users/sahoo/Desktop/RandomWalk/400 steps/walk2.txt", "w");
		fptr3 = fopen("C:/Users/sahoo/Desktop/RandomWalk/400 steps/walk3.txt", "w");
		fptr4 = fopen("C:/Users/sahoo/Desktop/RandomWalk/400 steps/walk4.txt", "w");
		fptr5 = fopen("C:/Users/sahoo/Desktop/RandomWalk/400 steps/walk5.txt", "w");
	}

	if (N == 450)
	{
		fptr1 = fopen("C:/Users/sahoo/Desktop/RandomWalk/450 steps/walk1.txt", "w");
		fptr2 = fopen("C:/Users/sahoo/Desktop/RandomWalk/450 steps/walk2.txt", "w");
		fptr3 = fopen("C:/Users/sahoo/Desktop/RandomWalk/450 steps/walk3.txt", "w");
		fptr4 = fopen("C:/Users/sahoo/Desktop/RandomWalk/450 steps/walk4.txt", "w");
		fptr5 = fopen("C:/Users/sahoo/Desktop/RandomWalk/450 steps/walk5.txt", "w");
	}

	if (fptr1 == NULL || fptr2 == NULL || fptr3 == NULL || fptr4 == NULL || fptr5 == NULL)
	{
		// File not created hence exit
		printf("\nUnable to create one of the files.\n");
		exit(EXIT_FAILURE);
	}


	//generating random files to be plotted
	int a[5];
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		a[i] = (rand() % 100) + 1;
	}

	double X, Y;
	double R = 0;
	double rsum = 0, xsum = 0, ysum = 0;

	//generating random walk
	for(int i = 1; i <= 100; i++)
	{
		X = 0;
		Y = 0;
		for(int j = 1; j <= N; j++)
		{
			double random = rand() / ((double)RAND_MAX);
			double num = (random * 22 * 2) / 7;
			//plot files
			if (i == a[0])
				fprintf(fptr1, "%lf\t%lf\n", X, Y);
			if (i == a[1])
				fprintf(fptr2, "%lf\t%lf\n", X, Y);
			if (i == a[2])
				fprintf(fptr3, "%lf\t%lf\n", X, Y);
			if (i == a[3])
				fprintf(fptr4, "%lf\t%lf\n", X, Y);
			if (i == a[4])
				fprintf(fptr5, "%lf\t%lf\n", X, Y);
			X += cos(num);
			Y += sin(num);
		}
		double r = X * X + Y * Y;
		R = R + sqrt(r);
		rsum += (r);
		xsum += X;
		ysum += Y;
	}
	double Rrms = sqrt(rsum / 100);
	double Ravg = R / 100;
	double disp = sqrt(xsum * xsum + ysum * ysum);
	printf("\n The radial distance is %lf", Ravg);
	printf("\n The rms value of distance is %lf", Rrms);
	printf("\n The net displacement is %lf\n", disp);
	return Rrms;
}

