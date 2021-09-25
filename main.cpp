#include<bits/stdc++.h>
using namespace std;

//splitting each line into array of strings
vector<string> listOfWords(string s)
{
    stringstream ss(s);
    string word;
    vector<string> words;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

int main() {
  // dont forget to use try catch to handle exception cases.
  ifstream fin;
  fin.open("input.txt");
  string line;

  getline(fin,line);
  vector<string> tokens=listOfWords(line);
  //creating the parking slots of given size
  Create_parking_lot Parking(stoi(tokens[1]));

  while(fin){
    getline(fin,line);
    vector<string> words=listOfWords(line);
    string fun=words[0];
    
    
    if(fun=="Create_parking_lot"){
          cout<<"Creating another parking slots declined"<<endl;  
        }
    else if(fun=="Park"){  
          Parking.Park(words);
        }
    else if(fun=="Leave"){
          Parking.Leave(words);
        }
    else if(fun=="Vehicle_registration_number_for_driver_of_age"){
          Parking.Vehicle_registration_number_for_driver_of_age(words);
        }
    else if(fun=="Slot_number_for_car_with_number"){
          Parking.Slot_number_for_car_with_number(words);
        }
    else if(fun=="Slot_numbers_for_driver_of_age"){
          Parking.Slot_numbers_for_driver_of_age(words);
        }
    else{
          cout<<"Invalid Parking Request!"<<endl;
        }
  }
  fin.close();
  exit(0);
return 0;
}