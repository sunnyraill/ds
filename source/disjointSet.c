#include<stdio.h>
#include<stdlib.h>
#include "../include/disjointset.h"
//Make set
void MakeSet(int s[], int sizeOfArray){
    for(int i=0; i<sizeOfArray; i++){
        s[i]= -1;
    }
}

//set find
int Find (int s[], int size, int X){
    //index of array is given
    //we need to find the root of tree

    //1st check if array is out of bound
    if(X<0 || X>size-1)
        return -1;
    
    if(s[X]<0) // this is root element: treat X(root element) as name of set
        return X;
    else 
        return Find(s,size,s[X]); //recursively search for root of this tree
}

// set union
void UnionBySize(int s[], int size, int root1, int root2){  
    //root emement stores negative of no of elements of the set. if size is 3 then store -3 as root.
    //whichever is smaller make as child

    // check if both elements already belong to same set
    if((Find(s,size,root1) == Find(s,size,root2)) && !(Find(s,size,root1) == -1)){
        return;
    }


    if(root1 < root2) { //root1 is bigger set
        int temp = s[root2]; //saving the size of 2nd set
        s[root2] = root1;
        s[root1] = s[root1] + temp; 
    } else { //root2 is bigger set
        int temp = s[root1]; //saving the size of 1st set
        s[root1] = root2;
        s[root2] = s[root2] + temp; 
    }
}

void unionByHeight(int s[], int size, int root1, int root2){
    //root element strores the negative of height of tree. if height is 3, it stores -3 as root.
    //height of tree is one element is assumed 1.
    //whichever tree is smaller, make as child. 

    // check if both elements already belong to same set
    if((Find(s,size,root1) == Find(s,size,root2)) && !(Find(s,size,root1) == -1)){
        return;
    }
    
    if(root1 < root2) { //set one has more height
        s[root2] = root1;
        // height of 1st set will remain unchanged

    } else { //root2 is bigger set

        if(root1 == root2){
            s[root2]--; // increase height of set 2 by one
        }
        s[root1] = root2; //assign tree one as child of tree 2
    }

}

 int main(){
     printf("hello world\n");
 }

/* 
mumbai, kolkata, asansol, jalpaiguri, nagpur,
raipur, wardha, aurangabad, bhopal
*/
