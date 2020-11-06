#include <iostream>
#include "../headers/Session.h"
#include <fstream>



//using namespace std;

int main(int argc, char** argv){

    if(argc != 2){
        std::cout << "usage cTrace <config_path>" << std::endl;
        const std::string s= "//home//spl211//CLionProjects//SPL_Assignment1//config1.json";
        Session sess(s); //TODO add in CLion parameters config1.file
        sess.simulate();
       }

    Session sess(argv[1]);
    sess.simulate();
    return 0;
}


  //


    // TODO change headers folder to include before submission
