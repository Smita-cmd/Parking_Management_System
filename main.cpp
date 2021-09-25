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

class Create_parking_lot{
 
   set<string> available_parking_slot;
   unordered_map<string,vector<string>> slotNo_to_RegAge;
   
   //data1
   unordered_map<string,vector<string>> age_to_regNo;
   //data2
   unordered_map<string,string> regNo_to_slotNo;
   //data3
   unordered_map<string,vector<string>> driverAge_to_slotNo;

public:
  Create_parking_lot(int slots){
    //initialising the parking slots
    
  }

  void Park(vector<string> NewCar){
    //parking the vehicles
    
  }

  void Leave(vector<string> SlotNo){
    //algorithm when vehicle vacates the parking slot
   
    
  
  }
  void Vehicle_registration_number_for_driver_of_age(vector<string> Age){
    //finding registration number of vehicles using age
    
   
  }
  void Slot_number_for_car_with_number(vector<string> reg){
    //finding slot number from registration number
    //some logic to implement this.
    
  }

  void Slot_numbers_for_driver_of_age(vector<string> Age){
    //  Slot Number(Comma-separated)
    //finding slot numbers from age
      
  }

};


int main() {
  
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