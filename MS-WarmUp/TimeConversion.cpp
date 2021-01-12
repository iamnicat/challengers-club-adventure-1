#include <bits/stdc++.h>

using namespace std;

string timeConversion(string const& time) {
   string hour = time.substr(0, 2); // hour is the only thing to convert
   string const id = time.substr(8, 2);   // AM/PM
   int nHour = stoi(hour);

   if( id == "PM" )
   {
       if(nHour != 12)
           nHour += 12;

       hour = to_string(nHour);
   }
   else
   {
       if( nHour == 12 )
           hour = "00";
       else if( nHour < 10 )
           hour = "0" + to_string(nHour); // zero padding
       else
           hour = to_string(nHour);
   }

   return hour + time.substr(2, 6);
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
