#include <bits/stdc++.h>
using namespace std;

int countbytesinfile(ifstream &input_file) {
  input_file.seekg(0,ios::end);
  int size=input_file.tellg();
  return size;
}

int countlinesinfile(ifstream &input_file) {
  int numlines=0; string line;
  while(getline(input_file,line)) {
    numlines++;
  }
  return numlines;
}

int countwordsinfile(ifstream &input_file) {
  int numwords=0; string line;
  while(getline(input_file,line)) {
    string word; istringstream ss(line);
    while(ss>>word) {
      numwords++;
    }
  }
  return numwords;
}

int countcharsinfile(ifstream &input_file) {
  int numchars=0; char ch;
  while(input_file.get(ch)) {
    numchars++;
  }
  return numchars;
}

ifstream openfile(char* filename) {
  ifstream input_file(filename);
  if(!input_file.is_open()) {
    cerr<<"Error: Could not open the file "<<filename<<endl;
    return ifstream();
  }
  return input_file;
}

int main(int argc, char* argv[]) {
  string cincheck; getline(cin,cincheck);
  if(cincheck.length()!=0) {
      string line; ofstream output_file("data.txt");
      while(getline(cin,line)) {
        output_file<<line<<endl;
      }
      output_file.close();
      ifstream input_file("data.txt");
      if(strcmp(argv[1],"-c")==0) {
      int numbytes=countbytesinfile(input_file);
        if(numbytes!=-1) {
          cout<<numbytes<<endl;
        }
      }
      if(strcmp(argv[1],"-l")==0) {
        int numlines=countlinesinfile(input_file);
        if(numlines!=-1) {
          cout<<numlines<<endl;
        }
      }  
      if(strcmp(argv[1],"-w")==0) {
        int numwords=countwordsinfile(input_file);
        if(numwords!=-1) {
          cout<<numwords<<endl;
        }
      }  
      if(strcmp(argv[1],"-m")==0) {
        int numchars=countcharsinfile(input_file);
        if(numchars!=-1) {
          cout<<numchars<<endl;
        }
      }
    input_file.close();
    remove("data.txt");
    return 0;
  }
  if(argc==3) {
    ifstream input_file=openfile(argv[2]);
    if(strcmp(argv[1],"-c")==0) {
      int numbytes=countbytesinfile(input_file);
      if(numbytes!=-1) {
        cout<<numbytes<<" "<<argv[2]<<endl;
        return 0;
      }
      return -1;
    } else if(strcmp(argv[1],"-l")==0) {
      int numlines=countlinesinfile(input_file);
      if(numlines != -1) {
        cout<<numlines<<" "<<argv[2]<<endl;
        return 0;
      }
      return -1;
    } else if(strcmp(argv[1],"-w")==0) {
      int numwords=countwordsinfile(input_file);
      if(numwords != -1) {
        cout<<numwords<<" "<<argv[2]<<endl;
        return 0;
      }
    } else if(strcmp(argv[1],"-m")==0) {
        int numchars=countcharsinfile(input_file); // check again
        if(numchars != -1) {
          cout<<numchars<<" "<<argv[2]<<endl;
          return 0;
        }
      return -1;
    }
    input_file.close();
  } else if(argc==2) {
      ifstream input_file=openfile(argv[1]);
      int numbytes=countbytesinfile(input_file);
      input_file.close();
      input_file=openfile(argv[1]);
      int numlines=countlinesinfile(input_file);
      input_file.close();
      input_file=openfile(argv[1]);
      int numwords=countwordsinfile(input_file);
      input_file.close();
      cout<<numlines<<" "<<numwords<<" "<<numbytes<<" "<<argv[1]<<endl;
      return 0;
  } 
  return 0;
}
