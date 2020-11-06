#include <iostream>
#include "../headers/Session.h"
#include <fstream>
#include "../headers/json.hpp"


using namespace std;
using json = nlohmann::json;

int main(int argc, char** argv){

    if(argc != 2){
        std::cout << "usage cTrace <config_path>" << std::endl;
        std::ifstream ifs("//home//spl211//CLionProjects//SPL_Assignment1new//1.json");
       }

    Session sess(argv[1]);
    sess.simulate();
    return 0;
}


  //


    // TODO change headers folder to include before submission
