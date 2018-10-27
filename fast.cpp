#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

double Number(string str)   // Converts String part to integer.
{
    double number=0;
    string temp;
    for (unsigned int i=0; i < str.size(); i++)
    {
        if(isdigit(str[i]))
        {
            for (unsigned int a=i; a<str.size(); a++)
            {
                temp += str[a];               
            }
            break;
        }    
    }
    
    istringstream stream(temp);
    stream >> number;
    return number;
}
int main()
{
    ifstream Lin,Win,Dri,Top;
    ofstream Lar;
    string str;
    Top.open("top_files_number");  // get top TOP_FILES number
    int TOP_FILES = 10;
    while(getline(Top, str))
    {
        TOP_FILES = Number(str);
        break;  // As top file number contains only 1 line
    }
    Lin.close();
    string list[3*TOP_FILES],solution[3*TOP_FILES];
    int i=0,j,k=0;
    double size[3*TOP_FILES];
    long long int ans[3*TOP_FILES],ref[3*TOP_FILES];
     
    Lin.open("linux_max");  // get top TOP_FILES files from linux
    while(getline(Lin, str))
    {
        list[i] = str;
        i++;
    }
    Lin.close();
    
    Win.open("windows_max");  // get top TOP_FILES files from windows
    while(getline(Win, str))
    {
        list[i] = str;
        i++;
    }
    Win.close();
    
    Dri.open("drives_max");   // get top TOP_FILES files from all other drives
    while(getline(Dri, str))
    {
        list[i] = str;
        i++;
    }
    Dri.close();
    
    // Getting size in bytes from here 
    for(j=0;j<3*TOP_FILES;j++)
    {
        size[j] = Number(list[j]);
    }
    
    for(i=0;i<3*TOP_FILES;i++)
    {
        for(j=0;j<list[i].size();j++)
        {
            int x = list[i].at(j);
            if(x==75)
            {
                ans[i] = size[i]*1024;
                break;
            }
            else if(x==77)
            {
                ans[i] = size[i]*1024*1024;
                break;
            }
            else if(x==71)
            {
                ans[i] = size[i]*1024*1024*1024;
                break;
            }
            else if(x==46)
            {
                
            }
            else if(x>=48 && x<=57)
            {
            
            }
            else
            {
                break;
            }
        }
    }
    // Till here
    
    /* As TOP_FILES of all folders included in current scenario will be a subset of TOP_FILES from windows,linux,all other drives. So, sort the sizes obtained and display first TOP_FILES maximum sizes*/
    
    bool flag[3*TOP_FILES];
    for(j=0;j<3*TOP_FILES;j++)
    {
        flag[j] = false;
        ref[j] = ans[j];
    }
    sort(ans,ans+3*TOP_FILES);
    
    for(i=3*TOP_FILES-1;i>=0;i--)
    {
        for(j=0;j<3*TOP_FILES;j++)
        {
            if(flag[j]==false && ref[j]==ans[i])
            {
                flag[j] = true;
                solution[k] = list[j];
                k++;
            }
        }
    }
    j=1;
    for(i=0;i<3*TOP_FILES;i++)
    {
        if(solution[i]!="" && j<=10)
        {
            cout<<j<<") "<<solution[i]<<endl;
            j++;
        }
    }
    
    return 0;
}
