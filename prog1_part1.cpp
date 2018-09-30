#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;


int main(int argc, char *argv[])

{
    if(argc == 1){
        cout<<"NO PHRASE LENGTH"<<endl;
        return 0;
    }
    string nStr(argv[1]);
    int nInt = atoi(nStr.c_str());
    if(nInt < 1){
        cout<<"INVALID PHRASE LENGTH"<<endl;
        return 0;
    }
    
    if(argc == 2){
        cout<<"NO MODE"<<endl;
        return 0;
    }
    string mode(argv[2]);
    if(!(mode=="all" || mode=="top")){
        cout<<"INVALID MODE"<<endl;
        return 0;
    }
    
    
    if(argc == 3){
        cout<<"NO FILES GIVEN"<<endl;
        return 0;
    }
    
    
    
    for(int cc = 3;cc<argc;cc++){
        
        ifstream infile;
        infile.open(argv[cc]);
        
        if(infile.is_open() == false){
            cout<<"BAD FILE "<<argv[cc]<<endl;
            return 0;
        }
        
    infile.close();    
    infile.clear();
    }
    
    
    
    return 0;
    
}
