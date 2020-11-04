#include <iostream>
//#include "../headers/Session.h"
#include <fstream>
#include "json.hpp"


using namespace std;
using json = nlohmann::json;

int main(int argc, char** argv){

    if(argc != 2){
        std::cout << "usage cTrace <config_path>" << std::endl;


        std::ifstream ifs("//home//spl211//CLionProjects//SPL_Assignment1new//1.json");
        nlohmann::json jf = nlohmann::json::parse(ifs);
       std::cout << jf["agents"]<< std::endl;
       for (auto elem: jf["agents"]){
           if(elem[0]=="V") cout <<"cool"<<endl;
           if(elem[0]=="C") cout << "no"<<endl;
        //  cout<< elem << endl;
       }

        }
        return 0;
    }


  //

    //Session sess(argv[1]); //TODO add in CLion parameters config1.file
    //sess.simulate();

    // TODO change headers folder to include before submission
