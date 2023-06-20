#include <iostream>
#include <string>
#include <fstream>

using namespace std;

 //structure of users
struct User{
    string Username;
    string password;
};

bool registerUser(User);
bool loginUser(User);

int main(){
    int option;
    User user;

    cout << "Welcome to your login and registration page!" << endl;
     
     do{
        cout << "Please select an option : " << endl;
        cout << "1.Register" << endl;
        cout << "2.Login" << endl;
        cout << "3.Exit" <<endl;
        cin >>option;
        
        switch (option)
        {
        case 1:
           cout << "Enter Username: " << endl;
            cin >>user.Username;
           cout << "Enter Password: " <<endl;
           cin >>user.password;

           if(registerUser(user)){
            cout <<"User Registraton Successful!" << endl;
           }
           else {
            cout <<  "User Registration FAILED!" <<endl;
           }
            break;

            case 2:
            cout << "Enter Username: " << endl;
            cin >>user.Username;
           cout << "Enter Password: " <<endl;
           cin >>user.password;

           if(loginUser(user)){
            cout <<"User Login Successful!" << endl;
           }
           else {
            cout <<  "User Login FAILED!" <<endl;
           }
            break;


            case 3:
            cout << "Exiting..." << endl;
            break;
        default:
        cout << "Invalod Option, Please Try again!" << endl;
            break;
        }   
      } while (option !=3);

      return 0;
}
      bool registerUser(User user){
        fstream file;
        file.open("users.txt",ios::app);

        if (!file)
        {
            cout << "Error Opening File1" << endl;
            return false;
        }
        
        file << user.Username << " " <<user.password << endl;
        file.close();
        
        return true;
      }

      bool  loginUser(User user){
        fstream file;
        string username, password;

        file.open("users.txt",ios::in);
        
        if(!file){
            cout << "Error opening file!" << endl;
            return false;
        }

        while (file >> username >> password){
            if (username == user.Username && password == user.password)
            {
                file.close();
                return true;
            }
            
        }
         file.close();
        return false;
           
        }
        
      
