#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
template <class T>
class MySet{
		T* set;
		int cardinality;
	public:
	void input(){
		cout<<"\nEnter "<<cardinality<<" Elements of Set :-\n";
		for(int i=0;i<cardinality;i++){
			cin>>set[i];
		}
		rm_duplicate();
	}
	MySet(){
		cardinality = 0;
	}
	MySet(int size){
		cardinality = size;
		set = new T(cardinality);
	}
	void rm_duplicate(){
		for(int i=0;i<cardinality;i++){
			int flag = 0;
			int dup_index =0;
			for(int k=0;k<i;k++){
				if(set[i]==set[k]){
					flag = 1;
					dup_index = i;
				}
			}
			if(flag==1){
				for(int j=dup_index;j<cardinality-1;j++){
					set[j] = set[j+1];
				}
				cardinality--;
				i--;
			}
		}
	}
	void print(){
		cout<<"{";
		for(int i=0;i<cardinality;i++){
			if(i!=cardinality-1)
			cout<<set[i]<<",";
			else
			cout<<set[i];
		}
		cout<<"}";
	}
	int get_cardinality(){
		return cardinality;
	}
	MySet<T> operator + (MySet &obj){
		MySet<T> temp(this->cardinality + obj.cardinality);
		int m=0;
		for(int i=0;i<this->cardinality;i++){
			temp.set[m++] = this->set[i];
		}
		for(int i=0;i<obj.cardinality;i++){
			temp.set[m++] = obj.set[i];
		}
		temp.rm_duplicate();
		return temp;
	}
	MySet<T> operator * (MySet &obj){
		MySet<T> temp;
		int m=0;
		temp.cardinality = 0;
		for(int i=0;i<this->cardinality;i++){
			for(int k=0;k<obj.cardinality;k++){
				if(this->set[i] == obj.set[k]){
					temp.cardinality++;
					temp.set[m++] = this->set[i];
					break;
				}
			}
		}
		return temp;
	}
	MySet<T> operator - (MySet &obj){
		MySet<T> temp;
		int m=0;
		temp.cardinality = 0;
		for(int i=0;i<this->cardinality;i++){
			int flag = 0;
			for(int j=0;j<obj.cardinality;j++){
				if(this->set[i] == obj.set[j]){
					flag=1;
				}
			}
			if(flag==0){
				temp.cardinality++;
				temp.set[m++] = this->set[i];
			}
		}
		return temp;
	}
	MySet<T> operator ^ (MySet obj){
		MySet<T> Union1 = *this + obj;
		MySet<T> Intersection1 = *this * obj;
		MySet<T> temp = Union1 - Intersection1;
		return temp;
 	}
	void operator = (MySet &obj){
		this->cardinality = obj.cardinality;
		for(int i=0;i<obj.cardinality;i++){
			this->set[i] = obj.set[i];
		}
	}
	bool operator == (MySet &obj){
		if(this->cardinality == obj.cardinality){
			for(int i=0;i<obj.cardinality;i++){
				if(this->set[i]!=obj.set[i]){
					return false;
				}
			}
			return true;
		}
		
		return false;
	}
	void powerset() const
	{
		cout<<"The power set is : {";
		for(int i=0;i<pow(2,this->cardinality);i++)
		{
			cout<<"{";
			for(int t=i,j=0;j<this->cardinality;j++)
			{
				if(t&1)
				{
					cout<<set[j];
				}
				t=t>>1;
				
			}
			cout<<"}";
			cout<<((i<pow(2,this->cardinality)-1)?',':'}');
		}
		cout<<"\n";
		cout<<"\nThe cardianality of power se is: "<<pow(2,this->cardinality);	
	}
};
template <typename Y>
void initialization(){
	int size;
	cout<<"\nEnter The Size Of set A : ";
	cin>>size;
	MySet<Y> set_A(size);
	set_A.input();
	cout<<"\nEnter The Size Of set B : ";
	cin>>size;
	MySet<Y> set_B(size);
	set_B.input();
	int choice=0;
	char ch=' ';
	do{
		system("CLS");
		cout<<"Set A : ";
		set_A.print();
		cout<<"\nSet B : ";
		set_B.print();
		
		cout<<"\n------------Operations on sets----------";
		cout<<"\n1. Union of two sets\n";
		cout<<"\n2. Intersection of two sets\n";
		cout<<"\n3. Difference of two sets \n";
		cout<<"\n4. Symmetric Difference of two sets \n";
		cout<<"\n5. Check The Equality Of The Sets \n";
		cout<<"\n6. Generate Power Set \n";
		cout<<"\n7. Get Cardinality \n";
		cout<<"-----------------------------------------";
		cout<<"\nEnter Choice : ";
		cin>>choice;
		
		switch(choice){
			case 1:{
				MySet<Y> Union = set_A + set_B;
				cout<<"Union of Set A and Set B : ";
				Union.print();
				break;
			}
			case 2 :{
				MySet<Y> intersection = set_A * set_B;
				cout<<"Intersection of Set A and Set B : ";
				intersection.print();
				break;
			}
			case 3:{
				MySet<Y> set_difference = set_A - set_B;
				cout<<"Set Difference of Set A and Set B : ";
				set_difference.print();
				break;
			}
			case 4:{
				MySet<Y> symmetric_difference = set_A ^ set_B;
				cout<<"Symmetric difference of Set A and Set B : ";
				symmetric_difference.print();
				break;
			}
			case 5:{
				if(set_A == set_B){
					cout<<"Both Sets Are Equal";
				}else{
					cout<<"Sets Are Not Equal";
				}
				break;
			}
			
			case 6:{
				chooseagain:
				system("CLS");
				int subchoice;
				cout<<"1. power set of Set A \n";
				cout<<"2. power set of Set B \n";
				cout<<"Choose An Option : ";
				cin>>subchoice;
				if(subchoice == 1){
					set_A.powerset();
				}else if(subchoice == 2){
					set_B.powerset();
				}else{
					cout<<"Wrong choice choose again \n";
					goto chooseagain;
				}
				break;
			}
			
		}
		cout<<"\n\nDo You Want To Continue(y/n) : ";
		cin>>ch;
			
	}while(ch=='Y'||ch=='y');
	
}
int main(){
	
	int choice=0;
	start:
	cout<<"1-> int type\n";
	cout<<"2-> char type\n";
	cout<<"3-> float type\n";
	cout<<"Enter the type of data : ";
	cin>>choice;
	
	switch(choice){
		case 1 : initialization<int>();
					break;
		
		case 2 : initialization<char>();
					break;
		
		case 3 : initialization<float>();
					break;
		default : cout<<"Wrong Choice choose again \n";
					system("CLS");
					goto start;
	}
	

	return 0;
}
