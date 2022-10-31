#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main()
{
  vector<string> dataStr;
  vector<int> dataPoint;
  string title, header1, header2,s;
  cout<<"Enter a title for the data:\n";
  getline(cin,title);
  cout<<"You entered: "<<title<<endl;
  cout<<"\nEnter the column 1 header:\n";
  getline(cin,header1);
  cout<<"You entered: "<<header1<<endl;
  cout << endl;
  cout<<"Enter the column 2 header:\n";
  getline(cin,header2);
  cout<<"You entered: "<<header2<<endl;  
  cout << endl;
  while(true)
  {
    cout<<"Enter a data point (-1 to stop input):\n";
    getline(cin,s);
    if(s == "-1")
    {
    cout << endl;
    break;
    }
  else
    {
    int commaCount = 0;
    for(int i=0; i<s.length(); i++)
    {
      if(s[i] == ',')
      commaCount++;
    }
    if(commaCount == 0)
    {
      cout<<"Error: No comma in string.\n"<<endl;
    }
    else if(commaCount > 1)
    {
      cout<<"Error: Too many commas in input.\n"<<endl;
    }
    else
    {
      string firstWord = s.substr(0, s.find(","));
      string secondWord = s.substr(s.find(",")+1, s.length()-1);
      firstWord.erase(0, firstWord.find_first_not_of(' '));
      secondWord.erase(0, secondWord.find_first_not_of(' '));
      int countNumbers = 0;
      for(int i=0; i<secondWord.length(); i++)
      {
        if(secondWord[i] >='0' && secondWord[i] <= '9')
        {
          countNumbers++;
        }
      }  
  if(countNumbers == secondWord.length())
  {
    dataPoint.push_back(atoi(secondWord.c_str()));
    dataStr.push_back(firstWord);
    cout<<"Data string: "<<firstWord<<endl;
    cout<<"Data integer: "<<secondWord<< endl;
    cout << endl;
  }
  else
  {
    cout<<"Error: Comma not followed by an integer.\n"<<endl;
  }
    }
}
  }
  cout << endl;
  cout<<right<<setw(33)<<title<<endl;
  cout<<left<<setw(20)<<header1<<"|"<<right<<setw(23)<<header2<<endl;
  cout<<"--------------------------------------------"<<endl;
  int maxLen = 0;
  for(int i=0; i<dataStr.size(); i++)
  {
    if(dataStr[i].length() > maxLen)
    maxLen = dataStr[i].length();
    cout<<left<<setw(20)<<dataStr[i]<<"|"<<right<<setw(23)<<dataPoint[i]<<endl;
  }
  cout << endl;
  for(int i=0; i<dataStr.size();i++)
  {
    for(int spaces = 0; spaces < (maxLen - dataStr[i].length() + 1); spaces++)
    cout << " ";
    cout<<dataStr[i]<<" ";
    for(int j=0; j<dataPoint[i];j++)
    {
      cout<<"*";
    }
  cout<<endl;
  }
return 0;
}