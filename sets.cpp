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
	MySet operator * (MySet &obj){
		MySet temp;
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
	MySet operator - (MySet &obj){
		MySet temp;
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
	MySet operator ^ (MySet &obj){
		MySet temp;
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
		for(int i=0;i<obj.cardinality;i++){
			int flag = 0;
			for(int j=0;j<this->cardinality;j++){
				if(obj.set[i] == this->set[j]){
					flag=1;
				}
			}
			if(flag==0){
				temp.cardinality++;
				temp.set[m++] = obj.set[i];
			}
		}
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
		cout<<"\n1. Union of two sets :-\n";
		cout<<"\n2. Intersection of two sets :-\n";
		cout<<"\n3. Difference of two sets :-\n";
		cout<<"\n4. Symmetric Difference of two sets :-\n";
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
//			case 5:{
//				MySet<Y> intersection = set_A ^ set_B;
//				cout<<"Intersection of Set A and Set B : ";
//				intersection.print();
//				break;
//			}
		}
		cout<<"\n\nDo You Want To Continue(y/n) : ";
		cin>>ch;
			
	}while(ch=='Y'||ch=='y');
	
}
int main(){
//	MySet m1,m2;
//	cout<<"Enter Info of set 1 :-\n";
//	m1.input();
//	cout<<"\nEnter Info of set 2 :-\n";
//	m2.input();
//	cout<<"Set 1 : ";
//	m1.print();
//	cout<<"\nSet 2 : ";
//	m2.print();
////	MySet intersection,difference,Symmetric_difference;
//	MySet Union = m1 + m2;
//	cout<<"\nUnion Of Set 1 And Set 2 : ";
//	Union.print();
//	
//	MySet intersection = m1 * m2;
//	cout<<"\nIntersection Of Set 1 And Set 2 : ";
//	intersection.print();
//	
//	MySet difference = m1 - m2;
//	cout<<"\nDifference Of Set 1 And Set 2 : ";
//	difference.print();
//	
//	MySet Symmetric_difference = m1 ^ m2;
//	cout<<"\nSymmetric Difference Of Set 1 And Set 2 : ";
//	Symmetric_difference.print();
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
