#include"json.hpp"
using json=nlohmann::json;
#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

string func1()
{
    json js;
    js["msg_type"]=2;
    js["from"]="zhangsan";
    js["to"]="lisi";
    js["msg"]="Hello,What are you donging now ?";
    //cout<<js<<endl;
    string sendBuf=js.dump();
    //cout<<sendBuf.c_str()<<endl;
    return sendBuf;
}
//序列化普通类型
string func2()
{
    json js;
    js["id"]={1,2,3,4,5};
    js["name"]="zhang san";
    js["msg"]["zhang san"]="hello world";
    js["msg"]["liu shuo"]="hello china";
    js["msg"]={{"zhang san","hello world"},{"liu shuo","hello china"}};
    //cout<<js<<endl;
    return js.dump();
}
//序列化容器类型
string  func3()
{
  json js;
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(5); 
  js["list"]=vec;
  map<int,string> m;
  m.insert({1,"黄山"});
  m.insert({2,"华山"});
  m.insert({3,"泰山"});
  js["path"]=m;
  string sendBuf=js.dump();
  return sendBuf;
  //cout<<sendBuf<<endl;
  //cout<<js<<endl;
}
int main()
{
    cout<<"========================================"<<endl;
    string recBuf=func1();
    json jsbuf=json::parse(recBuf);
    cout<<jsbuf["msg_type"]<<endl;
    cout<<jsbuf["from"]<<endl;
    cout<<jsbuf["to"]<<endl;
    cout<<jsbuf["msg"]<<endl;
    cout<<"======================================"<<endl;
    string recBuf2=func2();
    json jsbuf2=json::parse(recBuf2);
    cout<<jsbuf2["id"]<<endl;
    auto arr=jsbuf2["id"];
    cout<<arr[2]<<endl;
    auto msgjs=jsbuf2["msg"];
    cout<<msgjs["zhang san"]<<endl;
    cout<<msgjs["liu shuo"]<<endl;
    cout<<"====================================== "<<endl;
    string recBuf3=func3();
    json jsbuf3=json::parse(recBuf3);
    vector<int> vec=jsbuf3["list"];
    for(auto value:vec)
    {
      cout<<value<<" ";
    }
    cout<<endl;
    map<int,string> mymap=jsbuf3["path"];
    for(auto &p:mymap)
    {
     cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<endl;
    cout<<"====================================== "<<endl;



    return 0;
}
