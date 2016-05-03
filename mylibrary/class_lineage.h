#ifndef __LINEAGE_H_
#define __LINEAGE_H_

class lineage {
private:
  int id; //this is the species identity number
  double time_b; // this is the time when the lineage appears
  double time_d; // this is the time when the lineage dies or splits
  int parent_id; // this is the identity of the parent
  bool ext; //whether the lineage went extinct or not
  bool spe; //whether the lineage split into two species or no
  vector<int> dist; //the occurence of the species


public:
  lineage(int _id, double _tb, double _td, int _pid, vector<int> _dist,int NREGION){
    this -> id = _id;
    this -> time_b = _tb;
    this -> time_d = _td;
    this -> parent_id = _pid;
    this -> ext = false;
    this -> spe = false;
    this -> dist = new _dist[NREGION];
  }

  ~lineage(){
    delete[] this -> dist
  }

  int get_id(){
    return this -> id;
  }

  int get_dist(int region){
    return this -> dist[region];
  }

  double get_time_b(){
    return this -> time_b;
  }

  double get_time_d(){
    return this -> time_d;
  }

  bool get_spe(){
    return this -> spe;
  }

  bool get_ext(){
    return this -> ext;
  }
  void modify_time_d(double new_td){
    this -> time_d = new_td;
  }

  void set_spe_true(){
    this -> spe = true;
  }

  void set_ext_false(){
    this -> ext = false;
  }

  void local_ext(int region){
    assert(dist[region] == 1);
    this -> dist[region] = 0;
  }

  void local_col(int region){
    assert(dist[region] == 0 );
    this -> dist[region] = 1;
  }

  int get_total_dist(){
    int result = 0;
    for(int i = 0 ; i <NREGION ; i++)
      result +=  dist[i];
    return result;
  }
};

void output_lineage(lineage *lin){
  cout << lin -> get_id() << "\t" << lin -> get_time_b() << "\t"
       << lin -> get_time_d() << "\t" << lin -> get_time_b() << "\t"
       << lin -> get_parent_id() << "\t"
       << lin -> get_ext() << "\t" << lin -> get_spe() << "\t" ;
  for(int i = 0 ; i < NREGION; i++){
    cout<< lin -> dist[i] << "\t";
  }
  cout << endl;
}

#endif //__LINEAGE_H_
