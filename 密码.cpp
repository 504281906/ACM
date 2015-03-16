#include <iostream> 
 #include <cmath> 
 #include <string.h>
 #include <stdlib.h>
  using namespace std; 
   int main() 
    {  
		char chr[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
		 int a,chrlen = strlen(chr);  
		 cout << "ÇëÊäÈëÃÜÂë³¤¶È: ";  
		 cin >> a;  
		 cout.setf(ios::fixed); 
		  int(*b)[1] = new int[a][1]; 
		   for (int i=0;i<a;i++)  
		   (*b)[0]=0;  
		   for (int i=0;i<pow(chrlen,(float)a);i++)  
		   {  for (int j=a-1;j>=0;j--)
		     {  if (b[j][0]>=chrlen && j>0) 
			  {  b[j][0] = 0;  b[j-1][0]++;  } 
			   cout << chr[b[j][0]];  }  
			   cout << " ";  b[a-1][0]++;  }
			     delete b;  
				 system("PAUSE");  
				 return 0; 
 } 
