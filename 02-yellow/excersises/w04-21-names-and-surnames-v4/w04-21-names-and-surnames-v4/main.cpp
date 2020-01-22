//
//  main.cpp
//  w04-21-names-and-surnames-v4
//
//  Created by Sergey Gordeev on 21/01/2020.
//  Copyright © 2020 Sergey Gordeev. All rights reserved.
//

#include <iostream>
#include "test_runner.hpp"
#include "assertation_tools.hpp"
#include "person.hpp"

void TestIncognito(){
    Person p;
    AssertEq("Incognito",p.GetFullName(1900),"New object");
    p.ChangeFirstName(1910, "name-1910");
}

void TestName(){
    Person p;
    p.ChangeFirstName(1910, "name-1910");
   
    AssertEq("Incognito",p.GetFullName(1900),
             "1900 => The name has been changed in 1910 to name-1910");
  
    AssertEq("name-1910 with unknown last name",p.GetFullName(1910),
             "1910 => The name has been changed in 1910 to name-1910");
  
    AssertEq("name-1910 with unknown last name",p.GetFullName(1911),
             "1911 => The name has been changed in 1910 to name-1910");
    
    p.ChangeFirstName(1910, "name-1910-v2");
  
    AssertEq("Incognito",p.GetFullName(1900),
             "1900 => The name has been changed in 1910 to name-1910-v2");
  
    AssertEq("name-1910-v2 with unknown last name",p.GetFullName(1910),
             "1910 => The name has been changed in 1910 to name-1910-v2");
   
    AssertEq("name-1910-v2 with unknown last name",p.GetFullName(1911),
             "1911 => The name has been changed in 1910 to name-1910-v2");
    
    p.ChangeFirstName(1911, "name-1911");
    AssertEq("Incognito",p.GetFullName(1900),
             "1900 => The name has been changed in 1910 to name-1911");
   
    AssertEq("name-1910-v2 with unknown last name",p.GetFullName(1910),
             "1910 => The name has been changed in 1910 to name-1911");
   
    AssertEq("name-1911 with unknown last name",p.GetFullName(1911),
             "1911 => The name has been changed in 1910 to name-19111");
   
    AssertEq("name-1911 with unknown last name",p.GetFullName(1912),
             "1912 => The name has been changed in 1910 to name-1911");
    
}
void TestSurname(){
    Person p;
    p.ChangeLastName(1910, "surname-1910");
   
    AssertEq("Incognito",p.GetFullName(1900),
             "1900 => The surname has been changed in 1910 to surname-1910");
    
    AssertEq("surname-1910 with unknown first name",p.GetFullName(1910),
             "1910 => The surname has been changed in 1910 to surname-1910");
    
    AssertEq("surname-1910 with unknown first name",p.GetFullName(1911),
             "1911 => The surname has been changed in 1910 to surname-1910");
    
    p.ChangeLastName(1910, "surname-1910-v2");
   
    AssertEq("Incognito",p.GetFullName(1900),
             "1900 => The surname has been changed in 1910 to surname-1910-v2");
    
    AssertEq("surname-1910-v2 with unknown first name",p.GetFullName(1910),
             "1910 => The surname has been changed in 1910 to surname-1910-v2");
    
    AssertEq("surname-1910-v2 with unknown first name",p.GetFullName(1911),
             "1911 => The surname has been changed in 1910 to surname-1910-v2");
    
    p.ChangeLastName(1911, "surname-1911");
    
    AssertEq("Incognito",p.GetFullName(1900),
             "1900 => The surname has been changed in 1910 to surname-1911");
    
    AssertEq("surname-1910-v2 with unknown first name",p.GetFullName(1910),
             "1910 => The surname has been changed in 1910 to surname-1911");
   
    AssertEq("surname-1911 with unknown first name",p.GetFullName(1911),
             "1911 => The surname has been changed in 1910 to surname-1911");
    
    AssertEq("surname-1911 with unknown first name",p.GetFullName(1912),
             "1912 => The surname has been changed in 1910 to surname-1911");
    
}

void Test(){
    Person p;
    AssertEq("Incognito",p.GetFullName(1900),"New object");
    p.ChangeFirstName(1910, "name-1910");
    p.ChangeLastName(1910, "surname-1910");
    AssertEq("Incognito",p.GetFullName(1900),"1900=> After both names has been setted");
    AssertEq("name-1910 surname-1910",p.GetFullName(1910),"1910=> After both names has been setted");
    AssertEq("name-1910 surname-1910",p.GetFullName(1911),"1911=> After both names has been setted");
    
    p.ChangeFirstName(1911, "name-1911");
    AssertEq("name-1911 surname-1910",p.GetFullName(1911),"1911=> name has been changed in 1911");
    AssertEq("name-1911 surname-1910",p.GetFullName(1912),"1912=> name has been changed in 1911");
    p.ChangeLastName(1913, "suname-1913");
    AssertEq("name-1911 surname-1910",p.GetFullName(1911),"1911=> name has been changed in 1911, surname - 1913");
    AssertEq("name-1911 surname-1910",p.GetFullName(1912),"1912=> name has been changed in 1911, surname - 1913");
    AssertEq("name-1911 surname-1913",p.GetFullName(1913),"1912=> name has been changed in 1911, surname - 1913");
}
int main(int argc, const char * argv[]) {
    // insert code here...
    TestRunner r;
    r.RunTest(TestIncognito,"TestIncognito");
    r.RunTest(TestName,"TestName");
    r.RunTest(TestSurname,"TestSurname");
    r.RunTest(TestIncognito,"Test");
    return 0;
}
