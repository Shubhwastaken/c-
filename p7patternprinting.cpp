#include<iostream>
using namespace std;
int main(){
int a,b;
cout<<"Enter a:";
cin>>a;
cout<<"Enter b:";
cin>>b;
//  for(int i=1;i<=a;i++){                   //****  full rectangle
//     for(int j =1;j<=b;j++){               //****   
//         cout<<"*";                        //**** 
//     }                                     //**** 
//     cout<<endl;
// }

// cout<<endl;
// cout<<endl;
// cout<<endl;

//   for(int m =1;m<=a;m++){
//     for(int n=1;n<=b;n++){                                        //***** hollow rectangle
//         if(m == 1 || m == a || n ==1 || n == b){                  //*   *
//             cout<<"*";                                            //*   *
//         }                                                         //*   *
//         else{                                                     //***** 
//             cout<<" ";
//         }
//     }
//     cout<<endl;
//   }
// cout<<endl;
// cout<<endl;
// cout<<endl;

// for(int x=1;x<=a;x++){                   //*  pyramid
//     for(int y =1;y<=i;y++){              //**   
//         cout<<"*";                       //*** 
//     }                                    //**** 
//     cout<<endl;
// }

// cout<<endl;
// cout<<endl;
// cout<<endl;

for(int r=a;r>=1;r--){                   //*****    inverted pyramid
    for(int s =1;s<=r;s++){              //****   
        cout<<"*";                       //*** 
    }                                    //** 
    cout<<endl;                          //*
}


    return 0;
}