#include<iostream>
using namespace std;
//q1
// int add(int a,int b){
//     int sum =  a + b;
//     return sum;
// }
//q2
// int square(int a){
//    return a*a;
// }


//q3
// float area(int r){
//     return 3.14*r*r;
// }
// float circum(int c){
//     return 2*3.14*c;
// }

//q4
// int odd(int a, int b){
   
//     for(int i = a;i<=b;i++){
//         if (i % 2 != 0)
//         {
//             cout<<i<<endl;
//         }
        
//     }
//     return 0;
// }



    bool pythagoras(int a, int b, int c) {
    if (c > a &&  b > a) {
        return c * c == a * a + b * b;
    } 
    else if (a > b && b > c) {
        return a * a == b * b + c * c;
    } else if (b > c && a > c) {
        return b * b == a * a + c * c;
    }
    else {
        return false;
    }
  }


int main(){
    int x,y,z;
    cout<<"Enter the value of x :";
    cin>>x;
    cout<<"Enter the value of y :";
    cin>>y;
    cout<<"Enter the value of z :";
    cin>>z;
    if(pythagoras(x,y,z)){
        cout<<"they are pythagoras triplets";
    }
    else{
        cout<<"No they are not pythagoras triplets";
    }

    // cout<<add(x,y)<<endl;



    // for (int i = 1; i <= x; i++)
    // {
    //     cout<<square(i)<<endl;
    // }



    // cout<<"The area of circle is :"<<area(x)<<endl;
    // cout<<"The circumference of circle is :"<<circum(x);

    // cout<<odd(x,y);

    return 0;
}