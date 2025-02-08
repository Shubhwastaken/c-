#include<iostream>
using namespace std;
int main(){
    // continue and break
// int pocketmoney = 3000;
// for(int i = 1;i<=30;i++){
//     if(i%2==0){
//         continue;
//     }
//     if (pocketmoney==0)
//     {
//       break;
//     }
    
//     cout<<"Go out today"<<i<<endl;
//     pocketmoney = pocketmoney - 500;
// }

//no. divisible by 3


// for(int j = 1;j<=100;j++){
//     if (j%3==0)
//     {
//         continue;
//     }
    
//     cout<<j<<endl;

// }



// prime or not
// int n;
// cout<<"Enter n: ";
// cin>>n;
// int i;
// for(i=2;i<n;i++) {
//     if (n % i == 0) {
//         cout << n << " is not a prime number" << endl;
//         break;
//     }  
// }
// if (i == n) {
//         cout << n << " is a prime number" << endl;
// }




// prime numbers between a and b
int a,b;
cout<<"Enter a :";
cin>>a;
cout<<"Enter b :";
cin>>b;
for(int i = a;i<=b;i++){
    int j;
    for(j=2;j<i;j++){
         if (i % j == 0) {
         break;
    }    
}
if(j==i){
        cout<<i<<endl;
  }

    

}
    return 0;
}