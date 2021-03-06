#ifndef BENCHMARKFUNCTIONS_H_INCLUDED
#define BENCHMARKFUNCTIONS_H_INCLUDED 

typedef enum {
	create,
	verify,
	dontDoAnything
	} Choice;
typedef enum {
	root,
	notRoot
	} rootOrNot;

typedef struct {
	double openTime;
	double generateArrayTime;
	double readOrWriteTime;
	double closeTime;
	} Timing;

typedef struct {
	char filename[50];
	char filesize[50];
	long long int SIZE;	
	} InfoAboutFile;

void setBoundsForRanks(int, int, long long int, long long int*, long long int*);

long long int setSize(char*);

#endif
