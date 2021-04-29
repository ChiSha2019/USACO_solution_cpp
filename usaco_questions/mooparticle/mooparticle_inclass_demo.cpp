#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN = 100000;

int N;

class Particle{
    public:
    int x, y;
    Particle(){};
    Particle(int a, int b){
        x = a;
        y = b;
    }

    void display(){cout << "x =" << x <<" y =" << y <<endl;}
};

//read the particles left to right and top down
bool compare_particle(Particle p1, Particle p2){
    if (p1.x == p2.x)
    {
        return p1.y > p2.y;
    }else{
        return p1.x < p2.x;
    }
    
}

int main(){
    freopen("1.in","r",stdin);
    //freopen("moop.out","w",stdout);
    
    cin >> N;
    Particle particles[N];
    int x1,y1;
    for (int i = 0; i < N; i++)
    {
        cin >> x1 >> y1;
        particles[i].x = x1;
        particles[i].y = y1;
    }

    sort(particles, particles+N, compare_particle);

    for (Particle p: particles)
    {
        p.display();
    }
    
    
}
