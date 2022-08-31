//************************************************************
//**                                                        **
//**STUDENT NAME: Merve KILCI                               **
//**STUDENT NUMBER:b211202375                               **
//************************************************************

#include <iostream> //libraries
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int const n=5; //definitons
    int const m=10;
    
    cout<<"------------------------------"<<endl;
    cout<<"---------INPUT MATRIX---------"<<endl;
    cout<<"------------------------------"<<endl;  //explanation of input matrix
    unsigned int input[m][m]=
    {
        {3,2,5,1,4,5,7,8,1,0},
        {6,2,1,0,7,4,1,0,3,1},
        {3,0,0,2,0,1,5,2,0,0},
        {1,1,3,2,2,4,3,3,3,1},
        {0,3,1,0,0,4,6,1,1,2},
        {7,1,2,2,1,0,3,3,4,7},
        {4,3,6,0,3,9,9,8,8,1},
        {5,3,1,2,7,6,1,5,3,1},
        {0,3,1,0,0,4,6,1,1,2},
        {3,0,1,2,0,1,4,2,1,5}
    };
    for (int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cout <<input[i][j]<<'\t';

        }
        cout<<endl;
    }
    cout<<"----------------------------"<<endl;
    cout<<endl;

    

    //definitions
    unsigned int lenght;       //use insigned because values positive
    unsigned int core[n][n];

    cout<< "Enter core lenght:"; //users will enter the lenght
    cin>>lenght;
    int lenght2=lenght;

    if(lenght >=2 && lenght<=5){   //enter area of the lenght
        for (int i=0; i<lenght; i++){
            for(int j=0; j<lenght; j++){
                cout<<"core"<< "["<<i<<"]"<<"["<<j<<"]=";
                cin>>core[i][j];

        
            }
        }
        
        cout<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"---------CORE MATRIX---------"<<endl;
        cout<<"-----------------------------"<<endl; //explanation of input matrix
        for(int i=0; i<lenght; i++){
            for(int j=0; j<lenght; j++){
                cout<<core[i][j]<<'\t';

            }
            cout<<endl;
        }

    

        
    }
    else
    cout<<"Please enter the lenght between 2 and 5."<<endl; //if user use unvalid number, warn the user.
    cout<<endl;

  

int sum=0;
int outputrowsize=(m-lenght)+1;  //explanation of the output row size rule
int output[100][100];

cout<<endl;
for(int i=0; i<m; i++) {  //loops for matrix operations
    for(int j=0; j<m; j++){   //operation rules
        for(int a=0; a<lenght2; a++){
            for(int k=0; k<lenght2; k++){
                sum += input[a+i][k+j]*core[a][k];
            }
        }
        output[i][j]=sum;
        sum=0;
    }
}

    cout<<"-------------------------------"<<endl; //use cout to print to the screen
    cout<<"---------OUTPUT MATRIX---------"<<endl; //design
    cout<<"-------------------------------"<<endl; //enter the output matrix


for(int i=0; i<outputrowsize; i++){
    for(int j=0; j<outputrowsize; j++){
        cout<<setw(5)<<output[i][j];
    }
    cout<<endl;
    
}
    cout<<"-------------------------------"<<endl;
}


