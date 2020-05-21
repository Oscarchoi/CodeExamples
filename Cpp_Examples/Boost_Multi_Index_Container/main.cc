#include <iostream>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>

using namespace std;
using namespace ::boost;
using namespace ::boost::multi_index;

struct employee {
  int id;
  string name;

  employee(int id, const string& name): id(id), name(name){}

  bool operator<(const employee& e) const {return id<e.id;}
};


using employee_set = multi_index_container<
  employee,
  indexed_by<
    // sort by employee::operator<
    ordered_unique<identity<employee> >,

    // sort by less<string> on name
    ordered_non_unique<member<employee,std::string,&employee::name> >,

    // unorderd_map
    hashed_unique<member<employee,std::string,&employee::name> >
  >
>;

// use name_index as a regular std::set
void print_out_by_name(const employee_set& es)
{
  // get a view to index #1 (name)
  const employee_set::nth_index<1>::type& name_index=es.get<1>();
  for(auto& e : name_index) cout<<e.name<<endl;
}

/* multi_set */
void print_out_by_id(const employee_set& es)
{
  const employee_set::nth_index<0>::type& id_index=es.get<0>();
  for(const auto& e: id_index) cout<<e.id<<endl;
}

/
void print_id_by_name(const employee_set& es, const string& name){
  
  const employee_set::nth_index<2>::type& hashed_index=es.get<2>();
  cout<<"[name] "<<name<<" : "<<hashed_index.find(name)->id<<endl;
}

int main(){

  employee_set es = {employee(0,"Tom"), employee(1,"Alice")};
  es.insert({2,"Choi"});

  print_out_by_name(es);
  print_out_by_id(es);
  print_id_by_name(es,"Choi");
  
  return 0;
}
