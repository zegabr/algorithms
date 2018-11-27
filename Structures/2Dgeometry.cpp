//used by ufpe maratona guys
#include <bits/stdc++.h>
using namespace std;
struct pt{
    double x,y;

    pt(double x=0,double y=0):x(x), y(y){}
    pt operator+(const pt &p) const {return pt(x+p.x, y+p.y);}
    pt operator-(const pt &p) const {return pt(x-p.x, y-p.y);}
    pt operator*(double c) const {return pt(x*c,y*c);}
    pt operator/(double c) const {return pt(x/c,y/c);}
    double operator!() const {return hypot(x,y);}//length
    double operator*(const pt &p) const {return x*p.x+y*p.y;}//dot prod
    double operator%(const pt &p) const {return x*p.x-y*p.y;}//cross prod
    double operator^(const pt &p) const {return atan2(*this%p, *this * p);}//angle
};
const double EPS = 1e-12;
int cmp(double a,double b=0.0){
    if(abs(a-b)<EPS)return 0;
    else if(a<b) return -1;
    return 1;
}
    //r = a<->b
    //s = c<->d
bool parallel(const pt &a,const pt &b,const pt &c,const pt &d){//paralelismo
    return cmp((b-a)%(c-d))==0;
}
bool collinear(const pt &a,const pt &b,const pt &c,const pt &d){//coincidencia
    return parallel(a,b,c,d) and cmp((a-b)%(a-c))==0 and cmp((c-d)%(c-a))==0;
}
bool perpendicular(const pt &a,const pt &b,const pt &c,const pt &d){//angulo reto
    return cmp((b-a)*(c-d))==0;
}
pt intersec(const pt &a,const pt &b,const pt &c,const pt &d){//entre retas
    if(!parallel(a,b,c,d)) return pt(3e9,3e9);
    pt v1=b-a, v2=c-d, v3=c-a;
    return a + v1*(v3%v2)/(v1%v2);
}
void swap (double &a, double &b){
    double aux=a;a=b;b=aux;
}
bool ptInSeg(const pt &c,pt a,pt b){
    pt v1=b-a, v2=c-a;
    if(a.x>b.x) swap(a.x,b.x);
    if(a.y>b.y) swap(a.y,b.y);    
    return  cmp(v2.x/v1.x , v2.y/v1.y)==0
        and cmp(a.x,c.x)<=0 and cmp(c.x,b.x)<=0
        and cmp(a.y,c.y)<=0 and cmp(c.y,b.y)<=0;  
}
bool pointInPoly(const vector<pt> &p, pt q){
    bool c=0;
    for(int i=0;i<p.size();i++){
        int j=(i+1)%p.size();
        if((cmp(p[i].y,q.y) <=0 and cmp(q.y,p[j].y) < 0 or
        cmp(p[j].y,q.y) <=0 and cmp(q.y,p[i].y) < 0) and
        q.x<p[i].x + (p[j].x - p[i].x)*(q.y - p[i].y) / (p[j].y - p[i].y))
        c=!c;
    }
    return c;
}
bool pointInTriangle(pt a, pt b, pt c, pt d){
    //d is inside a,b,c
    bool comp1 = cmp((b-a)%(d-a)) <0,
         comp2 = cmp((c-a)%(d-b)) <0,
         comp3 = cmp((a-c)%(d-c)) <0;
    return (comp1==comp2) and (comp2==comp3);
}
bool pointInPolygon2(const vector<pt> &p, pt q){
    int l=1, r=p.size()-1;
    if(ptInSeg(p[0],p[l],q) or ptInSeg(p[0],p[r],q)) return false;
    while(r-l>1){
        int m=(l+r)>>1;
        double prod = (p[m]-p[0]) % (q-p[0]);
        if(cmp(prod)==0)return ptInSeg(p[m],p[0],q);
        else if(prod<0)l=m;
        else r=m;
    }
    return pointInTriangle(p[0],p[l],p[r],q)
            or ptInSeg(p[0],p[l],q)
            or ptInSeg(p[0],p[r],q);
}
double area(const vector<pt> &p){
    double area=0;
    for(int i=0;i<p.size();i++){
        int j=(i+1)%p.size();
        area+=(p[i]-p[0])%(p[j]-p[0]);
    }
    return abs(area)/2.0;
}
