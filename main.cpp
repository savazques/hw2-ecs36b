
#include <iostream>
#include <string>
#include <vector>
#include <list>
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
    Person(); 
    Person(string); 
    Json::Value dump2JSON(); 
}; 

Person::Person()
{
    this->Name = " ";
}

Person::Person(string name)
{
    this->Name = name; 
}

Json::Value Person::dump2JSON(void)
{
    Json::Value result; 
    result["name"] = Name;
    return result;    
    
}


class Thing
{
   public:
   string Description;
   Thing();
   Thing(string); 
   Json::Value dump2JSON(); 
}; 

Thing::Thing()
{
    this->Description = " "; 
}

Thing::Thing(string arg)
{
    this->Description = arg;
}

Json::Value Thing::dump2JSON(void)
{
    Json::Value result; 
    result["item"] = Description; 

    return result;

}


class GPS
{
    public:
    string Description;
    GPS();
    GPS(string);  
    Json::Value dump2JSON();  

    private: 
}; 

GPS::GPS()
{
    this->Description = " "; 
}

GPS::GPS(string arg)
{
    this->Description = arg; 
}

Json::Value GPS::dump2JSON(void)
{
    Json::Value result; 
    result["area"] = Description;

    return result;
}

class Time
{
    public: 
    string when; 
    Time(); 
    Time(string); 
    Json::Value dump2JSON();  
   
}; 

Time::Time()
{
    this->when = " "; 
}

Time::Time(string arg)
{
    this->when = arg; 
}

Json::Value Time::dump2JSON(void)
{
    Json::Value result; 
    result["when"] = when;
    return result;
}

class Record
{
    
    private:
        Person person;
        Person person2;
        Thing thing;
        Thing thing2; 
        GPS loc;
        Time when; 
        string object;
    public:   
        Record();  
        Record(Person, Person,  Thing, Thing, GPS, Time);
        Json::Value dump2JSON(); 
}; 

Record::Record()
{
    this->person = Person{};
    this->thing = Thing{}; 
    this->loc = GPS{}; 
    this->when = Time{}; 
}


Record::Record (Person arg_name, Person arg2_names, Thing arg_item, Thing arg2_items,  GPS arg_location, Time arg_hour)
{
    this->person2 = arg2_names; 
    this->person = arg_name;
    this->thing = arg_item;
    this->thing2 = arg2_items;
    this->loc = arg_location;
    this->when = arg_hour;
}

Json::Value Record::dump2JSON(void)
{
    Json::Value result{}; 
    Json::Value jvResult;

    jvResult = (this->person).dump2JSON(); 
        result["Person 1"] = jvResult;

    jvResult = (this->person2).dump2JSON(); 

        if (jvResult != " ")
        {
            result["Person2 2"] = jvResult; 
        } 
        
    
    jvResult = (this->thing).dump2JSON();
        result["Thing"] = jvResult;
    
    jvResult = (this->thing2).dump2JSON();
        if (jvResult != " ")
        {
            result["Thing 2"] = jvResult;
        }
    

    jvResult = (this->loc).dump2JSON(); 
        result["GPS"] = jvResult;

    jvResult = (this->when).dump2JSON(); 
        result["Time"] = jvResult; 
    
   cout<< result.toStyledString()<< endl;
    


    return result;
}

  
int main ()
{


Person RedRidingHood{"Red Riding Hood"};
Thing Cap{"a cap of red Velvet"};
GPS where{"somewhere"};
Time when{"One day"}; 

Person Mom{"her mother"};
Thing Cake{"A piece of cake"}; 
Thing Wine{"wine"}; 

Person Wolf{"Wolf"};
GPS Woods{" a particular spot in woods"}; 
Thing Anotherthing{"thing"};

Person Grandma{"Grandma"}; 
Thing Home{"was at her home"};
GPS OakTrees{"3 large  oak trees"}; 

Thing NULLpt{""};
Person NULLptr{""}; 



Record Record1(RedRidingHood, NULLptr,  Cap, NULLpt, where, when);
cout<<"Record 1"<<endl; 
Record1.dump2JSON(); 


Record Record2(Mom, RedRidingHood , Cake, Wine, where, when );
cout<<"Record 2"<<endl;
Record2.dump2JSON();

Record Record3(Wolf, RedRidingHood, Anotherthing, NULLpt, Woods, when); 
cout<<"Record 3"<<endl;
Record3.dump2JSON(); 

Record Record4(Grandma, NULLptr, Home, NULLpt, OakTrees, when); 
cout<<"Record 4"<<endl;
Record4.dump2JSON(); 


return 0; 
}