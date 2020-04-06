//
//  hannahDoTM.cpp
//  helloworld
//
//  Created by Hannah Do on 03/04/2020.
//  Copyright © 2020 theoryclass. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

    int main()
    {
        string filename;
        char qstate = '0';
        int position = 0;
        int i = 0;
        string line;
        string myArray[100];
        string inputword;
        
        cout << "sample files :" << endl;
        cout << "test3.txt  - this tm accepts L=01*" << endl;
        cout << "test2.txt  - this tm recognizes strings in 0^n 1^n 0^n" << endl << endl;

        
        cout << "Please enter a file name:" << endl;
        cin >> filename;
        
        
        cout << "Please enter the input word : ";
        cin >> inputword;

            
        ifstream open_infile(filename);
            if(open_infile.is_open()){

                while (! open_infile.eof()){
                    getline (open_infile, line);
                    
                    
                    std::size_t found = line.find("/");
                    line = line.substr(0,found);
                    

                    
                    std::string::iterator end_pos = std::remove(line.begin(), line.end(), ' ');
                    line.erase(end_pos, line.end());
                    
                    if (line != ""){
                    myArray[i] = line;
                    i++;

                    }
                }
                open_infile.close();
            }
            else cout << "Unable to open file, or file does not exist";

        
        int loop = 1;
            while (loop){

                for (int i = 0 ; i < 100 ; i++){
                if ((qstate == myArray[i][0]) && (inputword[position] == myArray[i][1]) && (position < inputword.length())){

                    cout << inputword << endl << endl;
                    qstate = myArray[i][2];
                 
                    inputword[position] = myArray[i][3];

                    if(myArray[i][4] == 'R'){
                        ++position;
                    }else if(myArray[i][4] == 'L'){
                        --position;

                    }
                    
                }else if(qstate == myArray[i][0] && ((position >= inputword.length()) || position < 0)){
                    
                    if(myArray[i][1]=='B'){
                        cout << inputword << endl << endl;
                        qstate = myArray[i][2];

                        inputword[position] = myArray[i][3];

                        if(myArray[i][4] == 'R'){
                            ++position;
                        }else if(myArray[i][4] == 'L'){
                            --position;
                        }
                    }
                }
//                else{
//                    cout << "the string cannot be accepted." << endl;
//                    loop = 0;
//                    i = 1000;
//                }
                    
                if(qstate == 'f'){

                    cout << "Final state has been reached. The string is accepted." << endl << endl;
                    loop = 0;
                    i = 1000;
                    
                }
            }
            }
            

        return 0;
    
}
