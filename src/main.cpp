#include <iostream>
#include "../headers/Session.h"
#include <fstream>



//using namespace std;

int main(int argc, char** argv){

    if(argc != 2) {
        std::cout << "usage cTrace <config_path>" << std::endl;

        //Session sess("//home//spl211//CLionProjects//SPL_Assignment1//config1.json");
        //sess.simulate();}
    }
    Session sess(argv[1]);
    sess.simulate();

    return 0;
}


  //

