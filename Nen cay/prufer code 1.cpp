#include<iostream>
using namespace std;
void swap(int *a,int *b){
	int m;
	m=*a;*a=*b;*b=m;
}

int main(){
	//khoi tao mang va sap xep
	int n,i,j,k;cin>>n;
	int *a,*b,*c;
    a=new int[n];b=new int [n];c=new int[n]();
   
	for(i=0;i<n;i++){
		cin>>a[i]>>b[i];
		if(a[i]!=0) c[a[i]-1]++;
		if(b[i]!=0) c[b[i]-1]++;
		if(a[i]==0 || a[i]>b[i] && b[i]!=0)
			swap(a+i,b+i);
	}
	int gia_tri_xoa=0,vi_tri=0;

	while(vi_tri<n){
		//tim gia tri xoa
		for(i=gia_tri_xoa;i<n;i++){	
			if(c[i]==1) {
				gia_tri_xoa=i+1; 
				break;
			}
		}
		if(vi_tri!=0){
		
		if(b[vi_tri-1]!=0)
			if(c[b[vi_tri-1]-1]==1  &&  b[vi_tri-1]<gia_tri_xoa)
				gia_tri_xoa=b[vi_tri-1];
		}
		//dao vi tri
		for(i=vi_tri;i<n;i++){
			if(a[i]==gia_tri_xoa  ||  b[i]==gia_tri_xoa) {
				
				if(b[i]==gia_tri_xoa)	swap(a[i],b[i]);
				swap(a+vi_tri,a+i); 
				swap(b+vi_tri,b+i);
			
				if(a[vi_tri]!=0) c[a[vi_tri]-1]--;
				if(b[vi_tri]!=0) c[b[vi_tri]-1]--;
		
			break;
			
			}
		
		}
		vi_tri++;

	}
	
	
	for(i=0;i<n-1;i++)
		printf("%d ",b[i]);
		
	delete[]a;	delete[]b;	delete[]c;
	
	return 0;
}
