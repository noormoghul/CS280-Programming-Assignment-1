#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <iterator>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
    
    
    if(argc < 2){
        cout<<"NO PHRASE LENGTH"<<endl;
        return 0;
    }
    string nStr(argv[1]);
    int nInt = atoi(nStr.c_str());
    if(nInt < 1){
        cout<<"INVALID PHRASE LENGTH"<<endl;
        return 0;
    }
    
    if(argc < 3){
        cout<<"NO MODE"<<endl;
        return 0;
    }
    string mode(argv[2]);
    if(!(mode=="all" || mode=="top")){
        cout<<"INVALID MODE"<<endl;
        return 0;
    }
    
    
    if(argc < 4){
        cout<<"NO FILES GIVEN"<<endl;
        return 0;
    }
    
    
    map<string, int> mapz;
    
    string word = "";
    
    vector<string> v;
    
    string strang;
    
    
    int cc = 3;
    while(cc < argc){
        
        ifstream file;
        file.open(argv[cc]);
        
        if(file.peek() == std::ifstream::traits_type::eof()){
            cc++;
            cout<<"NO PHRASES"<<endl;
            continue;
        }
        
        if(!file.is_open()){
            cc++;
            cout<<"BAD FILE "<<argv[cc]<<endl;
            continue;
        }
        
        
        string oneline;
        while(getline(file, oneline)){
            stringstream ss(oneline);
            while(! ss.eof()){
                ss >> word;
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                
                if(nInt == 1)
                {
                    mapz[word]++;
                }
                else
                {
                    
                    v.push_back(word);
                    
                    if(v.size() == nInt)
                    {
                        strang = v[0];
                        for(int l = 1; l < v.size(); l++)
                        {
                            strang = strang +" " + v[l];
                        }
                        mapz[strang]++;
                        v.erase( v.begin() );
                    }
                    
                }
                
            }
        }
        file.close();
        file.clear();
        
        cc++;
        
    }
    
    map<int,string> mapzFlipped;
    
    for(map<string,int>::iterator i = mapz.begin(); i != mapz.end(); ++i){
        mapzFlipped[i->second] = i->first;
    }
    
    if(mapzFlipped.size() == 1){
        cout<<"ALL PHRASES EQUALLY FREQUENT"<<endl;
        return 0;
    }
    
    
    int tempHighest = 0;
    
    if(mode == "top"){
        for(map<string,int>::iterator wit = mapz.begin(); wit!= mapz.end(); ++wit){
            
            while(mapz.empty())
                break;
            
            if(wit->second > tempHighest)
                tempHighest = wit->second;
        }
        for(map<string,int>::iterator tit = mapz.begin(); tit!= mapz.end(); ++tit){
            
            if(tit->second == tempHighest){
                cout<< tit->first << " " <<tit->second <<endl;
            }
        }
        
    }
    else{
        
        for(map<string, int>::iterator wit = mapz.begin(); wit != mapz.end(); ++wit)
            cout<< wit->first << " " <<wit->second <<endl;
        
    }
    
    
    
    
    return 0;
}
