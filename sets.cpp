#include<iostream>

using namespace std;
class MySet{
		int set[100];
		int cardinality;
	public:
	void input(){
		cout<<"Enter Cardinality : ";
		cin>>cardinality;
		cout<<"Enter "<<cardinality<<"Elemnets of Set :-\n";
		for(int i=0;i<cardinality;i++){
			cin>>set[i];
		}
		rm_duplicate();
	}
	Myset(){
		
		cardinality = 0;
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
	int find_cardinality(){
		return cardinality;
	}
	MySet operator + (MySet &obj){
		MySet temp;
		int m=0;
		temp.cardinality = this->cardinality + obj.cardinality;
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
int main(){
	MySet m1,m2;
	cout<<"Enter Info of set 1 :-\n";
	m1.input();
	cout<<"\nEnter Info of set 2 :-\n";
	m2.input();
	cout<<"Set 1 : ";
	m1.print();
	cout<<"\nSet 2 : ";
	m2.print();
//	MySet intersection,difference,Symmetric_difference;
	MySet Union = m1 + m2;
	cout<<"\nUnion Of Set 1 And Set 2 : ";
	Union.print();
	
	MySet intersection = m1 * m2;
	cout<<"\nIntersection Of Set 1 And Set 2 : ";
	intersection.print();
	
	MySet difference = m1 - m2;
	cout<<"\nDifference Of Set 1 And Set 2 : ";
	difference.print();
	
	MySet Symmetric_difference = m1 ^ m2;
	cout<<"\nSymmetric Difference Of Set 1 And Set 2 : ";
	Symmetric_difference.print();
	
	MySet m3;
	m3 = m1;
	m3.print();
	if(m3==m2){
		cout<<"These Are Equal";
	}else{
		cout<<"Not Equal";
	}

	return 0;
}
