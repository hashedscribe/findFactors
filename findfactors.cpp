#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> factor(int num){
    if(num < 0){
        num = num*-1;
    }
    vector<int> factors;
    for(int i = 1; i <= num; i++){
        if(num%i == 0){
            factors.push_back(i);
            factors.push_back(i*-1);
        }
    }
    return(factors);
}

float solve(float x, int* arr, int len){
    float rem = 0;
    for(int i = 0; i < len; i++){
        rem = rem + arr[i]*pow(x, len-i-1);
    }
    return(float(int(rem*100000)/100000));
}

void printPoly(int* arr, int len){
    cout << "Current equation: ";
    for(int i = 0; i < len; i++){
        if(arr[i] != 0){
            if(arr[i] != 1){
                cout << arr[i];
            }
            cout << "x^" << len-i-1;
            if(i < len-1){
                cout << " + ";
            }
        }
    }
}

int main(){
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;
    degree = degree+1;
    int poly[degree];
    cout << "Enter your constants: ";
    for(int i = 0; i < degree; i++){
        cin >> poly[i];
    }
    printPoly(poly, degree);
    int a = poly[0], c = poly[degree-1];
    vector<int>aFact = factor(a);
    vector<int>cFact = factor(c);

    cout << endl << "Factors of LC: ";
    for(int i = 0; i < aFact.size(); i++){
        cout << aFact[i] << "\t";
    }

    cout << endl << "Factors of Constant: ";
    for(int i = 0; i < cFact.size(); i++){
        cout << cFact[i] << "\t";
    }

    float x; bool flag = false;
    int af, cf;

    for(int i = 0; i < aFact.size(); i++){
        for(int j = 0; j < cFact.size(); j++){ 
            cf = cFact[j];
            af = aFact[i];
            x = float(cf)/float(af);
            float rem = solve(x, poly, degree);
            cout << endl << cFact[j] << "/" << aFact[i] << ", " << x << ": " << rem;
            if(rem == 0){
                 cout << endl << "Factor found: " << cf << "/" << af << endl;
                flag = true;
                break;
            }
        }
        if(flag)break;
    }
    if(!flag)cout << "No factors found." << endl;
    return 0;
}