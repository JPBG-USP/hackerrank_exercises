#include<bits/stdc++.h>

using namespace std;

class Box{
  private:
    int l, b, h;
  
  public:  
    Box(){
        this->l = 0;
        this->b = 0;
        this->h = 0;
    }
    Box(const int l, const int b, const int h){
        this->l = l;
        this->b = b;
        this->h = h;
    };
    Box(const Box& box){
        this->l = box.l;
        this->b = box.b;
        this->h = box.h;
    }
    ~Box(){};
    
    int getLength(){return  this->l;};
    int getBreadth(){return  this->b;};
    int getHeight(){return  this->h;};
    
    long long CalculateVolume() const{
        return static_cast<long long>(l) * b * h;
    }
    
    bool operator<(Box& box){
        if (this->l < box.l)
            return  true;
            
        if (this->b < box.b && this->l == box.l)
            return true;
            
        if (this->h < box.h && this->b==box.b && this->l == box.l)
            return true;
        
        return false;
    };
    
    friend std::ostream& operator<<(std::ostream& out, const Box& B) {
        out << B.l << " " <<B.b << " " << B.h;
    return out;
    }
};


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}