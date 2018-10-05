#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>

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
                mapz[word]++;
            }
        }
        file.close();
        file.clear();
        
        
        
        cc++;
        
    }
    
    
    for(map<string, int>::iterator wit = mapz.begin(); wit != mapz.end(); ++wit)
        cout<< wit->first << " " <<wit->second <<endl;
    
    return 0;
}
