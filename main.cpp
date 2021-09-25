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
    for(int i=1;i<=slots;i++){
       available_parking_slot.insert(to_string(i));
     }

     cout<<"Created parking of "<<slots<<" slots"<<endl;
  }

  void Park(vector<string> NewCar){

    //parking the vehicles
    if(available_parking_slot.size()==0){
      cout<<"Sorry! No parking slots available here";
      cout<<endl;
    }
    else{
      //assigning the slot no;
      string slot= *available_parking_slot.begin();
      //erasing the retrieved slot as it is occupied now
      available_parking_slot.erase(available_parking_slot.begin());

      string regNo=NewCar[1];
      string age=NewCar[3];
      
      slotNo_to_RegAge[slot].push_back(regNo);
      slotNo_to_RegAge[slot].push_back(age);

      age_to_regNo[age].push_back(regNo);

      regNo_to_slotNo[regNo]=slot;

      driverAge_to_slotNo[age].push_back(slot);

      cout<<"Car with vehicle registration number "<<'"'<<regNo<<'"'<<" has been parked at slot number "<<slot<<endl;

    }
  }

  void Leave(vector<string> SlotNo){
    //algorithm when vehicle vacates the parking slot
    //some logic for emptyig the slot
    //retrive the slot no
    string slotNo=SlotNo[1];
    //removing its existence from all 3 data list
    //some code
    if(slotNo_to_RegAge.find(slotNo)!=slotNo_to_RegAge.end()){
      string regNo=slotNo_to_RegAge[slotNo][0];
      string age=slotNo_to_RegAge[slotNo][1];
       
      //deleting the regNo from data1

      for (auto it = age_to_regNo[age].begin(); it != age_to_regNo[age].end(); ++it)
        {
          if(*it!=regNo){
              age_to_regNo[age].erase(it);
              break;
          }
        }
      
      //deleting the regNo from data2
        regNo_to_slotNo.erase(regNo);

      //deleting the regNo from data3
       for (auto it = age_to_regNo[age].begin(); it != age_to_regNo[age].end(); ++it)
        {
          if(*it!=slotNo){
              driverAge_to_slotNo[age].erase(it);
              break;
          }
        }
      //print the details of car which vacate the parking slot.
        cout<<"Slot number "<<slotNo<<" vacated, the car with vehicle registration number "<<'"'<<regNo<<'"'<<" left the space, the driver of the car was of age "<<age<<endl;

     //adding this slot to available slots
      available_parking_slot.insert(slotNo);
    }
  }

  void Vehicle_registration_number_for_driver_of_age(vector<string> Age){

    //finding registration number of vehicles using age
    //extract age from string
    string age=Age[1];
    
    //Print the regNo for particular query
    for(auto regNo:age_to_regNo[age]){
      cout<<regNo<<",";
    }
    cout<<endl;
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