// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void passvalue(int n){
    cout<<"value = "<<n<<endl;
    n+=20;
    cout<<"value after the increment = "<< n <<endl;
}
void passbyreference(int &n){
    cout<<"value = "<< n <<endl;
    n+=20;
    cout<<"second value after the increment = "<<n<<endl;
}

void staticvariable(){
    static int count = 0;
    count++;
    cout<<"count after the increment = "<< count <<   endl;
}
float add(float n1,float n2){
    float sum = n1 + n2;
    cout<<"Two numbers num = "  << sum <<endl;
    return sum;
}


int main() {
    float n1,n2;
    cout<<"Enter the first number for addtion = ";
    cin>>n1;
    cout<<"Enter the second number for addition = ";
    cin>>n2;
    
  add(n1, n2);
  cout<<"Enter the value for pass by value and reference " <<endl;
  int n;
  cin >> n;
   passvalue(n);
   cout<<"For Pass by reference "<<endl;
   passbyreference(n);
  staticvariable();
    return 0;
}
