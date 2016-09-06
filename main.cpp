#include <iostream>
#include <cstring>
#include<iostream>
#include<fstream>
#include <sstream>
using namespace std;
void PREKMP(string pattern, int arr[])
{
    int m = pattern.length(), k;
    arr[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = arr[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = arr[k];
        }
        arr[i] = k + 1;
    }
}
 
int KMP(int i,string pattern, string target)
{
    int m = pattern.length();
    int n = target.length();
    int arr[m];     
    PREKMP(pattern, arr);     
    
    int k = 0;        
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m)
                return i-k+1;
        }
        else
            k = arr[k];
    }
    return -2;
}
void word(int m,int count){
	ifstream file("input.txt");
	string myArray[1000];
    if(file.is_open())
    {
        for(int i = 0; i < 1000; i++)
        {
            file >> myArray[i];
        }
    }
    cout<<myArray[count]<<endl;
} 
int main()
{
	ifstream file("input.txt");
	int i=0;
    stringstream buffer;
    buffer << file.rdbuf();
    string str = buffer.str();
    cout << str<<endl;
    string pat;
    int m=0;
    int para=1;
    for(int k=0;k<str.length();k++)
	{
    	if(str[k]=='\n' && str[k+1]=='\n')
		{	
    		para++;
		}
	}
	cout<<""<<endl;
	cout<<" NO of paragraphs are "<<para<<endl;
	cout<<""<<endl;
    cout<<"Enter substring"<<endl;
    cin>>pat;
    while(i<str.length() && i>=0){
	    int m=KMP(i,pat,str);
	    int count=0;
	    m++;
	    i=m;
	    if(i!=-1){
	    	for (int j= 0; j <i; j++){
	            if (str[j] == ' ' ||(str[j]=='\n' && str[j+1]=='\n')){
	                	count++;
	            }
			}
			cout<<"The substring starts at "<<i-1<<" and the word is ";
			word(i,count);
		}  
	}
}
