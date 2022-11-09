
#include <iostream>
#include <string>
#include <vector>
// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>

using namespace std;


class Person
{   
    public: 
    string Name;
    Person(std::string name)
    {
        Name = name;
    }
    Json::Value dump2JSON(); 
}; 


Json::Value Person::dump2JSON(void)
{
    Json::Value result; 
    result["person"] = Name;
    return result;    
}


class Thing
{
   public:
   string Description;
   
   Json::Value dump2JSON(); 
};

Json::Value Thing::dump2JSON(void)
{
    Json::Value result; 
    result["Thing"] = Description; 
    return result;

}


class GPS
{
    public:
    string Description; 
    Json::Value dump2JSON();  

    private: 
}; 

Json::Value GPS::dump2JSON(void)
{
    Json::Value result; 
    result["location"] = Description;

    return result;
}

class Time
{
    public: 
    int hour; //military time
    Json::Value dump2JSON();  
   
}; 

Json::Value Time::dump2JSON(void)
{
    Json::Value result; 
    result["Time"] = hour;
    return result;
}

class Record
{
    private:
    Person person;
    Thing thing;
    GPS loc;
    Time hours; 
    
    public:
        
        Record(Person, Thing, GPS, Time);
        Json::Value dump2JSON(); 
}; 



Record::Record (Person arg_name, Thing arg_item, GPS arg_location, Time arg_hour)
{
    this->person = arg_name;
    this->thing = arg_item;
    this->loc = arg_location;
    this->hours = arg_hour;
}

Json::Value Record::dump2JSON(void)
{
    Json::Value result;

    result = (this->person).dump2JSON();
        result["person"] = result;
    result = (this->thing).dump2JSON();
        result["thing"] = result;
    result = (this->loc).dump2JSON(); 
        result["location"] = result;
    result = (this->hours).dump2JSON(); 
        result["Time"] = result; 

    return result;
}

  
int main ()
{

Person person1{"Little Red Riding Hood"};


cout<<person1.Name<<endl;

Thing item; 
item.Description = "Cap"; 
cout<<item.Description<<endl;

GPS where;
where.Description = "somewhere";
cout<<where.Description<<endl;

Time when;
when.hour = 15;
cout << when.hour << endl;

Record Record1(person1, item, where, when);
std::cout<<(Record1.dump2JSON().toStyledString())<<std::endl; 



return 0; 
}