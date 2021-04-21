#include <bits/stdc++.h>
using namespace std;

bool cochannel(int a,int b,int c,int i,int j){
    int eCheck, lCheck;
    eCheck = a-2;
    if(eCheck <= 0)
        eCheck += 6;
    
    if(a==1 || a==4){        
        lCheck = 1+j;

        if(eCheck == b and lCheck == c)
            return true;
        else
            return false;
    }

    else if(a==2 || a==5){
        lCheck = i+j+1;

        if(eCheck == b and lCheck == c)
            return true;
        else
            return false;
    }
    else{
        lCheck = 1+i;

        if(eCheck == b and lCheck == c)
            return true;
        else
            return false;
    }
}
    

int main(){

    int i,j,n,val,a,b,c;
    int score=0,  right=0, wrong=0;
    list<int> arr;
    cout<<"Guess the co channel correctly and win !!!\n";
    cout<<"Enter i & j value: \n";
    cin>>i>>j;

    n = i*i + i*j + j*j;

    cout<<"\nThe Value of generated N: " <<n << endl;

    cout<<"\n     *   \n";
    cout<<"\n  (3) (2)\n";
    cout<<"\n  *     *\n";
    cout<<"\n (4)   (1)\n";
    cout<<"\n  *     *\n";
    cout<<"\n  (5) (6)\n";
    cout<<"\n     *   \n";


    cout<<"\nLet the game begin | Current Score '0' \n\n";

    while(score>=0 && score<3){
        cout << "\nEnter value for \n";
        cin >> a>>b>>c;
        val = a*b*c;

        if(cochannel(a,b,c,i,j)){
            score += 1;
            right += 1;
            arr.push_back(val);
            cout<<"Correct !!!!!\nCurrent Score: "<<score<<endl;
        }
        else{
            score -= 1;
            wrong += 1;
            cout<<"Wrong !!!!!!\nCurrent Score: "<<score<<endl;
        }
    }    

    if(score == 3){
        cout<<"Congratualions you won !!"<<endl;
        cout<<"Right:  " << right << " Wrong: " <<wrong<<endl;
    }
    else{
        cout<<"Go study and come again !!"<< endl;     
        cout<<"Right: " << right << " Wrong: " <<wrong<<endl;
    }

}
