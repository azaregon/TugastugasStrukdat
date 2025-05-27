#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int,int> mii; //key : integer, value integer; // distrik peserta dalam bentuk map
    int distrik;
    int penantang;
    int dafPes[500];
    
    scanf("%d",&distrik);
    scanf("%d",&penantang);
    
    int middle = (penantang % 2 == 0) ? penantang / 2 : (penantang / 2) +1;

    for (int i = 0; i < distrik+6; i++) {
        mii[i+1] = 0;
    }
    
    for (int i = 0; i < penantang; i++) {
        int now;
        scanf("%d",&now);
        dafPes[i];
        printf("%d  \n",now);
        mii[now]++;
    }

    int mid_inp = dafPes[middle];

    int count = 0;
    for(auto i = mii.begin(); i != mii.end(); i++){
        cout << i->first << " " << i->second << "   ";
        count+= i->second;
        if (count > middle) {
            printf("%d %d\n",mid_inp,i->first);
            if (i->first == mid_inp) {
                cout << "Tidak ada yang menang";
            } else {
                cout << "Distrik " << mid_inp <<  " menang";
            }
            break;
        }

        // if (map_int_int.count(i))
        //     cout << "elemen dengan key " << i << " ada di dalam map" << endl;
        // else
        //     cout << "elemen dengan key " << i << " tidak ada di dalam map" << endl; 
    }

}