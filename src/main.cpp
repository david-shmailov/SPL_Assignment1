#include <iostream>
//#include "../headers/Session.h"
#include <fstream>
#include "json.hpp"
//#include <nlohmann/json.hpp>

//using namespace std;
//using json = nlohmann::json;

int main(int argc, char** argv){

    if(argc != 2){
        std::cout << "usage cTrace <config_path>" << std::endl;
//        std::string line;
//        std::ifstream myfile ("//home//spl211//CLionProjects//SPL_Assignment1new//1.json");
//        if (myfile.is_open())
//        {
//
//            while ( getline (myfile, line) )
//            {
//                std::cout << line << '\n';
//            }
//            myfile.close();
//        }

        std::ifstream ifs("//home//spl211//CLionProjects//SPL_Assignment1new//1.json");
        //std::cout << ifs << std::endl;
        nlohmann::json jf = nlohmann::json::parse(ifs);
       std::cout << jf["agents"]<< std::endl;

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
