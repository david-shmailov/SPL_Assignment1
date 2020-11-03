#include <iostream>
#include "../headers/Session.h"
#include <fstream>
#include "../headers/json.hpp"

using namespace std;
using json = nlohmann::json;

int main(int argc, char** argv){

    if(argc != 2){
        cout << "usage cTrace <config_path>" << endl;

        return 0;
    }

    //Session sess(argv[1]); //TODO add in CLion parameters config1.file
    //sess.simulate();
    return 0;
    // TODO change headers folder to include before submission
}