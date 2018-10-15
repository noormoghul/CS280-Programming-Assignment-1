//Noor Moghul 10/14/2018

#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <iterator>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
    
    
    if(argc < 2)                                                                //check if any arguements are passed
    {
        cout<<"NO PHRASE LENGTH"<<endl;
        return 0;
    }
    string nStr(argv[1]);                                                       //check if a phrase length was provided
    int nInt = atoi(nStr.c_str());
    if(nInt < 1)
    {
        cout<<"INVALID PHRASE LENGTH"<<endl;
        return 0;
    }
    
    if(argc < 3)                                                                //verify a mode
    {
        cout<<"NO MODE"<<endl;
        return 0;
    }
    string mode(argv[2]);
    if(!(mode=="all" || mode=="top"))
    {
        cout<<"INVALID MODE"<<endl;
        return 0;
    }
    
    
    if(argc < 4)                                                                //check if you were given any files
    {
        cout<<"NO FILES GIVEN"<<endl;
        return 0;
    }
    
    
    map<string, int> mapz;                                                      //map to count the words/phrases
    
    string word = "";
    
    vector<string> v;                                                           //vector to go through the phrases
    
    string strang;
    
    
    int cc = 3;
    while(cc < argc)                                                           //open a file
    {
        
        ifstream file;
        file.open(argv[cc]);
        
        if(file.peek() == std::ifstream::traits_type::eof())                  //check if file is empty
        {
            cc++;
            cout<<"NO PHRASES"<<endl;
            continue;
        }
        
        if(!file.is_open())                                                  //check if filed opened successfully
        {
            cc++;
            cout<<"BAD FILE "<<argv[cc]<<endl;
            continue;
        }
        
        
        string oneline;
        while(getline(file, oneline))                                               //get a line
        {
            stringstream ss(oneline);
            while(! ss.eof())                                                       //get a word
            {
                ss >> word;
                transform(word.begin(), word.end(), word.begin(), ::tolower);       //make word lowercase
                
                if(nInt == 1)                                                       
                {
                    mapz[word]++;
                }
                else
                {
                    
                    v.push_back(word);                                              //add word to vector until phrase 
                                                                                    //length is reached
                    if(v.size() == nInt)
                    {
                        strang = v[0];
                        for(int l = 1; l < v.size(); l++)                           //assign vector to "strang", thang,
                        {                                                           //put it in the map
                            strang = strang +" " + v[l];
                        }
                        mapz[strang]++;
                        v.erase( v.begin() );                                       //erase the first index in the vector
                    }
                    
                }
                
            }
        }
        file.close();
        file.clear();
        
        cc++;
        
    }
    
    map<int,string> mapzFlipped;                                                    //map to check if all the phrases have
                                                                                    //same frequency
    for(map<string,int>::iterator i = mapz.begin(); i != mapz.end(); ++i)
    {                                                                               //flip map, same data will get overwritten,
        mapzFlipped[i->second] = i->first;                                          //if one key is left, frequency is same
    }
    
    if(mapzFlipped.size() == 1)
    {
        cout<<"ALL PHRASES EQUALLY FREQUENT"<<endl;
        return 0;
    }
    
    
    int tempHighest = 0;
    
    if(mode == "top")                                                               
    {
        for(map<string,int>::iterator wit = mapz.begin(); wit!= mapz.end(); ++wit)      //finds the highest value
        {
            
            while(mapz.empty())
                break;
            
            if(wit->second > tempHighest)
                tempHighest = wit->second;
        }
        for(map<string,int>::iterator tit = mapz.begin(); tit!= mapz.end(); ++tit)      //finds others that match the highest
        {
            
            if(tit->second == tempHighest)
            {
                cout<< tit->first << " " <<tit->second <<endl;
            }
        }
        
    }
    else
    {
        
        for(map<string, int>::iterator wit = mapz.begin(); wit != mapz.end(); ++wit)            //print the map
            cout<< wit->first << " " <<wit->second <<endl;
        
    }
    
    
    
    
    return 0;
}
