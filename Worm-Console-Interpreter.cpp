#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
//-------------------------------
char a[24][80];
int cond=1;
char pen1='*';
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
double ghadremotlagh(double x)
{
	if(x>0)
		return x;
	else
		return (-x);
}
void firstuse()
{
	int i,j;
	for(i=0;i<80;i++)
	{
		for(j=0;j<24;j++)
			a[j][i]=' ';
	}
}
void line(int startx,int starty,int endx,int endy,char pen)
{
	int i,j,x,d;
	double min1;
	a[starty][startx]=pen;
	a[endy][endx]=pen;
	if(endx<startx)
	{
		line(endx,endy,startx,starty,pen);
		return;
	}
	if(starty==endy)
	{
		for(i=startx;i<=endx;i++)
			a[starty][i]=pen;
	}
	else
	{
		if(startx==endx)
		{
			for(i=min(starty,endy);i<=max(starty,endy);i++)
				a[i][startx]=pen;
		}
		else
		{
			if(starty<endy)
			{
				double m=(double(endy-starty))/(endx-startx);
				for(j=starty+1;j<=endy;j++)
				{
					min1=100;
					for(i=startx+1;i<=endx;i++)
					{
						if(ghadremotlagh((((double)j-(double)starty)/(double(i)-double(startx)))-m)<min1)
						{
							min1=ghadremotlagh((((double)j-(double)starty)/(double(i)-double(startx)))-m);
							x=i;
						}
					}
					a[j][x]=pen;
				}
				d=endy-starty;
				if(d==1)
				{
					for(i=startx;i<startx+(endx-startx)/2;i++)
						a[starty][i]=pen;
					for(i=startx+(endx-startx)/2;i<endx;i++)
						a[endy][i]=pen;
				}
				if(d>1&&d<5&&(endx-startx)>12*d)
				{
					for(j=0;j<=d;j++)
					{
						a[starty+j][startx+int((2*j+1)*(double(endx-startx)/(2*d)))+1]=pen;
					}

				}
			}
			if(starty>endy)
			{
				double m=(double(endy-starty))/(endx-startx);
				for(j=starty-1;j>=endy;j--)
				{
					min1=100;
					for(i=startx+1;i<=endx;i++)
					{
						if(ghadremotlagh((((double)j-(double)starty)/(double(i)-double(startx)))-m)<min1)
						{
							min1=ghadremotlagh((((double)j-(double)starty)/(double(i)-double(startx)))-m);
							x=i;
						}
					}
					a[j][x]=pen;
				}
				d=starty-endy;
				if(d==1)
				{
					for(i=startx;i<startx+(endx-startx)/2;i++)
						a[starty][i]=pen;
					for(i=startx+(endx-startx)/2;i<endx;i++)
						a[endy][i]=pen;
				}
				if(d>1&&d<5&&(endx-startx)>12*d)
				{
					for(j=0;j<=d;j++)
					{
						a[starty-j][startx+int((2*j+1)*(double(endx-startx)/(2*d)))+1]=pen;
					}
				}
			}
		}
	}
}
void circle(double x,double y,double r,char pen)
{
	int i,j,min1,m,t=0;
	if(r==0)
	{
		a[int(y)][int(x)]=pen;
		return;
	}
	if(r==1)
	{
		a[int(y)-1][int(x)]=pen;
		a[int(y)+1][int(x)]=pen;
		a[int(y)][int(x)+4]=pen;
		a[int(y)+1][int(x)+2]=pen;
		a[int(y)-1][int(x)+2]=pen;
		if(x>3)
			a[int(y)][int(x)-4]=pen;
		if(x>1)
		{
			a[int(y)+1][int(x)-2]=pen;
			a[int(y)-1][int(x)-2]=pen;
		}
		return;
	}
		
	for(j=0;j<24;j++)
	{
		min1=8;
		t=0;
		for(i=0;i<80;i++)
		{
			if(ghadremotlagh((.1*((double)i-x)*((double)i-x)+((double)j-y)*((double)j-y))-(r*r))<min1)
			{
				min1=ghadremotlagh((.1*((double)i-x)*((double)i-x)+((double)j-y)*((double)j-y))-(r*r));
				m=i;
				t=1;
			}
		}
		if(t==1)
		{
			if(m<x)
			{
				a[j][m]=pen;
				if(int(2*x)-m<80)
					a[j][int(2*x)-m]=pen;
			}
			if(m>x||(x+4*r>79))
				a[j][m]=pen;
		}
		if(y>=r)
			a[int(y)-int(r)][int(x)]=pen;
		a[int(y)+int(r)][int(x)]=pen;
		if(int(x)<=1)
		{
			if(r>2)
			{
				if(y>=r)
					a[int(y)-int(r)][int(x)+3]=pen;
				a[int(y)+int(r)][int(x)+3]=pen;
			}
			if(r==2)
			{
				if(y>=r)
					a[int(y)-int(r)][int(x)+2]=pen;
				a[int(y)+int(r)][int(x)+2]=pen;
			}
		}
	}
}
void fillcircle(double x,double y,double r,char pen)
{
	int i,j,min1,m,t=0,h=0;
	if(r==0)
	{
		a[int(y)][int(x)]=pen;
		return;
	}
	if(r==1)
	{
		a[int(y)-1][int(x)]=pen;
		a[int(y)+1][int(x)]=pen;
		a[int(y)+1][int(x)+2]=pen;
		a[int(y)-1][int(x)+2]=pen;
		if(x>3)
		{
			for(i=x-4;i<x+5;i++)
				a[int(y)][i]=pen;
		}
		else
		{
			for(i=0;i<x+5;i++)
				a[int(y)][i]=pen;
		}
		if(x>1)
		{
			for(i=x-2;i<x+3;i++)
			{
				a[int(y)+1][i]=pen;
				a[int(y)-1][i]=pen;
			}
		}
		else
		{
			for(i=0;i<x+3;i++)
			{
				a[int(y)+1][i]=pen;
				a[int(y)-1][i]=pen;
			}
		}
		return;
	}
		
	for(j=0;j<24;j++)
	{
		min1=5;
		t=0;
		for(i=0;i<80;i++)
		{
			if(ghadremotlagh((.1*((double)i-x)*((double)i-x)+((double)j-y)*((double)j-y))-(r*r))<min1)
			{
				min1=ghadremotlagh((.1*((double)i-x)*((double)i-x)+((double)j-y)*((double)j-y))-(r*r));
				m=i;
				t=1;
			}
		}
		if(t==1)
		{
			if(m<x)
			{
				a[j][m]=pen;
				if(int(2*x)-m<80)
					a[j][int(2*x)-m]=pen;
			}
			if(m>x)
				a[j][m]=pen;
		}
		if(y>=r)
			a[int(y)-int(r)][int(x)]=pen;
		a[int(y)+int(r)][int(x)]=pen;
		if(int(x)<=1)
		{
			if(r>2)
			{
				if(y>=r)
				{
					for(i=0;i<x+4;i++)
						a[int(y)-int(r)][i]=pen;
				}
				for(i=0;i<x+4;i++)
					a[int(y)+int(r)][i]=pen;
			}
			if(r==2)
			{
				if(y>=r)
				{
					for(i=0;i<x+3;i++)
						a[int(y)-int(r)][i]=pen;
				}
				for(i=0;i<x+3;i++)
					a[int(y)+int(r)][i]=pen;
			}
		}
		for(i=0;i<80;i++)
		{
			if(a[j][i]==pen)
				h=1;
		}
		if((h==1)&&(j<=y+r))
		{
			if(m<x&&int(2*x)-m<80)
			{
				for(i=m+1;i<(int(2*x)-m);i++)
					a[j][i]=pen;
			}
			if(m>x)
			{
				for(i=0;i<m;i++)
					a[j][i]=pen;
			}
			if(int(2*x)-m>79)
			{
				for(i=m+1;i<80;i++)
					a[j][i]=pen;
			}
		}
	}
}
void rectangle(int x,int y,int w,int h,char pen)
{
	if(x+w-1<80)
		line(x,y,x+w-1,y,pen);
	else
		line(x,y,79,y,pen);
	if(x+w-1<80)
		line(x+w-1,y,x+w-1,y+h-1,pen);
	if(x+w-1<80)
		line(x+w-1,y+h-1,x,y+h-1,pen);
	else
		line(79,y+h-1,x,y+h-1,pen);
	line(x,y+h-1,x,y,pen);
}
void fillrectangle(int x,int y,int w,int h,char pen)
{
	int i;
	for(i=0;i<h;i++)
	{
		if(x+w-1<80)
			line(x,y+i,x+w-1,y+i,pen);
		else
			line(x,y+i,79,y+i,pen);
	}
}
void polygon(int n,int b[100],int c[100],char pen)
{
	int i;
	for(i=0;i<n-1;i++)
		line(b[i],c[i],b[i+1],c[i+1],pen);
	line(b[i],c[i],b[0],c[0],pen);
}
void fillpolygon(int n,int b[100],int c[100],char pen)
{
	int i=0,j=0,k,e,f,t;
	char d[24][80];
	for(i=0;i<80;i++)
	{
		for(j=0;j<24;j++)
		{
			if(a[j][i]==pen)
			{
				a[j][i]=NULL;
				d[j][i]=pen;
			}
		}
	}
	polygon(n,b,c,pen);
	for(j=0;j<24;j++)
	{
		k=0;
		t=0;
		for(i=0;i<80;i++)
		{
			if((a[j][i]==pen)&&(k==0))
			{
				e=i;
				k=1;
			}
			if((a[j][i]==pen)&&(k==1))
			{
				f=i;
				t=1;
			}
		}
		if(k==1,t==1)
			line(e,j,f,j,pen);
	}
	for(i=0;i<80;i++)
	{
		for(j=0;j<24;j++)
		{
			if(d[j][i]==pen)
			{
				a[j][i]=pen;
			}
		}
	}
}
void text(int x,int y,int direction,char *b)
{
	char c[100]={NULL};
	int i=0,l;
	while(*(b+i)!=NULL)
	{
		l=i;
		i++;
	}
	if(x+l<=79)
	{
		i=0;
		if(direction==1)
		{
			while(*(b+i)!=NULL)
			{
				a[y][x+i]=*(b+i);
				i++;
			}
		}
		else
		{
			while(*(b+i)!=NULL)
			{
				a[y+i][x]=*(b+i);
				i++;
			}
		}
		return;
	}
	if(x+l>79&&direction==1)
	{
		for(i=0;i<80-x;i++)
			c[i]=b[i];
		text(x,y,direction,c);
		return;
	}
}
void display()
{
	int i,j;
	for(j=0;j<24;j++)
	{
		for(i=0;i<80;i++)
			cout<<a[j][i];
		cout<<endl;
	}
}
void clear()
{
	int i,j;
	for(i=0;i<80;i++)
	{
		for(j=0;j<24;j++)
			a[j][i]=' ';
	}
}
//-----------------------------------
int stringToInt(string str);
char stringtochar(int i,int j,vector<string> vec)
{
	char a=vec[i][j];
	return a;
}
int Choose_Form(vector<string> vec)
{
	if(vec[0]=="outline")
	{
		cond=1;
		return 1;
	}
	else if(vec[0]=="fill")
	{
		cond=-1;
		return 1;
	}
	else if(vec[0]=="pen")
	{
		pen1=stringtochar(1,0,vec);
		return 1;
	}
	else if(vec[0]=="rectangle")
	{
		int x1=stringToInt(vec[1]);
		int y1=stringToInt(vec[2]);
		int w1=stringToInt(vec[3]);
		int h1=stringToInt(vec[4]);
		if(cond==1)
			rectangle(x1,y1,w1,h1,pen1);
		else
			fillrectangle(x1,y1,w1,h1,pen1);
		return 1;
	}
	else if(vec[0]=="line")
	{
		int sx=stringToInt(vec[1]);
		int sy=stringToInt(vec[2]);
		int ex=stringToInt(vec[3]);
		int ey=stringToInt(vec[4]);
		line(sx,sy,ex,ey,pen1);
		return 1;
	}
	else if(vec[0]=="circle")
	{
		int x1=stringToInt(vec[1]);
		int y1=stringToInt(vec[2]);
		int r1=stringToInt(vec[3]);
		if(cond==1)
			circle(x1,y1,r1,pen1);
		else
			fillcircle(x1,y1,r1,pen1);
		return 1;
	}
	else if(vec[0]=="polygon")
	{
		int b[100]={NULL};
		int c[100]={NULL};
		int n=stringToInt(vec[1]);
		for(int i=0;i<n;i++)
		{
			b[i]=stringToInt(vec[2*i+2]);
			c[i]=stringToInt(vec[2*i+3]);
		}
		if(cond==1)
			polygon(n,b,c,pen1);
		else
			fillpolygon(n,b,c,pen1);
		return 1;
	}
	else if(vec[0]=="text")
	{
		int x1=stringToInt(vec[1]);
		int y1=stringToInt(vec[2]);
		int dir=stringToInt(vec[3]);
		char b[100]={NULL};
		int i1;
		for(i1=0;i1<vec[4].length();i1++)
			*(b+i1)=stringtochar(4,i1,vec);
		text(x1,y1,dir,b);
		return 1;
	}
	else if(vec[0]=="display")
	{
		display();
		return 1;
	}
	else if(vec[0]=="clear")
	{
		clear();
		return 1;
	}
	return 0;
}
//----------------------------------
void quick(vector<double> &vec,int start,int end)
{
	if(start<end)
	{
	int index=start;
	double t;
	for(int i=start;i<end;i++)
		if(vec[i]<vec[end])
		{
			t=vec[i];
			vec[i]=vec[index];
			vec[index]=t;
			index++;
		}
		t=vec[index];
		vec[index]=vec[end];
		vec[end]=t;
		quick(vec,index+1,end);
		quick(vec,start,index-1);
	}
}
vector<string> tokenize(string str)//the function that seperates a line into its words
{
	vector<string> vec;
	if(str=="")
		return vec;
	for(int i=0;i<str.length()-1;i++)
		if(str[i]==' ' && str[i+1]==' ')
		{
			str.replace(i,2," ");
			i--;
		}
	int start=0;
	int temp=str.find(" ",start);
	while(temp>=0)
	{
		vec.push_back(str.substr(start,temp-start));
		start=temp+1;
		temp=str.find(" ",start);
	}
	vec.push_back(str.substr(start,str.length()-start));
	return vec;
}
int stringToInt(string str)
{
	int s=0;
	for(int i=0;i<str.length();i++)
	{
		s*=10;
		s+=str[i]-'0';
	}
	return s;
}
double stringToDouble(string value)
{
		if(value.find(".")<value.length())
		{
			string a;
			a=value.substr(0,value.find("."));
			string b;
			b=value.substr(value.find(".")+1,value.length()-value.find(".")-1);
			int x=stringToInt(a);
			double y=stringToInt(b);
			while( y>=1)
				y/=10;
			y+=x;
			return y;
		}
		else
			return stringToInt(value);
	}
string IntToString(int x)
{
	string s;
	if(!x)
		s="0";
	while(x>0)
	{
		s.push_back(x%10+'0');
		x/=10;
	}
	char t;
	for(int i=0;i<s.length()/2;i++)
	{
		t=s[i];
		s[i]=s[s.length()-1-i];
		s[s.length()-1-i]=t;
	}
	return s;
}
string doubleToString(double d)
{
	string s=IntToString((int)d);
	if(d-(int)d)
	{
		d-=(int)d;
		int i=0;
		while((d-(int)d) && i<5)
		{
			d*=10;
			i++;
		}
		s+="."+IntToString(d);
	}
	return s;
}
class variable
{
      public:
	         string name;
             string value;
	         string type;
	         double getNumeriacalValue()
	         {
		            return stringToDouble(value);
             }
};
class collection
{
      public:
	         vector<variable *> vec;
	         string name;
	         string type;
	         string output()
	         {
		            string s="{";
		            for(int i=0;i<vec.size();i++)
		            	s+=vec[i]->value+",";
                    s=s.substr(0,s.length()-1);
                    s+="}";
		            return s;
             }
};
class file
{
      public:
	         string fileName;
             string name;
};
string minusString(string s1,string s2)
{
	while(s1.find(s2)<s1.length())
	{
		s1.replace(s1.find(s2),s2.length(),"");
	}
	return s1;
}
float avg(collection * c)
{
	float a=0;
	for(int i=0;i<c->vec.size();i++)
		a+=c->vec[i]->getNumeriacalValue();
	a/=c->vec.size();
	return a;
}
float variance(collection * c)
{
      	float a=0;
      	for(int i=0;i<c->vec.size();i++)
      	     a+=(c->vec[i]->getNumeriacalValue())*(c->vec[i]->getNumeriacalValue());
        a/=c->vec.size();
        a-=((avg(c))*(avg(c)));
        return a;
}
float sum(collection * c)
{
      
      	float a=0;
      	for(int i=0;i<c->vec.size();i++)
             a+=c->vec[i]->getNumeriacalValue();
        return a;
}
int main()
{
	cout << " _ _ _  ___   ____ ____" << endl;
    cout << "| | | |/ _ \\ / ___)    \\ " << endl;
    cout << "| | | | |_| | |   | | | |" << endl;
    cout << " \\____|\\___/|_|   |_|_|_|" << endl << endl;
	vector<string> vec;
	vector<variable *> var;
	vector<collection *> col;
	vector<file *> files;
	int c2;
	while(true)
    {
        string command;
        cout << ">>> ";
        getline(cin,command);
		vec=tokenize(command);
		c2=Choose_Form(vec);
		if(c2==0)
		{
		if(vec.size()>=3 && vec[1]=="=" && vec[2]=="avg")
		{
			for(int i=0;i<col.size();i++)
				if(col[i]->name==vec[3])
				{
					variable *v=NULL;
					for(int j=0;j<var.size();j++)
						if(var[j]->name==vec[0])
						v=var[j];
						for(int j=0;j<col.size();j++)
							for(int k=0;k<col[j]->vec.size();k++)
								if(col[j]->vec[k]->name==vec[0])
									v=col[j]->vec[k];
						if(v==NULL)
						{
							var.push_back(new variable);
							v=var[var.size()-1];
							v->name=vec[0];
						}
						double x=avg(col[i]);
						if(x-(int)x)
					v->type="double";
				else
					v->type="int";
				v->value=doubleToString(x);
								break;
				}
		}
		else if(vec.size()>=3 && vec[1]=="=" && vec[2]=="var")
		{
			for(int i=0;i<col.size();i++)
				if(col[i]->name==vec[3])
				{
					variable *v=NULL;
					for(int j=0;j<var.size();j++)
						if(var[j]->name==vec[0])
						v=var[j];
						for(int j=0;j<col.size();j++)
							for(int k=0;k<col[j]->vec.size();k++)
								if(col[j]->vec[k]->name==vec[0])
									v=col[j]->vec[k];
						if(v==NULL)
						{
							var.push_back(new variable);
							v=var[var.size()-1];
							v->name=vec[0];
						}
						v->type="double";
						v->value=doubleToString(variance(col[i]));
								break;
				}
		}
		else if(vec.size()>=3 && vec[1]=="=" && vec[2]=="sum")
		{
			for(int i=0;i<col.size();i++)
				if(col[i]->name==vec[3])
				{
					variable *v=NULL;
					for(int j=0;j<var.size();j++)
						if(var[j]->name==vec[0])
						v=var[j];
						for(int j=0;j<col.size();j++)
							for(int k=0;k<col[j]->vec.size();k++)
								if(col[j]->vec[k]->name==vec[0])
									v=col[j]->vec[k];
						if(v==NULL)
						{
							var.push_back(new variable);
							v=var[var.size()-1];
							v->name=vec[0];
						}
						v->type="double";
						v->value=doubleToString(sum(col[i]));
								break;
				}
		}
		else if(vec.size()>=3 && vec[1]=="=" && vec[2]=="max")
		{
			double t;
			if(vec[4][0]>='0' && vec[4][0]<='9')
				t=stringToInt(vec[4]);
			else
			{
				variable *v=NULL;
					for(int j=0;j<var.size();j++)
						if(var[j]->name==vec[0])
						v=var[j];
						for(int j=0;j<col.size();j++)
							for(int k=0;k<col[j]->vec.size();k++)
								if(col[j]->vec[k]->name==vec[0])
									v=col[j]->vec[k];
						t=v->getNumeriacalValue();

			}
			for(int i=0;i<col.size();i++)
				if(col[i]->name==vec[3])
				{
					vector<double> d;
					for(int j=0;j<col[i]->vec.size();j++)
						d.push_back(col[i]->vec[j]->getNumeriacalValue());
					quick(d,0,col[i]->vec.size()-1);
					t=d[d.size()-t];
					break;
				}
				variable *v=NULL;
					for(int j=0;j<var.size();j++)
						if(var[j]->name==vec[0])
						v=var[j];
						for(int j=0;j<col.size();j++)
							for(int k=0;k<col[j]->vec.size();k++)
								if(col[j]->vec[k]->name==vec[0])
									v=col[j]->vec[k];
						if(v==NULL)
						{
							var.push_back(new variable);
							v=var[var.size()-1];
							v->name=vec[0];
						}
						if(t-(int)t)
					v->type="double";
				else
					v->type="int";
						v->value=doubleToString(t);

		}
				else if(vec.size()>=3 && vec[1]=="=" && vec[2]=="min")
		{
			double t;
			if(vec[4][0]>='0' && vec[4][0]<='9')
				t=stringToInt(vec[4]);
			else
			{
				variable *v=NULL;
					for(int j=0;j<var.size();j++)
						if(var[j]->name==vec[0])
						v=var[j];
						for(int j=0;j<col.size();j++)
							for(int k=0;k<col[j]->vec.size();k++)
								if(col[j]->vec[k]->name==vec[0])
									v=col[j]->vec[k];
						t=v->getNumeriacalValue();

			}
			for(int i=0;i<col.size();i++)
				if(col[i]->name==vec[3])
				{
					vector<double> d;
					for(int j=0;j<col[i]->vec.size();j++)
						d.push_back(col[i]->vec[j]->getNumeriacalValue());
					quick(d,0,col[i]->vec.size()-1);
					t=d[t-1];
					break;
				}
				variable *v=NULL;
					for(int j=0;j<var.size();j++)
						if(var[j]->name==vec[0])
						v=var[j];
						for(int j=0;j<col.size();j++)
							for(int k=0;k<col[j]->vec.size();k++)
								if(col[j]->vec[k]->name==vec[0])
									v=col[j]->vec[k];
						if(v==NULL)
						{
							var.push_back(new variable);
							v=var[var.size()-1];
							v->name=vec[0];
						}
						if(t-(int)t)
					v->type="double";
				else
					v->type="int";
						v->value=doubleToString(t);

		}
		else if(vec.size()>=3 && vec[1]=="=" && vec[2]=="file")
		{
			files.push_back(new file);
			files[files.size()-1]->name=vec[0];
			files[files.size()-1]->fileName=vec[3];
		}
		else if(vec.size()>=3 && vec[1]=="=" && vec[2]=="array")
		{
			int n=stringToInt(vec[4]);
			col.push_back(new collection);
			col[col.size()-1]->name=vec[0];
			col[col.size()-1]->type=vec[3];
			string str;
			for(int i=0;i<n;i++)
			{
				cout<<vec[0]<<":"<<i<<"?";
				getline(cin,str);
				col[col.size()-1]->vec.push_back(new variable);
				col[col.size()-1]->vec[col[col.size()-1]->vec.size()-1]->type=col[col.size()-1]->type;
				col[col.size()-1]->vec[col[col.size()-1]->vec.size()-1]->name=vec[0]+":"+IntToString(i);
				col[col.size()-1]->vec[col[col.size()-1]->vec.size()-1]->value=str;
				if(col[col.size()-1]->vec[col[col.size()-1]->vec.size()-1]->type=="string")
					col[col.size()-1]->vec[col[col.size()-1]->vec.size()-1]->value=col[col.size()-1]->vec[col[col.size()-1]->vec.size()-1]->value.substr(1,col[col.size()-1]->vec[col[col.size()-1]->vec.size()-1]->value.length()-2);
			}
			
		}
		else if(vec.size()>=3 && vec[1]=="=")
		{
			int l=-1;
			for(l=0;l<col.size();l++)
				if(col[l]->name==vec[2])
				{
					collection *c=new collection;
					c->name=vec[0];
					c->type=col[l]->type;
					for(int i=0;i<col[l]->vec.size();i++)
						c->vec.push_back(col[l]->vec[i]);
					if(vec[3]=="+")
					{
						for(int j=0;j<col.size();j++)
							if(vec[4]==col[j]->name)
							{
								for(int i=0;i<col[j]->vec.size();i++)
						c->vec.push_back(col[j]->vec[i]);
							}
					}
					col.push_back(c);
					break;
				}
				if(l==col.size())
				{
			variable *v=NULL;
			for(int i=0;i<var.size();i++)
				if(var[i]->name==vec[0])
					v=var[i];
			for(int i=0;i<col.size();i++)
				for(int j=0;j<col[i]->vec.size();j++)
					if(col[i]->vec[j]->name==vec[0])
						v=col[i]->vec[j];
			if(v==NULL)
			{
				var.push_back(new variable);
				v=var[var.size()-1];
				v->name=vec[0];
			}
			double x=0,x1=0;
			string y,y1;
			if(vec[2][0]>='0' && vec[2][0]<='9')
			{
				x=stringToDouble(vec[2]);
				if(vec[2].find(".")<vec[2].length())
					v->type="double";
				else
					v->type="int";
			}
			else if(vec[2][0]=='"')
			{
				y=vec[2];
				for(int k=3;k<vec.size();k++)
					y+=" "+vec[k];
				y=y.substr(1,y.length()-2);
				v->type="string";
			}
			else
			{
			variable *u=NULL;
			for(int i=0;i<var.size();i++)
				if(var[i]->name==vec[2])
					u=var[i];
			for(int i=0;i<col.size();i++)
				for(int j=0;j<col[i]->vec.size();j++)
					if(col[i]->vec[j]->name==vec[2])
						u=col[i]->vec[j];
			if(u==NULL)
			{
				cout<<"\'"<<vec[2]<<"\' is not defined."<<endl;
				continue;
			}
			else if(u->type=="string")
				y=u->value;
			else
				x=u->getNumeriacalValue();
			v->type=u->type;
			}
			if(vec.size()==5)
			{
			if(vec[4][0]>='0' && vec[4][0]<='9')
			{
				x1=stringToDouble(vec[4]);
			}
			else
			{
			variable *u=NULL;
			for(int i=0;i<var.size();i++)
				if(var[i]->name==vec[4])
					u=var[i];
			for(int i=0;i<col.size();i++)
				for(int j=0;j<col[i]->vec.size();j++)
					if(col[i]->vec[j]->name==vec[4])
						u=col[i]->vec[j];
			if(u==NULL)
			{
				cout<<"\'"<<vec[4]<<"\' is not defined."<<endl;
				break;
			}
			else if(u->type=="string")
				y1=u->value;
			else
				x1=u->getNumeriacalValue();
			}
			if(vec[3]=="+")
			{
				y+=y1;
				x+=x1;
			}
			else	if(vec[3]=="-")
			{
				x-=x1;
				y=minusString(y,y1);
			}
			else if(vec[3]=="*")
				x*=x1;
			else if(vec[3]=="/")
				x/=x1;
			}
			if(v->type=="string")
				v->value=y;
			else
			{
				if(x-(int)x)
					v->type="double";
				else
					v->type="int";
				v->value=doubleToString(x);
			}
			}
		}
		else if(vec[0]=="bye")
			return 0;
		else if(vec[0]=="about")
			cout<<"nader beigiparast & amirpedram bamoniri & ali rasteh"<<endl;
		else if(vec.size()==1)
		{
			int i;
			for(i=0;i<var.size();i++)
				if(var[i]->name==vec[0])
					break;
			if(i==var.size())
			{
				int j;
				for(j=0;j<col.size();j++)
					if(col[j]->name==vec[0])
						break;
				if(j==col.size())
					cout<<"\'"<<vec[0]<<"\' is not defined."<<endl;
				else
					cout<<col[j]->name<<" ("<<col[j]->type<<"): "<<col[j]->output()<<endl;
			}
				
			else
				cout<<var[i]->name<<" ("<<var[i]->type<<"): "<<((var[i]->type=="string")?"\"":"")<<var[i]->value<<((var[i]->type=="string")?"\"":"")<<endl;
		}
		else if(vec[0]=="input")
		{
			variable *v=NULL;
			for(int i=0;i<var.size();i++)
				if(var[i]->name==vec[1])
					v=var[i];
			for(int i=0;i<col.size();i++)
				for(int j=0;j<col[i]->vec.size();j++)
					if(col[i]->vec[j]->name==vec[1])
						v=col[i]->vec[j];
			if(v==NULL)
				cout<<"\'"<<vec[1]<<"\' is not defined."<<endl;
			else
			{
				string str;
				for(int k=2;k<vec.size();k++)
					str+=vec[k]+" ";
				str=str.substr(1,str.length()-3);
				cout<<str;
				getline(cin,str);
				v->value=str;
				if(v->type=="string")
					v->value=v->value.substr(1,v->value.length()-2);
			}

		}
		else if(vec[0]=="output")
		{
			for(int i=1;i<vec.size();i++)
			{
				if(vec[i][0]<='9' && vec[i][0]>='0')
					cout<<vec[i]<<" ";
				else
				{
					for(int j=0;j<var.size();j++)
						if(var[j]->name==vec[i])
							cout<<var[j]->value<<" ";
					for(int j=0;j<col.size();j++)
						if(col[j]->name==vec[i])
							cout<<col[j]->output()<<" ";
					for(int j=0;j<col.size();j++)
						for(int k=0;k<col[j]->vec.size();k++)
						if(col[j]->vec[k]->name==vec[i])
							cout<<col[j]->vec[k]->value<<" ";
				}
			}
			cout<<endl;
		}
		else if(vec[0]=="for" && vec[2]=="in")
		{
			for(int i=0;i<col.size();i++)
				if(vec[3]==col[i]->name)
				{
					if(vec[4]=="input")
					{
						for(int j=0;j<col[i]->vec.size();j++)
						{
							getline(cin,col[i]->vec[j]->value);
							if(col[i]->type=="string")
								col[i]->vec[j]->value=col[i]->vec[j]->value.substr(1,col[i]->vec[j]->value.length()-2);

						}
					}
					else if(vec[4]=="output")
					{
						for(int j=0;j<col[i]->vec.size();j++)
							cout<<((col[i]->vec[j]->type=="string")?"\"":"")<<col[i]->vec[j]->value<<((col[i]->vec[j]->type=="string")?"\"":"")<<endl;
					}
					else if(vec[4]=="write")
					{
						for(int k=0;k<files.size();k++)
							if(files[k]->name==vec[5])
							{
								ofstream fout(files[k]->fileName,ios::app);
						        for(int j=0;j<col[i]->vec.size();j++)
							    fout<<((col[i]->vec[j]->type=="string")?"\"":"")<<col[i]->vec[j]->value<<((col[i]->vec[j]->type=="string")?"\"":"")<<endl;
							    fout.close();
							    break;
							}
					}
					break;
				}
		}
		else if(vec[0]=="read")
		{
			for(int i=0;i<files.size();i++)
				if(files[i]->name==vec[1])
				{
					ifstream fin(files[i]->fileName);
					char ch;
					while(!fin.eof())
					{
						fin.get(ch);
						cout<<ch;
					}
					fin.close();
					break;
				}
		}
		else if(vec[0]=="write")
		{
			for(int l=0;l<files.size();l++)
				if(files[l]->name==vec[1])
				{
					ofstream fout(files[l]->fileName,ios::app);
					for(int i=2;i<vec.size();i++)
			{
				if(vec[i][0]<='9' && vec[i][0]>='0')
					fout<<vec[i]<<" ";
				else
				{
					for(int j=0;j<var.size();j++)
						if(var[j]->name==vec[i])
				
							fout<<var[j]->value<<" ";
					for(int j=0;j<col.size();j++)
						if(col[j]->name==vec[i])
							fout<<col[j]->output()<<" ";
					for(int j=0;j<col.size();j++)
						for(int k=0;k<col[j]->vec.size();k++)
						if(col[j]->vec[k]->name==vec[i])
							fout<<col[j]->vec[k]->value<<" ";
				}
			}
			fout<<endl;
			fout.close();
			break;
				}
		}
		else if(vec[0]=="upper")
		{
			for(int i=0;i<var.size();i++)
				if(var[i]->name==vec[1])
				{
					for(int j=0;j<var[i]->value.length();j++)
						if(var[i]->value[j]>='a' && var[i]->value[j]<='z')
							var[i]->value[j]+='A'-'a';
				}
				for(int i=0;i<col.size();i++)
					for(int j=0;j<col[i]->vec.size();j++)
						for(int k=0;k<col[i]->vec[j]->value.length();k++)
							if(col[i]->vec[j]->value[k]>='a' &&  col[i]->vec[j]->value[k]<='z')
								col[i]->vec[j]->value[k]+='A'-'a';
		}
		else if(vec[0]=="lower")
		{
			for(int i=0;i<var.size();i++)
				if(var[i]->name==vec[1])
				{
					for(int j=0;j<var[i]->value.length();j++)
						if(var[i]->value[j]>='A' && var[i]->value[j]<='Z')
							var[i]->value[j]+='a'-'A';
				}
				for(int i=0;i<col.size();i++)
					for(int j=0;j<col[i]->vec.size();j++)
						for(int k=0;k<col[i]->vec[j]->value.length();k++)
							if(col[i]->vec[j]->value[k]>='A' &&  col[i]->vec[j]->value[k]<='Z')
								col[i]->vec[j]->value[k]+='a'-'A';
		}
		else if(vec[0]=="title")
		{
			for(int i=0;i<var.size();i++)
				if(var[i]->name==vec[1])
				{
					for(int j=0;j<var[i]->value.length();j++)
						if(var[i]->value[0]>='a' && var[i]->value[j]<='z')
							var[i]->value[0]+='A'-'a';
				}
				for(int i=0;i<col.size();i++)
					for(int j=0;j<col[i]->vec.size();j++)
						for(int k=0;k<col[i]->vec[j]->value.length();k++)
							if(col[i]->vec[j]->value[0]>='a' &&  col[i]->vec[j]->value[0]<='z')
								col[i]->vec[j]->value[0]+='A'-'a';
		}
        else if(vec[0]=="sort")
		{
			for(int i=0;i<col.size();i++)
			{
				if(col[i]->name==vec[1])
				{
					vector<double> d;
					for(int j=0;j<col[i]->vec.size();j++)
						d.push_back(col[i]->vec[j]->getNumeriacalValue());
					quick(d,0,d.size()-1);
					for(int j=0;j<col[i]->vec.size();j++)
						col[i]->vec[j]->value=doubleToString(d[j]);
					break;
				}
			}
		}
		else if(vec[0]=="shuffle")
		{
			for(int i=0;i<col.size();i++)
				if(col[i]->name==vec[1])
				{
					srand(time(0));
					for(int j=0;j<col[i]->vec.size();j++)
					{
						int a=rand()%col[i]->vec.size();
						int b=rand()%col[i]->vec.size();
						variable* t=col[i]->vec[a];
						col[i]->vec[a]=col[i]->vec[b];
						col[i]->vec[b]=t;

					}
					break;
				}
		}
		else if(vec[0]=="run")
		{
			ifstream f_run(vec[1]);
	while(!f_run.eof())
    {
		vector<string> vec;
        string command;
        getline(f_run,command);
		vec=tokenize(command);
		Choose_Form(vec);
		if(vec.size()>=3 && vec[1]=="=" && vec[2]=="avg")
		{
			for(int i=0;i<col.size();i++)
				if(col[i]->name==vec[3])
				{
					variable *v=NULL;
					for(int j=0;j<var.size();j++)
						if(var[j]->name==vec[0])
						v=var[j];
						for(int j=0;j<col.size();j++)
							for(int k=0;k<col[j]->vec.size();k++)
								if(col[j]->vec[k]->name==vec[0])
									v=col[j]->vec[k];
						if(v==NULL)
						{
							var.push_back(new variable);
							v=var[var.size()-1];
							v->name=vec[0];
						}
						double x=avg(col[i]);
						if(x-(int)x)
					v->type="double";
				else
					v->type="int";
				v->value=doubleToString(x);
								break;
				}
		}
		else if(vec.size()>=3 && vec[1]=="=" && vec[2]=="var")
		{
			for(int i=0;i<col.size();i++)
				if(col[i]->name==vec[3])
				{
					variable *v=NULL;
					for(int j=0;j<var.size();j++)
						if(var[j]->name==vec[0])
						v=var[j];
						for(int j=0;j<col.size();j++)
							for(int k=0;k<col[j]->vec.size();k++)
								if(col[j]->vec[k]->name==vec[0])
									v=col[j]->vec[k];
						if(v==NULL)
						{
							var.push_back(new variable);
							v=var[var.size()-1];
							v->name=vec[0];
						}
						v->type="double";
						v->value=doubleToString(variance(col[i]));
								break;
				}
		}
		else if(vec.size()>=3 && vec[1]=="=" && vec[2]=="sum")
		{
			for(int i=0;i<col.size();i++)
				if(col[i]->name==vec[3])
				{
					variable *v=NULL;
					for(int j=0;j<var.size();j++)
						if(var[j]->name==vec[0])
						v=var[j];
						for(int j=0;j<col.size();j++)
							for(int k=0;k<col[j]->vec.size();k++)
								if(col[j]->vec[k]->name==vec[0])
									v=col[j]->vec[k];
						if(v==NULL)
						{
							var.push_back(new variable);
							v=var[var.size()-1];
							v->name=vec[0];
						}
						v->type="double";
						v->value=doubleToString(sum(col[i]));
								break;
				}
		}
		else if(vec.size()>=3 && vec[1]=="=" && vec[2]=="max")
		{
			double t;
			if(vec[4][0]>='0' && vec[4][0]<='9')
				t=stringToInt(vec[4]);
			else
			{
				variable *v=NULL;
					for(int j=0;j<var.size();j++)
						if(var[j]->name==vec[0])
						v=var[j];
						for(int j=0;j<col.size();j++)
							for(int k=0;k<col[j]->vec.size();k++)
								if(col[j]->vec[k]->name==vec[0])
									v=col[j]->vec[k];
						t=v->getNumeriacalValue();

			}
			for(int i=0;i<col.size();i++)
				if(col[i]->name==vec[3])
				{
					vector<double> d;
					for(int j=0;j<col[i]->vec.size();j++)
						d.push_back(col[i]->vec[j]->getNumeriacalValue());
					quick(d,0,col[i]->vec.size()-1);
					t=d[d.size()-t];
					break;
				}
				variable *v=NULL;
					for(int j=0;j<var.size();j++)
						if(var[j]->name==vec[0])
						v=var[j];
						for(int j=0;j<col.size();j++)
							for(int k=0;k<col[j]->vec.size();k++)
								if(col[j]->vec[k]->name==vec[0])
									v=col[j]->vec[k];
						if(v==NULL)
						{
							var.push_back(new variable);
							v=var[var.size()-1];
							v->name=vec[0];
						}
						if(t-(int)t)
					v->type="double";
				else
					v->type="int";
						v->value=doubleToString(t);

		}
				else if(vec.size()>=3 && vec[1]=="=" && vec[2]=="min")
		{
			double t;
			if(vec[4][0]>='0' && vec[4][0]<='9')
				t=stringToInt(vec[4]);
			else
			{
				variable *v=NULL;
					for(int j=0;j<var.size();j++)
						if(var[j]->name==vec[0])
						v=var[j];
						for(int j=0;j<col.size();j++)
							for(int k=0;k<col[j]->vec.size();k++)
								if(col[j]->vec[k]->name==vec[0])
									v=col[j]->vec[k];
						t=v->getNumeriacalValue();

			}
			for(int i=0;i<col.size();i++)
				if(col[i]->name==vec[3])
				{
					vector<double> d;
					for(int j=0;j<col[i]->vec.size();j++)
						d.push_back(col[i]->vec[j]->getNumeriacalValue());
					quick(d,0,col[i]->vec.size()-1);
					t=d[t-1];
					break;
				}
				variable *v=NULL;
					for(int j=0;j<var.size();j++)
						if(var[j]->name==vec[0])
						v=var[j];
						for(int j=0;j<col.size();j++)
							for(int k=0;k<col[j]->vec.size();k++)
								if(col[j]->vec[k]->name==vec[0])
									v=col[j]->vec[k];
						if(v==NULL)
						{
							var.push_back(new variable);
							v=var[var.size()-1];
							v->name=vec[0];
						}
						if(t-(int)t)
					v->type="double";
				else
					v->type="int";
						v->value=doubleToString(t);

		}
		else if(vec.size()>=3 && vec[1]=="=" && vec[2]=="file")
		{
			files.push_back(new file);
			files[files.size()-1]->name=vec[0];
			files[files.size()-1]->fileName=vec[3];
		}
		else if(vec.size()>=3 && vec[1]=="=" && vec[2]=="array")
		{
			int n=stringToInt(vec[4]);
			col.push_back(new collection);
			col[col.size()-1]->name=vec[0];
			col[col.size()-1]->type=vec[3];
			string str;
			for(int i=0;i<n;i++)
			{
				cout<<vec[0]<<":"<<i<<"?";
				getline(cin,str);
				col[col.size()-1]->vec.push_back(new variable);
				col[col.size()-1]->vec[col[col.size()-1]->vec.size()-1]->type=col[col.size()-1]->type;
				col[col.size()-1]->vec[col[col.size()-1]->vec.size()-1]->name=vec[0]+":"+IntToString(i);
				col[col.size()-1]->vec[col[col.size()-1]->vec.size()-1]->value=str;
				if(col[col.size()-1]->vec[col[col.size()-1]->vec.size()-1]->type=="string")
					col[col.size()-1]->vec[col[col.size()-1]->vec.size()-1]->value=col[col.size()-1]->vec[col[col.size()-1]->vec.size()-1]->value.substr(1,col[col.size()-1]->vec[col[col.size()-1]->vec.size()-1]->value.length()-2);
			}
			
		}
		else if(vec.size()>=3 && vec[1]=="=")
		{
					int l=-1;
			for(l=0;l<col.size();l++)
				if(col[l]->name==vec[2])
				{
					collection *c=new collection;
					c->name=vec[0];
					c->type=col[l]->type;
					for(int i=0;i<col[l]->vec.size();i++)
						c->vec.push_back(col[l]->vec[i]);
					if(vec[3]=="+")
					{
						for(int j=0;j<col.size();j++)
							if(vec[4]==col[j]->name)
							{
								for(int i=0;i<col[j]->vec.size();i++)
						c->vec.push_back(col[j]->vec[i]);
							}
					}
					col.push_back(c);
					break;
				}
				if(l==col.size())
				{
					variable *v=NULL;
			for(int i=0;i<var.size();i++)
				if(var[i]->name==vec[0])
					v=var[i];
			for(int i=0;i<col.size();i++)
				for(int j=0;j<col[i]->vec.size();j++)
					if(col[i]->vec[j]->name==vec[0])
						v=col[i]->vec[j];
			if(v==NULL)
			{
				var.push_back(new variable);
				v=var[var.size()-1];
				v->name=vec[0];
			}
			double x=0,x1=0;
			string y,y1;
			if(vec[2][0]>='0' && vec[2][0]<='9')
			{
				x=stringToDouble(vec[2]);
				if(vec[2].find(".")<vec[2].length())
					v->type="double";
				else
					v->type="int";
			}
			else if(vec[2][0]=='"')
			{
				y=vec[2];
				for(int k=3;k<vec.size();k++)
					y+=" "+vec[k];
				y=y.substr(1,y.length()-2);
				v->type="string";
			}
			else
			{
			variable *u=NULL;
			for(int i=0;i<var.size();i++)
				if(var[i]->name==vec[2])
					u=var[i];
			for(int i=0;i<col.size();i++)
				for(int j=0;j<col[i]->vec.size();j++)
					if(col[i]->vec[j]->name==vec[2])
						u=col[i]->vec[j];
			if(u==NULL)
			{
				cout<<"\'"<<vec[2]<<"\' is not defined."<<endl;
				continue;
			}
			else if(u->type=="string")
				y=u->value;
			else
				x=u->getNumeriacalValue();
			v->type=u->type;
			}
			if(vec.size()==5)
			{
			if(vec[4][0]>='0' && vec[4][0]<='9')
			{
				x1=stringToDouble(vec[4]);
			}
			else
			{
			variable *u=NULL;
			for(int i=0;i<var.size();i++)
				if(var[i]->name==vec[4])
					u=var[i];
			for(int i=0;i<col.size();i++)
				for(int j=0;j<col[i]->vec.size();j++)
					if(col[i]->vec[j]->name==vec[4])
						u=col[i]->vec[j];
			if(u==NULL)
			{
				cout<<"\'"<<vec[4]<<"\' is not defined."<<endl;
				break;
			}
			else if(u->type=="string")
				y1=u->value;
			else
				x1=u->getNumeriacalValue();
			}
			if(vec[3]=="+")
			{
				y+=y1;
				x+=x1;
			}
			else	if(vec[3]=="-")
			{
				x-=x1;
				y=minusString(y,y1);
			}
			else if(vec[3]=="*")
				x*=x1;
			else if(vec[3]=="/")
				x/=x1;
			}
			if(v->type=="string")
				v->value=y;
			else
			{
				if(x-(int)x)
					v->type="double";
				else
					v->type="int";
				v->value=doubleToString(x);
			}
			}
		}
		else if(vec[0]=="bye")
			return 0;
		else if(vec[0]=="about")
			cout<<"nader beigiparast & amirpedram bamoniri & ali rasteh"<<endl;
		else if(vec.size()==1)
		{
			int i;
			for(i=0;i<var.size();i++)
				if(var[i]->name==vec[0])
					break;
			if(i==var.size())
			{
				int j;
				for(j=0;j<col.size();j++)
					if(col[j]->name==vec[0])
						break;
				if(j==col.size())
					cout<<"\'"<<vec[0]<<"\' is not defined."<<endl;
				else
					cout<<col[j]->name<<" ("<<col[j]->type<<"): "<<col[j]->output()<<endl;
			}
				
			else
				cout<<var[i]->name<<" ("<<var[i]->type<<"): "<<((var[i]->type=="string")?"\"":"")<<var[i]->value<<((var[i]->type=="string")?"\"":"")<<endl;
		}
		else if(vec[0]=="input")
		{
			variable *v=NULL;
			for(int i=0;i<var.size();i++)
				if(var[i]->name==vec[1])
					v=var[i];
			for(int i=0;i<col.size();i++)
				for(int j=0;j<col[i]->vec.size();j++)
					if(col[i]->vec[j]->name==vec[1])
						v=col[i]->vec[j];
			if(v==NULL)
				cout<<"\'"<<vec[1]<<"\' is not defined."<<endl;
			else
			{
				string str;
				for(int k=2;k<vec.size();k++)
					str+=vec[k]+" ";
				str=str.substr(1,str.length()-3);
				cout<<str;
				getline(cin,str);
				v->value=str;
				if(v->type=="string")
					v->value=v->value.substr(1,v->value.length()-2);
			}

		}
		else if(vec[0]=="output")
		{
			for(int i=1;i<vec.size();i++)
			{
				if(vec[i][0]<='9' && vec[i][0]>='0')
					cout<<vec[i]<<" ";
				else
				{
					for(int j=0;j<var.size();j++)
						if(var[j]->name==vec[i])
							cout<<var[j]->value<<" ";
					for(int j=0;j<col.size();j++)
						if(col[j]->name==vec[i])
							cout<<col[j]->output()<<" ";
					for(int j=0;j<col.size();j++)
						for(int k=0;k<col[j]->vec.size();k++)
						if(col[j]->vec[k]->name==vec[i])
							cout<<col[j]->vec[k]->value<<" ";
				}
			}
			cout<<endl;
		}
		else if(vec[0]=="for" && vec[2]=="in")
		{
			for(int i=0;i<col.size();i++)
				if(vec[3]==col[i]->name)
				{
					if(vec[4]=="input")
					{
						for(int j=0;j<col[i]->vec.size();j++)
						{
							getline(cin,col[i]->vec[j]->value);
							if(col[i]->type=="string")
								col[i]->vec[j]->value=col[i]->vec[j]->value.substr(1,col[i]->vec[j]->value.length()-2);

						}
					}
					else if(vec[4]=="output")
					{
						for(int j=0;j<col[i]->vec.size();j++)
							cout<<((col[i]->vec[j]->type=="string")?"\"":"")<<col[i]->vec[j]->value<<((col[i]->vec[j]->type=="string")?"\"":"")<<endl;
					}
					else if(vec[4]=="write")
					{
						for(int k=0;k<files.size();k++)
							if(files[k]->name==vec[5])
							{
								ofstream fout(files[k]->fileName,ios::app);
						        for(int j=0;j<col[i]->vec.size();j++)
							    fout<<((col[i]->vec[j]->type=="string")?"\"":"")<<col[i]->vec[j]->value<<((col[i]->vec[j]->type=="string")?"\"":"")<<endl;
							    fout.close();
							    break;
							}
					}
					break;
				}
		}
		else if(vec[0]=="read")
		{
			for(int i=0;i<files.size();i++)
				if(files[i]->name==vec[1])
				{
					ifstream fin(files[i]->fileName);
					char ch;
					while(!fin.eof())
					{
						fin.get(ch);
						cout<<ch;
					}
					fin.close();
					break;
				}
		}
		else if(vec[0]=="write")
		{
			for(int l=0;l<files.size();l++)
				if(files[l]->name==vec[1])
				{
					ofstream fout(files[l]->fileName,ios::app);
					for(int i=2;i<vec.size();i++)
			{
				if(vec[i][0]<='9' && vec[i][0]>='0')
					fout<<vec[i]<<" ";
				else
				{
					for(int j=0;j<var.size();j++)
						if(var[j]->name==vec[i])
				
							fout<<var[j]->value<<" ";
					for(int j=0;j<col.size();j++)
						if(col[j]->name==vec[i])
							fout<<col[j]->output()<<" ";
					for(int j=0;j<col.size();j++)
						for(int k=0;k<col[j]->vec.size();k++)
						if(col[j]->vec[k]->name==vec[i])
							fout<<col[j]->vec[k]->value<<" ";
				}
			}
			fout<<endl;
			fout.close();
			break;
				}
		}
		else if(vec[0]=="upper")
		{
			for(int i=0;i<var.size();i++)
				if(var[i]->name==vec[1])
				{
					for(int j=0;j<var[i]->value.length();j++)
						if(var[i]->value[j]>='a' && var[i]->value[j]<='z')
							var[i]->value[j]+='A'-'a';
				}
				for(int i=0;i<col.size();i++)
					for(int j=0;j<col[i]->vec.size();j++)
						for(int k=0;k<col[i]->vec[j]->value.length();k++)
							if(col[i]->vec[j]->value[k]>='a' &&  col[i]->vec[j]->value[k]<='z')
								col[i]->vec[j]->value[k]+='A'-'a';
		}
		else if(vec[0]=="lower")
		{
			for(int i=0;i<var.size();i++)
				if(var[i]->name==vec[1])
				{
					for(int j=0;j<var[i]->value.length();j++)
						if(var[i]->value[j]>='A' && var[i]->value[j]<='Z')
							var[i]->value[j]+='a'-'A';
				}
				for(int i=0;i<col.size();i++)
					for(int j=0;j<col[i]->vec.size();j++)
						for(int k=0;k<col[i]->vec[j]->value.length();k++)
							if(col[i]->vec[j]->value[k]>='A' &&  col[i]->vec[j]->value[k]<='Z')
								col[i]->vec[j]->value[k]+='a'-'A';
		}
		else if(vec[0]=="title")
		{
			for(int i=0;i<var.size();i++)
				if(var[i]->name==vec[1])
				{
					for(int j=0;j<var[i]->value.length();j++)
						if(var[i]->value[0]>='a' && var[i]->value[j]<='z')
							var[i]->value[0]+='A'-'a';
				}
				for(int i=0;i<col.size();i++)
					for(int j=0;j<col[i]->vec.size();j++)
						for(int k=0;k<col[i]->vec[j]->value.length();k++)
							if(col[i]->vec[j]->value[0]>='a' &&  col[i]->vec[j]->value[0]<='z')
								col[i]->vec[j]->value[0]+='A'-'a';
		}
        else if(vec[0]=="sort")
		{
			for(int i=0;i<col.size();i++)
			{
				if(col[i]->name==vec[1])
				{
					vector<double> d;
					for(int j=0;j<col[i]->vec.size();j++)
						d.push_back(col[i]->vec[j]->getNumeriacalValue());
					quick(d,0,d.size()-1);
					for(int j=0;j<col[i]->vec.size();j++)
						col[i]->vec[j]->value=doubleToString(d[j]);
					break;
				}
			}
		}
		else if(vec[0]=="shuffle")
		{
			for(int i=0;i<col.size();i++)
				if(col[i]->name==vec[1])
				{
					srand(time(0));
					for(int j=0;j<col[i]->vec.size();j++)
					{
						int a=rand()%col[i]->vec.size();
						int b=rand()%col[i]->vec.size();
						variable* t=col[i]->vec[a];
						col[i]->vec[a]=col[i]->vec[b];
						col[i]->vec[b]=t;

					}
					break;
				}
		}
	}
			f_run.close();
		}
		}
	}
	return 0;
}