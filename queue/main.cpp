//
//  main.cpp
//  queue
//
//  Created by 村上候助 on 2017/10/04.
//  Copyright © 2017 村上候助. All rights reserved.
//

#include <iostream>

using namespace std;

struct Process{
    char name[10];
    int time;
};


int main(int argc, const char * argv[]) {
    int n, q;
    scanf("%d %d", &n, &q);
    Process p[n];
    for (int i = 0; i < n; i++){
        scanf("%s %d", p[i].name, &p[i].time);
    }
    
    cout << p[0].name <<endl;
    cout << p[0].time <<endl;
    
    int accu_time = 0;
    int done_ct = 0;
    int ct = 0;
    while(done_ct != n){
        if(p[ct].time == 0){
            ct++;
            ct %= n;
            continue;
        }
        
        if(p[ct].time <= q){
            accu_time+=p[ct].time;
            p[ct].time = 0;
            cout << p[ct].name <<" "<<accu_time << endl;
            done_ct++;
        }
        else{
            accu_time += q;
            p[ct].time -= q;
        }
        ct++;
        ct %= n;
    }
    
    return 0;
}
