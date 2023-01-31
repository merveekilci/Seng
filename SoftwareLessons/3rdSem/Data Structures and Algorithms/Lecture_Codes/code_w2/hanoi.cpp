#include <cstdlib>
#include <iostream>
using namespace std;

void hanoi(int nDisk,string Src,string Dst,string Tmp){
	if (nDisk==1){		 
		cout<<"move "<<Src<<"->"<<Dst<<endl;
	}
	else{//nDisk>1
		hanoi(nDisk-1, Src,Tmp,Dst);
		hanoi(1, Src,Dst,Tmp);
		hanoi(nDisk-1, Tmp,Dst,Src);
	}
}

//cout<<"move "<<cnt<<": "<<Src<<"->"<<Dst<<endl;
//static int cnt=0;cnt++;//for counting the number of moves
int main(){
	hanoi(3, "Src","Dst","Tmp");
	return 0;
}

//https://www.mathsisfun.com/games/towerofhanoi.html
