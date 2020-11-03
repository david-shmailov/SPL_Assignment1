#include <iostream>
#include "../headers/Session.h"
#include <fstream>
#include "../headers/json.hpp"

using namespace std;
using json = nlohmann::json;

int main(int argc, char** argv){

    if(argc != 2){
        cout << "usage cTrace <config_path>" << endl;

        std::string s = "../1.json";
        std::ifstream i(s);
        std::cout << i.rdbuf()<<endl;
        json j;
        j << i.rdbuf();

        }



      //  vector<vector <int , string >> a = ;
        //cout << j << endl;
        //
          //cout << j << endl;

        return 0;
    }


  //

    //Session sess(argv[1]); //TODO add in CLion parameters config1.file
    //sess.simulate();

    // TODO change headers folder to include before submission
