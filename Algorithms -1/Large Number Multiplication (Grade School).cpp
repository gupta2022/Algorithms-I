#include <iostream>
#include <string.h>
using namespace std;

//inputs a large no upto 75 digits
void input_large_no(int n[75])
{
    //string to enter the large no
    char a[76];
    cin>>a;

    // size of the string
    int i = strlen(a),j=0;

    //inserting the no to the array
    while(i>0)
    {
        n[74-j]=int(a[i-1])-48;
        //cout<<n[74-j]<<" "<<74-j;
        i--;
        j++;
    };
}

//Prints The large no
void print_no(int n[75])
{
    int i = 0;
    while(n[i]==0)
    {
        i++;
    }
    for(;i<75;i++)
    {
        cout<<n[i];
    }
}

//Prints the no
void print_product(int n[150])
{
    int i = 0;
    while(n[i]==0)
    {
        i++;
    }
    for(;i<150;i++)
    {
        cout<<n[i];
    }
    cout<<endl;
}

//Adding The Levels
void add_larger_no(int n1[150],int n2[150])
{
    //returning the sum to n1
    int c = 0;
    for(int i=149;i>=0;i--)
    {
        int t = n1[i];
        n1[i]=(c+n1[i]+n2[i])%10;
        c= (c+t+n2[i])/10;
    };
}

//Multiply a constant with the large no
void multiply(int n[75], int t, int arr[150],int place)
{
    int c=0;
    int j=1;
    for(int i = 74;i>=0;i--)
    {
        arr[150-j-place]=(c+n[i]*t)%10;
        c=(c+n[i]*t)/10;
        j++;
    }
}

//Multiply Two Large Nos
void multiply_two_large_number(int n1[75],int n2[75],int p[150])
{
    for(int i = 74;i>=0;i--)
    {
        int arr[150]={ };
        multiply(n1,n2[i],arr,74-i);
        //print_product(arr);
        add_larger_no(p,arr);
    }
}

int main()
{
    //Program Take Input Of Number With Maximum Of 75 Digits

    int n1[75],n2[75];//75 max input of numbers 1 and 2

    //intializing the array to 0
    for(int i =0;i<75;i++)
    {
        n1[i]=0;
        n2[i]=0;
    }

    //inputing large no
    input_large_no(n1);
    input_large_no(n2);

    int p[150]={ 0 };

    multiply_two_large_number(n1,n2,p);

    print_product(p);
    return(0);
}
