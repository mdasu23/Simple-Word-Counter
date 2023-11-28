#include <bits/stdc++.h>
using namespace std;

int countbytesinfile(char* filename) {
  ifstream input_file(filename);
  if(!input_file.is_open()) {
    cerr<<"Error: Could not open the file "<<filename<<endl;
    return -1;
  }
  input_file.seekg(0,ios::end);
  int size=input_file.tellg();
  input_file.close();
  return size;
}

int countlinesinfile(char* filename) {
  ifstream input_file(filename);
  if(!input_file.is_open()) {
    cerr<<"Error: Could not open the file "<<filename<<endl;
    return -1;
  }
  int numlines=0; string line;
  while(getline(input_file,line)) {
    numlines++;
  }
  input_file.close();
  return numlines;
}

int countwordsinfile(char* filename) {
  ifstream input_file(filename);
  if(!input_file.is_open()) {
    cerr<<"Error: Could not open the file "<<filename<<endl;
    return -1;
  }
  int numwords=0; string line;
  while(getline(input_file,line)) {
    string word; istringstream ss(line);
    while(ss>>word) {
      numwords++;
    }
  }
  input_file.close();
  return numwords;
}

int countcharsinfile(char* filename) {
  ifstream input_file(filename);
  if(!input_file.is_open()) {
    cerr<<"Error: Could not open the file "<<filename<<endl;
    return -1;
  }
  int numchars=0; char ch;
  while(input_file.get(ch)) {
    numchars++;
  }
  input_file.close();
  return numchars;
}

int main(int argc, char* argv[]) {
  if(argc==3) {
    if(strcmp(argv[1],"-c")==0) {
      int numbytes=countbytesinfile(argv[2]);
      if(numbytes!=-1) {
        cout<<numbytes<<" "<<argv[2]<<endl;
        return 0;
      }
      return -1;
    } else if(strcmp(argv[1],"-l")==0) {
      int numlines=countlinesinfile(argv[2]);
      if(numlines != -1) {
        cout<<numlines<<" "<<argv[2]<<endl;
        return 0;
      }
      return -1;
    } else if(strcmp(argv[1],"-w")==0) {
      int numwords=countwordsinfile(argv[2]);
      if(numwords != -1) {
        cout<<numwords<<" "<<argv[2]<<endl;
        return 0;
      }
    } else if(strcmp(argv[1],"-m")==0) {
        int numchars=countcharsinfile(argv[2]); // check again
        if(numchars != -1) {
          cout<<numchars<<" "<<argv[2]<<endl;
          return 0;
        }
      return -1;
    }
  } else if(argc==2) {
    if(strcmp(argv[1],"-l")!=0 && strcmp(argv[1],"-m")!=0 && strcmp(argv[1],"-c")!=0) {
      int numbytes=countbytesinfile(argv[1]);
      int numlines=countlinesinfile(argv[1]);
      int numwords=countwordsinfile(argv[1]);
      if(numbytes != -1 && numlines != -1 && numwords != -1) {
        cout<<numlines<<" "<<numwords<<" "<<numbytes<<" "<<argv[1]<<endl;
        return 0;
      } else {
        cerr<<"Error: Error in opening file"<<endl;
        return -1;
      }
    } else {
      
    }
  } 
  return 0;
}
//check numchars // wrong