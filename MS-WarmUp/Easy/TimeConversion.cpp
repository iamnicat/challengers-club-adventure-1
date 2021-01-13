#include <bits/stdc++.h>

using namespace std;

string timeConversion(string time) {
  if (time[0]=='1' && time[1]=='2') // 12 AM to 12 PM and vice versa
      time[8] = "PA"[time[8]=='P']; 
      
  if (time[8] == 'P') {
    if (time[1] < '8') {
      time[1] += 2;
      time[0] += 1; 
    } else {
      time[1] -= 8;
      time[0] += 2;
    }
  }
  
  if (time[0]=='2' && time[1]=='4') // 24 to 00
    time[0]=time[1]='0';

  time.resize(time.size()-2); // remove AM/PM
  return time;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
