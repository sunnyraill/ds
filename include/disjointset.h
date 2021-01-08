#ifndef DISJOINTSET_H

#define DISJOINTSET_H
void MakeSet(int s[], int sizeOfArray);
int Find (int s[], int size, int X);
void UnionBySize(int s[], int size, int root1, int root2);
void unionByHeight(int s[], int size, int root1, int root2);

#endif
