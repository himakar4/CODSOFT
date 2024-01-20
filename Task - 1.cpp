//NUMBER GUESSING GAME

#include<bits/stdc++.h>
using namespace std;

int rand_no()
{
	srand(time(0));
	int x=rand();
	return x;
}
int main()
{
	int no=rand_no();
	cout<<"A Secret Number is Generated, Guess the Number!!"<<endl;
  	while(true)
  	{
  		int n;
  		cout<<"\nEnter Your Guess : ";
		cin>>n;	
		if(no>n)
		{
			 cout << "Your Guess is Low!\nTry Again!!\n";
		}
		else if(no<n)
		{
			cout << "Your Guess is High!\nTry Again!!\n";
		}
		else
		{
			cout << "Your Guess is Correct!!\n";
            cout << "Your Guess is: " << n << "\nSecret Number is: " << no;
            break;
		}
	}
    
    return 0; 
}
