#include <iostream>
using namespace std;

int main() {
    // int n, m, x;
    // cout << "Enter n: ";
    // cin >> n;
    // cout << "Enter m: ";
    // cin >> m;
    // cout << "Enter x: ";
    // cin>>x;
    // int arr[n][m];


    // this is for input and output if 2d array
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << "Enter element " << i << "," << j << ": ";
    //         cin >> arr[i][j];
    //     }
    // }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //this is for searching an element in 2d array


    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << "Enter element " << i << "," << j << ": ";
    //         cin >> arr[i][j];
    //     }
    // }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if(arr[i][j]==x){
    //             cout<<"Element found at "<<i<<","<<j;
    //         }
    //         else{
    //             cout<<"Invalid element";
    //         }
    //     }
    //     cout << endl;
    // }



    //transposing a matrix NxN
    // int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    // for(int i = 0;i<3;i++){
    //     for(int j = i;j<3;j++){
    //         int temp = arr[i][j];
    //         arr[i][j] = arr[j][i];
    //         arr[j][i]= temp;
    //     }
    // }
    // for(int a = 0;a<3;a++){
    //     for(int b = 0;b<3;b++){
    //         cout<<arr[a][b]<<" ";
    //     }
    //     cout<<"\n";
    // }/


    //maximum column sum
    // int arr[3][3] ={{1,2,3},{4,5,6},{7,8,9}};
    
    // int maxsum = INT32_MIN;
    // for(int i = 0;i<3;i++){
    //     int colsum = 0;
    //     for(int j = 0;j<3;j++){
    //         colsum += arr[j][i];
    //     }
    //      maxsum = max(maxsum,colsum);
    // }
   
    // cout<<maxsum<<endl;

    //diagonal sum
    int m, n;
    cout<<"Enter the number of rows in square matrix: ";
    cin >> m;
    n = m; 
    int arr[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout<<"Enter element "<<i<<j<<endl;
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int diagonal_sum = 0;
    for (int i = 0; i < m; i++) {
        diagonal_sum += arr[i][i]; 
        if (i != n - 1 - i) { 
            diagonal_sum += arr[i][n - 1 - i];
        }
    }

    cout << diagonal_sum << endl;
    return 0;
}